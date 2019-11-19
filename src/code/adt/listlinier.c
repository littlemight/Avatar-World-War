#include "../../header/adt/listlinier.h"

boolean LIsEmpty (List L)
/* Mengirim true jika list kosong */
{
  return (LFirst(L) == NilList);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void LCreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
  LFirst(*L) = NilList;
}

addressList Alokasi (Linfotype X)
/* Mengirimkan addressList hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressList tidak NilList, dan misalnya */
/* menghasilkan P, maka LInfo(P)=X, LNext(P)=NilList */
/* Jika alokasi gagal, mengirimkan NilList */
{
  addressList P;
  P = (addressList) malloc (sizeof(addressList));
  if (P != NilList) {
    LInfo(P) = X;
    LNext( P) = NilList;
    return P;
  } else return NilList;
}

void Dealokasi (addressList *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressList P */
{
  free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressList Search (List L, Linfotype X)
/* Mencari apakah ada elemen list dengan LInfo(P)= X */
/* Jika ada, mengirimkan addressList elemen tersebut. */
/* Jika tidak ada, mengirimkan NilList */
{
  addressList P = LFirst(L);
  boolean found = false;
  while (P != NilList && !found) {
    if (X == LInfo(P)) found = true;
    else P = LNext(P);
  }
  if (found) return P;
  else return NilList;
}


/****************** PRIMITIF BERDASARKAN NilListAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, Linfotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan NilListai X jika alokasi berhasil */
{
  addressList P = Alokasi(X);
  if (P != NilList) {
    if (LIsEmpty(*L)) LFirst(*L) = P;
    else {
     LNext( P) = LFirst(*L);
      LFirst(*L) = P;
    }
  }
}

void InsVLast (List *L, Linfotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNilListai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
  addressList P = Alokasi(X);
  if (P != NilList) {
    addressList cur = LFirst(*L);
    if (cur != NilList) {
      while (LNext(cur) != NilList) {
        cur = LNext(cur);
      }
      LNext(cur) = P;
    } else {
      LFirst(*L) = P;
    }
  }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, Linfotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: NilListai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
  addressList P = LFirst(*L);
  *X = LInfo(P);
  LFirst(*L) = LNext(LFirst(*L));
  free(P);
}

void DelVLast (List *L, Linfotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: NilListai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
  addressList P = LFirst(*L), prev = NilList;
  while (LNext(P) != NilList) {
    prev = P;
    P = LNext(P);
  }
  *X = LInfo(P);
  if (prev == NilList) LFirst(*L) = NilList;
  else LNext(prev) = NilList;
  Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, addressList P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressList P sebagai elemen pertama */
{
 LNext( P) = LFirst(*L);
  LFirst(*L) = P;
}

void InsertAfter (List *L, addressList P, addressList Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
 LNext( P) =LNext( Prec);
 LNext( Prec) = P;
}

void InsertLast (List *L, addressList P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
  if (LIsEmpty(*L)) {
    LFirst(*L) = P;
  } else {
    addressList c = LFirst(*L);
    while (LNext(c) != NilList) c = LNext(c);
   LNext( c) = P;
  }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, addressList *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
  *P = LFirst(*L);
  LFirst(*L) =LNext( LFirst(*L));
}


void DelP (List *L, Linfotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressList P, dengan LInfo(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info berNilListai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan LInfo(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
  if (!LIsEmpty(*L)) {
    if (LInfo(LFirst(*L)) == X) {
      LFirst(*L) =LNext( LFirst(*L));
    } else {
      addressList cur = LFirst(*L);
      while (LNext(cur) != NilList && LInfo(LNext(cur)) != X) {
        cur = LNext( cur);
      }
      if (cur != NilList && LNext(cur) != NilList) {
       LNext( cur) =LNext( LNext(cur));
      }
    }
  }
}

void DelLast (List *L, addressList *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
  if (LNext(LFirst(*L)) == NilList) {
    *P = LFirst(*L);
    LFirst(*L) = NilList;
  } else {
    addressList cur = LFirst(*L);
    while (LNext(LNext(cur)) != NilList) cur =LNext( cur);
    *P =LNext( cur);
   LNext( cur) = NilList;
  }
}

void DelAfter (List *L, addressList *Pdel, addressList Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus LNext(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
  if (LNext(Prec) != NilList) {
    *Pdel =LNext( Prec);
   LNext( Prec) =LNext( LNext(Prec));
  } else *Pdel = NilList;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNilListai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
  addressList cur = LFirst(L);
  printf("[");
  while (cur != NilList) {
    printf("%d", LInfo(cur));
    cur = LNext(cur);
  }
}

int NbElmt(List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
  int cnt = 0;
  addressList cur = LFirst(L);
  while (cur != NilList) {
    cnt++;
    cur = LNext(cur);
  }
  return cnt;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
Linfotype Max (List L)
/* Mengirimkan NilListai LInfo(P) yang maksimum */
{
  addressList cur = LFirst(L);
  int mx = LInfo(cur);
  cur = LNext(cur);
  while (cur != NilList) {
    if (LInfo(cur) > mx) mx = LInfo(cur);
    cur = LNext(cur);
  }
  return mx;
}

int LGetNthInfo(List L, int n) {
  addressList cur = LFirst(L);
  while (n != 1) {
    cur = LNext(cur);
    n--;
  }
  return LInfo(cur);
}

void CopyList(List Lin, List *Lout) {
  LCreateEmpty(Lout);
  addressList cur = LFirst(Lin);
  while (cur != NilList) {
    InsVLast(Lout, LInfo(cur));
    cur = LNext(cur);
  }
  // printf("list success copy\n");
}

void DealokasiAll(List L) {
  addressList cur = LFirst(L);
  while (cur != NilList) {
    addressList nex = LNext(cur);
    Dealokasi(&cur);
    cur = nex;
  }
}