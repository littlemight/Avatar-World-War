#include "skill.h"

// Do Skill
void doInstantUpgrade(int PlayerID) {
    addressList cur = LFirst(Buildings(P(S, PlayerID)));
    while (cur != NilList) {
        Building *ref = &AElmt(ArrBuilding(S), LInfo(cur));
        if (Level(*ref) + 1 <= 4) {
            ChangeBaseProperty(ref, GetBase(*ref, Level(*ref) + 1));
        }
        cur = LNext(cur);
    }
    printf("All of your buildings have been leveled up!\n");
    return;
}

void doShield(int PlayerID) {
    if (PShield(P(S, PlayerID)) != 0) {
        printf("Your shield duration have been maxed out\n");
    } else {
        printf("You now have shield!\n");    
    }
    PShield(P(S, PlayerID)) = 2;
    return;
}

void doExtraTurn(int PlayerID) {
    PTurn(P(S, PlayerID))++;
    printf("You have 1 more extra turn.\n");
    getCriticalHit((PlayerID % 2) +1);
    return;
}

void doAttackUp(int PlayerID) {
    PAttackUp(P(S, PlayerID)) = true;
    printf("You now have Attack Up!\n");
    return;
}

void doCriticalHit(int PlayerID) {
    PCriticalHit(P(S, PlayerID)) = true;
    printf("You now have Critical Hit!\n");
    return;
}

void doInstantReinforcement(int PlayerID) {
    addressList cur = LFirst(Buildings(P(S, PlayerID)));
    while (cur != NilList) {
        Troop(AElmt(ArrBuilding(S), LInfo(cur))) += 5;
        cur = LNext(cur);
    }
    printf("All of your buildings now have 5 more troops!\n");
    return;
}

void doBarrage(int PlayerID) {
    int EnemyID = PlayerID % 2+ 1;
    addressList cur = LFirst(Buildings(P(S, EnemyID)));
    while (cur != NilList) {
        Building *ref = &AElmt(ArrBuilding(S), LInfo(cur));
        Troop(*ref) -= 10;
        if (Troop(*ref) < 0) {
            Troop(*ref) = 0;
        }
        cur = LNext(cur);
    }
    printf("The enemy took a big hit.\n");
    return;
}


// Get Skill
void getShield(State SBef, State SNow){
    int getID = CurPlayerID(SNow) % 2 + 1; 
    if(LNbElmt(Buildings(P(SBef, getID)))==3 && LNbElmt(Buildings(P(SNow, getID)))==2){
        QAdd(&(Skills(P(S, getID))), Shield);
        PrintKata(Username(P(SNow, getID))); printf(" got "); reverse(); printf("[SHIELD]"); normal(); printf("\n");
    }
    return;
}

void getAttackUp(State SBef, State SNow){
    int curAfter = 0,  curBef = 0;
    int curID = CurPlayerID(SNow);
    int enemyID = curID % 2 + 1;
    addressList aL = LFirst(Buildings(P(SNow, curID)));
    while(aL != NilList){
        if(Type(AElmt(ArrBuilding(SNow), LInfo(aL)))=='T' && OwnerID(AElmt(ArrBuilding(SNow), LInfo(aL))) == curID) curAfter++;
        aL = LNext(aL);
    }
    aL = LFirst(Buildings(P(SBef, curID)));
    while(aL != NilList){
        if(Type(AElmt(ArrBuilding(SBef), LInfo(aL)))=='T' && OwnerID(AElmt(ArrBuilding(SBef), LInfo(aL))) == curID) curBef++;
        aL = LNext(aL);
    }

    int enemyAfter = 0, enemyBef = 0;
    aL = LFirst(Buildings(P(SNow, enemyID)));
    while(aL != NilList){
        if(Type(AElmt(ArrBuilding(SNow), LInfo(aL)))=='T' && OwnerID(AElmt(ArrBuilding(SNow), LInfo(aL))) == enemyID) enemyAfter++;
        aL = LNext(aL);
    }

    aL = LFirst(Buildings(P(SBef, enemyID)));
    while(aL != NilList){
        if(Type(AElmt(ArrBuilding(SBef), LInfo(aL)))=='T' && OwnerID(AElmt(ArrBuilding(SBef), LInfo(aL))) == enemyID) enemyBef++;
        aL = LNext(aL);
    }

    if(curBef == 2 && curAfter == 3 && ((enemyAfter - enemyBef) == -1)){
        QAdd(&(Skills(P(S, curID))), AttackUp);
        PrintKata(Username(P(SNow, curID))); printf(" got "); reverse(); printf("[ATTACK UP]"); normal(); printf("\n");
    }
    return;
}

void getBarrage(State SBef, State SNow){
    int curID = CurPlayerID(S);
    int getID = curID % 2 + 1;
    if(LNbElmt(Buildings(P(SBef, curID)))==9 && LNbElmt(Buildings(P(SNow, curID)))==10){
        //push ke queue skill p1
        QAdd(&(Skills(P(S, getID))), Barrage);
        if (getID == 1) blue();
        else red();
        PrintKata(Username(P(SNow, getID))); normal(); printf(" got "); reverse(); printf("[BARRAGE]"); normal(); printf("\n");
    }
    return;
}

void getInstantReinforcement(State SNow){
    addressList aL;
    boolean b;
    int curID = CurPlayerID(S);
    if(!LIsEmpty(Buildings(P(SNow, curID)))){
        b = true;
        aL = LFirst(Buildings(P(SNow, curID)));
        while(b && aL != NilList){
            b = (Level(AElmt(ArrBuilding(SNow), LInfo(aL))) == 4);  
            aL = LNext(aL);
        }
        if(b){
            //push skill ke p2
            if (!QIsFull(Skills(P(S, curID)))) {
                QAdd(&(Skills(P(S, curID))), InstantReinforcement);
                if (curID == 1) blue(); else red();
                PrintKata(Username(P(SNow, curID))); normal();
                printf(" got "); reverse(); printf("[INSTANT REINFORCEMENT]"); normal(); printf("\n");
            }
        }
    }
    return;
}

void getExtraTurn(State SBef, State SNow){
    addressList aL;
    int curID = CurPlayerID(S);
    int getID = curID % 2 + 1;
    aL = LLastElmt(Buildings(P(SNow, curID)));
    int buildID = LInfo(aL);
    if(Type(AElmt(ArrBuilding(SNow), buildID)) == 'F' && OwnerID(AElmt(ArrBuilding(SBef), buildID)) == getID){
        //push skill ke p1
        if (!QIsFull(Skills(P(S, getID)))) {
            QAdd(&(Skills(P(S, getID))), ExtraTurn);
            if (getID == 1) blue(); else red();
            PrintKata(Username(P(S, getID))); normal(); printf(" got "); reverse(); printf("[EXTRA TURN]"); normal(); printf("\n");
        }
    }
    return;
}

void getCriticalHit(int PlayerID){
    if (!QIsFull(Skills(P(S, PlayerID)))) {
        QAdd(&(Skills(P(S, PlayerID))), CriticalHit);
        if (PlayerID == 1) blue();
        else red();
        PrintKata(Username(P(S, PlayerID))); normal(); printf(" got "); reverse(); printf("[CRITICAL HIT]"); normal(); printf("\n");
    }
}

void getSkills(State SBef, State SNow){
    getShield(SBef, SNow);
    getAttackUp(SBef, SNow);
    getBarrage(SBef, SNow);
    getExtraTurn(SBef, SNow);
}
