//******************************************************************************
//
// idt.h
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
#ifndef __IDT_H__
#define __IDT_H__

#include <stdint.h>

//******************************************************************************
// Defines and Macros
//******************************************************************************
#define IDT_TABLE_SIZE  256

//******************************************************************************
// Data Structures
//******************************************************************************
struct idt_entry
{
    uint16_t    base_low;
    uint16_t    sel;
    uint8_t     zero;
    uint8_t     flags;
    uint8_t     base_high;
} __attribute__((packed)); // Prevents compiler optimization

//
// Flags byte:
// Bit 7: Segment in memory (used with virtual memory)
// Bits 5-6: Descriptor privelege level
//   0 = (Ring 0) Highest
//   ...
//   3 = (Ring 3) Lowest
// Bit 4: Storage segment (always 0 for interrupts)
// Bits 0-3: Gate type
//   0b0101 = 80386 32-bit task gate
//   0b0110 = 80286 16-bit interrupt gate
//   0b0111 = 80286 16-bit trap gate
//   0b1110 = 80386 32-bit interrupt gate
//   0b1111 = 80386 32-bit trap gate
//

struct idt_ptr
{
    uint16_t    limit;
    uint32_t     base;
} __attribute__((packed));

//******************************************************************************
// Function Prototypes
//******************************************************************************
extern void idt_init(void);
extern void idt_set_gate(uint8_t num, uint64_t base, uint16_t sel,
        uint8_t flags);
extern void idt_load(void);

#endif /* __IDT_H__ */

