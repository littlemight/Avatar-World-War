#include "stack.h"

void SCreateEmpty (Stack *S){
  Top(*S) = NilStack;
}

boolean SIsEmpty (Stack S){
  return (Top(S) == NilStack);
}

boolean SIsFull (Stack S){
  return (Top(S) = SMaxEl);
}

void SPush (Stack * S, Sinfotype X){
  Top(*S)++;
  CopyState(X, &InfoTop(*S));
}


void SPop (Stack * S, Sinfotype* X){
  CopyState(InfoTop(*S), X);
  Top(*S)--;
}

// void SavePrintStack(FILE *file, Stack UndoStack) {
//   fprintf(file,  "%d\n", Top(UndoStack));
//   for (int i = 1; i <= Top(UndoStack); i++) {
//     SavePrintState(file, UndoStack.T[i]);
//   }
// }