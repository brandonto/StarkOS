//******************************************************************************
//
// idt.c
//
// Interrupt descriptor tables for StarkOS.
//
// Copyright (c) 2016 Brandon To
// This code is licensed under BSD license (see LICENSE.txt for details)
//
// Created:
// March 29, 2016
//
//******************************************************************************
#include <idt.h>

#include <string.h>

// Interrupt descriptor table
struct idt_entry idt[IDT_TABLE_SIZE];
struct idt_ptr idtptr;

void idt_init(void)
{
    // Initialize IDT pointer
    idtptr.base = (uint32_t)(&idt);
    idtptr.limit = (sizeof(struct idt_entry)*IDT_TABLE_SIZE) - 1;

    // Initialize IDT
    memset(&idt, 0, sizeof(struct idt_entry)*IDT_TABLE_SIZE);

    // Initialize ISRs

    // Loads new IDT into registers
    idt_load();
}

void idt_set_gate(uint8_t num, uint64_t base, uint16_t sel, uint8_t flags)
{
    // Set up descriptor base address
    idt[num].base_low = (base & 0xFFFF);
    idt[num].base_high = ((base >> 16) & 0xFFFF);

    // Set up descriptor selector
    idt[num].sel = sel;

    // Set up descriptor unused bits
    idt[num].zero = 0;

    // Set up descriptor flags
    idt[num].flags = flags;
}

