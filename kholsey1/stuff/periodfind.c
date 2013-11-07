#include <stdio.h>
/*This doesn't work as it should, probably due to a silly error on my part. Turning in what I have anyway, though. */
int main()
{
FILE *fp;
char buffer[1000];
char baseArray[1000] = {0};
char arrayFirst[500], arraySecond[500], arrayThird[500], arrayFourth[500];
int countArray[255] = {0};
fp = fopen("text.two.encrypt", "r");
int i,j, max, index, key;
int count1, count2, count3, count4;
char s, test1, test2, test3, test4;
while(!feof(fp)) { //Reads entire file, dumps to array
        if ( fgets( buffer, sizeof(buffer), fp)) {
                for( i=0; i< 1000; i++)
                {
                if( buffer[i] == '\n') break;
                if( buffer[i] == '\0') break;
                 s = tolower(buffer[i]);
                 if( s < 'a' || s > 'z') continue;
		baseArray[i] = s;
			}//End of For
		}//End of If
	}//End of While
/*Splits the first array into two, to test frequency*/
for (i=0; baseArray[i] !=0 && baseArray[(i+1)] !=0 ; i+2) {
	arrayFirst[i] = baseArray[i];
	arraySecond[i] = baseArray[i+j];
		}
	
count1 = 0;
for (i=0; arrayFirst[i] !=0; i++) {
	if (arrayFirst[i] !=0 && arraySecond[i] !=0) {
		 test1 = arrayFirst[i];
		 test2 = arraySecond[i];
		if (test1 == test2) {
			count1++;
			}
	}
}
//Resetting them to 0
memset(&arrayFirst[0], 0, sizeof(arrayFirst));
memset(&arraySecond[0], 0, sizeof(arraySecond));
for (i=0; baseArray[i] !=0 && baseArray[i+1] !=0 && baseArray[i+2] !=0 ; i+3) {
        arrayFirst[i] = baseArray[i];
        arraySecond[i] = baseArray[(i+1)];
	arrayThird[i] = baseArray[(i+2)];
                }
count2 = 0;
for (i=0; arrayFirst[i] !=0; i++) {
        if (arrayFirst[i] !=0 && arraySecond[i] !=0 && arrayThird[i] != 0) {
                 test1 = arrayFirst[i];
                 test2 = arraySecond[i];
		 test3 = arrayThird[i];
                if (test1 == test2 == test3) {
                        count2++;
                        }
        }
}
/* Do it again, testing every 4 steps */
memset(&arrayFirst[0], 0, sizeof(arrayFirst));
memset(&arraySecond[0], 0, sizeof(arraySecond));
memset(&arrayThird[0], 0, sizeof(arrayThird));
for (i=0; baseArray[i] !=0 && baseArray[i+1] !=0 && baseArray[i+2] !=0 &&
	baseArray[i+3] !=0; i+4) {
        arrayFirst[i] = baseArray[i];
        arraySecond[i] = baseArray[(i+1)];
        arrayThird[i] = baseArray[(i+2)];
        arrayFourth[i] = baseArray[(i+3)];        
		 }
count3 = 0;
for (i=0; arrayFirst[i] !=0; i++) {
        if (arrayFirst[i] !=0 && arraySecond[i] !=0 && arrayThird[i] != 0 &&
		arrayFourth[i] !=0) {
                 test1 = arrayFirst[i];
                 test2 = arraySecond[i];
                 test3 = arrayThird[i];
		 test4 = arrayFourth[i];
                if (test1 == test2 == test3 == test4) {
                        count3++;
                        }
        }
}
//compare similarity count
int check[3] = {count1, count2, count3};
max = 0;
for (i=0; i<sizeof(check); i++) {
	if ( check[i] > max){
	max = check[i];
	}
}
max = max+2;
printf("The period is %d.", max);
}//End of Main
