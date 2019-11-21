#include "point.h"

Point MakePoint (int R, int C)
/* Membentuk sebuah Point dari komponen-komponennya */
{
  // KAMUS LOKAL
  Point ret;
  // ALGORITMA
  Row(ret) = R;
  Col(ret) = C;
  return ret;
}

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
void BacaPoint (Point * P) {
  int R, C;
  InputInt(&R); InputInt(&C);
  Row((*P)) = R;
  Col((*P)) = C;
}

void TulisPoint (Point P)
/* Nilai P ditulis ke layar dengan format "(R,C)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output R dan C harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
{
  printf("(%d,%d)", Row(P), Col(P));
}
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(R,C)" */

boolean IsEQPoint(Point P1, Point P2) {
  return (Row(P1) == Row(P2) && Col(P1) == Col(P2));
}

void CopyPoint(Point Pin, Point *Pout) {
  Row(*Pout) = Row(Pin);
  Col(*Pout) = Col(Pin);
  return;
}
