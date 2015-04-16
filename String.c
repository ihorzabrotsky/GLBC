#include <stdio.h>

#include "String.h"

void* MemoryCopy(const char* from, char* to, int bytes)
{
	int i;

	const char* fromPtr = from;
	char* toPtr = to;

	for (i = 0; i < bytes; i++)
	{
		*toPtr = *fromPtr;

		++toPtr;
		++fromPtr;
	}

	return to;
}

void* MemoryMove(const char* from, char* to, size_t bytes)
{
	int i;

	const char* fromPtr = from;
	char* toPtr = to;

	for (i = 0; i < bytes; i++)
	{
		*toPtr = *fromPtr;

		++toPtr;
		++fromPtr;
	}

	return to;
}

char* StringCopy(const char* from, char* to)
{
	const char* fromPtr = from;
	char* toPtr = to;

	while (*fromPtr != TS)
	{
		*toPtr = *fromPtr;

		++toPtr;
		++fromPtr;
	}

	return to;
}

char* StringCopyN(const char* from, char* to, size_t num)
{
	const char* fromPtr = from;
	char* toPtr = to;
	int i;
	int j;

	for (i = 0; i < num; i++)
	{
		if (*fromPtr != TS)
		{
			*toPtr = *fromPtr;

			++toPtr;
			++fromPtr;
		}
		else
		{
			for (j = i; j < num; j++)
			{
				*toPtr = TS;

				++toPtr;
			}

			i = num;
		}
	}

	return to;
}

char* StringConcatenation(char* str1, const char* str2)
{
	char* s1 = str1;
	const char* s2 = str2;

	while (*s1 != TS)
	{
		++s1;
	}

	while (*s2 != TS)
	{
		*s1 = *s2;

		++s1;
		++s2;
	}

	*s1 = TS;

	return str1;
}

char* StringNConcatenation(char* str1, const char* str2, size_t n)
{
	int i;

	char* s1 = str1;
	const char* s2 = str2;

	while (*s1 != TS)
	{
		++s1;
	}

	for (i = 0; i < n && *s2 != TS; i++)
	{
		*s1 = *s2;

		++s1;
		++s2;
	}

	return str1;
}

int MemoryCompare(const char* str1, const char* str2, size_t num)
{
	int i;

	const char* s1 = str1;
	const char* s2 = str2;

	int result = 0;

	for (i = 0; i < num; i++)
	{
		if (*s1 > *s2)
		{
			result = 1;
			break;
		}
		else
			if (*s1 < *s2)
			{
				result = -1;
				break;
			}

		++s1;
		++s2;
	}

	return result;
}

int StringCompare(const char* str1, const char* str2)
{
	const char* s1 = str1;
	const char* s2 = str2;

	int result = 0;

	while (*s1 != TS || *s2 != TS)
	{
		if (*s1 > *s2)
		{
			result = 1;
			break;
		}
		else
			if (*s1 < *s2)
			{
				result = -1;
				break;
			}

		++s1;
		++s2;

	}

	return result;
}

int StringNCompare(const char* str1, const char* str2, size_t num)
{
	const char* s1 = str1;
	const char* s2 = str2;

	int result = 0;

	while (num && (*s1 != TS || *s2 != TS))
	{
		if (*s1 > *s2)
		{
			result = 1;
			break;
		}
		else
			if (*s1 < *s2)
			{
				result = -1;
				break;
			}

		++s1;
		++s2;

		--num;
	}

	return result;
}

void* MemoryCharacterSearch(const char* str, const int value, size_t num)
{
	void* ptr = NULL;
	char cValue = (char) value;

	while (num-- && *str != value)
	{
		++str;
	}

	if (num > 0 && *str == value)
		ptr = (void*)str;

	return ptr;
}

char* StringCharacterSearch(const char* str, const char value)
{
	char* result = NULL;

	while (*str != TS)
	{
		if (*str == value)
		{
			result = (char*)str;
			break;
		}

		++str;
	}

	if (*str == value)
		result = (char*)str;

	return result;
}

size_t StringSpan(const char* str1, const char* str2)
{
	int result = -1;

	const char* s1 = str1;
	const char* s2;

	for (; *s1 != TS && result < 0; ++s1)
	{
		for (s2 = str2; *s2 != TS && result < 0; ++s2)
		{
			if (*s1 == *s2)
			{
				result = s1 - str1;
				break;
			}
		}
	}

	if (*s1 == TS && result < 0)
		result = s1 - str1;

	return result;
}

char* StringLocateCharacter(const char* str1, const char* str2)
{
	char* result = NULL;

	const char* s1 = str1;
	const char* s2;

	for (; *s1 != TS && result == NULL; ++s1)
	{
		for (s2 = str2; *s2 != TS && result == NULL; ++s2)
		{
			if (*s1 == *s2)
			{
				result = (char*)s1;
				break;
			}
		}
	}

	return result;
}

char* StringCharacterSearchLast(const char* str, const char value)
{
	char* result = NULL;

	while (*str != TS)
	{
		if (*str == value)
		{
			result = (char*)str;
		}

		++str;
	}

	if (*str == value)
		result = (char*)str;

	return result;
}

size_t StringSpanContain(const char* str1, const char* str2)
{
	int result = -1;

	const char* s1 = str1;
	const char* s2;

	for (; *s1 != TS && result < 0; ++s1)
	{
		for (s2 = str2; *s2 != TS; ++s2)
		{
			if (*s2 == *s1)
			{
				break;
			}
		}

		if (*s2 == TS)
		{
			result = s1 - str1;
		}
	}

	if (*s1 == TS && result < 0)
		result = s1 - str1;

	return result;
}

size_t StringLength(const char* str)
{
	int result = 0;

	while (*str != TS)
	{
		++result;
		++str;
	}

	return result;
}

char* StringSubstring(const char* str1, const char* str2)
{
	char* result = NULL;

	const char* s1 = str1;
	const char* s2 = str2;

	int sizeStr1 = StringLength(str1);
	int sizeStr2 = StringLength(str2);

	int i;

	if (sizeStr2 == 0)
	{
		result = 0;
	}
	else
	{
		for (i = 0; i <= sizeStr1 - sizeStr2; i++)
		{
			if (!MemoryCompare(str1 + i, str2, sizeStr2))
			{
				result = (char*)(str1 + i);
			}
		}
	}

	return result;
}

char* StringToken(char* str, const char* delimiters)
{
	static char* ptr = 0;

	if (str != NULL)
	{
		ptr = str;
	}
	else
	{
		if (ptr == NULL)
		{
			ptr = NULL;
			return ptr;
		}
	}

	str = ptr + StringSpanContain(ptr, delimiters);
	ptr = str + StringSpan(str, delimiters);

	if (str == ptr)
	{
		ptr = NULL;
		return NULL;
	}

	if (*ptr == TS)
	{
		ptr = NULL;
	}
	else
	{
		*ptr = TS;
		++ptr;
	}

	return str;

}

char* MemorySet(char* str, int value, size_t num)
{
	char* ptr = str;
	unsigned char cValue = value;

	while (num--)
	{
		*ptr = cValue;
		++ptr;
	}

	return str;
}

void StringConvertToMyString(char* str)
{
	char* ptr = str;

	while (*ptr != '\0')
	{
		++ptr;
	}

	*ptr = TS;
}

void StringConvertToCString(char* str)
{
	char* ptr = str;

	while (*ptr != TS)
	{
		++ptr;
	}

	*ptr = '\0';
}

void StringPrint(const char* str)
{
	const char* ptr = str;

	while (*ptr != TS)
	{
		putchar(*ptr);
		++ptr;
	}

	putchar('\n');
}
