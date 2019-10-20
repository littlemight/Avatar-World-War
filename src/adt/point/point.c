#include "point.h"
#include "math.h"
#include <stdio.h>

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y){
  POINT titik;
  Absis(titik) = X;
  Ordinat(titik) = Y;
  return titik;
}
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P){
  /* Membaca nilai absis dan ordinat dari keyboard dan membentuk
    POINT P berdasarkan dari nilai absis dan ordinat tersebut */
  /* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
  /* Contoh: 1 2
    akan membentuk POINT <1,2> */
  /* I.S. Sembarang */
  /* F.S. P terdefinisi */
  float x, y;
  scanf("%f %f", &x, &y);
  *P = MakePOINT(x,y);
}

void TulisPOINT (POINT P){
  /* Nilai P ditulis ke layar dengan format "(X,Y)"
    tanpa spasi, enter, atau karakter lain di depan, belakang,
    atau di antaranya
    Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
  */
  /* I.S. P terdefinisi */
  /* F.S. P tertulis di layar dengan format "(X,Y)" */
  printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
  /* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
  return ((Absis(P1)==Absis(P2))&&(Ordinat(P1)==Ordinat(P2)));
}

boolean NEQ (POINT P1, POINT P2){
  /* Mengirimkan true jika P1 tidak sama dengan P2 */
  return(!EQ(P1,P2));
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
  /* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
  return MakePOINT(Absis(P)+deltaX, Ordinat(P)+deltaY);
}

float Jarak0 (POINT P){
  /* Menghitung jarak P ke (0,0) */
  return (sqrt((Absis(P)*Absis(P) + Ordinat(P)*Ordinat(P))));
}

float Panjang (POINT P1, POINT P2){
  /* Menghitung panjang garis yang dibentuk P1 dan P2 */
  /* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
  /* Tuliskan spec fungsi yang lebih tepat. */
  float deltaX, deltaY;
  deltaX = Absis(P1) - Absis(P2);
  deltaY = Ordinat(P1) - Ordinat(P2);
  return (sqrt(deltaX * deltaX + deltaY * deltaY));
}

void Geser (POINT *P, float deltaX, float deltaY){
  /* I.S. P terdefinisi */
  /* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
  *P = PlusDelta(*P, deltaX, deltaY);
}

void GeserKeSbX (POINT *P){
  /* I.S. P terdefinisi */
  /* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
  /* Proses : P digeser ke sumbu X. */
  /* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
  *P = MakePOINT(Absis(*P), 0);
}

void GeserKeSbY (POINT *P){
  /* I.S. P terdefinisi*/
  /* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
  /* Proses : P digeser ke sumbu Y. */
  /* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
  *P = MakePOINT(0, Ordinat(*P));
}

void Mirror (POINT *P, boolean SbX){
  /* I.S. P terdefinisi */
  /* F.S. P dicerminkan tergantung nilai SbX atau SbY */
  /* Jika SbX true maka dicerminkan terhadap sumbu X */
  /* Jika SbX false maka dicerminkan terhadap sumbu Y */
  *P = MirrorOf(*P, SbX);
}

void Putar (POINT *P, float Sudut){
  /* I.S. P terdefinisi */
  /* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) searah jarum jam*/
  float x, y, z;
  x = Absis(*P);
  y = Ordinat(*P);
  z = Sudut*3.14159265358979323846/180.0;
  *P = MakePOINT((cos(z) * x + sin(z) * y), (-sin(z) * x + cos(z) * y) );
}
