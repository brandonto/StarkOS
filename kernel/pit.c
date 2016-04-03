//******************************************************************************
//
// pit.c
//
// Programmblae interval timer driver for StarkOS.
//
// Copyright (c) 2016 Brandon To
// This code is licensed under BSD license (see LICENSE.txt for details)
//
// Created:
// April 3, 2016
//
//******************************************************************************
#include <pit.h>

#include <irq.h>
#include <isr.h>
#include <system.h>

// Number of ticks on timer
static uint32_t _ticks = 0;

// ISR for counter 0. Increments number of ticks.
static void _counter_0_isr(struct registers *r)
{
    _ticks++;
}

void pit_init(uint32_t hz)
{
    uint32_t divisor = PIT_DIVISOR / hz;

    // Install ISR (IRQ0) for counter 0
    irq_install_handler(0, &_counter_0_isr);

    // Configure counter 0 to square mode and prepare it to read LSB then MSB
    outportb(PIT_CMD_REG, PIT_CW_SC_0 | PIT_CW_RW_LSB_MSB | PIT_CW_MODE_3);

    // Send LSB then MSB of divisor
    outportb(PIT_DATA_REG_0, divisor & 0xFF);
    outportb(PIT_DATA_REG_0, (divisor >> 8) & 0xFF);
}

void pit_counter_0_delay(uint32_t ticks)
{
    uint64_t total_ticks = _ticks + ticks;

    // Loop until total_ticks is reached
    while (total_ticks >= _ticks);
}

