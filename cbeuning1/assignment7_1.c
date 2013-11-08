#include <stdio.h>


int main (int argc, char **argv)
{

char buffer[1000];
int counters[26];
int key;
int k;

for (k=0; k<26; k++)
{
	counters[k]=0;
}


while (fgets(buffer, sizeof(buffer), stdin) != (char*)0)
{
	int i;

	for (i=0; i<1000; i++)
	{
	
	if (buffer[i] == '\n') break;
	if (buffer[i] == '\0') break;

	if (buffer[i] < 'a' || buffer[i] > 'z') continue;

	counters[buffer[i]-'a']++;
	}
}


k=0;
int max=counters[0];
int maxIndex=0;
for (k=1; k<26; k++)
{
	if (counters[k]>max)
	{
	max=counters[k];
	maxIndex=k;
	}

}
key=((maxIndex+22)%26);
printf("key: %d\n", key);
}

