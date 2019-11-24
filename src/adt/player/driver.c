#include "player.h"

int main(){
    STARTKATA(0);
    
	Player P1, P2;
    Kata username, skill;
    PCreateEmpty(&P1);
    PCreateEmpty(&P2);

    InputKata(&username);
    CopyKata(username, &Username(P1));
    
    Kata InstantUpgrade;
    CopyKata(StrToKata("IU"), &InstantUpgrade);
    QAdd(&Skills(P1), InstantUpgrade);
    
    for (int i = 1; i <= 3; i++){
        AddBuilding(&Buildings(P1), i);
    }

    CopyPlayer(P1, &P2);

    printf("\nUsername player 1: ");
    PrintKata(Username(P1));
    
    printf("\nUsername player 2 (hasil copy player 1): ");
    PrintKata(Username(P2));

    QDel(&Skills(P1), &skill);
    printf("\n\nSkill yang dimiliki player 1: ");
    PrintKata(skill);

    QDel(&Skills(P2), &skill);
    printf("\nSkill yang dimiliki player 2 (hasil copy player 2): ");
    PrintKata(skill);

    printf("\n\nBuilding player 1: \n");
    PrintInfo(Buildings(P1));
    printf("\n\nBuilding player 2 (hasil copy player 1): \n");
    PrintInfo(Buildings(P2));
    printf("\n");

    return 0;
}