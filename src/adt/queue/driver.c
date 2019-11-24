#include <stdio.h>
#include "queue.h"

int main () {
	/*KAMUS*/
	Queue Q1,Q2;
	infotype X;
	int N;
	FILE coba;

	/*ALGORITMA*/
	scanf("%d\n",&N);
	QCreateEmpty(&Q1,N);
	scanf("%d\n",&X);
	QAdd(&Q1,X);
	CopySkills(Q1,&Q2);
	QDel(&Q1,&X);
	SavePrintQueue(&coba,Q2);
	return 0;
}