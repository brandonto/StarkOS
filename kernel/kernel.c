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
\n\n\n";

// Entry point to part of kernel written in C
int kernel_main(uint64_t multiboot_info_addr)
{
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
    vga_puts(_stark_os_logo);

    //vga_puts(itoa(255, buf, 10));
    vga_printf("Hello world! %d, %x, %s\n", 255, 255, "255");

    // Infinite loop
    while (1);
}

