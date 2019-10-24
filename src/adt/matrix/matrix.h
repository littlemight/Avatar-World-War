#ifndef Matrix_H
#define Matrix_H

#include "../boolean/boolean.h"
#include "../Point/Point.h"

#define NMaxSumbuX 20 // sumbu x
#define NMaxSumbuY 30 // sumbu y
#define Nil 0 // nilai dummy elemen Matrix

typedef int indeks;
typedef int ElType;
typedef struct {
    ElType Mem[NMaxSumbuY+1][NMaxSumbuX+1];
    int NEffSumbuY;
    int NEffSumbuY;
} Matrix;


#define NeffSumbuY(M) (M).NeffSumbuY;
#define NeffSumbuX(M) (M).NeffSumbuX;
#define Elmt(M,i,j) (M).Mem[(i)][(j)]


void MakeMatrix (Matrix *M, int NSumbuX, int NSumbuY);

boolean IsPointValid (Matrix M, Point P);

// void CopyMatrix (Matrix MIn, Matrix * MHsl);

ElType NilaiMatrixDariPoint (Matrix * M, Point P);

void TulisMatrix (Matrix M);

int NBBuildingMatrix (Matrix M);

#endif