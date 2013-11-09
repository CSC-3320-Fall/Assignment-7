#include <stdio.h>
int main()
{

int input, i, j;
float alphabet[26] = {0};
float sum = 0, count = 0;
char a = 97;

FILE *file;
file = fopen("/home/local/GSUAD/rwh/assignment7/text.two.encrypt","r");

while(input != EOF)
{
        input = getc(file);
        for(i = 0; i < 26; i++)
        {
                if (input == (a + i))
                {
                        alphabet[i]++;
                }
        }
	count++;
}

for(i = 0; i < 26; i++)
{
	//observed coincidences
	sum += alphabet[i]*(alphabet[i]-1);
}
//probability of coincidences in a random text
float rands = .0385;
//random coincidences
float rCo =(count*(count-1));
//incidence of coincidence
float ioc = sum/rCo;
float period = (.067-rands)/(ioc-rands);
printf("the period is %f. number of letters are %f", period,count);
}
