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

void analyze(int charSpace, int length) {
    int c,z,i , counter = 0, innerCounter = 0;
    int top = 0, count[26]={0}, l = length;
    char topC, ch = 97;
    char c1[5000];
    FILE *f;
    
    for(z = charSpace; z > 0; z--) {
        //printf("\nz = %d\n", z);
        f = fopen("/Users/eorndahl/Assignment7/text.two.encrypt" , "r");
        counter = 0;
        innerCounter = 0;
        top = 0;
        do {
        c = getc(f);
        if(c != '\n') {
            if(z != charSpace && counter == 0) {
                counter++;
                continue;
            }
            if(z != charSpace & counter == charSpace - z) {
                c1[innerCounter] = c;
                //printf("%c", c);
                innerCounter++;
                counter++;
                continue;
            }
            //printf("%d\n", counter);
            if((counter - (charSpace -z)) % (charSpace) == 0) {
                c1[innerCounter] = c;
                //printf("%c", c);
                innerCounter++;
            }
            counter++;
        }
    } while (c != EOF);
    
    for(int i = 0; i < 26; i++)
        count[i] = 0;
        
    for(i=0; i < innerCounter; i++) {
        //printf("%c", c1[i]);
        c = c1[i];
        for(int i = 0; i < 26; i++){ //loop through alphabet to tally the number of each letter
            if(c == (ch + i))
                count[i]++;
        }
    }
    for(int j=0;j<26;j++) { //find most frequent letter (this will be our shifted e)
        if(count[j] > top) {
            top = count[j];
            topC = ch + j;
        }
    }
    for(int i = 0; i <26; i++)
        printf("%c --> %d\n", i + 97, count[i]);
    printf("Row %d's most frequent letter shifted is... %c\n", z, ((topC - 101) % 26) + 97);
        fclose(f);
    }
}

int main(int argc, char** argv)
{
    FILE *f;
    int c, counter = 0, count[26] = {0};
    
    /* opening file for reading */
    f = fopen("/Users/eorndahl/Assignment7/text.two.encrypt" , "r");
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
        //printf("%c", c);
        //if(c != '\n')
        counter++;
    } while (c != EOF);
    fclose(f);
    
    //printf("\n\n");

    
    float coin = coincidence(count, counter); //returns coincidence rate
    float period = (.067 - .0385) / (coin - .0385); //period computed with kappa formula
    int smallest = (int)round(period); //round period
    printf("The largest period is %d\n\n", smallest);
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
    analyze(8, counter);
    printf("\nA period of four gives...\n");
    analyze(4, counter);
    printf("\nA period of two gives...\n");
    analyze(2, counter);
    printf("\nA period of one gives...\n");
    analyze(1, counter);
   
   fclose(f);
    return(0);
}
