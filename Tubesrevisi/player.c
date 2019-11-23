#include "player.h"
#include <stdio.h>
Player Player1, Player2;


void MakePlayer(Player *P, int X)
/*I.S: X = 1 || X=2
  F.S: Player baru dibuat.*/
{
    //Algoritma
    number(*P) = X;
    CreateEmptyQueue((&skill(*P)),10);
    Setatk(P, false);
    Setcrit(P, false);
    Setshield(P, 0);

}
void Setskill(Player *P, Queue skill)
/*I.S: Sembarang
  F.S: Menentukan skill player.*/
{
    //Algoritma
    CopyQueue( skill, &(skill(*P)) );
}

void Setatk(Player *P, boolean atk){
/*I.S: Sembarang
  F.S: Menentukan atk player.*/
    atk(*P)  = atk;
}

boolean IsAtk(Player P)
/*Input: Player
  Output Boolean true jika atk.*/
{
    //Algoritma
    return atk(P);
}
boolean IsAtkP(int X)
/*Input: integer X = 1 || X=2
  Output: Booeln true jika...*/
{
    //Algoritma
    switch (X)
    {
    case 1:
        return IsAtk(Player1);
        break;
    
    default:
        return IsAtk(Player2);
        break;
    }
}
void Setcrit(Player *P, boolean crit)
/*I.S: Sembarang
  F.S: Menetapkan critical.*/
{
    //Algoritma
    crit(*P) = crit;
}

boolean IsCrit(Player P)
/*Input: player
  Output: Boolean true jika critical.*/
{
    //Algoritma
    return crit(P);
}

boolean IsCritP(int X)
/*Input: integer X = 1 || X=2
  Output: Boolean true jika ...*/
{
    //Algoritma
    switch (X)
    {
    case 1:
        return IsCrit(Player1);
        break;
    
    default:
        return IsCrit(Player2);
        break;
    }
}
void Setshield(Player *P, int S)
/*I.S: Sembarang
  F.S: Shield ditentukan.*/
{
    //Algoritma
    shield(*P) = S;
}

int getShield(int X)
/*Input: integerX = 1 || X=2
  Output: integer*/
{
    //Algoritma
    switch (X)
    {
    case 1:
        return shield(Player1);
        break;
    
    default:
        return shield(Player2);
        break;
    }
}
void CopyPlayer(Player *P1, Player P2 )
/*I.S: Sembarang
  F.S: Player disalin.*/
{
    //Algoritma
    number(*P1) = number(P2);
    Setskill(P1, skill(P2));
    Setatk(P1, atk(P2));
    Setcrit(P1, crit(P2));
    Setshield(P1, shield(P2));
}
void AddSkill(int X, Kata K )
/*I.S: X = 1 || X=2
  F.S: Menambahkan skill.*/
{
    //Algoritma
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
void DelSkill(int X, Kata *K)
/*I.S: X = 1 || X=2
  F.S: Skill terhapus.*/
{
    //Algoritma
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

void SetatkP(int X, boolean atk)
/*I.S; X = 1 || X=2
  F.S: Menetapkan atk player.*/
{
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
void SetCritP(int X, boolean crit)
/*I.S; X = 1 || X=2
  F.S: Menetapkan crit player.*/{
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
void SetShieldP(int X, int S)
/*I.S; X = 1 || X=2 , 0<= S <= 2
  F.S: Menetapkan shield player.*/{
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

void infoSkill(int X)
/*I.S: X = 1 || X=2
  F.S: Mencetak skill.*/
{
    switch (X)
    {
    case 1:
        if (IsEmptyQueue(skill(Player1)))
        {
            printf("Tidak ada skill yang tersedia");
        }
        else{
            CetakKata(InfoHead(skill(Player1)));
        }
        break;
    
    default:
        if (IsEmptyQueue(skill(Player2)))
        {
            printf("Tidak ada skill yang tersedia");
        }
        else{
            CetakKata(InfoHead(skill(Player2)));
        }
        break;
    }
}

boolean IsEmptySkill(int X){
/*I.S: X = 1 || X=2
  F.S: Apakah skill pemain X kosong.*/
    switch (X)
    {
    case 1:
        return IsEmptyQueue(skill(Player1));
        break;
    
    default:
        return IsEmptyQueue(skill(Player2));
        break;
    }
}