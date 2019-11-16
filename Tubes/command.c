#include "console.h"
#include "command.h"
#include <stdio.h>
#include <stdlib.h>
#include "stackt.h"
#include "arraydin.h"
#include "skill.h"
#include "listlinier.h"
void Command(){
    CreateEmptyStack(&Undo);
    Push(&Undo,A);
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
        EXIT();
    }else{
        printf("Command tidak ada");
        outln();
    }
}

void Attack(){
    printf("Daftar bangunan:");
    outln();
    PrintListBangunan(GetListP(TURN));
    //Kalkulasi
    //di adt bangunan ada fungsinya tapi aku blm baca lgi



    Push(&Undo, A);
}
void Level_up(){
    printf("Daftar bangunan:");
    outln();
    PrintListBangunan(GetListP(TURN));
    //Kalkulasi
    //di adt bangunan ada fungsinya tapi aku blm baca lgi



    Push(&Undo, A);
}


void Skill(){
    useSkill();
}

void UNDO(){
    TabInt T;
    Pop(&Undo,&T);
    if(!IsEmptyStack){
        A = InfoTop(Undo);
    }else{
        Push(&Undo,T);
        printf("Tidak ada riwayat command");
        outln();
    }
    
}

void Move(){
    printf("Daftar bangunan:");
    outln();
    PrintListBangunan(GetListP(TURN));
    //Kalkulasi
    //gunain selektor d adt bangunan


    Push(&Undo, A);
}
void End_turn(){//Kayanya mending d console appnya yang ini
}
void Save(){
   // printf("%d",2);
}
void EXIT(){
    exit(0);
}

