#ifndef COMMAND_H
#define COMMAND_H

#include "graph.h"
#include "arraydin.h"
#include "matrix.h"
#include "player.h"
#include "building.h"
#include "point.h"
#include <stdio.h>

extern TabBuilding ArrBuilding;
extern int curPlayerID;
extern Matrix Peta;
extern Graph G;
extern Player P[3];
extern boolean hasAttacked[605];
extern void RegenTroop();
extern void StartTurn();
extern void PrintPlayerBuildings();
extern void PrintNeighbourBuilding(int BuildID);
extern void PrintOurBuilding(int BuildID);
extern int NeighbourDegree(Graph G, infotypeGraph X);
extern int OurDegree(Graph G, infotypeGraph X);
extern int GGetOurNthInfo(Graph G, infotypeGraph X, int n);
extern int GGetNeighbourNthInfo(Graph G, infotypeGraph X, int n);

float GetMultiplier(int idAttack, int ownerAttack) {
    float multiplier = 1;
    if (Defense(AElmt(ArrBuilding, idAttack)) || PShield(P[ownerAttack])) {
        multiplier = 0.75;
    }
    if (PAttackUp(P[ownerAttack])) {
        multiplier = 1;
    }
    if (PCriticalHit(P[ownerAttack])) {
        multiplier = 2;
        PCriticalHit(P[ownerAttack]) = false;
    }
    return multiplier;
}

void Attack(int PlayerID) {
    PrintPlayerBuildings(PlayerID);
    int pick = 0;
    int NBuild = NbElmt(Buildings(P[PlayerID]));
    int id = 0;
    do {
        printf("Bangunan yang digunakan untuk menyerang: ");
        InputInt(&pick);
        if (pick <= 0 || pick > NBuild) {
            printf("Pilihan tidak valid.\n");
        } else {
            id = LGetNthInfo(Buildings(P[PlayerID]), pick);
            if (hasAttacked[id]) {
                printf("Bangunan tersebut sudah menyerang dalam giliran ini!\n");
                pick = 0;   
            }
        }
    } while (pick <= 0 || pick > NBuild);
    id = LGetNthInfo(Buildings(P[PlayerID]), pick);
    
    printf("Daftar bangunan yang dapat diserang:\n");
    int NDegree = NeighbourDegree(G, id);
    PrintNeighbourBuilding(id);
    if (NDegree == 0) return;
    int pickAttack = 0;
    int idAttack = 0;
    do {
        printf("Bangunan yang diserang: ");
        InputInt(&pickAttack);
        if (pickAttack <= 0 || pick > NDegree) {
            printf("Pilihan tidak valid.\n");
        }
    } while (pickAttack <= 0 || pickAttack > NDegree);
    idAttack = GGetNeighbourNthInfo(G, id, pickAttack);

    int ownerAttack = OwnerID(AElmt(ArrBuilding, idAttack));
    int atkTroop;
    do {
        printf("Jumlah Pasukan: ");
        InputInt(&atkTroop);
        if (atkTroop <= 0 || atkTroop > Troop(AElmt(ArrBuilding, id))) {
            printf("Jumlah pasukan tidak valid!\n");
        }
    } while (atkTroop <= 0 || atkTroop > Troop(AElmt(ArrBuilding, id)));

    Troop(AElmt(ArrBuilding, id)) -= atkTroop;

    int enemyTroop = Troop(AElmt(ArrBuilding, idAttack));
    float multiplier = GetMultiplier(idAttack, ownerAttack);
    atkTroop *= multiplier;
    if (atkTroop < enemyTroop) {
        Troop(AElmt(ArrBuilding, idAttack)) -= atkTroop;
        printf("Bangunan gagal direbut.\n");
    } else {
        Troop(AElmt(ArrBuilding, idAttack)) = atkTroop - enemyTroop;
        ChangeBaseProperty(&AElmt(ArrBuilding, idAttack), GetBase(AElmt(ArrBuilding, idAttack), 1));
        OwnerID(AElmt(ArrBuilding, idAttack)) = PlayerID;
        printf("Bangunan menjadi milikmu!\n");
    }
}


void LevelUpBuilding(Building * B){
    int minToLevelUp = MaxCap(*B) / 2;
    if(Troop(*B) >= minToLevelUp && Level(*B) < 4){
        Troop(*B) -= minToLevelUp;
        ChangeBaseProperty(B, GetBase(*B, Level(*B) + 1));
        printf("Level ");
        PrintBuildingType(*B);
        printf("-mu meningkat menjadi %d!\n", Level(*B));
    } else {
        printf("Jumlah pasukan ");
        PrintBuildingType(*B);
        printf(" kurang untuk level up\n");
    }
}

void LevelUp(int PlayerID){
    PrintPlayerBuildings(PlayerID);
    int pick = 0;
    int NBuild = NbElmt(Buildings(P[PlayerID]));
    do {
        printf("Bangunan yang akan di level up: ");
        InputInt(&pick);
        if (pick <= 0 || pick > NBuild) {
            printf("Pilihan tidak valid.\n");
        }
    } while (pick <= 0 || pick > NBuild);
    int id = LGetNthInfo(Buildings(P[PlayerID]), pick);
    LevelUpBuilding(&AElmt(ArrBuilding, id));
}

void Move(int PlayerID){
    PrintPlayerBuildings(PlayerID);
    int pick = 0;
    int NBuild = NbElmt(Buildings(P[PlayerID]));
    do {
        printf("Bangunan yang digunakan untuk mengirim pasukan: ");
        InputInt(&pick);
        if (pick <= 0 || pick > NBuild) {
            printf("Pilihan tidak valid.\n");
        }
    } while (pick <= 0 || pick > NBuild);
    int id = LGetNthInfo(Buildings(P[PlayerID]), pick);
    
    printf("Daftar bangunan terdekat:\n");
    int NDegree = OurDegree(G, id);
    PrintOurBuilding(id);
    if (NDegree == 0) return;
    int pickMove = 0;
    int moveTroops = 0;
    do {
        printf("Bangunan yang akan menerima: ");
        InputInt(&pickMove);
        printf("Jumlah pasukan: ");
        InputInt(&moveTroops);
        if (pickMove <= 0 || pick > NDegree ) {
            printf("Pilihan tidak valid.\n");
        }
    } while (pickMove <= 0 || pickMove > NDegree);

    if (moveTroops > Troop(AElmt(ArrBuilding, id))){
        printf("Pasukan tidak cukup.\n");
    }
    else {
        int idTarget = GGetOurNthInfo(G, id, pickMove);
        Troop(AElmt(ArrBuilding, idTarget)) += moveTroops;
        Troop(AElmt(ArrBuilding, id)) -= moveTroops;
        printf("%d pasukan dari ", moveTroops);
        PrintBuildingType(AElmt(ArrBuilding, id)); printf(" ");
        TulisPoint(Pos(AElmt(ArrBuilding, id)));
        printf(" telah berpindah ke ");
        PrintBuildingType(AElmt(ArrBuilding, idTarget)); printf(" ");
        TulisPoint(Pos(AElmt(ArrBuilding, idTarget)));
    }
}

void EndTurn(int PlayerID){
    int enemyPlayerID = PlayerID % 2 + 1;
    if (PShield(P[enemyPlayerID]) > 0){
        PShield(P[enemyPlayerID]) --;
    }
    curPlayerID = enemyPlayerID;
    RegenTroop();
}


#endif