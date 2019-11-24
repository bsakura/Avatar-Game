#ifndef player_H
#define player_H

#include "../boolean/boolean.h"
#include "../console/console.h"
#include "../queue/queue.h"

typedef struct  
{
    int number;
    Queue skill;
    boolean atk_up;
    boolean crit;
    int shield;
}Player;

#define number(P) (P).number
#define skill(P) (P).skill
#define atk(P) (P).atk_up
#define crit(P) (P).crit
#define shield(P) (P).shield

extern Player Player1, Player2;
void MakePlayer(Player *P, int X);
/*I.S: X = 1 || X=2
  F.S: Player baru dibuat.*/

void Setskill(Player *P, Queue skill);
/*I.S: Sembarang
  F.S: Menentukan skill player.*/

void Setatk(Player *P, boolean atk);
/*I.S: Sembarang
  F.S: Menentukan atk player.*/

boolean IsAtk(Player P);
/*Input: Player
  Output Boolean true jika atk.*/

boolean IsAtkP(int X);
/*Input: integer X = 1 || X=2
  Output: Booeln true jika...*/

void Setcrit(Player *P, boolean crit);
/*I.S: Sembarang
  F.S: Menetapkan critical.*/
boolean IsCrit(Player P);
/*Input: player
  Output: Boolean true jika critical.*/

boolean IsCritP(int X);
/*Input: integer X = 1 || X=2
  Output: Boolean true jika ...*/

void Setshield(Player *P, int S);
/*I.S: Sembarang
  F.S: Shield ditentukan.*/
int getShield(int X);
/*Input: integer X = 1 || X=2
  Output: integer*/

void CopyPlayer(Player *P1, Player P2 );
/*I.S: Sembarang
  F.S: Player disalin.*/

void AddSkill(int X, Kata K );
/*I.S: X = 1 || X=2
  F.S: Menambahkan skill.*/

void DelSkill(int X, Kata *K);
/*I.S: X = 1 || X=2
  F.S: Skill terhapus.*/

void SetatkP(int X, boolean atk);
/*I.S; X = 1 || X=2
  F.S: Menetapkan atk player.*/

void SetCritP(int X, boolean crit);
/*I.S; X = 1 || X=2
  F.S: Menetapkan crit player.*/

void SetShieldP(int X, int S);
/*I.S; X = 1 || X=2 , 0<=X <=2
  F.S: Menetapkan shield player.*/

void infoSkill(int X);
/*I.S: X = 1 || X=2
  F.S: Mencetak skill.*/

boolean IsEmptySkill(int X);
/*I.S: X = 1 || X=2
  F.S: Apakah skill pemain X kosong.*/
#endif