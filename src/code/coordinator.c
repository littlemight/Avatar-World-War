#include "../header/coordinator.h"
#include "../header/utility.h"

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