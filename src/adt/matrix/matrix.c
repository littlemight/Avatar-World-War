#include "matrix.h"

void MakeMatrix(Matrix *M, int RIn, int CIn){
  REff(*M) = RIn;
  CEff(*M) = CIn; 
  for(int i = 1; i <= REff(*M); i++){
    for(int j = 1; j <= CEff(*M); j++){
      MElmt(*M, i , j) = Nil;
    }
  }
}

void SavePrintMatrix(FILE *file, Matrix M) {
  for (int i = 1; i <= REff(M); i++) {
    for (int j = 1; j <= CEff(M); j++) {
      fprintf(file, "%d", MElmt(M, i, j));
      if (j < CEff(M)) {
        fprintf(file, " ");
      }
    }
    fprintf(file,  "\n");
  }
}

void BacaMatrix(Matrix *M) {
  int R, C;
  printf("Masukkan dimensi matriks (R lalu C): ");
  InputInt(&R); InputInt(&C);
  MakeMatrix(M, R, C);
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      InputInt(&MElmt(*M, i, j));
    }
  }
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

// dibawah ini ga dipake
boolean IsPointValid (Matrix M, Point P){
  return (Row(P) >= 1 && Row(P) <= REff(M) && Col(P) >= 1 && Col(P) <= CEff(M) );
}

void CopyMatrix (Matrix MIn, Matrix * MHsl){
  REff(*MHsl) = REff(MIn);
  CEff(*MHsl) = CEff(MIn);
  for (int i = 1; i <= REff(MIn); i++) { 
    for (int j = 1; j <= CEff(MIn); j++) {
      MElmt(*MHsl, i , j) = MElmt(MIn, i ,j);
    }
  }
}

MEltype NilaiMatrixDariPoint (Matrix * M, Point P){
  return (MElmt(*M, Row(P), Col(P)) );
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