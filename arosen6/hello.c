// helloworld on the rocks
// needs more gin
//
#include <stdio.h>

int main()
{
int i;
float o;

for( i=0; i< 6; i++)
{
   float x; 
   x = (float)i;

   o = (float)0x6568*(x-1.)*(x-2.)*(x-3.)*(x-4.)*(x-5.)/(1.*2.*3.*4.*5); 	
   o += (float)0x6c6c*(x)*(x-2.)*(x-3.)*(x-4.)*(x-5.)/(1.*1.*2.*3.*4); 	
   o += (float)0x206f*(x)*(x-1.)*(x-3.)*(x-4.)*(x-5.)/(2.*1.*1.*2.*3); 	
   o += (float)0x6f77*(x)*(x-1.)*(x-2.)*(x-4.)*(x-5.)/(3.*2.*1.*1.*2); 	
   o += (float)0x6c72*(x)*(x-1.)*(x-2.)*(x-3.)*(x-5.)/(4.*3.*2.*1.*1); 	
   o += (float)0x0a64*(x)*(x-1.)*(x-2.)*(x-3.)*(x-4.)/(1.*2.*3.*4.*5); 	
	
	if( o < 0) o =-o;
        printf("%c%c",(unsigned int)o&0xff, (unsigned int)o>>8);
}
}
