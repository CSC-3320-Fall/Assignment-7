#include <stdio.h>
#include <stdlib.h>

//Now that the period of text.two.encrypt is known to be 4, This program finds
//the four keys used to decrypt the file

int main(int argc, char *argv[])
{

		
//Open file
	FILE *pFile;
	unsigned char a[255];

	pFile = fopen("/home/local/GSUAD/eboley1/text.two.encrypt", "r");	
	{
		fgets (a, 255, pFile);
	fclose(pFile);
	}


// period is 4. break input into 4 separate arrays to find 4 corresponding keys
int i, j, k, l, m;
j=0;
k=0;
l=0;
m=0;
unsigned char b[65];
unsigned char c[65];
unsigned char d[65];
unsigned char f[65];
{	for (i=0; i<255; i++){
	if (i%4==0){
	b[j]==a[i];
	j++;}
	else if (i%4==1){
	c[k]==a[i];
	k++;}
	else if (i%4==2){
	d[l]==a[i];
	l++;}
	else if(i%4==3){
	f[m]==a[i];
	m++;}

}
}

// find most frequent letter for each new array
int array[65]={0};
int x,index, max;

for (x=0; b[x] !=0; x++)
{
++array[b[x]];
}

max = array[0];
index =0;
for(x=0; b[x] !=0; x++)
{
	if (array[x] > max)
	{
	max = array[x];
}
}
//3 more
int array2[65]={0};
int y, index2 , max2;

for (y=0; c[y] !=0; y++)
{
++array2[c[y]];
}

max2 = array2[0];
index2 =0;
for(y=0; c[y] !=0; y++)
{
	if (array2[y] > max2)
	{
	max2 = array2[y];
}
}

//2 more
int array3[65]={0};
int z, index3, max3;

for (z=0; d[z] !=0; z++)
{
++array3[d[z]];
}

max3 = array3[0];
index3 =0;
for(z=0; d[z] !=0; z++)
{
	if (array3[z] > max3)
	{
	max3 = array3[z];
}
}
//last 1
int array4[65]={0};
int n, index4, max4;

for (n=0; f[n] !=0; n++)
{
++array4[f[n]];
}

max4 = array4[0];
index4 =0;
for(n=0; f[n] !=0; n++)
{
	if (array4[n] > max4)
	{
	max4 = array4[n];
}
}
printf ("Key 1: %d\nKey 2: %d\nKey 3: %d\nKey 4: %d\n", x, y, z, n);


}
