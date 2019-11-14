// #ifndef LIBRARY_H
// #define LIBRARY_H

#include "adt/building.h"
#include "adt/player.h"
#include "adt/arraydin.h"
#include "adt/graph.h"
#include "adt/matrix.h"
#include "pcolor.h"
#include "utility.h"

extern Building CASTLE[5];
extern Building TOWER[5];
extern Building FORT[5];
extern Building VILLAGE[5];

extern TabBuilding ArrBuilding;
extern Matrix Peta;
extern Graph G;
extern Player P[3];
extern boolean hasAttacked[605];
extern int N, M, B, curPlayerID;

// /** ======================================== SETUPS  ========================================  **/
void MakeAllBase();

Building GetBase(Building B, int Level);

void LoadInit();
/** ======================================== ----  ========================================  **/

/** ======================================== PRINT  ========================================  **/
void PrintPeta();

void PrintPlayerBuildings(int curPlayerID);

void PrintNeighbourBuilding(int BuildID);

void PrintOurBuilding(int BuildID); // mencetak building yang tetangga dan sama ownership

/** ======================================== ----  ========================================  **/

/** ======================================== NEIGHBOURHOOD TOOLS  ========================================  **/
int GGetNeighbourNthInfo(Graph G, infotypeGraph X, int n);

int GGetOurNthInfo(Graph G, infotypeGraph X, int n);

int NeighbourDegree(Graph G, infotypeGraph X);

int OurDegree(Graph G, infotypeGraph X);
/** ======================================== ----  ========================================  **/

/** ======================================== MEKANISME  ========================================  **/
void RegenTroop();
// }
// /** ======================================== ----  ========================================  **/

// /** ======================================== SKILL  ========================================  **/


// // void GetSkill(Player * P1, Player * P2){ //ngecek apakah dapet skill di akhir tiap move
// //     if(NbElmt(P2->Buildings == 2)){

// //     }
// //     if(){

// //     } 
// // }

// // void DoSkill(char* Cur, int curPlayerID) {
// //     if (Cur == InstantUpgrade)
// //     DoInstantUpgrade(curPlayerID);
// //     else if (Cur == Shield)
// //         DoShield(curPlayerID);
// //     else if (Cur ==  ExtraTurn)
// //         DoExtraTurn(curPlayerID);
// //     else if (Cur ==  AttackUp)
// //         DoAttackUp(curPlayerID);
// //     else if (Cur ==  CriticalHit)
// //         DoCriticalHit(curPlayerID);
// //     else if (Cur ==  InstantReinforcement)
// //         DoInstantReinforcement();
// //     else if (Cur ==  CriticalHit)
// //         DoCriticalHit();
// //     else if (Cur == InstantReinforcement)
// //         DoInstantReinforcement();
// //     else if (Cur == Barrage)
// //         DoBarrage();
// // }
// #endif