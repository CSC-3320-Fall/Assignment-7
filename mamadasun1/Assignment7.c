/* Author: Michael Amadasun
 * Date:   11/3/2013, 2013
 * Assignment7
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    char c;
    char lettr[] = {'a', 'b', 'c', 'd',
                    'e', 'f', 'g', 'h',
                    'i', 'j', 'k', 'l',
                    'm', 'n', 'o', 'p',
                    'q', 'r', 's', 't',
                    'u', 'v', 'w', 'x',
                    'y', 'z',};
    int i;

    FILE *fr = fopen("C:\\Users\\Michael\\Documents\\Michael's_documents\\textoneencrypt.txt", "r");
    do{

    c = fgetc(fr);
    printf("%c", c);

        for(i = 0; i <= EOF; i++){
            c = tolower(c);
            printf("%c", c);
        }
    }
    while(c != EOF);

    fclose(fr);

    return 0;
}


