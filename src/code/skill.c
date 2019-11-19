#include "../header/skill.h"
#include "../header/library.h"

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
    }
    printf("The enemy took a big hit.\n");
    return;
}