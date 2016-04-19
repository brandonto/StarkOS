//******************************************************************************
//
// vga.h
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
#ifndef __VGA_H__
#define __VGA_H__

#include <stdint.h>

//******************************************************************************
// Defines and Macros
//******************************************************************************
#define VGA_SCREEN_HEIGHT           25
#define VGA_SCREEN_WIDTH            80

#define VGA_COLOR_BLACK             0
#define VGA_COLOR_BLUE              1
#define VGA_COLOR_GREEN             2
#define VGA_COLOR_CYAN              3
#define VGA_COLOR_RED               4
#define VGA_COLOR_MAGENTA           5
#define VGA_COLOR_BROWN             6
#define VGA_COLOR_LIGHT_GRAY        7
#define VGA_COLOR_DARK_GREY         8
#define VGA_COLOR_LIGHT_BLUE        9
#define VGA_COLOR_LIGHT_GREEN       10
#define VGA_COLOR_LIGHT_CYAN        11
#define VGA_COLOR_LIGHT_RED         12
#define VGA_COLOR_LIGHT_MAGENTA     13
#define VGA_COLOR_LIGHT_BROWN       14
#define VGA_COLOR_WHITE             15

#define VGA_WORD(a, c) ((a << 8) | c)
#define VGA_ATTRIB(f, b) (f | (b << 4))

#define VDC_INDEX                   0x3D4
#define VDC_DATA                    0x3D5

#define CRT_CURSOR_HIGH_REG         0x0E
#define CRT_CURSOR_LOW_REG          0x0F

//******************************************************************************
// Function Prototypes
//******************************************************************************
extern void vga_settextcolor(uint8_t forecolor, uint8_t backcolor);
extern void vga_putch(char c);
extern void vga_puts(char *str);
extern void vga_clear(void);
extern void vga_printf(const char *format, ...);

#endif /* __VGA_H__ */

