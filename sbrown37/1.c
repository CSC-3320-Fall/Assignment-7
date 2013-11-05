#include <stdio.h>

int main( int argc, char **argv) {

    int key;
    char buffer[1000];
    int alph[26] = {0};//initialize to all zeros

    //read input file
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
            // a == 0, b == 1 ,...,z == 25
            alph[l] += 1;
        }
    }   
    
    int i, maxd;
    maxd = 0;
    //linear search for most frequent letter
    for(i=1; i<26; i++) {
        if (alph[maxd] < alph[i])
            maxd = i;
    }
    
    //take the most frequent letter to be e, subtract e's correct position (4, 
    //if 0 indexed) to get the offest key, add to 26 and % with 26 to account
    //for negative values
    key = ((maxd - 4) + 26) % 26;

    printf("The key used to encrypt this text was: %d \n", key);
  
}







