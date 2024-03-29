/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef _STACK_H
#define _STACK_H

#include "../boolean/boolean.h"
#include "../state/state.h"

#define NilStack 0
#define SMaxEl 100
/* NilStack adalah stack dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */

typedef State Sinfotype;
typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
  Sinfotype T[SMaxEl+1]; /* tabel penyimpan elemen */
  address TOP;  /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = NilStack */
/* Elemen yang dipakai menyimpan NilStackai Stack T[1]..T[SMaxEl] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void SCreateEmpty(Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas SMaxEl */
/* jadi indeksnya antara 1.. SMaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP berNilStackai NilStack */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean SIsEmpty(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */

boolean SIsFull(Stack S);
/* Mengirim true jika tabel penampung NilStackai elemen stack penuh */


/* ************ Menambahkan sebuah elemen ke Stack ************ */
void SPush(Stack *S, Sinfotype X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void SPop(Stack *S, Sinfotype *X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah NilStackai elemen TOP yang lama, TOP berkurang 1 */

void SavePrintStack(FILE *file, Stack UndoStack);
#endif