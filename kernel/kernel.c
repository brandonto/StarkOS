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
#include <string.h>
#include <system.h>
#include <vga.h>

// Entry point to part of kernel written in C
int main()
{
    char *hello_world = "Hello world!";

    // Set up global descriptor table
    gdt_init();

    // Set up interrupt descriptor table
    idt_init();

    // Set up interrupt service routines
    isr_init();

    // Set up interrupt requets
    irq_init();

    // Hello world test
    vga_clear();
    vga_puts(hello_world);

    // Infinite loop
    while (1);
}

