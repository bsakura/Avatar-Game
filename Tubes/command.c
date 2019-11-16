#include "console.h"
#include "command.h"
#include <stdio.h>


void Command(){
    if (CMPKATATabChar(STDIN,"ATTACK")){
        Attack();
    }else if(CMPKATATabChar(STDIN,"LEVEL_UP")){
        Level_up();
    }else if(CMPKATATabChar(STDIN,"SKILL")){
        Skill();
    }else if(CMPKATATabChar(STDIN, "UNDO")){
        UNDO();
    }else if(CMPKATATabChar(STDIN, "MOVE")){
        Move();
    }else if(CMPKATATabChar(STDIN, "END_TURN")){
        End_turn();
    }else if(CMPKATATabChar(STDIN, "SAVE")){
        Save();
    }else if(CMPKATATabChar(STDIN, "EXIT")){
        Exit();
    }else{
        printf("Command tidak ada");
        outln();
    }
}
void Attack(){}
void Level_up(){}
void Skill(){}
void UNDO(){}
void Move(){
    printf("%d",1);
}
void End_turn(){}
void Save(){
    printf("%d",2);
}
void Exit(){}

