/* first open file, read in a line at a time, for each character in line
 * until end of line is reached find letters and add count of each letter to
 * overall array of letter counts. find maximum value of that letter count
 * array, and then subtract difference between "e" and that letter from all
 * letters, special care being made to the alphabet wrapping around from a-z
 *
 * */

#include <stdio.h>
int main(){
        char line[500], c,j;
        int letterArray[256]={0},i,maximum,key;
        FILE *file1 = fopen("text.one.encrypt", "r");
        while(feof(file1)==0){ //continue until end of file
                fgets(line,500, file1); //read in a line
                for(i=0;i<500; i++){ //for each character in line
                        if(line[i]=='\n') break; //break line if lineend
                        c=line[i];//read character
                        if (c >='a' && c <='z') { //if in range of letters
                                letterArray[(int)c]++;  //increment leter count
                        }
                }
        }
		maximum=max(letterArray,256); //find letter most used
        key=maximum-(int)'e'; //find displacement of code
        printf("The key is: %d \n",key); //print code

        //section to decrypt code using key
        rewind(file1);
        while(feof(file1)==0){
                fgets(line,500,file1);
                for(i=0;i<500;i++){
                        c=line[i];
                        if(c=='\n') {
                                printf("\n");
                                break;
                                }

                        else if (c >='a'+key && c <='z') {
                                c=(char)((int)c-key);
                                printf("%c",c);
                        }
                        else if(c >='a' && c <'a'+key){
                                j=c-'a';
                                j='z'-key+j+1;
								j=c-'a';
                                j='z'-key+j+1;
                                printf("%c",j);
                        }
                        else printf("c",c);

                }

        }
}
//function to find index of maximum value of array
int max(int array[],int size){
int maximum=array[0];
int i,index;
for (i=0;i<size;i++){
        if (maximum<array[i]){
                maximum=array[i];
                index=i;
        }
}
return index;
}


