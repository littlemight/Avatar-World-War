#include "point.h"

int main() {
    STARTKATA(0);

    Point P;
    printf("Masukkin 2 angka: ");
    BacaPoint(&P);
    TulisPoint(P);

    return 0;
}