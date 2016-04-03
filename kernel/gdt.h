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

//
// Access byte:
// Bit 7: Segment in memory (used with virtual memory)
// Bits 5-6: Descriptor privelege level
//   0 = (Ring 0) Highest
//   ...
//   3 = (Ring 3) Lowest
// Bit 4: Descriptor bit
//   0 = System descriptor
//   1 = Code or data descriptor
// Bits 1-3: Descriptor type
//   Bit 3: Executable segment
//     0 = Data segment (non-executable)
//     1 = Code segment (executable)
//   Bit 2: Expansion direction (Data segment); Conforming (Code segment)
//   Bit 1: Reable and writable
//     0 = Read only (Data segment); Execute only (Code Segment)
//     1 = Read/write (Data segment); Read/execute (Code Segment)
// Bit 0: Access bit (used with virtual memory)
//
// Granularity byte:
// Bit 7: Granularity bit
//   0 = None
//   1 = Limit is multiplied by 4k
// Bit 6: Segment type
//   0 = 16-bit
//   1 = 32-bit
// Bit 5: Reserved (should be 0)
// Bit 4: Reserved
// Bits 0-3: Bits 16-19 of the segment limit
//

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
extern void gdt_load(void);

#endif /* __GDT_H__ */

