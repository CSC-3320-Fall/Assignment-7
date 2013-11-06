#include <stdio.h>
int main()
{

int input, i, j;
int biggest = 0, alphabet[26] = {0};
char biggestL, a = 97;

FILE *file;
file = fopen("/home/local/GSUAD/rwh/assignment7/text.one.encrypt","r");

while(input != EOF)
{
	input = getc(file);
	for(i = 0; i < 26; i++)
	{
		if (input == (a + i))
		{
			alphabet[i]++;
		}
	}
}

for (j = 0; j < 26; j++)
{
	if (alphabet[j] > biggest)
	{
		biggestL = a + j;
		biggest = alphabet[j];
	}
}

int shift = biggestL - 101 ;

printf("%d is the offset to the caesar cipher.\n", shift);
}
