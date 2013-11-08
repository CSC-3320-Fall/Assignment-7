#include <stdio.h>
int main()
{//b.main
	//File
	FILE * pFile;
	int c;
	int n = 0;
	int o = 0;
	int numerator = 0;
	int denominator = 0;
	float IOC = 0.0;
	int lettercount [] = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};	
	//for loop cycle thou alpha
	char alphabet [] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};	
	//for loop cycle thou alpha
	int a;
	for (a = 0; a < 26; a++ )
	{//f.begin
	pFile = fopen ("text.two.encrypt" , "r");
	if (pFile == NULL) perror ("Error opening file");
	else
	{//e.begin
	  do {//b.do
	   c = fgetc (pFile);
	   if ( c== alphabet[a]) n++; o++;
	  } while ( c != EOF);
	  fclose (pFile);
	  //printf
	}//e.end
	//reset
	lettercount [a] = o;
	o = 0;
	}//f.end
	//denominator
	denominator = n * (n -1);
	//numerator
	int b = 0;
	for (b = 0; b < 26; b++){
		numerator += lettercount [b] * (lettercount [b] -1);
	} 
	// IOC
	IOC = (float) numerator / (float) denominator;
	
	printf ( "%s %f\n" ,"IOC: ", IOC);
}//e.main
