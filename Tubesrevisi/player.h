#ifndef player_H
#define player_H


#include "queue.h"
#include "boolean.h"
#include "console.h"
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
void Setskill(Player *P, Queue skill);
void Setatk(Player *P, boolean atk);
boolean IsAtk(Player P);
boolean IsAtkP(int X);
void Setcrit(Player *P, boolean crit);
boolean IsCrit(Player P);
boolean IsCritP(int X);
void Setshield(Player *P, int S);
int getShield(int X);
void CopyPlayer(Player *P1, Player P2 );
void AddSkill(int X, Kata K);
void DelSkill(int X, Kata *K);
void SetatkP(int X, boolean atk);
void SetCritP(int X, boolean crit);
void SetShieldP(int X, int S);
void infoSkill(int X);

#endif