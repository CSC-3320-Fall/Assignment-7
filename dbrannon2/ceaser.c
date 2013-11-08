/* this is a simple implementation of a ceaser cipher
* 
* it strips out spaces and converts to lower case
*/
#include <stdio.h>

int main( int argc, char **argv)
{

char buffer[1000];
int key;

if( argc < 2)
{
	fprintf(stderr, "Usage is \n ceaser key < infile > output \n");
	return(1);
}

sscanf( argv[1],"%d",&key);
key = key %26;

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
	j = (j-key+26)%26;
	t = j + 'a';	
	putchar( t);
	}
	putchar('\n');

}


}
