#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LETTER_A 97
#define LETTER_E 101
#define ALL_CHAR 256

void PrintCipher(char *cipher, int shift)
{
	int i = 0;
	for (i = 0; i < strlen(cipher); i++)
	{
		if (isalpha(cipher[i]))
		{
			cipher[i] -= shift;
		}
	}
	printf(cipher);
}

//credit to "greggory.hz"
//http://codereview.stackexchange.com/questions/7552/finding-the-most-frequent-character-in-a-string
char MostCommonUsedChar(char *str, int length) 
{
	char holder[26];
	int i;
	for (i = 0; i < 26; i++) 
	{
		holder[i] = 0;
	}
	
	int x;
	for (x = 0; x < length; x++) 
	{
		holder[str[x]-97] += 1;
	}
	
	char b = 97;
	int count = holder[0];
	int t;
	for (t = 1; t < 26; t++) 
	{
		if (holder[t] > count) 
		{
		count = holder[t];
		b = t+97;
		}
	}

	return b;
}
int main(int argc, char **argv)
{
	if (argc =! 1)
	{
		perror("Wrong number of arguments");
		return -1;
	}
	FILE *file = fopen(argv[1], "r");
	if (file == NULL)
	{
		char buffer[32];
		sprintf(buffer, "Could not open file \"%s\"", argv[1]);
		perror(buffer);
		return -1;
	}
	int shift;
	char text[1024];
	char c;
	while ((c = fgetc(file)) != EOF)
	{
		text[strlen(text)] = c;
		text[strlen(text) + 1] = '\0';
	}
	char t = MostCommonUsedChar(text, strlen(text));
	shift = (int) (t - 'e');
	PrintCipher(text, shift);
	printf("The shift for the cipher was: %d\n", shift);
	return 0;
}


//Problems number 2 and 3 will be emailed to the professor.