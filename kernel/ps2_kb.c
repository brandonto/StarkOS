//******************************************************************************
//
// ps2_kb.c
//
// PS/2 keyboard driver for StarkOS.
//
// Copyright (c) 2016 Brandon To
// This code is licensed under BSD license (see LICENSE.txt for details)
//
// Created:
// April 5, 2016
//
//******************************************************************************
#include <ps2_kb.h>

#include <irq.h>
#include <isr.h>
#include <system.h>
#include <vga.h>

static char _ps2_kb_us[128] =
{
    0, 27,
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    '-', '=', '\b', /* Backspace */
    '\t', /* Tab */
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
    0, /* Control */
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',
    0, /* Left shift */
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',
    0, /* Right shift */
    '*',
    0, /* Alt */
    ' ', /* Space bar */
    0, /* Caps lock */
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/* F1 ... F10 */
    0, /* Num lock*/
    0, /* Scroll Lock */
    0, /* Home key */
    0, /* Up Arrow */
    0, /* Page Up */
    '-',
    0, /* Left Arrow */
    0,
    0, /* Right Arrow */
    '+',
    0, /* End key*/
    0, /* Down Arrow */
    0, /* Page Down */
    0, /* Insert Key */
    0,	/* Delete Key */
    0, 0, 0,
    0, /* F11 */
    0, /* F12 */
    0, /* Everything else is undefined */
};

// ISR for keyboard.
static void _ps2_kb_isr(struct registers *r)
{
    // Get the scancode of key pressed
    int scan_code = inportb(PS2_DATA_REG);

    if (scan_code & KB_KEY_RELEASED)
    {
        // TODO
    }
    else // Key pressed
    {
        vga_putch(_ps2_kb_us[scan_code]);
    }
}

void ps2_kb_init(void)
{
    // Install ISR (IRQ1) for keyboard
    irq_install_handler(IRQ1, &_ps2_kb_isr);
}

