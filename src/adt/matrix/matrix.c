#include <stdio.h>
#include "matrix.h"

void MakeMATRIKS (MATRIKS *M){
  for(int i = 1; i <= NBrs; i++){
    for(int j = 1; j <= NKol; j++){
      Elmt(*M, i , j) = Nil;
    }
  }
}

// void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
//   for ( int i = GetFirstIdxBrs(MIn); i <= NBrsEff(MIn); i ++ ){ 
//     for ( int j = GetFirstIdxKol(MIn); j <= NKolEff(MIn); j ++ ){
//       Elmt(*MHsl, i , j) = Elmt(MIn, i ,j);
//     }
//   }
// }

boolean IsPOINTValid (POINT P){
  return ( Absis(P) >= 1 && Absis(P) <= NBrs && Ordinat(P) >= 1 && Ordinat(P) <= NKol );
}

ElType NilaiMATRIKSDariPOINT (MATRIKS * M, POINT P){
  return ( Elmt(*M, Absis(P), Ordinat(P)) );
}

void TulisMATRIKS (MATRIKS M){
  for ( int i = 1; i <= NBrs; i ++ ){ 
    for ( int j = 1; j <= NKol; j ++ ){
      printf("%d", Elmt(M, i, j));
    }
    printf("\n");
  }
}

int NBBuildingMATRIKS (MATRIKS M){
  int count = 0;
  for(int i = 1; i <= NBrs; i ++ ){
    for(int j = 1; j <= NKol; j ++ ){
      if (Elmt(M, i, j) != 0){
        count ++;
      }
    } 
  }
  return count;
}
