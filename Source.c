// Example how to work

#include "String.h"

int main(void)
{
	char str1[MAX_LENGTH] = ",. UER-1234";
	char str2[MAX_LENGTH] = " ,.-";

	char* ptr = NULL;

	StringConvertToMyString(str1);
	StringConvertToMyString(str2);

	StringConcatenation(str1, str2);

	StringPrint(str1);
	
	return 0;
}
