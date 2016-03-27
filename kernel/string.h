#ifndef __STRING_H__
#define __STRING_H__

#include <stdint.h>

extern void *memcpy(void *dest, const void *src, size_t n);
extern void *memset(void *s, int c, size_t n);
extern size_t strlen(const char *s);

#endif /* __STRING_H__ */

