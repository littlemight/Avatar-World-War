#include <bits/stdc++.h>
using namespace std;

/** ======================================== BOOLEAN ========================================  **/
#include "boolean.h"
/** ================================================================================ **/

/** ======================================== COLORS ========================================  **/
#include "pcolor.h"
/** ================================================================================ **/

/** ======================================== POINT ========================================  **/
#include "point.h"
/** ================================================================================ **/

/** ======================================== BUILDING ========================================  **/
#include "building.h"
/** ================================================================================ **/

/** ======================================== LIST ========================================  **/
#include "list.h"
/** ================================================================================ **/

/** ======================================== PLAYER ========================================  **/
typedef struct {
  /**
   * Queue Skill
   * List Bangunan
   * 
   * --- SKILL ---
   * SHIELD DURATION
   * EXTRA TURN DURATION
   * HAS ATTACK UP?
   * HAS CRITICAL HIT?
   * */
  queue<string> Skill;
  List ListBuildID;
} Player;

#define ListBuildID(P) (P).ListBuildID

void AddBuilding(Player *P, Building B) {
  InsVLast(&ListBuildID(*P), B.ID);  
}
/** ================================================================================ **/

/** ======================================== SKILL ========================================  **/
void InstantUpgrade(int Player) { 
/** INSTANT UPGRADE
 * Seluruh bangunan yang dimiliki Player naik 1 level
 * Hanya didapat dari daftar skill awal
 * */
  for (int i = 1; i <= B; i++) {
    if (ListBuilding[i].Owner == Player) {
      if (ListBuilding[i].Level < 4) {
        ChangeBaseProperty(&ListBuilding[i], GetBase(ListBuilding[i], ListBuilding[i].Level + 1));
      }
    } 
  }
}
/** ================================================================================ **/


/** ======================================== GRAPH ========================================  **/
typedef vector<int> Graph;
/** ================================================================================ **/

/** ======================================== KAMUS ========================================  **/
const int NMAX = 600;
const int RMAX = 20;
const int CMAX = 30;
const int RMIN = 10;
const int CMIN = 10;

Building ListBuilding[NMAX + 1];
Graph adj[NMAX];
int N, M, B;
int Peta[RMAX + 1][CMAX + 1];
/** ================================================================================ **/

/** ======================================== INIT ========================================  **/
void LoadInit() {
  cin >> N >> M;
  cin >> B;
  for (int i = 1; i <= B; i++) {
    int owner = i;
    if (i > 2) owner = 0;
    char type; int r, c;
    cin >> type >> r >> c;
    POINT pos;
    pos = MakePOINT(r, c);
    Building base;
    switch (type) {
      case 'C':
        base = CASTLE[1];
        break;
      case 'T':
        base = TOWER[1];
        break;
      case 'F':
        base = FORT[1];
        break;
      case 'V':
        base = VILLAGE[1];
    }
    MakeBuilding(&ListBuilding[i], base, owner, pos, i);
    Peta[Absis(pos)][Ordinat(pos)] = i;
  }

  for (int i = 1; i <= B; i++) {
    for (int j = 1; j <= B; j++) {
      int x;
      cin >> x;
      if (x == 1) {
        adj[i].push_back(j);
      }
    }
  }
}

void PrintBuilding(Building B) {
  switch (B.Type) {
    case 'C':
      printf("Castle ");
      break;
    case 'T':
      printf("Tower ");
      break;
    case 'F':
      printf("Fort ");
      break;
    case 'V':
      printf("Village ");
      break;
    // default:
    //  printf("%c ", B.Type);
    //  break;
  }
  TulisPOINT(B.Pos);
  printf(" %d lv. %d\n", B.Troop, B.Level);
}
/** ================================================================================ **/

/** ======================================== PETA ========================================  **/
void PrintPeta() {
  for (int i = 0; i <= N + 1; i++) {
    for (int j = 0; j <= M + 1; j++) {
      if (i == 0 || j == 0 || i == N + 1 || j == M + 1) {
        printf("*");
        continue;
      }
      if (Peta[i][j] == 0) {
        printf(" ");
      } else {
        switch (ListBuilding[Peta[i][j]].Owner) {
          case 0:
            printf("%c", ListBuilding[Peta[i][j]].Type);
            break;
          case 1:
            print_blue(ListBuilding[Peta[i][j]].Type);
            break;
          case 2:
            print_red(ListBuilding[Peta[i][j]].Type);
            break;
        }
      }
    }
    printf("\n");
  }
}
/** ================================================================================ **/

int main() {
  MakeAllBase();
  LoadInit();
  for (int i = 1; i <= B; i++) {
    printf("%d. ",i);
    PrintBuilding(ListBuilding[i]);
  }
  PrintPeta();
  return 0;
}