//******************************************************************************
//
// kernel.c
//
// Main kernel of StarkOS.
//
// Copyright (c) 2016 Brandon To
// This code is licensed under BSD license (see LICENSE.txt for details)
//
// Created:
// March 27, 2016
//
//******************************************************************************
#include <gdt.h>
#include <idt.h>
#include <irq.h>
#include <isr.h>
#include <multiboot.h>
#include <pit.h>
#include <ps2_kb.h>
#include <stdint.h>
#include <string.h>
#include <system.h>
#include <vga.h>

#include <stdlib.h>

static char *_stark_os_logo =
"\n\n\n \
        _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/\n\
        \n\
       _/_/_/_/  _/_/_/_/  _/_/_/_/  _/_/_/    _/    _/    _/_/_/_/  _/_/_/_/\n\
      _/           _/     _/    _/  _/    _/  _/  _/      _/    _/  _/\n\
     _/_/_/_/     _/     _/_/_/_/  _/_/_/    _/_/        _/    _/  _/_/_/_/\n\
          _/     _/     _/    _/  _/   _/   _/  _/      _/    _/        _/\n\
   _/_/_/_/     _/     _/    _/  _/    _/  _/    _/    _/_/_/_/  _/_/_/_/\n\
   \n\
  _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/\n\
   \n Copyright (c) 2016 Brandon To\n\
\n\n";

// Entry point to part of kernel written in C
int kernel_main(uint32_t multiboot_info_addr)
{
    struct multiboot_info *mbi;
    struct multiboot_mmap_entry *mmap;

    // Saves address of multiboot info structure
    mbi = (struct multiboot_info*)multiboot_info_addr;

    // Initialization
    gdt_init();
    idt_init();
    isr_init();
    irq_init();
    pit_init(50);
    ps2_kb_init();

    // Enable interrupts
    __asm__ __volatile__ ("sti");

    // Display StarkOS logo
    vga_clear();
    //vga_puts(_stark_os_logo);

    //vga_printf("Hello world! %d, %x, %s\n", 255, 255, "255");

    if (mbi->flags & MULTIBOOT_INFO_MEMORY)
    {
        vga_printf("mem_lower = %uKB, mem_upper = %uKB\n",
                (uint32_t)mbi->mem_lower, (uint32_t)mbi->mem_upper);
    }

    if (mbi->flags & MULTIBOOT_INFO_MEM_MAP)
    {
        vga_printf("mmap_addr = 0x%x, mmap_length = 0x%x\n",
                (uint32_t)mbi->mmap_addr, (uint32_t)mbi->mmap_length);

        for (mmap = (struct multiboot_mmap_entry*)mbi->mmap_addr;
                (uint32_t)mmap < (mbi->mmap_addr + mbi->mmap_length);
                mmap = (struct multiboot_mmap_entry*)((uint32_t)mmap
                    + mmap->size + sizeof(mmap->size)))
        {
            vga_printf("base_addr_high = 0x%x, base_addr_low = 0x%x, "
                    "length_high = 0x%x, length_low = 0x%x, type = 0x%x\n",
                    mmap->addr >> 32,
                    mmap->addr & 0xFFFFFFFF,
                    mmap->len >> 32,
                    mmap->len & 0xFFFFFFFF,
                    (uint32_t)mmap->type);
        }
    }

    // Infinite loop
    while (1);
}

