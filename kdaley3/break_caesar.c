#include <stdio.h>
#include <stdlib.h>

size_t read_file(char** text, const char* fname){	
	FILE* file=fopen(fname, "r");
	fseek(file,0, SEEK_END);
	size_t filesz=ftell(file);
	fseek(file, 0, SEEK_SET);
	*text=malloc(filesz);
	fread(*text, 1, filesz, file);
	fclose(file);
	return filesz;
}
void decrypt_caesar(char* text, char** output, size_t length){
	*output=malloc(length+1);
	char counts[26];
	int number_of_distinct_letters=0;
	size_t i;
	for(i=0; i<26; ++i){
		counts[i]=0;
	}
	for( i=0; i<length; ++i){
		if(text[i]>97 || text[i]<=121)
			++counts[text[i]-97];
	}
	int max=0;
	int shift=0;
	for(i=0; i<26; ++i){
		if(counts[i]>max){
			max=counts[i];
			shift=4-i;
		}
	}
	for( i=0; i<length; ++i){
		if(text[i]>97 || text[i]<=121){
		output[0][i]=(text[i]+shift);
		if(output[0][i]<97){
			output[0][i]+=26;
		}
		else if(output[0][i]>121){
			output[0][i]-=26;
		}
		}
	}
	output[0][length]=0;
}
int main(int argc, char** argv){
	char* text, *output;
	size_t fsize=read_file(&text, argv[1]);	
	decrypt_caesar(text, &output, fsize);
	printf(output);
	free(output);
	free(text);
	return 0;
}
		
		
