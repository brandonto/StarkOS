#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include <stdint.h>

extern uint8_t char inportb(uint16_t port);
extern void outportb(uint16_t port, uint8_t data);

#endif /* __SYSTEM_H__ */
