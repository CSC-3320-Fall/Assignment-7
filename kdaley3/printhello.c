#include <stdio.h>

#define HALLOWEEN_MODE 0
int main(int argc, char** argv){
	#if HALLOWEEN_MODE
		printf("hello, clarice.");
	#else
		printf("hello, world.");
	#endif
}
