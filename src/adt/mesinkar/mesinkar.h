/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "../boolean/boolean.h"
#include <stdio.h>

#define MARK '#'

extern char CC;
extern boolean EOP;

void ADV();
boolean START(char* filename);

#endif