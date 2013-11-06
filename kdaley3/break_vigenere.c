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
char decrypt_caesar(const char* text, char** output, size_t length, int period, int start, int mode){
	char counts[26];
	size_t i;
	for(i=0; i<26; i++){
		counts[i]=0;
	}
	for( i=start; i<length; i+=period){
		if(text[i]>97 || text[i]<=121)
			++counts[text[i]-97];
	}
//	printf("%c\n",mode+97);
	int max=0;
	int shift=0;
	for(i=0; i<26; ++i){
		if(counts[i]>max){
			max=counts[i];
			shift=(mode-i);
		}
	}
	for( i=start; i<length; i+=period){
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
	return 97-shift;	
}
int find_period(char* text, int fsize){
	char counts[26];
	int i;
	float k0=0;
	for(i=0; i<88000; ++i){
		int i1=rand()%fsize;
		int i0=rand()%fsize;
		k0+=1/88000.0*(text[i1]==text[i0]);
	}
	float period=(0.067-0.0385)/(k0-0.0385); //friedman  test
	printf("%f",period);
	return period;
}

int main(int argc, char** argv){
	char* text, *output;
	size_t fsize=read_file(&text, argv[1]);	
	output=malloc(fsize+1);
	int p=find_period(text,fsize),s,m=4,fudge;
	
	for(fudge=-2; fudge<=2; ++fudge){
		for(s=0; s<p+fudge; ++s){
			char k=decrypt_caesar(text, &output, fsize, p+fudge,s,4);
			printf("%c",k);
		}
		printf("\n");
		printf(output);
		printf ("\n");
	}
	free(output);
	free(text);
	return 0;
}
		
		
