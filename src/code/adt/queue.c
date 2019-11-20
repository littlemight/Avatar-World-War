#include "../../header/adt/queue.h"
#include <string.h>

boolean QIsEmpty(Queue Q) {
  return (Head(Q) == Nil && Tail(Q) == Nil);
}

boolean QIsFull(Queue Q) {
  return ((Tail(Q) - Head(Q) + 1) == MaxEl(Q));
}

int QNbElmt(Queue Q) {
  if (QIsEmpty(Q)) return 0;
  if (Head(Q) <= Tail(Q)) return (Tail(Q) - Head(Q) + 1);
  return (MaxEl(Q) - Head(Q) + 1 + Tail(Q));
}

void QCreateEmpty(Queue* Q, int Max) {
  MaxEl(*Q) = Max;
  Head(*Q) = Nil;
  Tail(*Q) = Nil;
  (*Q).T = (infotype*) malloc((Max + 1) * sizeof(infotype));
  for (int i = 0; i <= MaxEl(*Q); i++) {
    KCreateEmpty(&(*Q).T[i]);
  }
}

void DeAlokasi(Queue *Q) {
  free((*Q).T);
  MaxEl(*Q) = 0;
}

void QAdd(Queue* Q, infotype X) {
  if (QIsEmpty(*Q)) {
    Head(*Q) = 1;
    Tail(*Q) = 1;
    CopyKata(X, &InfoTail(*Q));
    InfoTail(*Q) = X;
  } else {
    Tail(*Q) = (Tail(*Q) % MaxEl(*Q)) + 1;
    CopyKata(X, &InfoTail(*Q));
  }
}

void QDel(Queue* Q, infotype *X) {
  *X = InfoHead(*Q);
  if (Head(*Q) == Tail(*Q)) {
    Head(*Q) = Tail(*Q) = Nil;
  } else {
    Head(*Q) = (Head(*Q) % MaxEl(*Q)) + 1;
  }
}

void CopySkills(Queue Qin, Queue *Qout) {
  QCreateEmpty(Qout, 10);
  Head(*Qout) = Head(Qin);
  Tail(*Qout) = Tail(Qin);
  MaxEl(*Qout) = MaxEl(Qin);

  // printf("SKILLS COPY\n");
  // printf("tail: %d", Tail(*Qout));
  for (int i = Head(*Qout); i <= Tail(*Qout); i++) {
    CopyKata((Qin).T[i], &(*Qout).T[i]);
    // printf("skills: %d\n", i);
  }
}

void SavePrintQueue(FILE *file, Queue Q) {
  fprintf(file,  "%d\n", QNbElmt(Q));
  for (int i = 1; i <= QNbElmt(Q); i++) {
    SavePrintKata(file, Q.T[i]);
  }
}