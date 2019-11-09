#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "mesinkar.h"
#include "boolean.h"
#include <stdio.h>

#define NMax 50
#define BLANK ' '

typedef struct {
  char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
  int Length;
} Kata;

/* State Mesin Kata */
// extern boolean EndKata;
// extern Kata CKata;
boolean EndKata;
Kata CKata;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

boolean STARTKATA(char* filename);
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

int ToInteger();
/*
  CKata sudah diakuisisi
  Mengirim nilai CKata dalam integer jika CKata adalah integer yang valid
  Mengirim -1 jika CKata bukan integer yang valid */

void InputInt(int* X);
/* 
  I.S. : X sembarang, CKata belum diakuisisi
  F.S. : CKata sudah diakuisisi.
         X = CKata jika CKata adalah integer yang valid, X tidak berubah jika tidak */

boolean IsBlank() {
  // printf("Kata is now %s\n", CC);

  return (CC == BLANK || CC == 10 || CC == 0);
  // 10 is enter
  // 0 is null
}

void IgnoreBlank() {
  while (IsBlank()) {
    ADV();
  }
}

boolean STARTKATA(char* filename) {
  boolean valid = (START(filename) != 0);
  // printf("%s\n", filename);
  if (!valid) {
    EndKata = true;
    return valid;
  }

  if (filename != 0) {
    IgnoreBlank();
  }

  if (CC == MARK) {
    EndKata = true;
  } else {
    EndKata = false;
    // if (filename != 0) SalinKata();
  }
  return valid;
}

void TOSTDIN() {
  ADV();
  STARTKATA(NULL);
  CC = 0;
}

void ADVKATA() {
  IgnoreBlank();
  if (EOP) {
    EndKata = true;
  } else {
    SalinKata();
    // IgnoreBlank();
  }
}

void SalinKata() {
  int id;
  id = 1;
  while (!IsBlank() && !EOP) {
    if (id <= NMax) {
      CKata.TabKata[id] = CC;
    }
    ADV();
    id++;
  }
  if (id > NMax) id = NMax + 1;
  CKata.Length = id - 1;
}

int ToInteger() {
  boolean valid = true;
  int ret = 0;
  int i = 1, cur;

  while (i <= CKata.Length && valid) {
    cur = CKata.TabKata[i] - '0';
    if (cur >= 0 && cur <= 9) {
      ret = ret*10 + cur;
      i++;
    } else {
      valid = false;
      ret = -1;
    }
  }
  return ret;
}

void InputIntBef(int* X) {
  if (ToInteger() != -1) {
    *X = ToInteger();
  }
}

void InputInt(int* X) {
  ADVKATA();
  if (ToInteger() != -1) {
    *X = ToInteger();
  }
}

void InputKata(Kata* X) {
  ADVKATA();
  for (int i = 1; i <= CKata.Length; i++) {
    (*X).TabKata[i] = CKata.TabKata[i];
  }
  (*X).TabKata[CKata.Length + 1] = 0;
  (*X).Length = CKata.Length;
}

boolean EQKata(Kata X, Kata Y) {
  if (X.Length != Y.Length) {
    return false;
  }

  boolean valid = true;
  int i = 1;
  while (i <= X.Length & valid) {
    if (X.TabKata[i] == Y.TabKata[i]) {
      i++;
    } else {
      valid = false;
    }
  }
  return valid;
}

void PrintKata(Kata X) { // prints kata tanpa karakter apapun di depan/belakang
    for (int i = 1; i <= X.Length; i++) {
      printf("%c", X.TabKata[i]);
    }
}

void KataToArrChar(Kata K, char* eff) {
  for (int i = 1; i <= K.Length; i++) {
    eff[i - 1] = K.TabKata[i];
    // printf("%c", eff[i - 1]);
  }
  eff[K.Length] = 0;
}

boolean IsArrCharEQ(char a[], char b[])
{
   int c = 0;
 
   while (a[c] == b[c]) {
      if (a[c] == '\0' || b[c] == '\0')
         break;
      c++;
   }
   
   if (a[c] == '\0' && b[c] == '\0')
      return true;
   else
      return false;
}

#endif