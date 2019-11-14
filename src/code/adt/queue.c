#include "../../header/adt/queue.h"
boolean QIsEmpty(Queue Q) {
  return (Head(Q) == Nil && Tail(Q) == Nil);
}

boolean QIsFull(Queue Q) {
  return ((Tail(Q) - Head(Q) + 1) == MaxEl(Q));
}

int NBElmt(Queue Q) {
  if (QIsEmpty(Q)) return 0;
  if (Head(Q) <= Tail(Q)) return (Tail(Q) - Head(Q) + 1);
  return (MaxEl(Q) - Head(Q) + 1 + Tail(Q));
}

void QCreateEmpty(Queue* Q, int Max) {
  MaxEl(*Q) = Max;
  Head(*Q) = Nil;
  Tail(*Q) = Nil;
  (*Q).T = (infotype*) malloc((Max + 1) * sizeof(infotype));
}

void DeAlokasi(Queue *Q) {
  free((*Q).T);
  MaxEl(*Q) = 0;
}

void Add(Queue* Q, infotype X) {
  if (QIsEmpty(*Q)) {
    Head(*Q) = 1;
    Tail(*Q) = 1;
    InfoTail(*Q) = X;
  } else {
    Tail(*Q) = (Tail(*Q) % MaxEl(*Q)) + 1;
    InfoTail(*Q) = X;
  }
}

void Del(Queue* Q, infotype *X) {
  *X = InfoHead(*Q);
  if (Head(*Q) == Tail(*Q)) {
    Head(*Q) = Tail(*Q) = Nil;
  } else {
    Head(*Q) = (Head(*Q) % MaxEl(*Q)) + 1;
  }
}