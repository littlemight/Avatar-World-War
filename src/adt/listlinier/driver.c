#include "listlinier.h"
#include <stdio.h>
int main() {
  List L;
  LCreateEmpty(&L);

  printf("===================================\n");
  printf(">>>>> InsVFirst <<<<<\n");
  printf("Dimasukan angka 2-6 dengan insVFirst Pada List L\n");
  for(int i=2; i<=6; i++){
  	InsVFirst(&L, i);
  }
  PrintInfo(L); printf("\n");

  printf("===================================\n");
  printf(">>>>> AddBuilding <<<<<\n");
  printf("Dimasukan input dengan AddBuilding pada LIst L\n");
  printf("Masukan Infotype : ");
  Linfotype input;
  scanf("%d", &input);
  AddBuilding(&L, input);
  PrintInfo(L); printf("\n");

  printf("===================================\n");
  printf(">>>>> Search Idx <<<<<\n");
  printf("Cari jumlah infotype input pada list\n ");
  printf("Masukan Infotype : ");
  int nilai;
  scanf("%d", &nilai);
  int jumlah;
  jumlah = SearchIdx(L, nilai);
  printf("Jumlah infotype tersebut : "); printf("%d\n", jumlah );
  PrintInfo(L); printf("\n");

  printf("===================================\n");
  printf(">>>>> DelVFirst <<<<<\n");
  printf("menghapus elemen first pada list\n");
  Linfotype iinput;
  DelVFirst(&L, &iinput);
  PrintInfo(L); printf("\n");

  printf("===================================\n");
  printf(">>>>> DelVLast <<<<<\n");
  printf("menghapus elemen last pada list\n");
  DelVLast(&L, &iinput);
  PrintInfo(L); printf("\n");

  printf("===================================\n");
  printf(">>>>> Max <<<<<\n");  
  printf("nilai max dari list L adalah : "); printf("%d\n", Max(L));
  return 0; 
}