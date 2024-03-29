#include "mesinkata.h"

boolean EndKata;
Kata CKata;

boolean IsBlank() {
  return (CC == BLANK || CC == 10 || CC == 0 || CC == 13);
}

void IgnoreBlank() {
  while (IsBlank()) {
    ADV();
  }
}

boolean STARTKATA(char* filename) {
  boolean valid = (START(filename) != 0);
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

void InputInt(int* X) {
  ADVKATA();
  if (ToInteger() != -1) {
    *X = ToInteger();
  }
}

void KCreateEmpty(Kata *X) {
  (*X).Length = 0;
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
  while ((i <= X.Length) & valid) {
    if (X.TabKata[i] == Y.TabKata[i]) {
      i++;
    } else {
      valid = false;
    }
  }
  return valid;
}

void SavePrintKata(FILE* file, Kata X) { // prints kata tanpa karakter apapun di depan/belakang
    for (int i = 1; i <= X.Length; i++) {
      fprintf(file, "%c", X.TabKata[i]);
    }
}

void PrintKata(Kata X) { // prints kata tanpa karakter apapun di depan/belakang
    for (int i = 1; i <= X.Length; i++) {
      printf("%c", X.TabKata[i]);
    }
}

void KataToArrChar(Kata K, char* eff) {
  for (int i = 1; i <= K.Length; i++) {
    eff[i - 1] = K.TabKata[i];
  }
  eff[K.Length] = 0;
}

boolean IsStrEQ(char a[], char b[])
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

Kata StrToKata(char* Str) {
  Kata ret;
  int i = 0;
  while (true) {
    ret.TabKata[i + 1] = Str[i];
    if (Str[i] == '\0') break;
    i++;
  }
  ret.Length = i;
  ret.TabKata[i + 1] = 0;
  return ret;
}

void CopyKata(Kata Kin, Kata *Kout) {
  KCreateEmpty(Kout);
  (*Kout).Length = Kin.Length;
  for (int i = 1; i <= Kin.Length; i++) {
    (*Kout).TabKata[i] = (Kin).TabKata[i];
  }
  (*Kout).TabKata[Kin.Length + 1] = 0;
  return;
}

void ConcatKata(Kata K1, Kata K2, Kata *KOut) {
  KCreateEmpty(KOut);
  (*KOut).Length = (K1).Length + (K2).Length;
  for (int i = 1; i <= (*KOut).Length; i++) {
    if (i <= (K1).Length) {
      (*KOut).TabKata[i] = (K1).TabKata[i];
    } else {
      (*KOut).TabKata[i] = (K2).TabKata[i - (K1).Length];
    }
  }
  (*KOut).TabKata[(*KOut).Length + 1] = 0;
}