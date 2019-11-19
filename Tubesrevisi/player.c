#include "player.h"
Player Player1, Player2;


void MakePlayer(Player *P, int X){
    number(*P) = X;
    CreateEmptyQueue(&skill(*P),10);
    Setatk(P, false);
    Setcrit(P, false);
    Setshield(P, 0);

}
void Setskill(Player *P, Queue skill){
    CopyQueue( skill, &(skill(*P)) );
}

void Setatk(Player *P, boolean atk){
    atk(*P)  = atk;
}

boolean IsAtk(Player P){
    return atk(P);
}
boolean IsAtkP(int X){
    switch (X)
    {
    case 1:
        IsAtk(Player1);
        break;
    
    default:
        IsAtk(Player2);
        break;
    }
}
void Setcrit(Player *P, boolean crit){
    crit(*P) = crit;
}

boolean IsCrit(Player P){
    return crit(P);
}
boolean IsCritP(int X){
    switch (X)
    {
    case 1:
        IsCrit(Player1);
        break;
    
    default:
        IsCrit(Player2);
        break;
    }
}
void Setshield(Player *P, int S){
    shield(*P) = S;
}
int getShield(int X){
    switch (X)
    {
    case 1:
        shield(Player1);
        break;
    
    default:
        shield(Player2);
        break;
    }
}
void CopyPlayer(Player *P1, Player P2 ){
    number(*P1) = number(P2);
    Setskill(P1, skill(P2));
    Setatk(P1, atk(P2));
    Setcrit(P1, crit(P2));
    Setshield(P1, shield(P2));
}
void AddSkill(int X, Kata K ){
    switch (X)
    {
    case 1:
        AddQueue(&(skill(Player1)),K);
        break;
    
    default:
        AddQueue(&(skill(Player2)),K);
        break;
    }
}
void DelSkill(int X, Kata *K){
    switch (X)
    {
    case 1:
        DelQueue(&(skill(Player1)),K);
        break;
    
    default:
        DelQueue(&(skill(Player2)),K);
        break;
    }
}

void SetatkP(int X, boolean atk){
    switch (X)
    {
    case 1:
        Setatk(&Player1, atk);
        break;
    
    default:
        Setatk(&Player2, atk);
        break;
    }
}
void SetCritP(int X, boolean crit){
    switch (X)
    {
    case 1:
        Setcrit(&Player1, crit);
        break;
    
    default:
        Setcrit(&Player2, crit);
        break;
    }
}
void SetShieldP(int X, int S){
    switch (X)
    {
    case 1:
        Setshield(&Player1,S);
        break;
    
    default:
        Setshield(&Player2,S);
        break;
    }   
}

void infoSkill(int X){
    switch (X)
    {
    case 1:
        CetakKata(InfoHead(skill(Player1)));
        break;
    
    default:
        CetakKata(InfoHead(skill(Player1)));
        break;
    }
}