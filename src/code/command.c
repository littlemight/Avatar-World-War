#include "../header/command.h"
#include "../header/skill.h"

float GetMultiplier(int idAttack, int ownerAttack) {
    float multiplier = 1;
    if (Defense(AElmt(ArrBuilding(S), idAttack)) || PShield(P(S, ownerAttack))) {
        multiplier = 0.75;
    }
    if (PAttackUp(P(S, ownerAttack))) {
        multiplier = 1;
    }
    if (PCriticalHit(P(S, ownerAttack))) {
        multiplier = 2;
        PCriticalHit(P(S, ownerAttack)) = false;
    }
    return multiplier;
}

void Attack(int PlayerID) {
    PrintPlayerBuildings(PlayerID);
    int pick = 0;
    int NBuild = NbElmt(Buildings(P(S, PlayerID)));
    int id = 0;
    do {
        printf("Bangunan yang digunakan untuk menyerang: ");
        InputInt(&pick);
        if (pick <= 0 || pick > NBuild) {
            printf("Pilihan tidak valid.\n");
        } else {
            id = LGetNthInfo(Buildings(P(S, PlayerID)), pick);
            if (HasAttacked(AElmt(ArrBuilding(S), id))) {
                printf("Bangunan tersebut sudah menyerang dalam giliran ini!\n");
                pick = 0;   
            }
        }
    } while (pick <= 0 || pick > NBuild);
    id = LGetNthInfo(Buildings(P(S, PlayerID)), pick);

    HasAttacked(AElmt(ArrBuilding(S), id)) = true;
    
    printf("Daftar bangunan yang dapat diserang:\n");
    int NDegree = NeighbourDegree(G, id);
    PrintNeighbourBuilding(id);
    if (NDegree == 0) return;
    int pickAttack = 0;
    int idAttack = 0;
    do {
        printf("Bangunan yang diserang: ");
        InputInt(&pickAttack);
        if (pickAttack <= 0 || pickAttack > NDegree) {
            printf("Pilihan tidak valid.\n");
        }
    } while (pickAttack <= 0 || pickAttack > NDegree);
    idAttack = GGetNeighbourNthInfo(G, id, pickAttack);

    int ownerAttack = OwnerID(AElmt(ArrBuilding(S), idAttack));
    int atkTroop;
    do {
        printf("Jumlah Pasukan: ");
        InputInt(&atkTroop);
        if (atkTroop <= 0 || atkTroop > Troop(AElmt(ArrBuilding(S), id))) {
            printf("Jumlah pasukan tidak valid!\n");
        }
    } while (atkTroop <= 0 || atkTroop > Troop(AElmt(ArrBuilding(S), id)));

    Troop(AElmt(ArrBuilding(S), id)) -= atkTroop;

    int enemyTroop = Troop(AElmt(ArrBuilding(S), idAttack));
    float multiplier = GetMultiplier(idAttack, ownerAttack);

    int tmAtk = atkTroop*multiplier;
    if (tmAtk < enemyTroop) {
        Troop(AElmt(ArrBuilding(S), idAttack)) -= tmAtk;
        printf("Bangunan gagal direbut.\n");
    } else {
        int minToConquer = 0;
        for (int i = 1; i <= atkTroop; i++) {
            if (multiplier*i >= enemyTroop) {
                minToConquer = i;
                break;
            }
        }
        int survivingTroop = atkTroop - minToConquer;
        Troop(AElmt(ArrBuilding(S), idAttack)) = survivingTroop;
        ChangeBaseProperty(&AElmt(ArrBuilding(S), idAttack), GetBase(AElmt(ArrBuilding(S), idAttack), 1));

        int EnemyID = PlayerID % 2 + 1;
        if (OwnerID(AElmt(ArrBuilding(S), idAttack)) == EnemyID) {
            DelBuilding(&Buildings(P(S, EnemyID)), idAttack);
        }
        OwnerID(AElmt(ArrBuilding(S), idAttack)) = PlayerID;
        AddBuilding(&Buildings(P(S, PlayerID)), idAttack);
        
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
    int NBuild = NbElmt(Buildings(P(S, PlayerID)));
    do {
        printf("Bangunan yang akan di level up: ");
        InputInt(&pick);
        if (pick <= 0 || pick > NBuild) {
            printf("Pilihan tidak valid.\n");
        }
    } while (pick <= 0 || pick > NBuild);
    int id = LGetNthInfo(Buildings(P(S, PlayerID)), pick);
    LevelUpBuilding(&AElmt(ArrBuilding(S), id));
}

void Move(int PlayerID){
    PrintPlayerBuildings(PlayerID);
    int pick = 0;
    int NBuild = NbElmt(Buildings(P(S, PlayerID)));
    do {
        printf("Bangunan yang digunakan untuk mengirim pasukan: ");
        InputInt(&pick);
        if (pick <= 0 || pick > NBuild) {
            printf("Pilihan tidak valid.\n");
        }
    } while (pick <= 0 || pick > NBuild);
    int id = LGetNthInfo(Buildings(P(S, PlayerID)), pick);
    
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

    if (moveTroops > Troop(AElmt(ArrBuilding(S), id))){
        printf("Pasukan tidak cukup.\n");
    }
    else {
        int idTarget = GGetOurNthInfo(G, id, pickMove);
        Troop(AElmt(ArrBuilding(S), idTarget)) += moveTroops;
        Troop(AElmt(ArrBuilding(S), idTarget)) -= moveTroops;
        printf("%d pasukan dari ", moveTroops);
        PrintBuildingType(AElmt(ArrBuilding(S), id)); printf(" ");
        TulisPoint(Pos(AElmt(ArrBuilding(S), id)));
        printf(" telah berpindah ke ");
        PrintBuildingType(AElmt(ArrBuilding(S), idTarget)); printf(" ");
        TulisPoint(Pos(AElmt(ArrBuilding(S), idTarget)));
    }
}


void Skill(int PlayerID) {
    Kata cur = InfoHead(Skills(P(S, PlayerID)));
    if (QIsEmpty(Skills(P(S, PlayerID)))) {
        printf("You don't have any skills.\n");
    } else {
        if (EQKata(cur, InstantUpgrade)) {
            doInstantUpgrade(PlayerID);
        } else if (EQKata(cur, Shield)) {

        } else if (EQKata(cur, ExtraTurn)) {

        } else if (EQKata(cur, AttackUp)) {

        } else if (EQKata(cur, CriticalHit)) {

        } else if (EQKata(cur, InstantReinforcement)) {

        } else if (EQKata(cur, Barrage)) {

        }
        Del(&Skills(P(S, PlayerID)), &cur);
    }

}

void Undo() {
    if (SIsEmpty(UndoStack)) {
        printf("You can't undo now.\n");
    } else {
        SPop(&UndoStack, &S);
        printf("Undo succeeded.\n");
    }
}

void EndTurn(int PlayerID){
    // end turn kurang shield, dan update status player lain
    int enemyPlayerID = PlayerID % 2 + 1;
    if (PShield(P(S, enemyPlayerID)) > 0){
        PShield(P(S, enemyPlayerID)) --;
    }
    for (int i = 1; i <= ANbElmt(ArrBuilding(S)); i++) {
        Building *cur = &AElmt(ArrBuilding(S), i);
        if (OwnerID(*cur)) {
            if (HasAttacked(*cur)) {
                HasAttacked(*cur) = false;
            }
        }
    }
    CurPlayerID(S) = enemyPlayerID;
    RegenTroop();
    SCreateEmpty(&UndoStack);
}