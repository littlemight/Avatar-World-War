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
extern boolean EndKata;
extern Kata CKata;

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

void InputKata(Kata* X);
boolean EQKata(Kata X, Kata Y);
void PrintKata(Kata X);
void KataToArrChar(Kata K, char* eff);
boolean IsArrCharEQ(char a[], char b[]);
void TOSTDIN();
#endif