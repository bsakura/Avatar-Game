#include "console.h"
#include "command.h"
#include <stdio.h>
#include <stdlib.h>
#include "stackt.h"
#include "arraydin.h"
#include "skill.h"
#include "listlinier.h"
#include "graph.h"

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
	int x;
    printf("Daftar bangunan:");
    outln();
    PrintListBangunan(GetListP(TURN));
    //Kalkulasi
    //di adt bangunan ada fungsinya tapi aku blm baca lgi
    printf("Bangunan yang akan di level up: ");
    scanf("%d", &x);
    address P = Searchindex(GetListP(TURN), x);
    BANGUNAN B = Bangunan(A, Info(P));
	if (Pasukan(B) >= (Maksimum(B) / 2)) {
		LevelUp(&B);
		printf("Level %c-mu meningkat menjadi %d!", Jenis(B), Level(B));
	}
	else{
		printf("Jumlah pasukan %c kurang untuk level up", Jenis(B));
	};
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
        printf("Tidak ada riwayat command sebelumnya");
        outln();
    }
    
}

void Move(){
    int N, X,Y;
    printf("Daftar bangunan:");
    outln();
    PrintListBangunan(GetListP(TURN));
    outln();
    printf("Pilih bangunan: ");
    scanf("%d",&N);
    address P= Searchindex((GetListP(TURN)),N);
    X= Info(P);
    printf("Daftar bangunan terdekat: ");
    outln();
    List FL= FilterList(Trail(SearchGNode(GRAPH,Info(P))),TURN,true);
    if (IsEmpty(FL)){
        printf("Tidak ada bangunan terdekat");
        outln();
    }else{
        PrintListBangunan(FL);
        outln();
        printf("Bangunan yang akan menerima: ");
        scanf("%d",&N);
        P = Searchindex(FL,N);
        Y = Info(P);
        printf("Jumlah pasukan: ");
        scanf("%d",&N);
        if ((Pasukan(Bangunan(A,X))>=N) && ((Pasukan(Bangunan(A,Y))+N)>Maksimum(Bangunan(A,Y)))){
            TambahPasukanManual(&(Bangunan(A,X)),-1*N);
            TambahPasukanManual(&(Bangunan(A,Y)),N);
            printf("%d pasukan dari ",N);
            PrintJenisPoint(Bangunan(A,X));
            printf(" telah berpindah ke ");
            PrintJenisPoint(Bangunan(A,Y));
            outln();
        }else{
            printf("Jumlah pasukan yang akan dipindahkan kurang");
            outln();
        }
        Push(&Undo, A);
    }
}
void End_turn(){
    NextTurn();
}
void Save();
SaveGame(FileInput file) {
    file.writeInt(ListBangunan);
}
void EXIT(){
    exit(0);
}

