#include "stack.h"
#include <stdio.h>

void PrintStateLite(State S) {
 printf("\nPlayer 1: ");
    PrintKata(Username(P(S, 1))); printf(" "); PrintInfo(Buildings(P(S, 1)));
    printf("\n");
    printf("Player 2: ");
    PrintKata(Username(P(S, 2))); printf(" "); PrintInfo(Buildings(P(S, 2)));
    printf("\n\n");
 for(int p = 1; p <= 2; p ++){
  printf("Building List for ");
        if(p == 1){
            printf("current player - Player %d:\n", p);
        }
        else{
            printf("enemy player - Player %d:\n", p);
        }
        addressList cur = LFirst(Buildings(P(S, p)));
  int cnt = 1;
        for (int i = 1; i <= 4; i++) {
            Building B = AElmt(ArrBuilding(S), i);
            if (OwnerID(B) != p) continue;
            if (i < 10) printf(" ");
            printf("%d. ", cnt++);
            printf(" ");
            if (Row((B).Pos) < 10) printf(" ");
            TulisPoint((B).Pos); 
            if (Col(B.Pos) < 10) printf(" ");
            printf(" | Lv. %d |", Level(B)); 
            printf(" ");
            if (Troop(B) < 10) printf(" ");
            printf("%d", Troop(B));
            if (Troop(B) < 100) printf(" ");
            printf(" ");
            printf("\n");
            cur = LNext(cur);
        }
        printf("\n");
    }
} 

int main () {
 Stack ST;
 SCreateEmpty(&ST);
 STARTKATA(0);
    State S, X;
    Player P1[3], P2[3];
    Building T1, C1, F1, V1;
    CreateEmptyState(&S);
 CreateEmptyState(&X);

    TabBuilding ArrBuilding, ArrBuildingX;

    MakeBaseProperty(&T1, 'T', 1, 2, 40, true,100);
    MakeBaseProperty(&C1, 'C', 2, 2, 30, false,200);
    MakeBaseProperty(&F1, 'F', 3, 2, 30, true,300);
    MakeBaseProperty(&V1, 'V', 4, 2, 50, false,200);

    AMakeEmpty(&ArrBuilding, 4);
    
    Point
        Pos1 = MakePoint(1, 1),
        Pos2 = MakePoint(2, 2),
        Pos3 = MakePoint(3, 3),
        Pos4 = MakePoint(4, 4);
    
    ANeff(ArrBuilding) = 4;

 MakeBuilding(&AElmt(ArrBuilding, 1), T1, 1, Pos1, true, true);
    MakeBuilding(&AElmt(ArrBuilding, 2), C1, 1, Pos2, true, false);
    MakeBuilding(&AElmt(ArrBuilding, 3), F1, 2, Pos3, false, false);
    MakeBuilding(&AElmt(ArrBuilding, 4), V1, 2, Pos4, false, true);

    for (int i = 0; i < 3; i ++){
        PCreateEmpty(&P1[i]);
    }

 printf("Username player 1 (stack 1): ");
    InputKata(&Username(P1[1]));
    printf("Username player 2 (stack 1): ");
    InputKata(&Username(P1[2]));

    AddBuilding(&Buildings(P1[1]), 1);
    AddBuilding(&Buildings(P1[1]), 2);
    AddBuilding(&Buildings(P1[2]), 3);
    AddBuilding(&Buildings(P1[2]), 4);

    int curPlayerID1 = 1;
    MakeState(ArrBuilding, P1, curPlayerID1, &S);

 // untuk state 2

    for (int i = 0; i < 3; i++) {
        PCreateEmpty(&P2[i]);
    }
 AMakeEmpty(&ArrBuildingX, 4);
 ANeff(ArrBuildingX) = 4;
 // pos1 udah ada di atas?
 Point 
  Pos5 = MakePoint(4, 4),
  Pos6 = MakePoint(3, 3),
  Pos7 = MakePoint(2, 2),
  Pos8 = MakePoint(1, 1);

 MakeBaseProperty(&T1, 'T', 4, 2, 45, true,100);
    MakeBaseProperty(&C1, 'C', 3, 2, 35, false,200);
    MakeBaseProperty(&F1, 'F', 2, 2, 35, true,300);
    MakeBaseProperty(&V1, 'V', 1, 2, 55, false,200);

    MakeBuilding(&AElmt(ArrBuildingX, 1), T1, 2, Pos5, true, true);
    MakeBuilding(&AElmt(ArrBuildingX, 2), C1, 2, Pos6, true, false);
    MakeBuilding(&AElmt(ArrBuildingX, 3), F1, 1, Pos7, false, false);
    MakeBuilding(&AElmt(ArrBuildingX, 4), V1, 1, Pos8, false, true);
 
    printf("Username player 1 (stack 2): ");
    InputKata(&Username(P2[1]));
    printf("Username player 2 (stack 2): ");
    InputKata(&Username(P2[2]));

    int curPlayerID2 = 2;
    AddBuilding(&Buildings(P2[1]), 4);
    AddBuilding(&Buildings(P2[1]), 3);
    AddBuilding(&Buildings(P2[2]), 2);
    AddBuilding(&Buildings(P2[2]), 1);
    MakeState(ArrBuildingX, P2, curPlayerID2, &X);
 
 SPush(&ST, S);
 SPush(&ST, X);

 while (!SIsEmpty(ST)) {
  State tm;
  SPop(&ST, &tm);
  PrintStateLite(tm);
  printf("POPPED");
  printf("\n");
 }
 return 0;
}