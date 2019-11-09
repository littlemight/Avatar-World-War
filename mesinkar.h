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

char CC;
boolean EOP;

static FILE * pita;
static int retval;

void ADV() {
    retval = fscanf(pita,"%c",&CC);
    EOP = (CC == MARK);
    if (EOP) {
       if (pita != stdin) {
           fclose(pita);
       }
    }
}

boolean START(char* filename) {
    EOP = false;
    if (filename == 0) {
        pita = stdin;
    } else {
        pita = fopen(filename, "r");
        ADV();
    }
    return (pita != 0);
}

#endif