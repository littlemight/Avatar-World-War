#include "state.h"
#include "../pcolor/pcolor.h"

int main(){
    State S;
    Player P[3];
    Building T1, C1, F1, V1;
    CreateEmptyState(&S);

    MakeBaseProperty(&T1, 'T', 1, 2, 40, true,100);
    MakeBaseProperty(&C1, 'C', 2, 2, 30, false,200);
    MakeBaseProperty(&F1, 'F', 3, 2, 30, true,300);
    MakeBaseProperty(&V1, 'V', 4, 2, 50, false,200);
    
    TabBuilding ArrBuilding;;
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
        PCreateEmpty(&P[i]);
    }
    
    AddBuilding(&Buildings(P[1]), 1);
    AddBuilding(&Buildings(P[1]), 2);
    AddBuilding(&Buildings(P[2]), 3);
    AddBuilding(&Buildings(P[2]), 4);

    STARTKATA(0);
    printf("Username player 1: ");
    InputKata(&Username(P[1]));
    printf("Username player 2: ");
    InputKata(&Username(P[2]));

    int curPlayerID = 1;
    MakeState(ArrBuilding, P, curPlayerID, &S);
    
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
        for (int i = 1; i <= 4; i++) {
            Building B = AElmt(ArrBuilding, i);
            if (OwnerID(B) != p) continue;
            if (i < 10) printf(" ");
            printf("%d. ", i);
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

    return 0;
}