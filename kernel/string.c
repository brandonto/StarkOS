//******************************************************************************
//
// string.c
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
#include <string.h>

void *memcpy(void *dest, const void *src, size_t n)
{
    size_t i = 0;
    while (i<n)
    {
        *((char*)dest+i) = *((const char*)src+i);
        i++;
    }
    return dest;
}

void *memset(void *str, int c, size_t n)
{
    size_t i = 0;
    while (i<n)
    {
        *((char*)str+i++) = (char)(c);
    }
    return str;
}

size_t strlen(const char *str)
{
    size_t len = 0;
    while (*(str+len) != '\0')
    {
        len++;
    }
    return len;
}

