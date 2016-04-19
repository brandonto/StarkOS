//******************************************************************************
//
// vga.c
//
// VGA driver for StarkOS.
//
// Copyright (c) 2016 Brandon To
// This code is licensed under BSD license (see LICENSE.txt for details)
//
// Created:
// March 27, 2016
//
//******************************************************************************
#include <vga.h>

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <system.h>

// Address of VGA memory buffer
static uint16_t *_vga_memptr = (uint16_t*)0xB8000;
static uint8_t _attribute = VGA_ATTRIB(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
static int _cursor_x = 0;
static int _cursor_y = 0;

// Static function prototypes
static void _vga_move_cursor(void);
static void _vga_scroll(void);

void vga_settextcolor(uint8_t forecolor, uint8_t backcolor)
{
    _attribute = VGA_ATTRIB(forecolor, backcolor);
}

void vga_putch(char c)
{
    uint16_t *mem_loc;

    // Backspace
    if (c == 0x08)
    {
        if (_cursor_x != 0)
        {
            // Moves cursor back one space
            _cursor_x--;
        }
    }
    // Tab
    else if (c == 0x09)
    {
        // Increment x to the nearest column that is divisible by 8
        _cursor_x = (_cursor_x + 8) & ~(8 - 1);
    }
    // Carriage return
    else if (c == '\r')
    {
        // Moves x back to 0
        _cursor_x = 0;
    }
    // Newline
    else if (c == '\n')
    {
        // Moves x back to 0 and increments y
        _cursor_x = 0;
        _cursor_y++;
    }
    // Any printable character
    else if (c >= ' ')
    {
        // Calculate memory location and write to it
        mem_loc = _vga_memptr + _cursor_y*VGA_SCREEN_WIDTH + _cursor_x;
        *mem_loc = VGA_WORD(_attribute, c);
        _cursor_x++;
    }

    // Cursor moved past right side of screen.
    if (_cursor_x >= VGA_SCREEN_WIDTH)
    {
        _cursor_x = 0;
        _cursor_y++;
    }

    // Adjust screen and cursor
    _vga_scroll();
    _vga_move_cursor();
}

void vga_puts(char *str)
{
    int i = 0;
    while (*(str+i) != '\0')
    {
        vga_putch(*(str+i++));
    }
}

void vga_clear(void)
{
    int i;
    uint16_t space = VGA_WORD( VGA_ATTRIB( VGA_COLOR_BLACK,
                                           VGA_COLOR_BLACK), ' ');

    // Set entire screen to spaces
    for (i=0; i<VGA_SCREEN_HEIGHT*VGA_SCREEN_WIDTH; i++)
    {
        _vga_memptr[i] = space;
    }

    // Reset cursor
    _cursor_x = 0;
    _cursor_y = 0;
}

void vga_printf(const char *format, ...)
{
    char **args = (char **)&format;
    char buf[20];
    char *p = NULL;
    char c;

    // This makes pointer point to address of first variable argument
    args++;

    while ((c = *format++) != '\0')
    {
        if (c != '%')
        {
            vga_putch(c);
        }
        else
        {
            c = *format++;
            switch(c)
            {
                case 'd':
                case 'u':
                    p = itoa(*((int*)args++), buf, 10);
                    break;

                case 'x':
                    p = itoa(*((int*)args++), buf, 16);
                    break;

                case 's':
                    p = *args++;
                    if (p == NULL)
                    {
                        p = "(null)";
                    }
                    break;

                default:
                    vga_putch(**args++);
                    break;
            }

            if (p != NULL)
            {
                vga_puts(p);
                p = NULL;
            }
        }
    }
}

static void _vga_move_cursor(void)
{
    // Calculate location of "blinking" cursor
    uint16_t location = _cursor_y*VGA_SCREEN_WIDTH + _cursor_x;

    // Write to register of VGA controller that dictates blinking cursor
    outportb(VDC_INDEX, CRT_CURSOR_HIGH_REG);
    outportb(VDC_DATA, (uint8_t)((location >> 8)) | 0xFF);
    outportb(VDC_INDEX, CRT_CURSOR_LOW_REG);
    outportb(VDC_DATA, (uint8_t)(location | 0xFF));
}

static void _vga_scroll(void)
{
    int i;
    int diff;
    int last_row_index = VGA_SCREEN_WIDTH*(VGA_SCREEN_HEIGHT-1);
    uint16_t space = VGA_WORD( VGA_ATTRIB( VGA_COLOR_BLACK,
                                           VGA_COLOR_BLACK), ' ');

    // Cursor went past bottom of screen
    if (_cursor_y >= VGA_SCREEN_HEIGHT)
    {
        // Calculate how far the cursor passes screen height
        diff = _cursor_y - (VGA_SCREEN_HEIGHT - 1);

        // Shift every row from the first row until the row before the cursor
        // up by one row
        memcpy(_vga_memptr, _vga_memptr+(VGA_SCREEN_WIDTH*diff),
                VGA_SCREEN_WIDTH*(VGA_SCREEN_HEIGHT-diff)*sizeof(uint16_t));

        // Clear the new last row
        for (i=0; i<VGA_SCREEN_WIDTH; i++)
        {
            _vga_memptr[last_row_index+i] = space;
        }

        // Move cursor to last row
        _cursor_y = VGA_SCREEN_HEIGHT - 1;
    }
}

