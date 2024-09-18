// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	// copiem sursa la destinatie
	int i = 0;
	while (source[i] != 0) {
		destination[i] = source[i];
		i++;
	}

	// adaugam terminator
	destination[i] = 0;

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	// adaugam pana la terminator
	int i;
	for (i = 0; i < (int)len; i++) {
		if (source[i] == 0)
			break;
		destination[i] = source[i];
	}

	// completam cu 0
	for (; i < (int)len; i++)
		destination[i] = 0;

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	// implementare sugeratde de GNU libc manual
	strcpy(destination + strlen(destination), source);
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	// derivam din implementarea lui strcat
	int n = strlen(destination);

	strncpy(destination + n, source, len);
	destination[n + len] = 0;

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	int i = 0;
	while (str1[i] != 0 && str2[i] != 0) {
		if (str1[i] != str2[i])
			// s-a gasit locul unde sirurile difera
			return (int)str1[i] - (int)str2[i];
		i++;
	}

	// cel putin unul dintre sirri s-a terminat
	return (int)str1[i] - (int)str2[i];
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	// derivata din implementarea strcmp(+conditie de stop dupa len pasi)
	int i = 0;

	while (str1[i] != 0 && str2[i] != 0) {
		if (str1[i] != str2[i] || i == (int)len - 1)
			return (int)str1[i] - (int)str2[i];
		i++;
	}

	return (int)str1[i] - (int)str2[i];
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	char chr = (char)c;
	int i;

	// cautam caracterul dat
	while (str[i] != 0) {
		if (str[i] == chr)
			return (char*)str + i;
		i++;
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	char chr = (char)c;
	int i = strlen(str);

	// cautam caracterul ponind de la dreapta
	while (i >= 0) {
		if (str[i] == chr)
			return (char*)str + i;
		i--;
	}

	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	int n = strlen(needle), i = 0;

	// cautam al doilea tring in primul
	while (haystack[i] != 0) {
		if (strncmp(haystack + i, needle, n) == 0)
			return (char*)haystack + i;
		i++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	int n = strlen(needle), i = strlen(haystack);

	// cautam al doilea sir in primul de la dreapta
	while (i >= 0) {
		if (strncmp(haystack + i, needle, n) == 0)
			return (char*)haystack + i;
		i--;
	}
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	// castam sirurile la char
	char* dest = (char*)destination, *src = (char*)source;
	int i;

	// copiem din src in dest
	for (i = 0; i < (int)num; i++) {
		dest[i] = src[i];
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	// castam sirurile la char
	char *dest = (char*)destination;
	char *src = (char*)src;

	if (dest == src && num == 0)
		return dest;

	if (dest < src && src - dest < (int)num) {
		// copiem de la cap pentru a evita suprapunerea
		while (num > 0) {
			*(dest++) = *(src++);
			num--;
		}
	}

	if (src < dest && dest - src < (int)num) {
		// copiem de la coada pentru a evita suprapunerea
		dest += num;
		src += num;
		while (num > 0) {
			*(--dest) = *(--src);
			num--;
		}
	}

	memcpy(destination, source, num);

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	int i;
	char *str1 = ptr1, *str2 = ptr2;
	for (i = 0; i < (int)num; i++) {
		if (str1[i] != str2[i])
			return (int)str1[i] - (int)str2[i];
	}

	// daca s-a ajuns aici, sirurile sunt egale
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	int i;
	char chr = (char)value, *src = (char*)source;

	//dam fiecarui byte valoarea caracterului dat
	for (i = 0; i < (int)num; i++)
		src[i] = chr;

	return source;
}
