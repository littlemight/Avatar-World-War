#include "../command/command.h"
#include "../skill/skill.h"

float GetMultiplier(int idAttack, int ownerAttack) {
    float multiplier = 1;
    if (Defense(AElmt(ArrBuilding(S), idAttack)) || PShield(P(S, ownerAttack))) {
        multiplier = 0.75;
    }

    if (PAttackUp(P(S, CurPlayerID(S)))) {
        multiplier = 1;
    }
    if (PCriticalHit(P(S, CurPlayerID(S)))) {
        multiplier = 2;
        PCriticalHit(P(S, CurPlayerID(S))) = false;
    }
    return multiplier;
}

int Attack(int PlayerID) {
    PrintPlayerBuildings(PlayerID);
    int pick = 0;
    int id = 0;
    int NBuild = LNbElmt(Buildings(P(S, PlayerID)));
    printf("ATTACKER: ");
    InputInt(&pick);
    if (pick <= 0 || pick > NBuild) {
        printf("Invalid input.\n");
        return 1;
    } else {
        id = LGetNthInfo(Buildings(P(S, PlayerID)), pick);
        if (HasAttacked(AElmt(ArrBuilding(S), id))) {
            printf("That building has already attacked this turn.\n");
            return 1;
        }
    }
    id = LGetNthInfo(Buildings(P(S, PlayerID)), pick);
    

    clear();
    PrintPetaAttackable(id);
    int NDegree = NeighbourDegree(G, id);
    printf("ATTACKABLE:\n");
    if (NDegree == 0) {
        reverse(); printf("NONE"); normal();
        printf("\n");
        return 1;
    }
    PrintNeighbourBuilding(id);
    int pickAttack = 0;
    int idAttack = 0;

    printf("BUILDING TO ATTACK: ");
    InputInt(&pickAttack);
    if (pickAttack <= 0 || pickAttack > NDegree) {
        printf("Invalid input.\n");
        return 1;
    }
    
    idAttack = GGetNeighbourNthInfo(G, id, pickAttack);

    int ownerAttack = OwnerID(AElmt(ArrBuilding(S), idAttack));
    int atkTroop;
    
    printf("TROOPS ADVANCED [Max %d]: ", Troop(AElmt(ArrBuilding(S), id)));
    InputInt(&atkTroop);
    if (atkTroop <= 0 || atkTroop > Troop(AElmt(ArrBuilding(S), id))) {
        printf("Invalid input.\n");
        return 1;
    }
    
    HasAttacked(AElmt(ArrBuilding(S), id)) = true;
    Troop(AElmt(ArrBuilding(S), id)) -= atkTroop;

    int enemyTroop = Troop(AElmt(ArrBuilding(S), idAttack));
    float multiplier = GetMultiplier(idAttack, ownerAttack);

    int tmAtk = atkTroop*multiplier;
    if (tmAtk < enemyTroop) {
        Troop(AElmt(ArrBuilding(S), idAttack)) -= tmAtk;
        printf("Failed to conquer.\n");
        return 0;
    } else {
        int minToConquer = 0;
        for (int i = 0; i <= atkTroop; i++) {
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
        
        HasAttacked(AElmt(ArrBuilding(S), id)) = true;
        reverse(); printf("CONQUERED."); normal();
        return 0;
    }
}


int LevelUpBuilding(Building * B){
    int minToLevelUp = MaxCap(*B) / 2;
    if(Troop(*B) >= minToLevelUp && Level(*B) < 4){
        Troop(*B) -= minToLevelUp;
        ChangeBaseProperty(B, GetBase(*B, Level(*B) + 1));
        reverse(); printf("BUILDING LEVELED UP TO LEVEL %d", Level(*B)); normal();
        printf("\n");
        return 0;
    } else {
        if (Level(*B) < 4) {
            reverse(); printf("INSUFFICIENT TROOPS"); normal();
            printf("\n");
        } else {
            reverse(); printf("MAXED"); normal();
            printf("\n");
        }
        return 1;
    }
}

int LevelUp(int PlayerID){
    PrintPlayerBuildings(PlayerID);
    int pick = 0;
    int NBuild = LNbElmt(Buildings(P(S, PlayerID)));
    printf("BUILDING TO LEVEL UP: ");
    InputInt(&pick);
    if (pick <= 0 || pick > NBuild) {
        printf("Invalid input.\n");
        return 1;
    }
    int id = LGetNthInfo(Buildings(P(S, PlayerID)), pick);
    return LevelUpBuilding(&AElmt(ArrBuilding(S), id));
}

int Move(int PlayerID){
    PrintPlayerBuildings(PlayerID);
    int pick = 0;
    int id = 0;
    int NBuild = LNbElmt(Buildings(P(S, PlayerID)));

    printf("SENDER: ");
    InputInt(&pick);
    if (pick <= 0 || pick > NBuild) {
        printf("Invalid input.\n");
        return 1;
    }
    else {
        id = LGetNthInfo(Buildings(P(S, PlayerID)), pick);
        if (HasMoved(AElmt(ArrBuilding(S), id))) {
            printf("That building has already moved its troops this turn.\n");
            return 1;
        }
    }
    id = LGetNthInfo(Buildings(P(S, PlayerID)), pick);

    clear();
    PrintPetaMoveable(id);
    printf("REACHABLE:\n");
    int NDegree = OurDegree(G, id);
    if (NDegree == 0) {
        reverse(); printf("NONE"); normal();
        return 1;
    }
    PrintOurBuilding(id);
    int pickMove = 0;
    int moveTroops = 0;

    printf("RECEIVER: ");
    InputInt(&pickMove);
    if (pickMove <= 0 || pickMove > NDegree ) {
        printf("Invalid input.\n");
        return 1;
    }
    
    printf("TROOPS MOVED [Max %d]: ", Troop(AElmt(ArrBuilding(S), id)));

    InputInt(&moveTroops);
    if (moveTroops > Troop(AElmt(ArrBuilding(S), id)) || moveTroops <= 0){
        printf("Invalid input.\n");
        return 1;
    }
    else {
        int idTarget = GGetOurNthInfo(G, id, pickMove);
        Troop(AElmt(ArrBuilding(S), idTarget)) += moveTroops;
        Troop(AElmt(ArrBuilding(S), id)) -= moveTroops;
        printf("%d TROOP(S) SENT\n", moveTroops);
    }
    HasMoved(AElmt(ArrBuilding(S), id)) = true;
    return 0;
}


int Skill(int PlayerID) {
    if (QIsEmpty(Skills(P(S, PlayerID)))) {
        printf("You don't have any skills.\n");
        return 1;
    } else {
        Kata cur;
        QDel(&Skills(P(S, PlayerID)), &cur);
        if (EQKata(cur, InstantUpgrade)) {
            doInstantUpgrade(PlayerID);
        } else if (EQKata(cur, Shield)) {
            doShield(PlayerID);
        } else if (EQKata(cur, ExtraTurn)) {
            doExtraTurn(PlayerID);
        } else if (EQKata(cur, AttackUp)) {
            doAttackUp(PlayerID);
        } else if (EQKata(cur, CriticalHit)) {
            doCriticalHit(PlayerID);
        } else if (EQKata(cur, InstantReinforcement)) {
            doInstantReinforcement(PlayerID);
        } else if (EQKata(cur, Barrage)) {
            doBarrage(PlayerID);
        }
        return 0;
    }

}

void Undo() {
    if (SIsEmpty(UndoStack)) {
        printf("You can't undo now.\n");
    } else {
        SPush(&RedoStack, S);
        SPop(&UndoStack, &S);
        reverse(); printf("UNDO SUCCEEDED"); normal();
        printf("\n");
    }
}

void Redo() {
    if (SIsEmpty(RedoStack)) {
        printf("You can't redo now.\n");
    } else {
        SPush(&UndoStack, S);
        SPop(&RedoStack, &S);
        reverse(); printf("REDO SUCCEEDED\n"); normal();
        printf("\n");
    }
}

int GetLoadedFilename(char* filename) {
    FILE* file;
    int sz = 0;

    file = fopen("data/info.dat", "r");
    if (file) {
        STARTKATA("data/info.dat");
        InputInt(&sz);
        TOSTDIN();
    }
    if (sz == 0) {
        printf("No saved files found.\n");
        return 1;
    } else {
        STARTKATA("data/savelist.dat");
        Kata arrKata[sz + 1];
        for (int i = 1; i <= sz; i++) {
            InputKata(&arrKata[i]);
        }
        TOSTDIN();

        printf("%d saved files found.\n", sz);
        for (int i = 1; i <= sz; i++) {
            printf("%d. ", i); PrintKata(arrKata[i]); printf("\n");
        }
        printf("Choose file number to load: ");
        int pick;
        InputInt(&pick);
        if (pick <= 0 || pick > sz) {
            printf("Invalid file number\n.");
            return 1;
        } else {
            Kata dir; CopyKata(StrToKata("data/save/"), &dir);
            Kata ext; CopyKata(StrToKata(".dat"), &ext);
            Kata completeDir;
            ConcatKata(dir, arrKata[pick], &completeDir);
            ConcatKata(completeDir, ext, &completeDir);
            KataToArrChar(completeDir, filename);
            return 0;
        }
    }
}

int Load() {
    char filename[50];
    if (GetLoadedFilename(filename) == 0) {
        STARTKATA(filename);
        LoadSaved();
        TOSTDIN();
        printf("File loaded\n");
        return 0;
    } else {
        return 1;
    }
}

void GetSavedFilename(char* filename, char* nameOnly) {
  printf("Input file name, without spaces and without extension, maximum 30 characters\n");
  printf(">>> ");
  Kata saved; InputKata(&saved); KataToArrChar(saved, nameOnly);
  Kata dir; CopyKata(StrToKata("data/save/"), &dir);
  Kata ext; CopyKata(StrToKata(".dat"), &ext);
  Kata completeDir;
  ConcatKata(dir, saved, &completeDir);
  ConcatKata(completeDir, ext, &completeDir);
  KataToArrChar(completeDir, filename);
}

void AddSavedFilename(char* nameOnly) {
    FILE* file;
    int sz = 0;

    // add size of save file list
    file = fopen("data/info.dat", "r");
    if (file) {
        fscanf(file, "%d", &sz);
        fclose(file);
    }
    sz++;
    file = fopen("data/info.dat", "w");
    fprintf(file, "%d\n", sz);
    fclose(file);

    // append new file name to list
    file = fopen("data/savelist.dat", "a+");
    fprintf(file, "%s\n", nameOnly);
    fclose(file);
}

void Save() {
    clear();
    char filename[50], nameOnly[50]; 
    GetSavedFilename(filename, nameOnly);
    FILE *file = fopen(filename, "r");
    if (file) { // if file already exist
        printf("Saved data already exist, replace? (Y)\n");
        printf(">>> ");
        Kata query;
        InputKata(&query);
        if (EQKata(query, StrToKata("Y"))) {
            fclose(file);
            file = fopen(filename, "w");
            SavePrintGame(file, Peta, AdjMat, S, UndoStack);
            printf("Game saved\n");
        } else {
            printf("Save cancelled.\n");
        }
    } else { // no saved file with same name
        fclose(file);
        AddSavedFilename(nameOnly);
        file = fopen(filename, "w");
        SavePrintGame(file, Peta, AdjMat, S, UndoStack);
        printf("Game saved\n");
    }
}


void EndTurn(int PlayerID){
    PTurn(P(S, PlayerID))--;
    int CurPlayerID = 0;
    if (PTurn(P(S, PlayerID)) == 0) {
        int EnemyPlayerID = PlayerID % 2 + 1;
        PTurn(P(S, EnemyPlayerID)) = 1;
        if (PShield(P(S, EnemyPlayerID)) > 0){
            PShield(P(S, EnemyPlayerID))--;
        }
        CurPlayerID = EnemyPlayerID;
    } else {
        CurPlayerID = PlayerID;
    }
    
    for (int i = 1; i <= ANbElmt(ArrBuilding(S)); i++) {
        Building *cur = &AElmt(ArrBuilding(S), i);
        if (OwnerID(*cur) == PlayerID) {
            if (HasAttacked(*cur)) {
                HasAttacked(*cur) = false;
            }
            if (HasMoved(*cur)) {
                HasMoved(*cur) = false;
            }
        }
    }
    if (PAttackUp(P(S, CurPlayerID(S)))) {
        PAttackUp(P(S, CurPlayerID(S))) = false;
    }
    CurPlayerID(S) = CurPlayerID;
    RegenTroop();
    SCreateEmpty(&UndoStack);
    SCreateEmpty(&RedoStack);
    reverse(); printf("TURN ENDED"); normal(); ADV();
}