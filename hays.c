/*Ceasar Cipher
 *
 * First prints out the key and then prints the decrypted file to standard output.
 * However, I'm having problems with x's, y's and z's
 *other than that^ it should be good
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("enter file path: ");
	char filename[70];
	scanf("%s", &filename); 
	FILE *file = fopen(filename,"r");
	
	char c;
	
	/* 2 arrays, one to store letters, one to store a count of each letter */
	int count[26];
	char alpha[27]= {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
	'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
	't', 'u', 'v', 'w', 'x', 'y', 'z'};
	
	/*init count array values to zero for each one*/
	int i;
	for(i=0;i<26;i++) {
		count[i]=0;
	}
	
	/*for each character....*/
	do {
		c = fgetc(file);
		/*iterate through possible options for c's equivalent character
		* add 1 to the corresponding position in the counting array*/
		for(i=0;i<26;i++) {
			if(c == alpha[i]) 
				count[i]++;
		}
	} while(c != EOF);
	fclose(file);
	int larger=0;
	char temp;
	FILE *newfile = fopen(filename,"r");
	/*find the highest number in the counting array, and set the
	* corresponding position in alphabet to temp*/
	
	for(i=0;i<26;i++) {
		if(count[i] > larger) {
			larger=count[i];
			temp=alpha[i];
		}
	}

	int key = temp - 'e';
	key = key % 26;
	
	printf("value of key is: %d\n", key);
	//assigning int j as unsigned messed things up...
	unsigned int j;
	char t;

	char str[100];
	
	while (fgets(str,100,newfile) != NULL) {
		for(i=0;i<100;i++) {
			if (str[i] == '\n' ) break;
			if (str[i] == '\0') break;
			t=str[i];
			if(t < 'a' || t > 'z') continue;
			
			j = t - 'a'; 
			j = (j - key) % 26;
			t = j + 'a';
			/*      x  ,   y ,     z       */
			/* I didn't know how to deal with this, so this is a 
			*  temporary solution while I figure out what to really do.*/
			
			//if(t=='_') t = 'y';
			//if(t=='`') t = 'z';
			//if(t=='^') t = 'x';
			//[(i+j)%length]
			/* ^^^ x,y,z are the only characters to be printed this way
			* 	they're the last 3 (KEY's VALUE) letters...
			* 	maybe some sort of carry-out/in error?*/
			
			printf("%c",t);
		}
		printf("\n");
	}
	fclose(newfile);
}