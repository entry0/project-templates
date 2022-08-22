// string.h - Defines string-handling functions.

#ifndef STRING_H
#define STRING_H

#include "stdint.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wattributes"

size_t strlen(const char *s)
{
	const char* a = s;
	for (; *s; s++);
	return s - a;
}

char* strchrnul(const char* s, int c)
{
	c = (unsigned char)c;
	if (!c) return (char*)s + strlen(s);
	for (; *s && *(unsigned char*)s != c; s++);
	return (char *)s;
}

char* strchr(const char* s, int c)
{
	char* r = strchrnul(s, c);
	return *(unsigned char*)r == (unsigned char)c ? r : 0;
}

#define strrchr strchr

#pragma GCC diagnostic pop
#endif
