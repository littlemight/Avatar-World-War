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
  PrintInfo(L);

  printf("===================================\n");
  printf(">>>>> AddBuilding <<<<<\n");
  printf("Dimasukan input dengan AddBuilding pada LIst L\n");
  printf("Masukan Infotype : ");
  Linfotype input;
  scanf("%d\n", &input);
  AddBuilding(&L, input);
  PrintInfo(L);

  printf("===================================\n");
  printf(">>>>> Search <<<<<\n");
  printf("Cari infotype dan mengeluarkan address\n ");
  printf("Masukan Infotype : ");
  Linfotype nilai;
  scanf("%d\n", &nilai);
  addressList adres;
  adres = Search(L, nilai);
  printf(" Addressnya adalah : "); printf("%d\n", adres);
  PrintInfo(L);

  printf("===================================\n");
  printf(">>>>> Search Idx <<<<<\n");
  printf("Cari jumlah infotype input pada list\n ");
  printf("Masukan Infotype : ");
  scanf("%d\n", &nilai);
  int jumlah;
  jumlah = SearchIdx(L, nilai);
  printf("Jumlah infotype tersebut : "); printf("%d\n", jumlah );
  PrintInfo(L);

  printf("===================================\n");
  printf(">>>>> DelVFirst <<<<<\n");
  printf("menghapus elemen first pada list\n");
  Linfotype iinput;
  DelVFirst(&L, &iinput);
  PrintInfo(L);

  printf("===================================\n");
  printf(">>>>> DelVLast <<<<<\n");
  printf("menghapus elemen last pada list\n");
  DelVLast(&L, &iinput);
  PrintInfo(L);

  printf("===================================\n");
  printf(">>>>> InsertFIrst <<<<<\n");
  printf("Masukan address : ");
  addressList inputa;
  scanf("%d\n", &inputa);
  InsertFirst(&L, inputa);
  PrintInfo(L);

  printf("===================================\n");
  printf(">>>>> InsertAfter <<<<<\n");
  printf("Masukan address : ");
  addressList inputab;
  scanf("%d\n", &inputa);
  printf("Diinput setelah address : ");
  scanf("%d\n", &inputab);
  InsertAfter(&L, inputa, inputab);
  PrintInfo(L);

  printf("===================================\n");
  printf(">>>>> InsertLast <<<<<\n");
  printf("Masukan address : ");
  scanf("%d\n", &inputa);
  InsertLast(&L, inputa);
  PrintInfo(L);

  printf("===================================\n");
  printf(">>>>> DelFirst <<<<<\n");
  addressList inputabc;
  DelFirst(&L, &inputabc);
  PrintInfo(L);

  printf("===================================\n");
  printf(">>>>> DelLast <<<<<\n");
  DelLast(&L, &inputabc);
  PrintInfo(L);

  printf("===================================\n");
  printf(">>>>> DelAfter <<<<<\n");
  addressList inputabcd;
  printf("masukan address patokan : ");
  scanf("%d\n", &inputabcd);
  DelAfter(&L, &inputabc, inputabcd);
  PrintInfo(L);

  printf("===================================\n");
  printf(">>>>> Max <<<<<\n");  
  printf("nilai max dari list L adalah : "); printf("%d\n", Max(L));



  return 0; 
}