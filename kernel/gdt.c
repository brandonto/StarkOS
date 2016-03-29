//******************************************************************************
//
// gdt.c
//
// Global descriptor tables for StarkOS.
//
// Copyright (c) 2016 Brandon To
// This code is licensed under BSD license (see LICENSE.txt for details)
//
// Created:
// March 28, 2016
//
//******************************************************************************
#include <gdt.h>

// Global descriptor table
struct gdt_entry gdt[GDT_TABLE_SIZE];
struct gdt_ptr gdtptr;

void gdt_init(void)
{
    // Initialize GDT pointer
    gdtptr.base = (uint32_t)(&gdt);
    gdtptr.limit = (sizeof(struct gdt_entry)*GDT_TABLE_SIZE) - 1;

    // NULL descriptor
    gdt_set_gate(0, 0, 0, 0, 0);

    // Code segment
    gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);

    // Data segment
    gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);

    // Load new GDT into registers
    gdt_flush();
}

void gdt_set_gate(uint32_t num, uint64_t base, uint64_t limit, uint8_t access,
        uint8_t gran)
{
    // Set up descriptor base address
    gdt[num].base_low = (base & 0xFFFF);
    gdt[num].base_middle = ((base >> 16) & 0xFF);
    gdt[num].base_high = ((base >> 24) & 0xFF);

    // Set up descriptor limit
    gdt[num].limit_low = (limit & 0xFFFF);

    // Set up descriptor granularity
    gdt[num].granularity = ((limit >> 16) & 0x0F);
    gdt[num].granularity |= (gran & 0xF0);

    // Set up access flags
    gdt[num].access = access;
}

