#include "point.h"
#include <stdio.h>

POINT MakePOINT (float X, float Y){
  POINT titik;
  Absis(titik) = X;
  Ordinat(titik) = Y;
  return titik;
}

void BacaPOINT (POINT * P){
  float x, y;
  scanf("%f %f", &x, &y);
  *P = MakePOINT(x,y);
}

void TulisPOINT (POINT P){
  printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQPOINT (POINT P1, POINT P2){
  return ((Absis(P1)==Absis(P2))&&(Ordinat(P1)==Ordinat(P2)));
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
  return MakePOINT(Absis(P)+deltaX, Ordinat(P)+deltaY);
}

float Panjang (POINT P1, POINT P2){
  float deltaX, deltaY;
  deltaX = Absis(P1) - Absis(P2);
  deltaY = Ordinat(P1) - Ordinat(P2);
  return (sqrt(deltaX * deltaX + deltaY * deltaY));
}

void Geser (POINT *P, float deltaX, float deltaY){
  *P = PlusDelta(*P, deltaX, deltaY);
}