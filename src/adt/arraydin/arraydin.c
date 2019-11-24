#include "arraydin.h"
#include <stdlib.h>

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

boolean AIsEmpty(TabBuilding T)
{
  return ANbElmt(T) == 0;
}

boolean AIsFull(TabBuilding T)
{
  return (ANbElmt(T) == MaxElement(T));
}

IdxType Search1(TabBuilding T, AElType X) {
  int ret;
  if (ANbElmt(T) == 0) ret = IdxUndef;
  else {
    IdxType i = GetFirstIdx(T);
    while (!IsEQBuilding(AElmt(T, i), X) && i <= GetLastIdx(T)) i++;
    if (i > GetLastIdx(T)) ret = IdxUndef;
    else ret = i;
  }
  return ret;
}


void TulisIsiTab(TabBuilding T)
{
  if (AIsEmpty(T)) {
    printf("[]");
  } else {
    for (IdxType i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
      PrintBuilding(AElmt(T, i));
      printf("\n");
    }
  }
}

void SavePrintTabBuilding(FILE *file, TabBuilding ArrBuilding) {
  fprintf(file, "%d\n", ANbElmt(ArrBuilding));
  for (int i = 1; i <= ANbElmt(ArrBuilding); i++) {
    SavePrintBuilding(file, AElmt(ArrBuilding, i));
  }
}

void CopyTab(TabBuilding Tin, TabBuilding  *Tout) {
  AMakeEmpty(Tout, MaxElement(Tin));
  ANeff(*Tout) = ANbElmt(Tin);
  for (IdxType i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++) {
    CopyBuilding(AElmt(Tin, i), &AElmt(*Tout, i));
  }
}
