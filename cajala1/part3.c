#include <stdio.h>
#include <stdlib.h>
int main()
{
	int count=0,i=0,j,k,l;
    	char input;
    
    	FILE *file;
   
    	file = fopen("/home/local/GSUAD/rwh/assignment7/text.two.encrypt","r");
    
    
    	//load array with characters for the file
    	char *array1 = (char*)malloc(sizeof(int)*4976);
	while(input != EOF)
    	{
        	input = getc(file);
        	array1[i] = input;
        
       		 i++;
    	}
	fclose(file);
	
	i=0;
   	
 
    	char a=97;
    	int *alphabet = (int*)malloc(sizeof(int)*208);
/*
 *      load alphabet array with character frequency.
 *           Both the array1 and alphabet arrays are single
 *                dimension arrays but im accessing them in a 2d
 *                     format. Accessing based on a 622 by 8 format 
 *                          because I think the key length is 8.
 *                              */

for (j=0; j < 8; j++)
    {
        for (k=0; k < 622 ; k++)
        {
            for (l=0; l < 26; l++)
            {
                if (array1[(8*k)+j] == (a+l))
                    alphabet[(8*l)+j]++;
            }
        }
    }
//load biggestL array with the most frequent letter.
//each entry corresponds to each of the 8 groups.

int *biggestL = (int*)malloc(sizeof(int)*8);
    int biggest=0;
    
    for (j=0 ; j<8 ; j++)
    {
        for (k=0 ; k<26 ; k++)
        {
            if (alphabet[(8*k)+j] > biggest)
            {
                biggestL[j] = a + k;
                biggest = alphabet[(8*k)+j];
            }
        }
        biggest = 0;
    }

//shift array that holds the shift for each group
int *shift = (int*)malloc(sizeof(int)*8);
    for (j=0 ; j<8 ; j++)
    {
        shift[j] = (biggestL[j] - 101);
        printf("%d is the key for group %d.\n", shift[j], j+1);
    }
  
}
