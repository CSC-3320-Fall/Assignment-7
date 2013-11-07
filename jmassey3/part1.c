#include<stdio.h>

int main(){
	int c, key, max, count[26]={0};
	char ch, alpha1[27]="abcdefghijklmnopqrstuvwxyz", alpha2[27];
	FILE *fp;
	fp=fopen("/home/local/GSUAD/jmassey3/Assignment-7/text.one.encrypt","r");
	if(fp == NULL){
		printf("File not found.\n");
	}
	ch=fgetc(fp); //reads the file character by character
	while(ch != EOF){
		c = 0;
		while(alpha1[c] != '\0'){ //ensures it doesn't go past 'z'
			if(alpha1[c] == ch){
				count[c]++;
			}
			else{
				c++;
			}
		}
	}
	fclose(fp);
	max = count[0];
	for(c = 0; c< 27; c++){
		if(count[c] > max){
			max = count[c];
		}
	}
	key = max-4;
	printf("The key for this ceasar cypher is: %d \n", key);
}
