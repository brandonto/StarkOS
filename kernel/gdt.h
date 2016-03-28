//******************************************************************************
//
// gdt.h
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
#ifndef __GDT_H__
#define __GDT_H__

#include <stdint.h>

//******************************************************************************
// Defines and Macros
//******************************************************************************
#define GDT_TABLE_SIZE  3

//******************************************************************************
// Data Structures
//******************************************************************************
struct gdt_entry
{
    uint16_t    limit_low;
    uint16_t    base_low;
    uint8_t     base_middle;
    uint8_t     access;
    uint8_t     granularity;
    uint8_t     base_high;
} __attribute__((packed)); // Prevents compiler optimization

struct gdt_ptr
{
    uint16_t    limit;
    uint32_t     base;
} __attribute__((packed));

//******************************************************************************
// Function Prototypes
//******************************************************************************
extern void gdt_init(void);
extern void gdt_set_gate(uint32_t num, uint64_t base, uint64_t limit,
        uint8_t access, uint8_t gran);
extern void gdt_flush(void);

#endif /* __GDT_H__ */

