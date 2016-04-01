//******************************************************************************
//
// irq.c
//
// Interrupt requests for StarkOS.
//
// Copyright (c) 2016 Brandon To
// This code is licensed under BSD license (see LICENSE.txt for details)
//
// Created:
// March 31, 2016
//
//******************************************************************************
#include <irq.h>

#include <pic.h>

// Array of function pointers for IRQ handlers
void *irq_routines[16] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

void irq_init(void)
{
    // Map IRQ0 to 15 to IDT entries 32 to 47
    pic_remap(0x20, 0x28);

    // Install ISRs for IRQ entires in IDT
    idt_set_gate(32, (unsigned)irq0, 0x08, 0x8E);
    idt_set_gate(33, (unsigned)irq1, 0x08, 0x8E);
    idt_set_gate(34, (unsigned)irq2, 0x08, 0x8E);
    idt_set_gate(35, (unsigned)irq3, 0x08, 0x8E);
    idt_set_gate(36, (unsigned)irq4, 0x08, 0x8E);
    idt_set_gate(37, (unsigned)irq5, 0x08, 0x8E);
    idt_set_gate(38, (unsigned)irq6, 0x08, 0x8E);
    idt_set_gate(39, (unsigned)irq7, 0x08, 0x8E);

    idt_set_gate(40, (unsigned)irq8, 0x08, 0x8E);
    idt_set_gate(41, (unsigned)irq9, 0x08, 0x8E);
    idt_set_gate(42, (unsigned)irq10, 0x08, 0x8E);
    idt_set_gate(43, (unsigned)irq11, 0x08, 0x8E);
    idt_set_gate(44, (unsigned)irq12, 0x08, 0x8E);
    idt_set_gate(45, (unsigned)irq13, 0x08, 0x8E);
    idt_set_gate(46, (unsigned)irq14, 0x08, 0x8E);
    idt_set_gate(47, (unsigned)irq15, 0x08, 0x8E);
}

void irq_install_handler(uint32_t irq, void (*handler)(struct registers *r))
{
    irq_routines[irq] = handler;
}

void irq_uninstall_handler(uint32_t irq)
{
    irq_routines[irq] = 0;
}

void irq_handler(struct registers *r)
{
    // TODO (Brandon)
}

