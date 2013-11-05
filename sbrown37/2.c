#include <stdio.h>

int main( int argc, char **argv) {

    int key;
    char buffer[1000];
    char wholeThing[10000];
    int period[11];//ignore 0 

    
    int wTIndex = 0;
    int wTCount = 0;

    //read input file
    while( fgets( buffer, sizeof(buffer), stdin) != (char *)0) {
        int i;
        char c;

        //read line char by char and save in wholeThing
        for( i=0; i < 1000; i++) {
            if( buffer[i] == '\n') break;
            if( buffer[i] == '\0') break;

            c = buffer[i];
            //printf("%c",c);
            wholeThing[wTIndex++] = c;
            wTCount++;
        }
    }

    //int greatestCo = 1;
    //int greatestCoIndex = 0;//greatest will definately be above 0
    //measure the incidence of coincidence to find the period
    //shift once, twice...up to 10. 
    int ic[11]; 

    int i;
    for(i=1; i<11; i++) {
        int j;
        int sum = 0;
        //avoid edge cases by starting at 10, 
        //shouldn't change outcome
        //sum counts the number of time the same
        //letter appears
        for(j=10; j<wTCount; j++) {  
            if (wholeThing[j] == wholeThing[j-i])
                sum++;
            //printf("%c", wholeThing[i]);
        }

        ic[i] = sum;

        printf("The incidences of coincidence at shift %d, is: %d", i,sum);

        printf("\n");
    }

    //find the first peak that approaches 0.06 to get the peroid
    for(i=1; i<11; i++) {
        if (ic[i]/(double)wTCount > 0.05) {
            printf("\nIt appears that the period is %d \n\n", i);
            break;
        } 
    }


    //printf("The period is: %d\n", greatestCoIndex);
}
