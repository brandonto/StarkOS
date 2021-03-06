//******************************************************************************
//
// string.h
//
// String library for StarkOS.
//
// Copyright (c) 2016 Brandon To
// This code is licensed under BSD license (see LICENSE.txt for details)
//
// Created:
// March 27, 2016
//
//******************************************************************************
#ifndef __STRING_H__
#define __STRING_H__

#include <stddef.h>
#include <stdint.h>

//******************************************************************************
// Function Prototypes
//******************************************************************************
extern void *memcpy(void *dest, const void *src, size_t n);
extern void *memset(void *str, int c, size_t n);
extern size_t strlen(const char *str);

#endif /* __STRING_H__ */

