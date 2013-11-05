#include <stdio.h>

int main( int argc, char **argv) {

    const int PERIOD = 4;

    int key;
    char buffer[1000];
    
    //initialize to all zeros -- 26x10 array each row holds 26 letters
    //we know the period is between 1 and 10.
    int alph[(26*10)] = {0};
    int charTotal = 0;

    //read input file. Reading the input file is modified from Dr. Harrison's 
    //Examples in this same repository.
    while( fgets( buffer, sizeof(buffer), stdin) != (char *)0) {
        int i,l;
        char c;

        //read line char by char
        for( i=0; i < 1000; i++) {
            if( buffer[i] == '\n') break;
            if( buffer[i] == '\0') break;

            c = buffer[i];
            
            l = c-'a';

            //increment coresponding alphabet array
            //first specify the row corresponding the shift then increment the 
            //letter 
            // a == 0, b == 1 ,...,z == 25
            alph[(charTotal % PERIOD)*26 + l] += 1;

            charTotal += 1;
        }
    }   
    
    int i; 
    int maxd[10] = {0};

    //linear search for most frequent letter
    // for(i=1; i<26; i++) {
    //     if (alph[maxd] < alph[i])
    //         maxd = i;
    // }

    //linear search over 2d array for the highest number in each row
    //the index found corresponds to the most frequent letter in each row
    //I had to later this to find the the last occurence of the largest
    //number because the 4th characters had 2 letters that tied for
    //most frequent
    for(i=0; i<PERIOD; i++) {
        int j;
        for(j=1; j<26; j++) {
            if (alph[i*26 + maxd[i]] <= alph[i*26 + j])
                maxd[i] = j;
        }
    }
    
    printf("\n%s \n", "The key is:");

    //take the most frequent letter to be e, subtract e's correct position (4, 
    //if 0 indexed) to get the offest key, add to 26 and % with 26 to account
    //for negative values
    //do this for each key
    for(i=0; i<PERIOD; i++) {
        //printf("letter is %c\n", maxd[i]+'a' );
        printf("%d \n", (((maxd[i] - 4) + 26) % 26));
    }
}







