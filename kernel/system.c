//******************************************************************************
//
// system.c
//
// System library for StarkOS.
//
// Copyright (c) 2016 Brandon To
// This code is licensed under BSD license (see LICENSE.txt for details)
//
// Created:
// March 27, 2016
//
//******************************************************************************
#include <system.h>

uint8_t inportb(uint16_t port)
{
    uint8_t in;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (in) : "dN" (port));
    return in;
}

void outportb(uint16_t port, uint8_t data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (port), "a" (data));
}

