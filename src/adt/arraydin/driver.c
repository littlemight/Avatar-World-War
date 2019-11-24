#include "arraydin.h"
#include <stdio.h>
int main() {
  STARTKATA(0);
  
  TabBuilding A;
  AMakeEmpty(&A, 5);
  Building B, C, D, E, F, G;
  Point H = MakePoint(1,1);
  MakeBaseProperty(&C, 'T', 1, 2, 40, true,100);
  MakeBaseProperty(&D, 'T', 2, 2, 30, false,200);
  MakeBaseProperty(&E, 'T', 3, 2, 30, true,300);
  MakeBaseProperty(&F, 'T', 4, 2, 50, false,200);
  MakeBaseProperty(&G, 'T', 2, 2, 35, true,130);
  MakeBuilding(&C, B, 1, H, true, true);
  MakeBuilding(&D, B, 0, H, true, false);
  MakeBuilding(&E, B, 2, H, false, false);
  MakeBuilding(&F, B, 2, H, false, true);
  MakeBuilding(&G, B, 1, H, true, true);
  AElmt(A, 1) = C; AElmt(A, 2) = D; AElmt(A, 3) = E; AElmt(A, 4) = F; AElmt(A, 5) = G;
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
  printf("ini mengopy tabbuilding A ke tabbuilding I");
  return 0; 
}