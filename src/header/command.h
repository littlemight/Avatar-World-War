#ifndef COMMAND_H
#define COMMAND_H

#include "library.h"

float GetMultiplier(int idAttack, int ownerAttack);
void Attack(int PlayerID);
void LevelUpBuilding(Building *B);
void LevelUp(int PlayerID);
void Move(int PlayerID);
void EndTurn(int PlayerID);

#endif