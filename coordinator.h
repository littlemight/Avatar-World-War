#ifndef COORDINATOR_H
#define COORDINATOR_H

#include "building.h"
#include "player.h"
#include "arraydin.h"
#include "graph.h"
#include "matrix.h"
#include "pcolor.h"
#include "utility.h"
#include "command.h"
#include "skill.h"

TabBuilding ArrBuilding;
Matrix Peta;
Graph G;
Player P[3];
boolean hasAttacked[605];
int N, M, B, curPlayerID;

/** ======================================== PRINT  ========================================  **/
void PrintPeta() {
    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= M + 1; j++) {
            if (i == 0 || j == 0 || i == N + 1 || j == M + 1) {
                printf("*");
                continue;
            }
            if (MElmt(Peta, i, j) == 0) {
                printf(" ");
            } else {
                switch (AElmt(ArrBuilding, MElmt(Peta, i, j)).OwnerID) {
                    case 0:
                        printf("%c", AElmt(ArrBuilding, MElmt(Peta, i, j)).Type);
                        break;
                    case 1:
                        print_blue(AElmt(ArrBuilding, MElmt(Peta, i, j)).Type);
                        break;
                    case 2:
                        print_red(AElmt(ArrBuilding, MElmt(Peta, i, j)).Type);
                        break;
                }
            }
        }
        printf("\n");
    }
}

void PrintPlayerBuildings(){
    printf("Building List:\n");
    // printf(" Building Info:\n");
    int cnt = 1;
    for (int i = 1; i <= ANeff(ArrBuilding); i++){
        if (OwnerID(AElmt(ArrBuilding, i)) == curPlayerID){
            printf("%d. ", cnt++);
            PrintBuilding(AElmt(ArrBuilding, i));
            printf("\n");
        }
    }
}

void PrintNeighbourBuilding(int BuildID) { // mencetak building yang tetangga dan beda ownership
    adrNode Pn = SearchNode(G, BuildID);
    adrSuccNode P = Trail(Pn);
    int cnt = 1;
    Building Cur = AElmt(ArrBuilding, BuildID);
    while (P != NilGraph) {
        Building B = AElmt(ArrBuilding, Id(Succ(P)));
        if (OwnerID(B) != OwnerID(Cur)) {
            printf("%d. ", cnt++);
            PrintBuilding(B);
            printf("\n");
        }
        // printf("%d\n", cnt);
        P = Next(P);
    }
    if (cnt == 1) {
        printf("Tidak ada.\n");
    }
}

void PrintOurBuilding(int BuildID) { // mencetak building yang tetangga dan sama ownership
    adrNode Pn = SearchNode(G, BuildID);
    adrSuccNode P = Trail(Pn);
    int cnt = 1;
    Building Cur = AElmt(ArrBuilding, BuildID);
    while (P != NilGraph) {
        Building B = AElmt(ArrBuilding, Id(Succ(P)));
        if (OwnerID(B) == OwnerID(Cur)) {
            printf("%d. ", cnt++);
            PrintBuilding(B);
            printf("\n");
        }
        P = Next(P);
    }
    if (cnt == 1) {
        printf("Tidak ada.\n");
    }
}

/** ======================================== ----  ========================================  **/

int GGetNeighbourNthInfo(Graph G, infotypeGraph X, int n) {
	adrNode Pn = SearchNode(G, X);
	adrSuccNode P = Trail(Pn);
    Building Cur = AElmt(ArrBuilding, X);
	while (n != 1) {
        Building B = AElmt(ArrBuilding, Id(Succ(P)));
        if (OwnerID(B) != OwnerID(Cur)) n--;
		P = Next(P);
	}
	return Id(Succ(P));
}

int GGetOurNthInfo(Graph G, infotypeGraph X, int n) {
	adrNode Pn = SearchNode(G, X);
	adrSuccNode P = Trail(Pn);
    Building Cur = AElmt(ArrBuilding, X);
	while (n != 1) {
        Building B = AElmt(ArrBuilding, Id(Succ(P)));
        if (OwnerID(B) == OwnerID(Cur)) n--;
		P = Next(P);
	}
	return Id(Succ(P));
}

/** ======================================== MEKANISME  ========================================  **/
void AvatarWW();
void StartGame();
void RegenTroop();
void PrintStatus();

void AvatarWW() {
    clear();

    Kata username1, username2;
    printf("Masukkan Username Player 1: "); InputKata(&username1);
    printf("Masukkan Username Player 2: "); InputKata(&username2);
    Username(P[1]) = username1;
    Username(P[2]) = username2;
    QCreateEmpty(&Skills(P[1]), 10);
    QCreateEmpty(&Skills(P[2]), 10);

    Add(&Skills(P[1]), InstantUpgrade);
    Add(&Skills(P[2]), InstantUpgrade);

    curPlayerID = 1;
    StartGame();
}

void PrintStatus() {
    clear();

    PrintPeta();
    printf("Player ");
    PrintKata(Username(P[curPlayerID]));
    printf("\n");
    PrintPlayerBuildings(curPlayerID);
    printf("Skill Available: ");
    if (QIsEmpty(Skills(P[curPlayerID]))) {
        printf("None\n");
    } else {
        printf("%s\n", InfoHead(Skills(P[curPlayerID])));
    }
}

void StartGame() {
    Kata command;
    char effCommand[50];
    do {
        PrintStatus();
        printf(">>> ENTER COMMAND: ");
        InputKata(&command);
        KataToArrChar(command, effCommand);
        if (IsArrCharEQ(effCommand, "ATTACK")) {
            Attack(curPlayerID);
            ADV();
        } else if (IsArrCharEQ(effCommand, "LEVEL_UP")) {
            LevelUp(curPlayerID);
            ADV();
        } else if (IsArrCharEQ(effCommand, "SKILL")) {
            ADV();
        } else if (IsArrCharEQ(effCommand, "UNDO")) {
            ADV();
        } else if (IsArrCharEQ(effCommand, "END_TURN")) {
            EndTurn(curPlayerID);
        } else if (IsArrCharEQ(effCommand, "SAVE")) {
            ADV();
        } else if (IsArrCharEQ(effCommand, "MOVE")) {
            Move(curPlayerID);
            ADV();
        } else if (IsArrCharEQ(effCommand, "EXIT")) {
            ADV();
        } else {
            printf("Command tidak valid.\n");
            ADV();
        }
    } while (!IsArrCharEQ(effCommand, "EXIT"));
}

void RegenTroop() {
    for (int i = 1; i <= ANeff(ArrBuilding); i++) {
        if (OwnerID(AElmt(ArrBuilding, i)) == curPlayerID) {
            Building *B = &AElmt(ArrBuilding, i);
            if (Troop(*B) < MaxCap(*B)) {
                Troop(*B) += Regen(*B);
            }
        }
    }
}
/** ======================================== ----  ========================================  **/

/** ======================================== SKILL  ========================================  **/


// void GetSkill(Player * P1, Player * P2){ //ngecek apakah dapet skill di akhir tiap move
//     if(NbElmt(P2->Buildings == 2)){

//     }
//     if(){

//     } 
// }

// void DoSkill(char* Cur, int curPlayerID) {
//     if (Cur == InstantUpgrade)
//     DoInstantUpgrade(curPlayerID);
//     else if (Cur == Shield)
//         DoShield(curPlayerID);
//     else if (Cur ==  ExtraTurn)
//         DoExtraTurn(curPlayerID);
//     else if (Cur ==  AttackUp)
//         DoAttackUp(curPlayerID);
//     else if (Cur ==  CriticalHit)
//         DoCriticalHit(curPlayerID);
//     else if (Cur ==  InstantReinforcement)
//         DoInstantReinforcement();
//     else if (Cur ==  CriticalHit)
//         DoCriticalHit();
//     else if (Cur == InstantReinforcement)
//         DoInstantReinforcement();
//     else if (Cur == Barrage)
//         DoBarrage();
// }

// void DoInstantUpgrade(int curPlayerID){

// }
/** ======================================== ---- ========================================  **/

/** ======================================== GRAPH  ========================================  **/
int NeighbourDegree(Graph G, infotypeGraph X) {
	adrNode Pn = SearchNode(G, X);
    Building Cur = AElmt(ArrBuilding, X);
	int cnt = 0;
	adrSuccNode P = Trail(Pn);
	while (P != NilGraph) {
        Building B = AElmt(ArrBuilding, Id(Succ(P)));
        if (OwnerID(B) != OwnerID(Cur)) {
            cnt++;
        }
        P = Next(P);
	}
	return cnt;
}

int OurDegree(Graph G, infotypeGraph X) {
	adrNode Pn = SearchNode(G, X);
    Building Cur = AElmt(ArrBuilding, X);
	int cnt = 0;
	adrSuccNode P = Trail(Pn);
	while (P != NilGraph) {
        Building B = AElmt(ArrBuilding, Id(Succ(P)));
        if (OwnerID(B) == OwnerID(Cur)) {
            cnt++;
        }
        P = Next(P);
	}
	return cnt;
}
/** ======================================== ---- ========================================  **/

/** ======================================== SETUP  ========================================  **/
void LoadInit() {
    InputInt(&N);
    InputInt(&M);
    InputInt(&B);
    AMakeEmpty(&ArrBuilding, N*M);
    ANeff(ArrBuilding) = B;
    MakeMatrix(&Peta, N, M);
    for (int i = 1; i <= B; i++) {
        int OwnerID = i;
        if (i > 2) OwnerID = 0;
        else {
            if (i == 1) {
                InsVLast(&Buildings(P[i]), i);
            } else {
                InsVLast(&Buildings(P[i]), i);
            }
        }
        Kata type;
        int r, c;
        InputKata(&type);
        InputInt(&r); InputInt(&c);
        Point pos;
        pos = MakePoint(r, c);
        Building base;
        switch (type.TabKata[1]) {
            case 'C':
                base = CASTLE[1];
                break;
            case 'T':
                base = TOWER[1];
                break;
            case 'F':
                base = FORT[1];
                break;
            case 'V':
                base = VILLAGE[1];
                break;
        }
        MakeBuilding(&AElmt(ArrBuilding, i), base, OwnerID, pos);
        MElmt(Peta, Row(pos), Col(pos)) = i;
    }
    CreateGraph(1, &G);
    for (int i = 1; i <= B; i++) {
        for (int j = 1; j <= B; j++) {
            int x;
            InputInt(&x);
            if (x == 1) {
                InsertEdge(&G, i, j);
            }
        }
    }
}

#endif