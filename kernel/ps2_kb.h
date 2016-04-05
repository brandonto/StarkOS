//******************************************************************************
//
// ps2_kb.h
//
// PS/2 keyboard driver for StarkOS.
//
// Copyright (c) 2016 Brandon To
// This code is licensed under BSD license (see LICENSE.txt for details)
//
// Created:
// April 5, 2016
//
//******************************************************************************
#ifndef __PS2_KB_H__
#define __PS2_KB_H__

#include <stdint.h>

//******************************************************************************
// Defines and Macros
//******************************************************************************
#define PS2_DATA_REG        0x60
#define PS2_STATUS_REG      0x64
#define PS2_CMD_REG         0x64

#define KB_KEY_RELEASED     0x80

//******************************************************************************
// Function Prototypes
//******************************************************************************
extern void ps2_kb_init(void);

#endif /* __PS2_KB_H__ */

