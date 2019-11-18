#include "../../header/adt/mesinkar.h"

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