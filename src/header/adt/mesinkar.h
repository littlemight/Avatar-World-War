/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "boolean.h"
#include <stdio.h>

#define MARK '#'
/* State Mesin */

// extern char CC;
// extern boolean EOP;

extern char CC;
extern boolean EOP;

void ADV();
boolean START(char* filename);

#endif