
#include <stdio.h>
#include <stdlib.h>

//Part 1: finds the key for text.one.encrypt

int main(int argc, char *argv[])
{

int i, max, index;
int lett;
int key;

// initialize alphabet
int alph[26];
int j = 0;

alph[0] = 'a';
for (j=0; j<26; j++)
{
alph[j]=alph[0];
alph[0]++;
}

		
//Open file
	FILE *pFile;
	unsigned char a[255];

	pFile = fopen("/home/local/GSUAD/eboley1/text.one.encrypt", "r");	
	{
		fgets (a, 255, pFile);
	fclose(pFile);
	}
//find the most frequently occuring character


int array[255]={0};

for (i=0; a[i] !=0; i++)
{
++array[a[i]];
}

max = array[0];
index =0;
for(i=0; a[i] !=0; i++)
{
	if (array[i] > max)
	{
	max = array[i];
	index = i;
}
}
lett = (index - 5);
//find placement of most frequent letter

int n=0;
	for(n=0; n<27; n++){
	if (lett == alph[n])
break;
}
//and now the key
key = n-4;
key = 26-key;
printf ("The key is: %d\n",key);



}
















