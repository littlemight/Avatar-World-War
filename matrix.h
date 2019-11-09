#ifndef Matrix_H
#define Matrix_H

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

void MakeMatrix(Matrix *M, int RIn, int CIn){
  REff(*M) = RIn;
  CEff(*M) = CIn; 
  for(int i = 1; i <= REff(*M); i++){
    for(int j = 1; j <= CEff(*M); j++){
      MElmt(*M, i , j) = Nil;
    }
  }
}

void CopyMatrix (Matrix MIn, Matrix * MHsl){
  for (int i = 1; i <= REff(MIn); i++) { 
    for (int j = 1; j <= CEff(MIn); j++) {
      MElmt(*MHsl, i , j) = MElmt(MIn, i ,j);
    }
  }
}

boolean IsPointValid (Matrix M, Point P){
  return (Row(P) >= 1 && Row(P) <= REff(M) && Col(P) >= 1 && Col(P) <= CEff(M) );
}

MEltype NilaiMatrixDariPoint (Matrix * M, Point P){
  return (MElmt(*M, Row(P), Col(P)) );
}

void TulisMatrix(Matrix M){
  for ( int i = 1; i <= REff(M); i ++ ){ 
    for ( int j = 1; j <= CEff(M); j ++ ){
      if (MElmt(M, i, j) != 0){
        printf("%d", MElmt(M, i, j));
      }
      else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int NBBuildingMatrix (Matrix M){
  int count = 0;
  for(int i = 1; i <= REff(M); i ++ ){
    for(int j = 1; j <= CEff(M); j ++ ){
      if (MElmt(M, i, j) != 0){
        count ++;
      }
    } 
  }
  return count;
}
#endif