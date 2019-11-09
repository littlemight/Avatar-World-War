/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#ifndef queue_H
#define queue_H

#include "boolean.h"
#include "mesinkata.h"
#include <stdlib.h>

#define Nil 0
/* Konstanta untuk mendefinisikan addressQueue tak terdefinisi */

/* Definisi elemen dan addressQueue */
typedef char* infotype;
typedef int addressQueue;   /* indeks tabel */
/* Contoh deklarasi variabel bertype Queue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct {
  infotype* T;   /* tabel penyimpan elemen */
  addressQueue HEAD;  /* alamat penghapusan */
  addressQueue TAIL;  /* alamat penambahan */
  int MaxEl;     /* Max elemen queue */
} Queue;
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika Q adalah Queue, maka akses elemen : */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl

/* ********* Prototype ********* */
boolean QIsEmpty (Queue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean QIsFull (Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void QCreateEmpty (Queue * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(Queue * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
void Del (Queue * Q, infotype * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */

// IMPLEMENTASI
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
#endif