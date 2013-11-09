/*this is for the ceaser cipher
* it should include methods of intializing, functions, and finding
* the key.
*/

/*during this program it should be able to take in input of the
* text.one.encrypt file and then implement the function, 
* Once its a long string(file), then it can go through each letter one
* by one with a loop trying to match up the letters and count the
* number of gaps in between the matching letters<-- which is the key
*/


#include <stdio.h>

int main()  {

	char d;				//char for indexing purpose
	FILE *p;			//pointer for file name
	int num = 0;			//counter for compar.
	char alpha[26] = {0};		//array for alphabet	

	p = fopen("/home/local/GSUAD/rwh/assignment7/text.one.encrypt", "r");
	
	while (d = fgetc(p) != EOF) 		//run till it reaches end 
	{
		if (d  >= 'a' && d <= 'z') 	//if current is between a and z
		{
			alpha[d-'a'] +=1;    //subtract value of a then add one to get next alpha char
		}					
	}
		for (int i=0; i < 26; i++)
		{
				 
				
		}
	num = alpha[d];
	printf("frequent most letter in text.one.encrypt file is %c", num); 
	fclose(p);
	return 0;
	
}
