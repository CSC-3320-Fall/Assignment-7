/*
#include <stdio.h>
int main ()
{//b.main
	FILE * pFile;
	int c;
	int n[25];
	pFile = fopen ("myfile.txt" , "r");
	//check file
	if (pFile == NULL) perror ("Error opening file");
	else
	{//b.else
	 do
	  {//b.do
	//goes thou file character by character
	   c = fgetc (pFile);
	   if (c == 'a') n[0] = n[0] + 1;
	   //if (c == 'b') n[1]++;
	   //if (c == 'c') n[2]++;
	   //if (c == 'd') n[3]++;
	   //if (c == 'e') n[4]++;
	   //if (c == 'f') n[5]++;
	   //if (c == 'g') n[6]++;
	   //if (c == 'h') n[7]++;
	   //if (c == 'i') n[8]++;
	   //if (c == 'j') n[9]++;
	   //if (c == 'k') n[10]++;
	   //if (c == 'l') n[11]++;
	   //if (c == 'm') n[12]++;
	   //if (c == 'n') n[13]++;
	   //if (c == 'o') n[14]++;
	   //if (c == 'p') n[15]++;
	   //if (c == 'q') n[16]++;
	   //if (c == 'r') n[17]++;
	   //if (c == 's') n[18]++;
	   //if (c == 't') n[19]++;
	   //if (c == 'u') n[20]++;
	   //if (c == 'v') n[21]++;
	   //if (c == 'w') n[22]++;
	   //if (c == 'x') n[23]++;
	   //if (c == 'y') n[24]++;
	  //if (c == 'z') n[25]++;
	  }while (c != EOF);
	  fclose (pFile);
	 //Print out int array  
	//int a;
	//for ( a = 0; a < 26; a++)
	//{//b.for 
	printf ("%d \n" ,n[0]);
	//}//e.for
}
return 0;



}//e.main
*/
//////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
int main ()
{//b.main
	FILE * pFile;
	int c;
	int n;
	int o [26];
	char alphabet [] = { 'a' , 'b' , 'c' , 'd' , 'e', 'f' , 'g' , 'h' , 'i' , 'j' , 'k' , 'l' , 'm' , 'n' , 		'o', 'p' , 'q' , 'r' , 's' , 't' , 'u' , 'v' , 'w' , 'x' , 'y' , 'z'};
	//pFile = fopen ("myfile.txt" , "r");
	//for loop cycle throu alpa array
	int a;
	for (a = 0; a < 26; a++ )
	{//f.begun
	
		pFile = fopen ("text.one.encrypt" , "r");
		//check file
			if (pFile == NULL) perror ("Error opening file");
			else
			{//b.else
	 			do
	  			{//b.do
				//goes thou file character by character
	   			c = fgetc (pFile);
	   				if (c == alphabet[a]) n++;
	   			}while (c != EOF);
			}//e.else
		//reset
		o [a] = n;
		n = 0;
		//close pointer
	 	fclose (pFile);
	}//f.end
	//printf ("%c %d \n" ,alphabet [1] , o [1] );
	return 0;
	//find the most used letter
	int b;
	int largest = 0;
	int pos = 0;
	//printf ("%c \n" ,alphabet[3] );
	for (b = 0; b < 26; b++)
	{//f.begin
		if ( o [b] > largest)
		{//if.begin
		largest = o [b];
		pos = b;
		}//if.end
	}//f.end/
	//print out the most used letter	
	printf ("%c \n" , alphabet[pos] );
	//The key
	int key = 0;	
	if ( pos < 4 ) { key = 4 - pos;} 
	if ( pos > 4 ) { key =  pos - 4;}
	if ( pos == 4) { key = 4;}
	printf ("%s %d \n" , "The key:" , key);
	 
}//e.main
