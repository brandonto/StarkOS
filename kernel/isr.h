//******************************************************************************
//
// isr.h
//
// Interrupt service routines for StarkOS.
//
// Copyright (c) 2016 Brandon To
// This code is licensed under BSD license (see LICENSE.txt for details)
//
// Created:
// March 30, 2016
//
//******************************************************************************
#ifndef __ISR_H__
#define __ISR_H__

#include <stdint.h>

//******************************************************************************
// Data Structures
//******************************************************************************

// Registers pushed onto stack by ISR
struct registers
{
    uint32_t gs, fs, es, ds;
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
    uint32_t int_no, err_code;
    uint32_t eip, cs, eflags, useresp, ss;
};

//******************************************************************************
// Function Prototypes
//******************************************************************************
extern void isr0(void);
extern void isr1(void);
extern void isr2(void);
extern void isr3(void);
extern void isr4(void);
extern void isr5(void);
extern void isr6(void);
extern void isr7(void);
extern void isr8(void);
extern void isr9(void);
extern void isr10(void);
extern void isr11(void);
extern void isr12(void);
extern void isr13(void);
extern void isr14(void);
extern void isr15(void);
extern void isr16(void);
extern void isr17(void);
extern void isr18(void);
extern void isr19(void);
extern void isr20(void);
extern void isr21(void);
extern void isr22(void);
extern void isr23(void);
extern void isr24(void);
extern void isr25(void);
extern void isr26(void);
extern void isr27(void);
extern void isr28(void);
extern void isr29(void);
extern void isr30(void);
extern void isr31(void);

extern void isr_init(void);

#endif /* __ISR_H__ */

