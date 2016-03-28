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

// Address of VGA memory buffer
static uint16_t *_vga_memptr = (*uint16_t)0xB8000;
static int attribute = 0x0F;
static int cursor_x = 0;
static int cursor_y = 0;

void vga_settextcolor(uint8_t forecolor, uint8_t backcolor)
{
    // TODO (Brandon): Implementation
}

void vga_putch(unsigned char c)
{
    // TODO (Brandon): Implementation
}

void vga_puts(unsigned char *str)
{
    // TODO (Brandon): Implementation
}

void vga_clear(void)
{
    // TODO (Brandon): Implementation
}

