#include "building.h"

int main() {
    Building BC, BT, BV, BF, C, D, E, F;
    Point H = MakePoint(1,1), I = MakePoint(2, 3), J = MakePoint(3, 4), K = MakePoint(5, 6);

    MakeBaseProperty(&BC, 'C', 1, 10, 40, false, 40);
    MakeBaseProperty(&BT, 'T', 1, 5, 20, true, 30);
    MakeBaseProperty(&BV, 'F', 1, 10, 20, false, 80);
    MakeBaseProperty(&BF, 'V', 1, 5, 20, false, 20);
    MakeBuilding(&C, BC, 1, H, true, true);
    MakeBuilding(&D, BT, 0, I, true, false);
    MakeBuilding(&E, BV, 2, J, false, false);
    MakeBuilding(&F, BF, 2, K, false, true);

    PrintBuilding(C); printf("\n");
    PrintBuilding(D); printf("\n");
    PrintBuilding(E); printf("\n");
    PrintBuilding(F); printf("\n");
    
    return 0;
}