/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel dinamik */

#ifndef ARRAYDIN_H
#define ARRAYDIN_H

#include "boolean.h"
#include "building.h"

/*  Kamus Umum */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType; /* type indeks */
typedef Building AElType;  /* type elemen tabel */
typedef struct
{
  AElType *TI; /* memori tempat penyimpan elemen (container) */
  int ANeff;   /* >=0, banyaknya elemen efektif */
  int AMaxEl;  /* ukuran elemen */
} TabBuilding;
/* Indeks yang digunakan [IdxMin..AMaxEl] */
/* Jika T adalah TabBuilding, cara deklarasi dan akses: */
/* Deklarasi : T : TabBuilding */
/* Maka cara akses:
   T.ANeff  untuk mengetahui banyaknya elemen
   T.TI    untuk mengakses seluruh nilai elemen tabel
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: T.ANeff = 0
  Definisi elemen pertama : T.TI[i] dengan i=1
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.ANeff */

/* ********** SELEKTOR ********** */
#define ANeff(T) (T).ANeff
#define TI(T) (T).TI
#define AElmt(T, i) (T).TI[(i)]
#define AMaxEl(T) (T).AMaxEl

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void AMakeEmpty(TabBuilding *T, int AMaxEl);
/* I.S. T sembarang, AMaxEl > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas AMaxEl + 1 */

void ADealokasi(TabBuilding *T);
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, AMaxEl(T)=0; ANeff(T)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int ANbElmt(TabBuilding T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxElement(TabBuilding T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabBuilding T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx(TabBuilding T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabBuilding T, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff(TabBuilding T, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabBuilding T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull(TabBuilding T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabBuilding *T);
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */

void TulisIsiTab(TabBuilding T);
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabBuilding PlusMinusTab(TabBuilding T1, TabBuilding T2, boolean plus);
/* Prekondisi : T1 dan T2 memiliki ANeff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabBuilding T, AElType X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
boolean SearchB(TabBuilding T, AElType X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */

/* ********** OPERASI LAIN ********** */
void CopyTab(TabBuilding Tin, TabBuilding *Tout);
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, ANeff dan AMaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */

/* ********** KONSTRUKTOR ********** */
void AMakeEmpty(TabBuilding *T, int AMaxEl)
{
  TI(*T) = (AElType*) malloc((AMaxEl + 1) * sizeof(AElType));
  AMaxEl(*T) = AMaxEl;
  ANeff(*T) = 0;
}

void ADealokasi(TabBuilding *T)
{
  free(TI(*T));
  ANeff(*T) = 0;
  AMaxEl(*T) = 0;
}

int ANbElmt(TabBuilding T)
/* *** Daya tampung container *** */
{
  return ANeff(T);
}

int MaxElement(TabBuilding T)
{
  return AMaxEl(T);
}

IdxType GetFirstIdx(TabBuilding T)
{
  return IdxMin;
}

IdxType GetLastIdx(TabBuilding T)
{
  return GetFirstIdx(T) + ANbElmt(T) - 1;
}

boolean IsIdxValid(TabBuilding T, IdxType i)
{
  return (i >= 1 && i <= MaxElement(T));
}

boolean IsIdxEff(TabBuilding T, IdxType i)
{
  return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}

boolean IsEmpty(TabBuilding T)
{
  return ANbElmt(T) == 0;
}

boolean IsFull(TabBuilding T)
{
  return (ANbElmt(T) == MaxElement(T));
}

// void BacaIsi(TabBuilding *T)
// {
//   int n, x;
//   do {
//     scanf("%d", &n);
//   } while (n < 0 || n > MaxElement(*T));
//   ANeff(*T) = n;
//   if (n != 0) {
//     for (IdxType i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++) {
//       scanf("%d", &x);
//       AElmt(*T, i) = x;
//     }
//   }
// }

void TulisIsiTab(TabBuilding T)
{
  if (IsEmpty(T)) {
    printf("[]");
  } else {
    printf("[");
    for (IdxType i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
      printf("%d", AElmt(T, i));
      if (i != GetLastIdx(T)) {
        printf(",");
      }
    }
    printf("]");
  }
}

#endif