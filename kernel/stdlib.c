//******************************************************************************
//
// stdlib.c
//
// Standard library for StarkOS.
//
// Copyright (c) 2016 Brandon To
// This code is licensed under BSD license (see LICENSE.txt for details)
//
// Created:
// April 19, 2016
//
//******************************************************************************
#include <stdlib.h>

#include <stdint.h>

char *itoa(int val, char *buf, int base)
{
    char *p = buf;
    char *q = buf;
    char temp;
    int remainder;

    // Handles 0 case
    if (val == 0)
    {
        *p++ = '0';
        *p = '\0';
        return buf;
    }

    // Prepend negative sign for negative values
    if (base == 10 && val < 0)
    {
        *p++ = '-';
        q++;
        val = -val;
    }

    // Extract digits from value. Result is in reverse order.
    do
    {
        remainder = val % base;
        *p++ = (remainder > 9)?'A'+remainder-10:'0'+remainder;
        val = val / base;
    } while (val != 0);

    // Append null terminator
    *p = '\0';

    // Reverse digits
    p--;
    while (q < p)
    {
        temp = *p;
        *p-- = *q;
        *q++ = temp;
    }

    return buf;
}

