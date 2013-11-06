#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PERIOD 10

void format_cipher_text(FILE * input_file, char file_buffer[]){
	
	int n = sizeof(file_buffer);
	char *buffer_p;
	buffer_p = file_buffer;
	
	while(fgets(buffer_p, n , input_file) != (char *)0)
	{	
		int i;
		for( i= 0 ; i < n; i++)
		{
		//code snippet from caesar.c
			if( *(buffer_p+i) == '\n') break;
			if( *(buffer_p+i) == '\0') break;
			if(isspace(*(buffer_p+i)) ) continue;
			char t = tolower(*(buffer_p+i));
			*(buffer_p + i) = t;
			printf("%c", *(buffer_p+i));	
		}
	}
	fclose(input_file);
}

int main(int argc, char *argv[])
{
	FILE *fp;
	if (argc != 2)
	{
		printf("usage: decipher <filename>\n");
		exit(EXIT_FAILURE);
	}
	if (( fp = fopen(argv[1], "r")) == NULL)
	{
		printf("%s can't be opened.\n", argv[1]);
		exit(EXIT_FAILURE);
	}//code snippet from [King] ch22.
	
	/*Obtain length of file.*/
	fseek(fp, 0L, SEEK_END);
	int n = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	
	char cipher_buffer[n];
	char *cipher_buffer_p = cipher_buffer;
	format_cipher_text(fp, cipher_buffer);
	int i;
		for(i=0; i< n-1; i++)
		{
		printf("%c", *(cipher_buffer_p + i));
		}
	
	//printf("%d\n", max_count/(n-1));
	return 0;
}
