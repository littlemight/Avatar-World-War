#ifndef POINT_H
#define POINT_H

#include "../boolean/boolean.h"

typedef struct {
	int X; /* absis   */
	int Y; /* ordinat */
} POINT;

#define Absis(P) (P).X
#define Ordinat(P) (P).Y

POINT MakePOINT (float X, float Y);

void BacaPOINT (POINT * P);

void TulisPOINT (POINT P);

boolean EQPOINT (POINT P1, POINT P2);

POINT PlusDelta (POINT P, float deltaX, float deltaY);

float Panjang (POINT P1, POINT P2);

void Geser (POINT *P, float deltaX, float deltaY);

#endif