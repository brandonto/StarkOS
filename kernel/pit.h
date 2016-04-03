//******************************************************************************
//
// pit.h
//
// Programmblae interval timer driver for StarkOS.
//
// Copyright (c) 2016 Brandon To
// This code is licensed under BSD license (see LICENSE.txt for details)
//
// Created:
// April 3, 2016
//
//******************************************************************************
#ifndef __PIT_H__
#define __PIT_H__

#include <stdint.h>

//******************************************************************************
// Defines and Macros
//******************************************************************************
#define PIT_DATA_REG_0          0x40    /* Data register for counter 0 */
#define PIT_DATA_REG_1          0x41    /* Data register for counter 1 */
#define PIT_DATA_REG_2          0x42    /* Data register for counter 2 */
#define PIT_CMD_REG             0x43    /* Command register */

#define PIT_CW_SC_0             0x00    /* Select counter 0 */
#define PIT_CW_SC_1             0x40    /* Select counter 1 */
#define PIT_CW_SC_2             0x80    /* Select counter 2 */
#define PIT_CW_SC_3             0xD0    /* Read-back command */

#define PIT_CW_RW_LATCH         0x00    /* Counter latch command */
#define PIT_CW_RW_LSB           0x10    /* Read/write LSB only */
#define PIT_CW_RW_MSB           0x20    /* Read/write MSB only */
#define PIT_CW_RW_LSB_MSB       0x30    /* Read/write LSB then MSB */

#define PIT_CW_MODE_0           0x00    /* Interrupt on terminal count */
#define PIT_CW_MODE_1           0x02    /* Hardware retriggerable one-shot */
#define PIT_CW_MODE_2           0x04    /* Rate generator */
#define PIT_CW_MODE_3           0x06    /* Square wave generator */
#define PIT_CW_MODE_4           0x08    /* Software triggered strobe */
#define PIT_CW_MODE_5           0x0A    /* Hardware triggered strobe */

#define PIT_CW_BCD_0            0x00    /* Binary counter */
#define PIT_CW_BCD_1            0x01    /* Binary coded decimal counter */

#define PIT_DIVISOR             1193180

//******************************************************************************
// Function Prototypes
//******************************************************************************
extern void pit_init(uint32_t hz);
extern void pit_counter_0_delay(uint32_t ticks);

#endif /* __PIT_H__ */

