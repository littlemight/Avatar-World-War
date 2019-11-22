#include "point.h"

Point MakePoint (int R, int C)
{
  Point ret;
  Row(ret) = R;
  Col(ret) = C;
  return ret;
}

void BacaPoint (Point * P) {
  int R, C;
  InputInt(&R); InputInt(&C);
  Row((*P)) = R;
  Col((*P)) = C;
}

void TulisPoint (Point P)
{
  printf("(%d,%d)", Row(P), Col(P));
}

boolean IsEQPoint(Point P1, Point P2) {
  return (Row(P1) == Row(P2) && Col(P1) == Col(P2));
}

void CopyPoint(Point Pin, Point *Pout) {
  Row(*Pout) = Row(Pin);
  Col(*Pout) = Col(Pin);
  return;
}
