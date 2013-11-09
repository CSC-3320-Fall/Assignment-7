

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Original algorithm description:
Take a string, put it inside a linked list, each node is a character. When using tokenCompare,
all you have to do is compare the first linked list with a second linked list that is right 
shifted by one more than previous amount to find the amount of frequency between the two and the
most common character between the two that which should be returned as a struct.
Take that struct, put it inside of another linked list so that the elements do not get overwritten,
and you would be able to get access to all the information easily and each node would indicate how much the string
was shifted by.
The frequency then is found by the difference in the indices in which the most frequent letters appear and
that should have solved this */

/*gets the file by input */
void getFile(){
	Char *fileName;
	fprintf("%s", "Enter the file destination: ");
	scanf("%s", fileName);
	fopen(fileName, rt);
}

/* takes two strings as parameters, compares them and spits out a struct
with the character which has the most frequency and its frequency */

struct tokenCompare(Char *String1, Char *String2){
Struct{
	Char c; //holds the character
	int t; //holds the frequency
}freq;
	compare String1 and String 2;

	
	c= frequent character;
	t = frequency;
	
	return freq;
	
}
	//gets the string from file while removing all the linebreaks
Char* getString(){

}
	

//Takes string and shifts it to the right by i times and returns it
Char* stringShift(Char *C, int i){
	for(int j=0; j<i; j++){
		C[j] = " ";
	}
	returns C;
}



main(){
getFile();
Char* originalString = getString();
Struct{
	Char c;
	int T;
} difference;
		
for(int i =0; i<4000;i++){ //could use while !=EOF, but a smaller amount should work as well
	difference->next = tokenCompare(originalString, stringShift(originalString, i));
}

}	
/* p.s. I was originally wanting to use a linked List for putting all the structs so that 
each of the node would have a different struct that would contain the information necessary
for the comparison. However, I realized that C uses Structs for linked lists, which would mean
having a struct inside of a struct using malloc, which I don't know how to use, so this is as far
as my C programming skills have got me thus far */	
