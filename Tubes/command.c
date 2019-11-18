#include "console.h"
#include "command.h"
#include <stdio.h>
#include <stdlib.h>
#include "stackt.h"
#include "arraydin.h"
#include "skill.h"
#include "listlinier.h"
#include "graph.h"
#include "boolean.h"


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
        //printf("%d %d\n", N, Pasukan(Bangunan(A,X)));
        if(N<=Pasukan(Bangunan(A,X))){
            if (IsPertahanan(Bangunan(A,Y))&& !Atk_up && !Crit){
                M = Pasukan(Bangunan(A,Y)) * 4/3;
            }else{
                if(Crit){
                    N= N*2;
                }
                M= Pasukan(Bangunan(A,Y));
            }
            // if (Atk_up)
            // {
            //     M = Pasukan(Bangunan(A,Y));
            // }
            // if (Crit)
            // {
            //    N = N * 2;
            // }
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
                if(Jenis(Bangunan(A,Y))=='T' && Kepemilikan(Bangunan(A,Y))==ENEMY()){
                    address P= First(GetListP(TURN));
                    int count=0;
                    while (P != Nil){
                        if(Jenis(Bangunan(A, Info(P)))=='T'){
                            count++;
                        }
                        P=Next(P);
                    }
                    if(count==2){
                        switch (TURN)
                        {
                        case 1:
                            AddQueue(&Skill2,TabCHartoKata("AU"));
                            break;

                        default:
                            AddQueue(&Skill1,TabCHartoKata("AU"));
                            break;
                        }
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
                SetKepemilikan(&(Bangunan(A, Y)),TURN);
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
                printf("Bangunan menjadi milikmu!");
                outln();
            }else{
                TambahPasukanManual(&(Bangunan(A,X)),-1*N);
                if (IsPertahanan(Bangunan(A,Y))&& !Atk_up && !Crit){
                    TambahPasukanManual(&(Bangunan(A,Y)), N*-3/4);
                }else{
                    TambahPasukanManual(&(Bangunan(A,Y)), N*-1);
                }
                printf("Bangunan gagal direbut.");
                outln();
            }
        }else
        {
            printf("Jumlah pasukan melebihi yang ada pada bangunan");
            outln();
        }
        Crit = false;
    }
    content con;
    TabInt T;
    CopyTab(A, &T);
    Queue Q1 ,Q2;
    CopyQueue(Skill1, &Q1);
    CopyQueue(Skill2,&Q2);
    CreateContent(&con, T, Q1, Q2);
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
        TambahPasukanManual(&B, -1*(Maksimum(B) / 2));
		LevelUp(&B);
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
		printf("Level ");
        PrintJenisPoint(B);
        printf(" -mu meningkat menjadi %d!", Level(B));
        outln();

	}
	else{
		printf("Jumlah pasukan ");
        PrintJenisPoint(B);
        printf(" kurang untuk level up");
        outln();
	};
    
    content con;
    TabInt T;
    CopyTab(A, &T);
    Queue Q1 ,Q2;
    CopyQueue(Skill1, &Q1);
    CopyQueue(Skill2,&Q2);
    CreateContent(&con, T, Q1, Q2);
    Push(&Undo,con);
}


void Skill(){
    useSkill();
    CreateEmptyStack(&Undo);
    content con;
    TabInt T;
    CopyTab(A, &T);
    Queue Q1 ,Q2;
    CopyQueue(Skill1, &Q1);
    CopyQueue(Skill2,&Q2);
    CreateContent(&con, T, Q1, Q2);
    Push(&Undo,con);
}

void UNDO(){
    content con;
    Pop(&Undo,&con);
    if(!IsEmptyStack(Undo)){
        con = InfoTop(Undo);
        CopyTab(Tab(con), &A);
        CopyQueue(S1(con), &Skill1);
        CopyQueue(S2(con),&Skill2);
        CreateEmpty(&L1);
        CreateEmpty(&L2);
        ListBangunan(&L1,1);
        ListBangunan(&L2,2);
        // PrintStatus(Bangunan(A,1));
        // outln();
        // PrintStatus(Bangunan(A, 13));
        // outln();
        
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
    List FL= FilterList(Trail(SearchGNode(GRAPH,Info(P))),TURN,true);
    if (IsEmpty(FL)){
        printf("Daftar bangunan terdekat: ");
        outln();
        printf("Tidak ada bangunan terdekat");
        outln();
    }else if(Search(LMove,X)!=Nil){
        printf("Bangunan ini sudah pernah dipindahkan pasukannya");
        outln();
    }else{
        printf("Daftar bangunan terdekat: ");
        outln();
        PrintListBangunan(FL);
        outln();
        printf("Bangunan yang akan menerima: ");
        scanf("%d",&N);
        P = Searchindex(FL,N);
        Y = Info(P);
        printf("Jumlah pasukan: ");
        scanf("%d",&N);
        if ((Pasukan(Bangunan(A,X))>=N) && ((Pasukan(Bangunan(A,Y))+N)<=Maksimum(Bangunan(A,Y)))){
            TambahPasukanManual(&(Bangunan(A,X)),-1*N);
            TambahPasukanManual(&(Bangunan(A,Y)),N);
            printf("%d pasukan dari ",N);
            PrintJenisPoint(Bangunan(A,X));
            printf(" telah berpindah ke ");
            PrintJenisPoint(Bangunan(A,Y));
            outln();
            InsVLast(&LMove, X);
        }else if(Pasukan(Bangunan(A,X))<N){
            printf("Jumlah pasukan yang akan dipindahkan kurang");
            outln();
        }else{
            printf("Jumlah pasukan terlalu besar");
            outln();
        }
        
    }
    content con;
    TabInt T;
    CopyTab(A, &T);
    Queue Q1 ,Q2;
    CopyQueue(Skill1, &Q1);
    CopyQueue(Skill2,&Q2);
    CreateContent(&con, T, Q1, Q2);
    Push(&Undo,con);
}
void End_turn(){
    Atk_up = false;
    Crit = false;
    ENDTURN = true;
}
void Save(){}
    //SaveGame(FileInput file) {
    //file.writeInt(ListBangunan);
//}
void EXIT(){
    exit(0);
}

