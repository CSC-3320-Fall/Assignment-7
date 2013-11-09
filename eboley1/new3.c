#include <stdio.h>
#include <stdlib.h>

//finds the period of text.two.encrypt

int main (int argc, char **argv){
{


//Open file
	FILE *pFile;
	unsigned char a[255];
	pFile = fopen("/home/local/GSUAD/eboley1/text.two.encrypt", "r");	
	{
		fgets (a, 255, pFile);
	fclose(pFile);
}

//make copy of array a
unsigned char b[255];
int i =0;
for (i=0; i<256; i++){
b[i] == a[i];

}

//slide b along a
{
int shift =0;
int j = 0;
int * freq = malloc(255*sizeof (int));

for(shift =0; shift <256; shift++){
	for (j=0; shift<256; j++)
		if (a[j] =b[j+shift])
		
		freq[j]++;
	
}
int x =0;
int sum=0;
for (x=0; x<100; x++)

if (freq[x]>1)
sum+=x;
printf ("The period is: %d\n", sum/(26*2) );


}
}
}



