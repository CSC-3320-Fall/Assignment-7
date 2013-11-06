#include <stdio.h>
/*Aaron Nguyen
 * CSC 3320 T/TH 1pm - 2:15 pm
 *
 * Question 1 - Find the key for the le 'text.one.encrypted'.
*
 */

int main(int argc, char **argv)
{

    int letter; //variable to store each letter read from file
    int count[26] = {0}; //array of the frequency of each letter initialized to 0
    int max = 0; //location of the letter that has the highest frequency.
    int freq = 0; //the amount of times a letter appears
    int key = 0; //The key to the decrypt file
    FILE *infile = fopen(argv[1], "r"); //open file supplied in arg 1
    if (infile == NULL) { //if file doesnt exist
        printf("Invalid file, please enter ./program_name file_name\n");
        return 0;
    }
        while   ((letter = fgetc(infile)) != EOF) { //read each letter until end of file
                if (letter >= 97 && letter <=122){ //if letter is between a and z, subtract decimal value of letter - 97 (a). will give wither 0-25 and increment the count.
                count[letter-97] += 1; //increment count of letter frequency
                }

 }
        fclose(infile); //close file
        for(int i = 0; i <26; i++){ //go through each letter, and compare for the greatest frequency.
                if(count[i] > freq){
                freq = count[i]; //store the greatest frequency amount. 
                max = i; //store the location of the letter that occurs the most.

                }

       }
char letter2 = (char)max+97; //convert int value of most frequent letter to character
     key = (max+97) - 101; // subtract e from the most frequent letter to find the key.
printf("The most frequent character is %c.\n", letter2);
printf("The key is %d.\n", key);
return 0;
}
              
