#include "Point.h"
#include <stdio.h>

Point MakePoint (float X, float Y){
  Point titik;
  Absis(titik) = X;
  Ordinat(titik) = Y;
  return titik;
}

void BacaPoint (Point * P){
  float x, y;
  scanf("%f %f", &x, &y);
  *P = MakePoint(x,y);
}

void TulisPoint (Point P){
  printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQPoint (Point P1, Point P2){
  return ((Absis(P1)==Absis(P2))&&(Ordinat(P1)==Ordinat(P2)));
}

Point PlusDelta (Point P, float deltaX, float deltaY){
  return MakePoint(Absis(P)+deltaX, Ordinat(P)+deltaY);
}

float Panjang (Point P1, Point P2){
  float deltaX, deltaY;
  deltaX = Absis(P1) - Absis(P2);
  deltaY = Ordinat(P1) - Ordinat(P2);
  return (sqrt(deltaX * deltaX + deltaY * deltaY));
}

void Geser (Point *P, float deltaX, float deltaY){
  *P = PlusDelta(*P, deltaX, deltaY);
}