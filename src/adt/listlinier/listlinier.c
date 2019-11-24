#include "listlinier.h"

boolean LIsEmpty (List L)
{
  return (LFirst(L) == NilList);
}

void LCreateEmpty (List *L)
{
  LFirst(*L) = NilList;
}

addressList Alokasi (Linfotype X)
{
  addressList P;
  P = (addressList) malloc (sizeof(addressList));
  if (P != NilList) {
    LInfo(P) = X;
    LNext(P) = NilList;
    return P;
  } else return NilList;
}

void Dealokasi (addressList *P)
{
  free(*P);
}

addressList Search (List L, Linfotype X)
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

int SearchIdx(List L, Linfotype X)
{
  int cnt = 0;
  addressList P = LFirst(L);
  boolean found = false;
  while (P != NilList && !found) {
    cnt++;
    if (X == LInfo(P)) {
      found = true;
    }
    else P = LNext(P);
  }
  if (!found) cnt = 0;
  return cnt;
}

void InsVFirst (List *L, Linfotype X)
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

void AddBuilding (List *L, Linfotype X)
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
  } else {
  }
}

void DelVFirst (List *L, Linfotype *X)
{
  addressList P = LFirst(*L);
  *X = LInfo(P);
  LFirst(*L) = LNext(LFirst(*L));
  free(P);
}

void DelVLast (List *L, Linfotype *X)
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

void InsertFirst (List *L, addressList P)
{
 LNext( P) = LFirst(*L);
  LFirst(*L) = P;
}

void InsertAfter (List *L, addressList P, addressList Prec)
{
 LNext( P) =LNext( Prec);
 LNext( Prec) = P;
}

void InsertLast (List *L, addressList P)
{
  if (LIsEmpty(*L)) {
    LFirst(*L) = P;
  } else {
    addressList c = LFirst(*L);
    while (LNext(c) != NilList) c = LNext(c);
   LNext( c) = P;
  }
}

void DelFirst (List *L, addressList *P)
{
  *P = LFirst(*L);
  LFirst(*L) =LNext( LFirst(*L));
}


void DelBuilding (List *L, Linfotype X)
{
  if (!LIsEmpty(*L)) {
    if (LInfo(LFirst(*L)) == X) {
      LFirst(*L) = LNext(LFirst(*L));
    } else {
      addressList cur = LFirst(*L);
      while (LNext(cur) != NilList && LInfo(LNext(cur)) != X) {
        cur = LNext( cur);
      }
      if (cur != NilList && LNext(cur) != NilList) {
       LNext(cur) =LNext( LNext(cur));
      }
    }
  }
}

void DelLast (List *L, addressList *P)
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
{
  if (LNext(Prec) != NilList) {
    *Pdel =LNext( Prec);
   LNext( Prec) =LNext( LNext(Prec));
  } else *Pdel = NilList;
}

void PrintInfo (List L)
{
  addressList cur = LFirst(L);
  printf("[");
  while (cur != NilList) {
    printf(" %d", LInfo(cur));
    cur = LNext(cur);
  }
  printf(" ]");
}

void SavePrintList (FILE *file, List L)
{
  fprintf(file, "%d\n", LNbElmt(L));
  addressList cur = LFirst(L);
  while (cur != NilList) {
    fprintf(file, "%d\n", LInfo(cur));
    cur = LNext(cur);
  }
}

int LNbElmt(List L)
{
  int cnt = 0;
  addressList cur = LFirst(L);
  while (cur != NilList) {
    cnt++;
    cur = LNext(cur);
  }
  return cnt;
}

Linfotype Max (List L)
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
  int tm = 1;
  while (tm != n) {
    cur = LNext(cur);
    tm++;
  }
  return LInfo(cur);
}

void CopyList(List Lin, List *Lout) {
  LCreateEmpty(Lout);
  addressList cur = LFirst(Lin);
  while (cur != NilList) {
    AddBuilding(Lout, LInfo(cur));
    cur = LNext(cur);
  }
}

void DealokasiAll(List L) {
  addressList cur = LFirst(L);
  while (cur != NilList) {
    addressList nex = LNext(cur);
    Dealokasi(&cur);
    cur = nex;
  }
}

addressList LLastElmt(List L){
	if(LIsEmpty(L)) return NilList;
	addressList P = LFirst(L);
	while(LNext(P) != NilList){
		P = LNext(P);
	}
	return P;
}