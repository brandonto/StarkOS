//******************************************************************************
//
// system.h
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
#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include <stdint.h>

//******************************************************************************
// Function Prototypes
//******************************************************************************
extern uint8_t inportb(uint16_t port);
extern void outportb(uint16_t port, uint8_t data);

#endif /* __SYSTEM_H__ */

