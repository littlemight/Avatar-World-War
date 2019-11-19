#ifndef SKILL_H
#define SKILL_H

#include "library.h"

void doInstantUpgrade(int PlayerID);
void doShield(int PlayerID);
void doExtraTurn(int PlayerID);
void doAttackUp(int PlayerID);
void doCriticalHit(int PlayerID);
void doInstantReinforcement(int PlayerID);
void doBarrage(int PlayerID);

void getShield(State SBef, State SNow);
void getAttackUp(State SBef, State SNow);
void getBarrage(State SBef, State SNow);
void getInstantReinforcement(State SNow);
void getExtraTurn(State SBef, State SNow);
void getCriticalHit(State SBef, State SNow);

void getSkills(State SBef, State SNow);

#endif