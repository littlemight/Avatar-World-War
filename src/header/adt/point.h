/* File: Point.h */
/* Tanggal: 28 Agustus 2016 */
/* *** Definisi ABSTRACT DATA TYPE Point *** */

#ifndef _POINT_H
#define _POINT_H

#include <stdio.h>
#include "mesinkata.h"

typedef struct {
	int R; /* Row   */
	int C; /* Col */
} Point;

#define Row(P) (P).R
#define Col(P) (P).C

Point MakePoint(int R, int C);
void BacaPoint(Point *P);
void TulisPoint(Point P);
boolean IsEQPoint(Point P1, Point P2);
void CopyPoint(Point Pin, Point *Pout);
#endif