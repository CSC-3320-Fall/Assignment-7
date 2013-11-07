/*Here we gooooo */
#include <stdio.h>

int main()
{
FILE *fp;
char buffer[1000];
char str[1000] ;
int array[255] = {0};
int countArray[255] = {0};
fp = fopen("text.one.encrypt", "r");
int i, max, index, key;
char s;
while(!feof(fp)) { //This took me awhile to get. Reads that sucka good.
	if ( fgets( buffer, sizeof(buffer), fp)) {
		for( i=0; i< 1000; i++)
		{
		if( buffer[i] == '\n') break;
		if( buffer[i] == '\0') break;
		 s = tolower(buffer[i]);
		 if( s < 'a' || s > 'z') continue;
	str[i] = s;	
	++array[s];	
		}//End of For
	}//End of If
}//End of While
max = array[0]; //Using an array check to determine the most common element
index = 0;
for (i = 0; str[i] !=0; i++)
{
if(array[str[i]] > max)
{ max = array[str[i]];
  index = i;}
}//End of Fori
s = str[index]; //oh hey there it is
key  = 26+ s -'e'; //Can't perfectly determine mod, since it can be 26+anything
printf("The most common letter is %c, the key is %d\n", s, key);
} //End of Main
