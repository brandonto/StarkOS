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
#include <pit.h>
#include <ps2_kb.h>
#include <string.h>
#include <system.h>
#include <vga.h>

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
int kernel_main()
{
    // Set up global descriptor table
    gdt_init();

    // Set up interrupt descriptor table
    idt_init();

    // Set up interrupt service routines
    isr_init();

    // Set up interrupt requets
    irq_init();

    // Set up timer to 50hz
    pit_init(50);

    // Set up keyboard
    ps2_kb_init();

    // Enable interrupts
    __asm__ __volatile__ ("sti");

    // Logo
    vga_clear();
    vga_puts(_stark_os_logo);

    // Infinite loop
    while (1);
}

