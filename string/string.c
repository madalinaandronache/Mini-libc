// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	// Source: https://stackoverflow.com/questions/13460934/strcpy-using-pointers

	if(destination == NULL) {
		return NULL;
	}

	while(*source != '\0') {
		*destination = *source;
		destination++;
		source++;
	}

	*destination = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */

	if(destination == NULL) {
		return NULL;
	}

	char *ptr = destination;

	while(len != 0) {
		*ptr = *source;
		ptr++;
		source++;
		len--;
	}

	//destination = ptr;

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	// Source: https://www.techiedelight.com/implement-strcat-function-c/
	char *ptr = destination;
	ptr += strlen(destination);

	while(*source != '\0') {
		*ptr = *source;
		ptr++;
		source++;
	}

	*ptr = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	// Source: https://www.techiedelight.com/implement-strncat-function-c/

	char *ptr = destination;
	ptr += strlen(destination);

	while(len != 0 && *source != '\0') {
		*ptr = *source;
		ptr++;
		source++;
		len--;
	}

	*ptr = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	// Source: https://stackoverflow.com/questions/34873209/implementation-of-strcmp

	while(*str1) {
		if(*str1 != *str2) {
			return *(const unsigned char *)str1 - *(const unsigned char *)str2;
		}
		str1++;
		str2++;
	}

	if(*str1 == *str2) {
		return 0;
	}

	return -1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	// Source: https://stackoverflow.com/questions/32560167/strncmp-implementation

	while(len != 0 && *str1 != '\0') {
		if(*str1 != *str2) {
			return *(const unsigned char *)str1 - *(const unsigned char *)str2;
		}
		str1++;
		str2++;
		len--;
	}

	if(len == 0) {
		return 0;
	}

	return -1;
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
	// Source: https://www.harishnote.com/2016/06/c-programming-78-strchr-implementation.html


	while(*str != '\0'){
		if(*str == (char)c) {
			return (char *)str;
		}
		str++;
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	// Source: https://reviews.llvm.org/rGe8a2af28afd5b4370fb66d8810ff979d1cb4d45b

	const char *last = NULL;

	while(*str != '\0') {
		if(*str == (unsigned char)c) {
			last = str;
		}
		str++;
	}

	if(last != NULL) {
		return (char *)last;
	}

	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	// Source: http://www.firmcodes.com/write-c-code-to-implement-the-strstr-function-to-search-for-a-substring/
	const char *ptr1;
	const char *ptr2;

	while(*haystack != '\0') {
		ptr1 = haystack;
		ptr2 = needle;

		while(*ptr1 == *ptr2 && *ptr2 != '\0') {
			ptr1++;
			ptr2++;
		}

		if(*ptr2 == '\0') {
			return (char *)haystack;
		}

		haystack++;
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */

	if(*needle == '\0') {
		return (char *) haystack;
	}

	const char *ptr1, *ptr2, *last = NULL;

	while(*haystack != '\0') {
		ptr1 = haystack;
		ptr2 = needle;

		while(*ptr1 == *ptr2 && *ptr2 != '\0') {
			ptr1++;
			ptr2++;
		}

		if(*ptr2 == '\0') {
			last = haystack;
		}

		haystack++;
	}

	if(last != NULL) {
		return (char *)last;
	}

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	// Source: https://aticleworld.com/how-to-use-memcpy-and-how-to-write-your-own-memcpy/

	char *ptr1 = (char *) destination;
	const char *ptr2 = (const char *) source;


	if(ptr1 != NULL && ptr2 != NULL) {
		while(num) {
			*ptr1 = *ptr2;
			ptr1++;
			ptr2++;
			num--;
		}
	}

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	// Source: https://codereview.stackexchange.com/questions/174935/implementation-of-memmove
	unsigned char *dest = (unsigned char *)destination;
    const unsigned char *src = (const unsigned char *)source;

    if (dest < src) {
        while (num--) {
            *dest++ = *src++;
        }
    } else if (dest > src) {
        dest += num;
        src += num;
        while (num--) {
            *(--dest) = *(--src);
        }
    }

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	// Source: https://aticleworld.com/memcmp-in-c/

	const unsigned char *p = ptr1;
	const unsigned char *q = ptr2;
	int status = 0;

	if(ptr1 == ptr2) {
		return 0;
	}

	while(num > 0) {
		if(*p != *q) {
			status = (int)(*p - *q);
		}
		num--;
		p++;
		q++;
	}

	if(status != -1) {
		return status;
	}

	return -1;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	// Source: https://aticleworld.com/memset-in-c/

	unsigned char *ptr = source;

	while(num > 0) {
		*ptr = (unsigned char) value;
		ptr++;
		num--;
	}

	return source;
}
