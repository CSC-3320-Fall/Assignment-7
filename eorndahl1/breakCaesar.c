#include <stdio.h>

int main(int argc, char** argv)
{
    FILE *f; //make file pointer
    int c, top = 0, count[26]={0};
    char topC, ch = 97;
    
    /* opening file for reading */
    f = fopen(argv[1] , "r");
    if(f == NULL) {
        perror("Error opening file");
        return(-1);
    }
    do {
        c = getc (f); //get characters one by one from input stream f
        for(int i = 0; i < 26; i++){ //loop through alphabet to tally the number of each letter
            if(c == (ch + i))
                count[i]++;
        }
    } while (c != EOF);
    
    for(int j=0;j<26;j++) //find most frequent letter (this will be our shifted e)
    {
        if(count[j] > top) {
            top = count[j];
            topC = ch + j;
        }
    }
    printf("The key for this sample was %c or the right shift of %d spaces.\n\nHere is the decoded text:\n\n", topC, topC - 101);
    fclose(f);
    f = fopen(argv[1], "r");
    do {
        c = getc (f); //get characters one by one from input stream f
        int cha;
        cha = c;
        cha = (((c -97) - (topC - 101)) % 26);
        if(cha < 0)
            cha = 26 + cha + 97;
        else
            cha = cha +97;
        printf("%c", (char)cha); // and print with the found shift
    } while (c != EOF);
    
    fclose(f);
    return(0);
}
