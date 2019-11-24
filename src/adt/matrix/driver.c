#include "matrix.h"
#include <stdio.h>

int main() {
	STARTKATA(0);
	MATRIKS M1;
	MATRIKS M2;
    POINT P1;
    BacaPoint(&P1);
    TulisPoint(P1);

    MakeMatrix(&M1,7,7);
    MakeMatrix(&M2,7,7);
    BacaMatrix(&M1);
    TulisMatrix(M1);
    CopyMatrix(M1, &M2);

    NilaiMatrixDariPoint(&M2, P1);

    IsPointValid(M1, P1);

    NBBuildingMatrix(M1);

    printf("\n");



	return 0;
}