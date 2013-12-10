#include <stdio.h>

int main() {

int alphabet[26] = 0;
int key;
int k;
FILE *fp;
char *mode = "r";
fp = fopen("text_one_encrypt", mode);

if (fp == NULL) {
	fprintf(stderr, "Can't open input file text_one_encrypt!\n");
	exit(1);
	}
while (fscanf(fp) != EOF) {
	if ( k >= 'a' && k <='z')
	   count(alphabet[k-97] =+ 1;
	}

		
fprintf(key = %d, key);
}
