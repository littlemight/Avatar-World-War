/* File: point.h */
/* Tanggal: 28 Agustus 2016 */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#ifndef POINT_H
#define POINT_H

#include <bits/stdc++.h>
using namespace std;

typedef struct {
	int X; /* absis   */
	int Y; /* ordinat */
} POINT;

#define Absis(P) (P).X
#define Ordinat(P) (P).Y

POINT MakePOINT (int X, int Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
  // KAMUS LOKAL
  POINT ret;
  // ALGORITMA
  Absis(ret) = X;
  Ordinat(ret) = Y;
  return ret;
}

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
void BacaPOINT (POINT * P) {
  int X, Y;
  cin >> X >> Y;
  Absis((*P)) = X;
  Ordinat((*P)) = Y;
}

void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
{
  printf("(%d,%d)", Absis(P), Ordinat(P));
}
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
#endif