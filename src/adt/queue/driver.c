#include <stdio.h>
#include "queue.h"

int main () {
	STARTKATA(0);

	/*KAMUS*/
	Queue Q1,Q2;
	Kata X;
	int N;

	/*ALGORITMA*/
	InputInt(&N);
	QCreateEmpty(&Q1,N);
	for (int i = 1; i <= N; i++) {
		InputKata(&X);
		QAdd(&Q1, X);
	}
	CopySkills(Q1,&Q2);

	for (int i = 1; i <= N; i++) {
		QDel(&Q2, &X);
		PrintKata(X); printf("\n");
	}
	return 0;
}