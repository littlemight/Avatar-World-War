#ifndef _MATRIX_H
#define _MATRIX_H

#include "boolean.h"
#include "point.h"

#define RMIN 10
#define CMIN 10
#define RMAX 20
#define CMAX 30
#define Nil 0 // nilai dummy elemen Matrix

typedef int indeks;
typedef int MEltype;
typedef struct {
    MEltype Mem[RMAX+1][CMAX+1];
    int REff;
    int CEff;
} Matrix;

#define REff(M) (M).REff
#define CEff(M) (M).CEff
#define MElmt(M, i, j) (M).Mem[(i)][(j)]

void MakeMatrix(Matrix *M, int RIn, int CIn);
void CopyMatrix (Matrix MIn, Matrix * MHsl);
void SavePrintMatrix(FILE *file, Matrix M);
boolean IsPointValid (Matrix M, Point P);
MEltype NilaiMatrixDariPoint (Matrix * M, Point P);
void TulisMatrix(Matrix M);
int NBBuildingMatrix (Matrix M);
#endif