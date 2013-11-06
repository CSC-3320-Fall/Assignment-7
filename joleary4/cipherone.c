#include <stdio.h>

int main () {

char cipher[50];
int shift;

  FILE *one;

  one = fopen("/home/local/GSUAD/rwh/assignment7/text.one.encrypt","r");	
  scanf("%s", cipher);
   int i = 0;

  while (cipher[i] != '\0') {
    if ((cipher[i] += shift) > 65 && (cipher[i] += shift) <= 90) {
      cipher[i] += (shift);
    } else {
      cipher[i] += (shift - 25); 
    }
    i++;
  fclose(one);
  printf("%d", shift);
  return 0;
}



 

 
