#include "console.h"
#include "command.h"
#include <stdio.h>
#include <stdlib.h>
#include "stackt.h"
#include "arraydin.h"
#include "skill.h"
#include "listlinier.h"
#include "graph.h"
#include "queue.h"
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
        EXIT();
    }else{
        printf("Command tidak ada");
        outln();
    }
}

void Attack(){
    int N,M, X,Y;
    printf("Daftar bangunan:");
    outln();
    PrintListBangunan(GetListP(TURN));
    outln();
    printf("Bangunan yang digunakan untuk menyerang: ");
    scanf("%d",&N);
    NEED = true;
    address P= Searchindex((GetListP(TURN)),N);
    X= Info(P);
    printf("Daftar bangunan yang dapat diserang: ");
    outln();
    List FL= FilterList(Trail(SearchGNode(GRAPH,Info(P))),TURN,false);
    if (IsEmpty(FL)){
        printf("Tidak ada bangunan yang dapat diserang");
        outln();
    }else{
        PrintListBangunan(FL);
        outln();
        printf("Bangunan yang diserang: ");
        scanf("%d",&N);
        P = Searchindex(FL,N);
        Y = Info(P);
        printf("Jumlah pasukan :");
        scanf("%d", &N);
        if (IsPertahanan(Bangunan(A,Y))){
            M = Pasukan(Bangunan(A,Y)) * 4/3;
        }else{
            M= Pasukan(Bangunan(A,Y));
        }
        if (N>=M){
            TambahPasukanManual(&(Bangunan(A,X)),-1*N);
            SetPasukan(&(Bangunan(A,Y)), (N-M));
            if(Jenis(Bangunan(A,Y))=='F' && Kepemilikan(Bangunan(A,Y))==ENEMY()){
                switch (TURN)
                {
                case 1:
                    AddQueue(&Skill2,TabCHartoKata("ET"));
                    break;
                
                default:
                    AddQueue(&Skill1,TabCHartoKata("ET"));
                    break;
                }
            }
            switch (TURN)
            {
            case 1:
                if (Kepemilikan(Bangunan(A,Y))==2){
                    DelP(&L2, Y);
                }
                InsVLast(&L1, Y);
                break;
            
            default:
                    if (Kepemilikan(Bangunan(A,Y))==1){
                    DelP(&L1, Y);
                }
                InsVLast(&L2, Y);
                break;
            }
            if(NbElmt(GetListP(TURN))==10){
                switch (TURN)
                {
                case 1:
                    AddQueue(&Skill2,TabCHartoKata("BR"));
                    break;
                
                default:
                    AddQueue(&Skill1,TabCHartoKata("BR"));
                    break;
                }
            }
            SetKepemilikan(&(Bangunan(A, Y)),TURN);
            printf("Bangunan menjadi milikmu!");
            outln();
            if(IsEmpty(GetListP(ENEMY()))){
                ENDGAME = true;
                printf("Game Selesai");
                outln();
                printf("Player %d Menang", TURN);
                outln();
            }
        }else{
            TambahPasukanManual(&(Bangunan(A,X)),-1*N);
            TambahPasukanManual(&(Bangunan(A,Y)), N*-3/4);
            printf("Bangunan gagal direbut.");
            outln();
        }
    }
    content con;
    CreateContent(&con, A, Skill1, Skill2);
    Push(&Undo,con);
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
    NEED = true;
    address P = Searchindex(GetListP(TURN), x);
    BANGUNAN B = Bangunan(A, Info(P));
	if (Pasukan(B) >= (Maksimum(B) / 2)) {
		LevelUp(&B);
		printf("Level %c-mu meningkat menjadi %d!", Jenis(B), Level(B));
        outln();
        P =First(GetListP(TURN));
        boolean IR = true;
        while (P!=Nil && IR)
        {
            if(Level(Bangunan(A,Info(P)))!=4){
                IR = false;
            }
        }
        if (IR){
            switch (TURN)
            {
            case 1:
                AddQueue(&Skill1,TabCHartoKata("IR"));
                break;
            
            default:
                AddQueue(&Skill2,TabCHartoKata("IR"));
                break;
            }
        }
        
	}
	else{
		printf("Jumlah pasukan %c kurang untuk level up", Jenis(B));
        outln();
	};
    
    content con;
    CreateContent(&con, A, Skill1, Skill2);
    Push(&Undo,con);
}


void Skill(){
    useSkill();
}

void UNDO(){
    content con;
    Pop(&Undo,&con);
    if(!IsEmptyStack(Undo)){
        con = InfoTop(Undo);
        A = Tab(con);
        Skill1 = S1(con);
        Skill2 = S2(con);
        CreateEmpty(&L1);
        CreateEmpty(&L2);
        ListBangunan(&L1,1);
        ListBangunan(&L2,2);
    }else{
        Push(&Undo,con);
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
    NEED = true;
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
        
    }
    content con;
    CreateContent(&con, A, Skill1, Skill2);
    Push(&Undo,con);
}
void End_turn(){
    ENDTURN = true;
}
void Save(){}
    //SaveGame(FileInput file) {
    //file.writeInt(ListBangunan);
//}
void EXIT(){
    exit(0);
}

