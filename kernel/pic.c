//******************************************************************************
//
// pic.c
//
// Programmable interrupt controller for StarkOS.
//
// Copyright (c) 2016 Brandon To
// This code is licensed under BSD license (see LICENSE.txt for details)
//
// Created:
// April 1, 2016
//
//******************************************************************************
#include <pic.h>

#include <system.h>

//
// Initialization
//
// When you enter protected mode (or even before hand, if you're not using GRUB)
// the first command you will need to give the two PICs is the initialise
// command (code 0x11). This command makes the PIC wait for 3 extra
// "initialisation words" on the data port. These bytes give the PIC:
//
// - Its vector offset. (ICW2)
// - Tell it how it is wired to master/slaves. (ICW3)
// - Gives additional information about the environment. (ICW4)
//

// Remaps PIC to new vector offsets
void pic_remap(uint32_t offset1, uint32_t offset2)
{
    uint8_t m1, m2;

    // Save masks
    m1 = inportb(PIC_MASTER_DATA);
    m2 = inportb(PIC_SLAVE_DATA);

    // Start the initialization sequence (in cascade mode)
    outportb(PIC_MASTER_CMD, ICW1_INIT+ICW1_ICW4);
    outportb(PIC_SLAVE_CMD, ICW1_INIT+ICW1_ICW4);

    // Send vector offset address to master and slave PIC
    outportb(PIC_MASTER_DATA, offset1); // ICW2: Master PIC vector offset
    outportb(PIC_SLAVE_DATA, offset2);  // ICW2: Slave PIC vector offset

    // Tell PIC how it is wired to master/slaves
    outportb(PIC_MASTER_DATA, 0x04);    // ICW3: Slave PIC at IRQ2 (0000 0100)
    outportb(PIC_SLAVE_DATA, 0x02);     // ICW3: Casecade identity (0000 0010)

    // Gives additional information about the environment
    outportb(PIC_MASTER_DATA, ICW4_8086);
    outportb(PIC_SLAVE_DATA, ICW4_8086);

    // Restore saved masks
    outportb(PIC_MASTER_DATA, m1);
    outportb(PIC_SLAVE_DATA, m2);
}

