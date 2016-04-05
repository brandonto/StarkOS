//******************************************************************************
//
// irq.h
//
// Interrupt requests for StarkOS.
//
// Copyright (c) 2016 Brandon To
// This code is licensed under BSD license (see LICENSE.txt for details)
//
// Created:
// March 31, 2016
//
//******************************************************************************
#ifndef __IRQ_H__
#define __IRQ_H__

#include <isr.h>
#include <stdint.h>

//******************************************************************************
// Defines and Macros
//******************************************************************************
#define IRQ0    0
#define IRQ1    1
#define IRQ2    2
#define IRQ3    3
#define IRQ4    4
#define IRQ5    5
#define IRQ6    6
#define IRQ7    7
#define IRQ8    8
#define IRQ9    9
#define IRQ10   10
#define IRQ11   11
#define IRQ12   12
#define IRQ13   13
#define IRQ14   14
#define IRQ15   15

//******************************************************************************
// Function Prototypes
//******************************************************************************
extern void irq0(void);
extern void irq1(void);
extern void irq2(void);
extern void irq3(void);
extern void irq4(void);
extern void irq5(void);
extern void irq6(void);
extern void irq7(void);
extern void irq8(void);
extern void irq9(void);
extern void irq10(void);
extern void irq11(void);
extern void irq12(void);
extern void irq13(void);
extern void irq14(void);
extern void irq15(void);

extern void irq_init(void);
extern void irq_install_handler(uint32_t irq, void (*handler)(struct registers *r));
extern void irq_uninstall_handler(uint32_t irq);
extern void irq_handler(struct registers *r);

#endif /* __IRQ_H__ */

