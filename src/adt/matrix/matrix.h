#ifndef MATRIKS_H
#define MATRIKS_H

#include "../boolean/boolean.h"
#include "../point/point.h"

#define NBrs 20 // sumbu x
#define NKol 30 // sumbu y
#define Nil 0 // nilai dummy elemen matriks

typedef int indeks;
typedef int ElType;
typedef struct {
    ElType Mem[NBrs+1][NKol+1];
} MATRIKS;

#define Elmt(M,i,j) (M).Mem[(i)][(j)]



void MakeMATRIKS (MATRIKS *M);

boolean IsPOINTValid (POINT P);

// void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl);

ElType NilaiMATRIKSDariPOINT (MATRIKS * M, POINT P);

void TulisMATRIKS (MATRIKS M);

int NBBuildingMATRIKS (MATRIKS M);

#endif