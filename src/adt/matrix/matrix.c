#include <stdio.h>
#include "Matrix.h"

void MakeMatrix(Matrix *M, int NSumbuX, int NSumbuY){
  for(int i = 1; i <= NSumbuY; i++){
    for(int j = 1; j <= NSumbuX; j++){
      Elmt(*M, i , j) = Nil;
    }
  }
}

// void CopyMatrix (Matrix MIn, Matrix * MHsl){
//   for ( int i = GetFirstIdxBrs(MIn); i <= NSumbuYEff(MIn); i ++ ){ 
//     for ( int j = GetFirstIdxKol(MIn); j <= NSumbuXEff(MIn); j ++ ){
//       Elmt(*MHsl, i , j) = Elmt(MIn, i ,j);
//     }
//   }
// }

boolean IsPointValid (Matrix M, Point P){
  return ( Absis(P) >= 1 && Absis(P) <= NEffSumbuX(M) && Ordinat(P) >= 1 && Ordinat(P) <= NEffSumbuY(M) );
}

ElType NilaiMatrixDariPoint (Matrix * M, Point P){
  return ( Elmt(*M, Absis(P), Ordinat(P)) );
}

void TulisMatrix (Matrix M){
  for ( int i = 1; i <= NEffSumbuY(M); i ++ ){ 
    for ( int j = 1; j <= NEffSumbuX(M); j ++ ){
      if (Elmt(M, i, j) != 0){
        printf("%d", Elmt(M, i, j));
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
  for(int i = 1; i <= NEffSumbuY(M); i ++ ){
    for(int j = 1; j <= NEffSumbuX(M); j ++ ){
      if (Elmt(M, i, j) != 0){
        count ++;
      }
    } 
  }
  return count;
}
