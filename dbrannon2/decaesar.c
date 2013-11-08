#include<stdio.h>
char buffer[1000];
int alpha[26];
int main(int argc, char *argv[]){

if(argc<1){
fprintf(stderr, "usage: HW7 <filename>output\n");
return(1);
}
while( fgets(buffer, sizeof(buffer), stdin) != (char *)0)
{
char t;
int i,j;
for( i=0; i<1000; i++)
{
if(buffer[i]=='\n') break;
if(buffer[i]=='\0') break;
j=buffer[i]-'a';
t=j+'a';
alpha[j]++;
}
}
int key;
int max= alpha[0];
int max_Index=0;
int k;
for (k=1; k<26; k++){
if(max<alpha[k]){
max = alpha[k];
max_Index=k; 
printf("%d\n", k);
key = (k-4+26)%26;
}
printf("%d\n",  max);
printf("%d\n", key);
}
}

