//******************************************************************************
//
// paging.c
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
#include <paging.h>

#include <vga.h>

struct page_dir_entry page_dir[PAGE_DIR_SIZE];
struct page_table_entry page_table[PAGE_DIR_SIZE][PAGE_TBL_SIZE];

void paging_init(struct multiboot_mmap_entry *mmap)
{
    vga_printf("page_dir[0] address = 0x%x\n", page_dir);
    vga_printf("page_dir[1] address = 0x%x\n", &page_dir[1]);
    vga_printf("page_dir size = %d\n", sizeof(struct page_dir_entry)*PAGE_DIR_SIZE);

    vga_printf("page_table[0][0] address = 0x%x\n", page_table);
    vga_printf("page_table[1][0] address = 0x%x\n", &page_table[1][0]);
    vga_printf("page_table size = %d\n", sizeof(struct page_table_entry)*PAGE_DIR_SIZE*PAGE_TBL_SIZE);
}
