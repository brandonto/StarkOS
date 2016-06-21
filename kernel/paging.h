//******************************************************************************
//
// paging.h
//
// Paging for StarkOS.
//
// Copyright (c) 2016 Brandon To
// This code is licensed under BSD license (see LICENSE.txt for details)
//
// Created:
// April 6, 2016
//
//******************************************************************************
#ifndef __PAGING_H__
#define __PAGING_H__

#include <multiboot.h>
#include <stdint.h>

//******************************************************************************
// Defines and Macros
//******************************************************************************
#define PAGE_DIR_SIZE           1024
#define PAGE_TBL_SIZE           1024

//******************************************************************************
// Data Structures
//******************************************************************************
struct page_dir_entry
{
    uint8_t flags;
    uint8_t addr_low_flags;
    uint16_t addr_high;
} __attribute__((packed)); // Prevents compiler optimization

//
// Flags byte:
// Bit 7: Page size
//   0 = 4KB
//   1 = 4MB
// Bit 6: Reserved (set to 0)
// Bit 5: Accessed (will not be cleared by CPU)
//   0 = Page has not been read or written to
//   1 = Page has been read of written to
// Bit 4: Cache disabled
//   0 = Page will be cached
//   1 = Page will not be cached
// Bit 3: Write-through
//   0 = Write-back enabled
//   1 = Write-through enabled
// Bit 2: User/Supervisor
//   0 = Can be accessed by all
//   1 = Can only be accessed by supervisor
// Bit 1: Read/Write
//   0 = Read-only
//   1 = Read/Write
// Bit 0: Present
//   0 = Not present in physical memory
//   1 = Present in physical memory
//
// addr_low_flags byte:
// Bits 4-7: Lower 4 bits of address of page table
// Bits 1-3: Unused
// Bit 0: Ignored
//

struct page_table_entry
{
    uint8_t flags;
    uint8_t addr_low_flags;
    uint16_t addr_high;
} __attribute__((packed)); // Presents compiler optimization

//
// Flags byte:
// Bit 7: Reserved (set to 0)
// Bit 6: Dirty (will not be set by CPU)
//   0 = Page has not been written to
//   1 = Page has been written to
// Bit 5: Accessed (will not be cleared by CPU)
//   0 = Page has not been read or written to
//   1 = Page has been read of written to
// Bit 4: Cache disabled
//   0 = Page will be cached
//   1 = Page will not be cached
// Bit 3: Write-through
//   0 = Write-back enabled
//   1 = Write-through enabled
// Bit 2: User/Supervisor
//   0 = Can be accessed by all
//   1 = Can only be accessed by supervisor
// Bit 1: Read/Write
//   0 = Read-only
//   1 = Read/Write
// Bit 0: Present
//   0 = Not present in physical memory
//   1 = Present in physical memory
//
// addr_low_flags byte:
// Bits 4-7: Lower 4 bits of address of page
// Bits 1-3: Unused
// Bit 0: Global (Page global enable bit in CR4 must be set to use this feature)
//   0 = Allows the TBL to update address in cache is CR3 is set
//   1 = Prevents TBL from updating address in cache if CR3 is set
//

//******************************************************************************
// Function Prototypes
//******************************************************************************
extern void paging_init(struct multiboot_mmap_entry *mmap);

#endif /* __PAGING_H__ */

