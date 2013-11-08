
/* this is a simple implementation of a vigenere cipher
*
* though not as rigorous as the original
* 
* it strips out spaces and converts to lower case
*/
#include <stdio.h>

int main( int argc, char **argv)
{

char buffer[1000];
int key[10];
int i,k,nkey;

if( argc < 3)
{
	fprintf(stderr, "Usage is \n vigenere nkey key1 ... < infile > output \n");
	return(1);
}
sscanf(argv[1],"%d",&nkey);
if( nkey > 10) nkey = 10;
for( i=0; i< nkey; i++)
{
   sscanf(argv[1+i+1],"%d", &key[i]);
    key[i] = key[i]%26;
}

	k = 0;

while( fgets( buffer, sizeof(buffer), stdin) != (char *)0)
{
	int i,j; /* legal here and scoped to the end of the while loop */
        char t;

	for( i=0; i< 1000; i++)
	{
/* the two possible conditions for end of line */
	if( buffer[i] == '\n') break;
	if( buffer[i] == '\0') break;
	t = tolower(buffer[i]);
	if( t < 'a' || t > 'z') continue;

	
	j = t-'a'; /* set to zero */

	j = (j+key[k++])%26;
	k = k %nkey;

	t = j + 'a';	
	putchar( t);
	}
	putchar('\n');

}


}
