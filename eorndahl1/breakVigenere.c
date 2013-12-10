#include <stdio.h>
#include <math.h>

float coincidence (int arr[], int length) { //computes coincidence rate
    float coin = 0;
    for(int i = 0; i <26; i++) {
        float a = (float)arr[i];
        coin += (a * (a - 1)) / (length * (length -1));
    }
    return coin;
}

void analyze(FILE *f, int charSpace, int length) {
    int c,z,i , counter = 0, innerCounter = 0;
    int top = 0, count[26]={0};
    char topC, ch = 97;
    char c1[5000];
    
    for(z = charSpace; z > 0; z--) {
        counter = 0;                                                     // so this won't work w/o changing
        innerCounter = 0;
        top = 0;
        do {
        c = getc(f);
        if(c != '\n') {
            if(z != charSpace && counter == 0) {
                counter++;
                continue;
            }
            if(z != charSpace && counter == charSpace - z) {
                c1[innerCounter] = c;
                innerCounter++;
                counter++;
                continue;
            }
            if((counter - (charSpace -z)) % (charSpace) == 0) {
                c1[innerCounter] = c;
                innerCounter++;
            }
            counter++;
        }
    } while (c != EOF);
    
    for(int i = 0; i < 26; i++)
        count[i] = 0;
        
    for(i=0; i < innerCounter; i++) {
        c = c1[i];
        for(int i = 0; i < 26; i++){ //loop through alphabet to tally the number of each letter
            if(c == (ch + i))
                count[i]++;
        }
    }
    for(int j=0;j<26;j++) { //find most frequent letter (this will be our shifted e)
        if(count[j] >= top) {
            top = count[j];
            topC = ch + j;
        }
    }
//    for(int i = 0; i <26; i++)
//        printf("%c --> %d\n", i + 97, count[i]);
    printf("Row %d's most frequent letter shifted is... %c\n", z, ((topC - 101) % 26) + 97);
        fclose(f);
    }
}

int main(int argc, char** argv)
{
    FILE *f;
    int c, counter = 0, count[26] = {0};
    
    /* opening file for reading */
    f = fopen(argv[1] , "r");
    if(f == NULL) {
        perror("Error opening file");
        return(-1);
    }

    do {
        c = getc (f); //get characters one by one from input stream f
        for(int i = 0; i < 26; i++){ //loop through alphabet to tally the number of each letter
            if(c == (97 + i))
                count[i]++;
        }
        counter++;
    } while (c != EOF);
    fclose(f);
    
    float coin = coincidence(count, counter); //returns coincidence rate
    float period = (.067 - .0385) / (coin - .0385); //period computed with kappa formula
    int smallest = (int)round(period); //round period
//    printf("The largest period is %d\n\n", smallest);
    int keyList[5] = {0};
    int new = 1;
    for(int i=0; new > 0; i++) { //now fill an array with divisions of the period
        new = smallest / 2;
        if(new > 0) {
            smallest = new;
            keyList[i] = new;
        }
    }
    printf("While the other potential sizes are... (disregard 0's)\n\n");
    for(int i = 0; i < 5; i++)
        printf("%d\n", keyList[i]);
    
/* Let's experiment with the different periods. Putting them into a function that analyzes each column in the period.*/
    
    printf("\nA period of eight gives...\n");
    analyze(f, 8, counter);
    printf("\nA period of four gives...\n");
    analyze(f, 4, counter);
    printf("\nA period of two gives...\n");
    analyze(f, 2, counter);
    printf("\nA period of one gives...\n");
    analyze(f, 1, counter);


    //printf("The key for this sample was %c or the right shift of %d spaces.\n\nHere is the decoded text:\n\n", topC, topC - 101);
    fclose(f);
    f = fopen(argv[1], "r");
    counter = 0;

    //decodes cypher. I didn't manage to make this streamline so the key is manually entered in here. The other
    //commented out areas give the code however. Their output is in my text file.
    do {
        c = getc (f); //get characters one by one from input stream f
        if(c != '\n') {
            if(counter % 4 == 0) {
        int cha = (((c - 97) - (101 - 97)) % 26);
        if(cha < 0)
            cha = 26 + cha + 97;
        else
            cha = cha +97;
        printf("%c", (char)cha); // and print with the found shift
            }
            if((counter - 1) % 4 == 0 || counter == 1) {
                int cha = (((c - 97) - (105 - 97)) % 26);
                if(cha < 0)
                    cha = 26 + cha + 97;
                else
                    cha = cha +97;
                printf("%c", (char)cha); // and print with the found shift
            }
            if((counter - 2) % 4 == 0 || counter == 2) {
                int cha = (((c - 97) - (106 - 97)) % 26);
                if(cha < 0)
                    cha = 26 + cha + 97;
                else
                    cha = cha +97;
                printf("%c", (char)cha); // and print with the found shift
            }
            if((counter -3 ) % 4 == 0|| counter  == 3) {
                int cha = (((c - 97) - (107 - 97)) % 26);
                if(cha < 0)
                    cha = 26 + cha + 97;
                else
                    cha = cha +97;
                printf("%c", (char)cha); // and print with the found shift
            }
        counter++;
        }
   } while (c != EOF);
    
    fclose(f);
    return(0);
}


