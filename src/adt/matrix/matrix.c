#include <stdio.h>
#include "Matrix.h"

void MakeMatrix (Matrix *M){
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

boolean IsPointValid (Point P){
  return ( Absis(P) >= 1 && Absis(P) <= NSumbuY && Ordinat(P) >= 1 && Ordinat(P) <= NSumbuX );
}

ElType NilaiMatrixDariPoint (Matrix * M, Point P){
  return ( Elmt(*M, Absis(P), Ordinat(P)) );
}

void TulisMatrix (Matrix M){
  for ( int i = 1; i <= NSumbuY; i ++ ){ 
    for ( int j = 1; j <= NSumbuX; j ++ ){
      printf("%d", Elmt(M, i, j));
    }
    printf("\n");
  }
}

int NBBuildingMatrix (Matrix M){
  int count = 0;
  for(int i = 1; i <= NSumbuY; i ++ ){
    for(int j = 1; j <= NSumbuX; j ++ ){
      if (Elmt(M, i, j) != 0){
        count ++;
      }
    } 
  }
  return count;
}
