#ifndef _STRING_H_
#define _STRING_H_

#define NULL (void*)0 // NULL-pointer

#define MAX_LENGTH 300 // or we can declare the constant using "enum" in c-file

#define TS '\31' // don't know what for

typedef unsigned int size_t;

//const int FGF = 25;

/* function for copying a block of memory */
void* MemoryCopy(const void* from, void* to, size_t bytes);

/* function for moving some block of memory */
/* TODO: rethink the realization of MemoryMove */
void* MemoryMove(const void* from, void* to, size_t bytes);

/* function for copying strings*/
char* StringCopy(const char* from, char* to);

/* function for copying num characters */
char* StringCopyN(const char* from, char* to, size_t num);

/* function for concatenating strings*/
char* StringConcatenation(char* str1, const char* str2);

/* function for appending of n characters of a string to another string */
char* StringNConcatenation(char* str1, const char* str2, size_t n);

/* function for comparing two blocks of memory */
int MemoryCompare(const char* str1, const char* str2, size_t num);

/* function for comparing two strings */
int StringCompare(const char* str1, const char* str2);

/* function for comparing first num elements of two strings */
int StringNCompare(const char* str1, const char* str2, size_t num);

/* function for finding a character in the block of memory */
void* MemoryCharacterSearch(const char* str, const int value, size_t num);

/* function for finding the first occurrence of a characters in the string */
char* StringCharacterSearch(const char* str, const char value);

/* function that returns the size of the initial part of str1 not containing the symbols from str2 */
size_t StringSpan(const char* str1, const char* str2);

/* function that returns a pointer to the first occurrence in str1 of the characters from str2 */
char* StringLocateCharacter(const char* str1, const char* str2);

/* function for finding the last occurrence of a character in the string */
char* StringCharacterSearchLast(const char* str, const char value);

/* function that returns the size of the initial part of str1 containing the symbols from str2 */
size_t StringSpanContain(const char* str1, const char* str2);

/* function that returns the length of a string */
size_t StringLength(const char* str);

/* function for finding a substring in another string */
char* StringSubstring(const char* str1, const char* str2);

/* function for splitting the string into tokens*/
char* StringToken(char* str, const char* delimiters);

/* function for setting some bytes of memory with a specific value */
char* MemorySet(char* str, int value, size_t num);

/* function for converting standart c-string to my String */
void StringConvertToMyString(char* str);

/* function for converting my String to c-string */
void StringConvertToCString(char* str);

/* function for printing a string */
void StringPrint(const char* str);

#endif /* _STRING_H_ */
