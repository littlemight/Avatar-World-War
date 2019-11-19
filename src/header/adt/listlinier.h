#ifndef _LISTLINIER_H
#define _LISTLINIER_H

#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"

#define NilList NULL

typedef int Linfotype;
typedef struct tElmtlist *addressList;
typedef struct tElmtlist {
	Linfotype info;
	addressList next;
} ElmtList;
typedef struct {
	addressList First;
} List;

/* Definisi list : */
/* List kosong : LFirst(L) = NilList */
/* Setiap elemen dengan addressList P dapat diacu LInfo(P), LNext(P) */
/* Elemen terakhir list : jika addressListnya Last, maka LNext(Last)=NilList */

#define LInfo(P) (P)->info
#define LNext(P) (P)->next
#define LFirst(L) ((L).First)

/****************** TEST LIST KOSONG ******************/
boolean LIsEmpty (List L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void LCreateEmpty (List *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addressList Alokasi (Linfotype X);
/* Mengirimkan addressList hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressList tidak NilList, dan misalnya */
/* menghasilkan P, maka LInfo(P)=X, LNext(P)=NilList */
/* Jika alokasi gagal, mengirimkan NilList */
void Dealokasi (addressList *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressList P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressList Search (List L, Linfotype X);
/* Mencari apakah ada elemen list dengan LInfo(P)= X */
/* Jika ada, mengirimkan addressList elemen tersebut. */
/* Jika tidak ada, mengirimkan NilList */

/****************** PRIMITIF BERDASARKAN NilListAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, Linfotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan NilListai X jika alokasi berhasil */
void InsVLast (List *L, Linfotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNilListai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, Linfotype *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: NilListai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, Linfotype *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: NilListai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, addressList P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressList P sebagai elemen pertama */
void InsertAfter (List *L, addressList P, addressList Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, addressList P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, addressList *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, Linfotype X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressList P, dengan LInfo(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info berNilListai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan LInfo(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, addressList *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, addressList *Pdel, addressList Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus LNext(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNilListai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt (List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
Linfotype Max (List L);
/* Mengirimkan NilListai LInfo(P) yang maksimum */

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3);
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

int LGetNthInfo(List L, int n);


void CopyList(List Lin, List *Lout);


void DealokasiAll(List L);


addressList LLastElmt(List L);


#endif