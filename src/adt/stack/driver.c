#include "stack.h"
#include <stdio.h>

int main () {
	/*KAMUS*/
	Stack S;
	Sinfotype X,Y;

	/*ALGORITMA*/
	SCreateEmpty(&S);
	scanf("%d\n",&X);
	scanf("%d\n",&Y);
	SPush(&S,X);
	SPush(&S,Y);
	SPop(&S,&Y);
	return 0;
}