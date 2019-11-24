#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
int main(){
    Kata K;
    MakePlayer(&Player1,1);
    MakePlayer(&Player2,2);
    printf("skill available :");
    AddSkill(1, TabCHartoKata("IU"));
    infoSkill(1);
    outln();
    AddSkill(2,TabCHartoKata("AU"));
    SetatkP(2,true);
    if (IsAtkP(2)){
        printf("skill available :");
        infoSkill(2);
        outln();
    }
    DelSkill(1, &K);
    SetCritP(1, true);
    if (IsCritP(1)){
        printf("skill digunakan :");
        CetakKata(K);
        outln();
    }
    SetShieldP(1,2);
    printf("Shield player 1 : %d", getShield(1));


}