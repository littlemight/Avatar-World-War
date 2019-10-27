/* File: point.h */
/* Tanggal: 28 Agustus 2016 */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#ifndef LIST_H
#define LIST_H

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> List;

void DelP(List *L, int X) {
  (*L).erase(remove((*L).begin(), (*L).end(), X), (*L).end());
}

void InsVLast (List *L, int X) {
  (*L).push_back(X);
}

#endif