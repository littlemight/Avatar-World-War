#include "skill.h"

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

// TAMBAH GET CRITICAL HIT DI SINI
void doExtraTurn(int PlayerID) {
    PTurn(P(S, PlayerID))++;
    getCriticalHit((PlayerID % 2) +1);
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
        cur = LNext(cur);
    }
    printf("The enemy took a big hit.\n");
    return;
}

void getShield(State SBef, State SNow){
    // klo stack kosong top nya null kah??
    if(LNbElmt(Buildings(P(SBef, 2)))==3 && LNbElmt(Buildings(P(SNow, 2)))==2){
        //push ke queue skill p2
        QAdd(&(Skills(P(S, 2))), Shield);
        printf("Selamat "); PrintKata(Username(P(SNow, 2))); printf(" mendapat skill Shield!!\n");
    }
    if(LNbElmt(Buildings(P(SBef, 1)))==3 && LNbElmt(Buildings(P(SNow, 1)))==2){
        //push ke queue skill p1
        QAdd(&(Skills(P(S, 1))), Shield);
        printf("Selamat "); PrintKata(Username(P(SNow, 1))); printf(" mendapat skill Shield!!\n");
    }
    return;
}

void getAttackUp(State SBef, State SNow){
    int cnt1 = 0,  cnt2 = 0;
    addressList aL = LFirst(Buildings(P(SNow, 1)));
    while(aL != NilList){
        if(Type(AElmt(ArrBuilding(SNow), LInfo(aL)))=='T') cnt1++;
        aL = LNext(aL);
    }
    aL = LFirst(Buildings(P(SBef, 1)));
    while(aL != NilList){
        if(Type(AElmt(ArrBuilding(SBef), LInfo(aL)))=='T') cnt2++;
        aL = LNext(aL);
    }
    if(cnt1 == 3 && cnt2 ==2){
        QAdd(&(Skills(P(S, 1))), AttackUp);
        printf("Selamat "); PrintKata(Username(P(SNow, 1))); printf(" mendapat skill Attack Up!!\n");
    }
    aL = LFirst(Buildings(P(SNow, 2)));
    while(aL != NilList){
        if(Type(AElmt(ArrBuilding(SNow), LInfo(aL)))=='T') cnt1++;
        aL = LNext(aL);
    }
    aL = LFirst(Buildings(P(SBef, 2)));
    while(aL != NilList){
        if(Type(AElmt(ArrBuilding(SBef), LInfo(aL)))=='T') cnt2++;
        aL = LNext(aL);
    }
    if(cnt1 == 3 && cnt2 ==2){
        QAdd(&(Skills(P(S, 2))), AttackUp);
        printf("Selamat "); PrintKata(Username(P(SNow, 2))); printf(" mendapat skill Attack Up!!\n");
    }
    return;
}

void getBarrage(State SBef, State SNow){
    if(LNbElmt(Buildings(P(SBef, 2)))==9 && LNbElmt(Buildings(P(SNow, 2)))==10){
        //push ke queue skill p1
        QAdd(&(Skills(P(S, 1))), Barrage);
        printf("Selamat "); PrintKata(Username(P(SNow, 1))); printf(" mendapat skill Barrage!!\n");
    }
    if(LNbElmt(Buildings(P(SBef, 1)))==9 && LNbElmt(Buildings(P(SNow, 1)))==10){
        //push ke queue skill p2
        QAdd(&(Skills(P(S, 2))), Barrage);
        printf("Selamat "); PrintKata(Username(P(SNow, 2))); printf(" mendapat skill Barrage!!\n");
    }
    return;
}

void getInstantReinforcement(State SNow){
    addressList aL;
    boolean b;
    if(!LIsEmpty(Buildings(P(SNow, 2)))){
        b = true;
        aL = LFirst(Buildings(P(SNow, 2)));
        while(b && aL != NilList){
            b = Level(AElmt(ArrBuilding(SNow), LInfo(aL))) == 4;  
            aL = LNext(aL);
        }
        if(b){
            //push skill ke p2
            QAdd(&(Skills(P(S, 2))), InstantReinforcement);
            printf("Selamat "); PrintKata(Username(P(SNow, 2))); printf(" mendapat skill Instant Reinforcement!!\n");
        }
    }
    if(!LIsEmpty(Buildings(P(SNow, 1)))){
        b = true;
        aL = LFirst(Buildings(P(SNow, 1)));
        while(b && aL != NilList){
            b = Level(AElmt(ArrBuilding(SNow), LInfo(aL))) == 4;  
            aL = LNext(aL);
        }
        if(b){
            //push skill ke p1
            QAdd(&(Skills(P(S, 1))), InstantReinforcement);
            printf("Selamat "); PrintKata(Username(P(SNow, 1))); printf(" mendapat skill Instant Reinforcement!!\n");
        }
    }
    return;
}

void getExtraTurn(State SBef, State SNow){
    addressList aL;
    if(!LIsEmpty(Buildings(P(S, 2)))){
        aL = LLastElmt(Buildings(P(SNow, 2)));
        if(Type(AElmt(ArrBuilding(SNow), LInfo(aL)))=='F' && Search(Buildings(P(SBef, 1)), LInfo(aL))!=NilList){
            //push skill ke p1
            QAdd(&(Skills(P(S, 1))), ExtraTurn);
            printf("Selamat "); PrintKata(Username(P(S, 1))); printf(" mendapat skill Extra Turn!!\n");
        }
    }
    if(!LIsEmpty(Buildings(P(S, 1)))){
        aL = LLastElmt(Buildings(P(SNow, 1)));
        if(Type(AElmt(ArrBuilding(SNow), LInfo(aL)))=='F' && Search(Buildings(P(SBef, 2)), LInfo(aL))!=NilList){
            //push skill ke p2
            QAdd(&(Skills(P(S, 2))), ExtraTurn);
            printf("Selamat "); PrintKata(Username(P(S, 2))); printf(" mendapat skill Extra Turn!!\n");
        }
    }
    return;
}

void getCriticalHit(int PlayerID){
    QAdd(&(Skills(P(S, PlayerID))), CriticalHit);
}
    /*if(PTurn(P(SBef, 1))<PTurn(P(SNow, 1)) && CurPlayerID(SBef) == CurPlayerID(SNow)){
        // //push skill ke p2
        QAdd(&(Skills(P(S, 2))), CriticalHit);
        printf("Selamat "); PrintKata(Username(P(S, 2))); printf(" mendapat skill Critical Hit!!\n");
    }
    if(PTurn(P(SBef, 2))<PTurn(P(SNow, 2)) && CurPlayerID(SBef) == CurPlayerID(SNow)){
        // //push skill ke p1
        QAdd(&(Skills(P(S, 1))), CriticalHit);
       printf("Selamat "); PrintKata(Username(P(S, 1))); printf(" mendapat skill Critical Hit!!\n");
    }*/

void getSkills(State SBef, State SNow){
    getShield(SBef, SNow);
    getAttackUp(SBef, SNow);
    getBarrage(SBef, SNow);
    getExtraTurn(SBef, SNow);
}
/* Ambigu :
  > Instart Reinf. itu setiap turn ada player yg lv 4 semua buildnya? -> maybe checking ny acuma diakhir turn aja (?) bukan per aksi
  > extraturn termasuk bisa di undo ke sebelum ny aapa engga
   ( corner case pas extra turn trus aktifin skill extraturn lagi)
  > 

  > Sistematika urutan nge add skill 

*/
