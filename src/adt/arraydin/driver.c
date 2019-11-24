#include "arraydin.h"
#include <stdio.h>
int main() {
  STARTKATA(0);
  
  TabBuilding A;
  AMakeEmpty(&A, 5);
  ANeff(A) = 5;
  Building C, D, E, F, G;
  Point H = MakePoint(1,1);
  MakeBaseProperty(&C, 'T', 1, 2, 40, true,100);
  MakeBaseProperty(&D, 'C', 2, 2, 30, false,200);
  MakeBaseProperty(&E, 'F', 3, 2, 30, true,300);
  MakeBaseProperty(&F, 'V', 4, 2, 50, false,200);
  MakeBaseProperty(&G, 'F', 2, 2, 35, true,130);
  MakeBuilding(&C, C, 1, H, true, true);
  MakeBuilding(&D, D, 0, H, true, false);
  MakeBuilding(&E, E, 2, H, false, false);
  MakeBuilding(&F, F, 2, H, false, true);
  MakeBuilding(&G, G, 1, H, true, true);
  CopyBuilding(C, &AElmt(A, 1));
  CopyBuilding(D, &AElmt(A, 2));
  CopyBuilding(E, &AElmt(A, 3));
  CopyBuilding(F, &AElmt(A, 4));
  CopyBuilding(G, &AElmt(A, 5));
  
  printf("===================================\n");
  printf("Terdapat data TabBuilding berisi 5 building yang sudah disediakan\n");
  printf("===================================\n");
  printf(">>>>> Search <<<<<\n");
  IdxType idxnya = Search1(A, C);
  printf("Building C ada pada index ke : ");
  printf("%d\n\n", idxnya);
  idxnya = Search1(A, D);
  printf("Building D ada pada index ke : ");
  printf("%d\n\n", idxnya);
  idxnya = Search1(A, F);
  printf("Building F ada pada index ke : ");
  printf("%d\n\n", idxnya);
  printf("===================================\n");
  printf(">>>>> TuilsIsiTab <<<<<\n");
  TulisIsiTab(A);
  printf("===================================\n");
  printf(">>>>> COPY TAB <<<<<\n");
  TabBuilding I;
  AMakeEmpty(&I, 5);
  CopyTab(A, &I);
  TulisIsiTab(I);
  return 0; 
}