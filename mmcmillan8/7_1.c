// CSc 3320 T/Th 1:00pm
// Assignment 7.1

#include <stdio.h>

int main() {
    int key, i = 0;       // Final key assignment
    char lines[100];      // Array to hold each line
    int alpha[26] = {0};  // Array to hold the frequency of each letter

    FILE *ip;
    ip = fopen("/home/local/GSUAD/mmcmillan8/Assignment7/Assignment-7/mmcmillan8/text.one.encrypt", "r");
    if (ip == NULL) 
        printf("The file does not exist.\n");
    

    // Read in each line of Dr Harrison's file
    while (fgets(lines, sizeof(lines), ip) !=0) {
        int x, letter;    
        char character;         

        // Check each character in the line, this worked better for me than fgetc
        for (x = 0; x < 100; x++) {
            // Handle end of line conditions
            if (lines[x] == '\n') break;
	    if (lines[x] == '\0') break;
	    
            // Otherwise take each letter and increment it by 1
   	    character = tolower(lines[x]);
	    letter = character - 'a';   		// What is the current letter?
            alpha[letter] = alpha[letter] + 1;		// Increment the use of the letter by 1
        }
    }     

    // Now loop through the alpha array to find our most frequently used letter
    int x, freq = 0;
    for (x = 0; x < 26; x++) {
        if (alpha[freq] < alpha[x]) freq = x;
    }

    // Assume the most frequent letter is 'e' and subtract it's position of 4 (where 'a' = 0) 
    // then add 26 for the shift.  I was getting 23 because I forgot to mod with 26 as well, 
    // so that's been updated  
    key = ((freq - 4) + 26) % 26;
    printf ("The key to text.one.encrypt is %d.\n", key);    // My answer here is '3'.

}
