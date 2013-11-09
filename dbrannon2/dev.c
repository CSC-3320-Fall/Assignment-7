#include<stdio.h>
char buffer[5000];
char lettrs[5000];
char array[5000];
char array2[5000];
int count[20];
char t;


int main(int argc, char *argv[]){

int j,lettrs_Indx,lettrs_count, k, temp;
lettrs_Indx=0;
lettrs_count=0;


	int decaesar(char*);
	if(argc<1){
		fprintf(stderr, "usage: HW7 <filename>output\n");
		return(1);
		}
	
	while( fgets(buffer, sizeof(buffer), stdin) != (char *)0){
	int i;
		for(i=0; i<sizeof(buffer); i++){
			if(buffer[i]=='\n') break;
			if(buffer[i]=='\0') break;
				lettrs[lettrs_Indx++]=buffer[i];
				lettrs_count++;

		}
}
		int i_count[11];
		int i;
	for(i=1;i<11; i++){

		int j;
		int sum=0; 
	for(j=10;j<lettrs_count; j++){
		if(lettrs[j]==lettrs[j-i])
			sum++;
}
		i_count[i]=sum;
		printf("%d\n", sum);
		printf("Shift %d\n", i);

		}

	for(i=1;i<11;i++){
	if(i_count[i]/(double)lettrs_count > 0.05){
		printf("\n %d\n\n", i);
		break;}
	}
}
					
			

