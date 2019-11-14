#include "../../header/adt/arraydin.h"
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

boolean AIsEmpty(TabBuilding T)
{
  return ANbElmt(T) == 0;
}

boolean AIsFull(TabBuilding T)
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
  if (AIsEmpty(T)) {
    printf("[]");
  } else {
    printf("[");
    for (IdxType i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
      printf("%d", AElmt(T, i).Defense);
      if (i != GetLastIdx(T)) {
        printf(",");
      }
    }
    printf("]");
  }
}