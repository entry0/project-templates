// ctype.h - Defines set of functions used to classify characters by their types or to convert between upper and lower case in a way that is independent of the used character set (typically ASCII or one of its extensions, although implementations utilizing EBCDIC are also known).

#ifndef CTYPE_H
#define CTYPE_H

int isalpha(int c)
{
	return ((unsigned int)c | 32) - 'a' < 26;
}

int isdigit(int c)
{
	return (unsigned)c - '0' < 10;
}

int isalnum(int c)
{
	return isalpha(c) || isdigit(c);
}

int isblank(int c)
{
	return (c == ' ' || c == '\t');
}

int iscntrl(int c)
{
	return (unsigned int)c < 0x20 || c == 0x7F;
}

int isgraph(int c)
{
	return (unsigned)c - 0x21 < 0x5E;
}


int islower(int c)
{
	return (unsigned)c - 'a' < 26;
}

int isprint(int c)
{
	return (unsigned)c - 0x20 < 0x5F;
}

int ispunct(int c)
{
	return isgraph(c) && !isalnum(c);
}

int isspace(int c)
{
	return c == ' ' || (unsigned)c - '\t' < 5;
}

int isupper(int c)
{
	return (unsigned)c - 'A' < 26;
}

int isxdigit(int c)
{
	return isdigit(c) || ((unsigned)c | 32) - 'a' < 6;
}

int tolower(int c)
{
	if (isupper(c)) return c | 32;
	return c;
}

int toupper(int c)
{
	if (islower(c)) return c & 0x5F;
	return c;
}

#endif
