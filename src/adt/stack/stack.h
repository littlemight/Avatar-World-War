#ifndef Stack_H
#define Stack_H

#include "../boolean/boolean.h"
#include "../gamestate/gamestate.h"

#define Nil 0
#define MaxEl 9999 // asumsi undo tak melebihi 9999 kali

typedef GameState infotype;
typedef int address;   /* indeks tabel */

typedef struct {
  infotype T[MaxEl+1]; /* tabel penyimpan elemen */
  address TOP;  /* alamat TOP: elemen puncak */
} Stack;

#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

void CreateEmpty (Stack *S);

// boolean IsEmpty (Stack S);

// boolean IsFull (Stack S);

void Push (Stack * S, infotype X);

void Pop (Stack * S, infotype* X);

#endif