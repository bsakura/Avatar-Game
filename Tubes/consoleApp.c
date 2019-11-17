#include "console.h"
#include "consoleApp.h"
#include <stdio.h>
#include "listlinier.h"
#include "input.h"
#include "matriks.h"
#include "bangunan.h"
#include "boolean.h"
#include "pcolor.h"
#include "arraydin.h"
#include "mesinkata.h"
#include "point.h"
#include "stackt.h"
#include "queue.h"
#include "graph.h"
#include "command.h"

TabInt A;
List L1, L2;
MATRIKS Map;
Kata STDIN;
Queue Skill1, Skill2;
Stack Undo;
Graph GRAPH;
boolean Extra_turn,ENDTURN,ENDGAME, NEED;
void CetakMap(){
    int i,j;
    for (i=1;i<=NKolEff(Map) +2; i++){
        printf("*");
    }
    outln();
    for (i=1;i<=NBrsEff(Map); i++){
        printf("*");
        for (j=1; j<=NKolEff(Map);j++){
            if (Elmt(Map,i,j) ==0){
                printf(" ");
            }else{ 
                switch (Kepemilikan(Bangunan(A,Elmt(Map,i,j))))
                {
                case 1:
                    print_blue(Jenis(Bangunan(A,Elmt(Map,i,j))));
                    break;
                case 2:
                    print_red(Jenis(Bangunan(A,Elmt(Map,i,j))));
                    break;
                default:
                    printf("%c", Jenis(Bangunan(A,Elmt(Map,i,j))));
                    break;
                }
                
            }
        }
        printf("*");
        outln();
    }
    for (i=1;i<=NKolEff(Map) +2; i++){
        printf("*");
    }
    outln();
}

void setstd(){
    set(false);
    STARTKATA();
    STDIN = CKata;
    // printf("OOOO : "); 
    // outln();
    // CetakKata(CKata);
    // outln();
    // CetakKata(STDIN);
    // outln();
    // printf("OOOO : ");
    // printf("ini %c ini ", CC);
    // outln();
}

void CetakCommand(){
    printf("ENTER COMMAND: ");
    // set(false);
    // STARTKATA();
    // STDIN = CKata; 
    // CetakKata(CKata);
    // CetakKata(STDIN);
    if(NEED){
        char C;
        fscanf(stdin,"%c",&C);
    }//print_blue(C);
    NEED =false;
    setstd();
    Command();
    EndKata =true;
    
}


void CetakTurn(){
    printf("Player %d", TURN);
    outln();
    PrintListBangunan(GetListP(TURN));
    printf("Skill Available: ");
    CetakKata(InfoHead(GetQueueP(TURN)));
    outln();
    CreateEmptyStack(&Undo);
    content con;
    TabInt T;
    CopyTab(A, &T);
    CreateContent(&con, T, Skill1, Skill2);
    Push(&Undo,con);
    NEED =false;
    ENDTURN = false;
    while(!ENDGAME && !ENDTURN){
        CetakCommand();
        // PrintStatus(Bangunan(A,1));
        // outln();
        // PrintStatus(Bangunan(A, 13));
        // outln();
    }
}
// void CetakSkill(Queue Q){
//     printf("Skill Available: ");
//     //CetakKata(InfoHead(Q));
//     //BELUM BACANYA 
// }

// void CetakBangunanP(List P){
//         address a;
//         a= First(L);
//         int index = 1;
//         do{
//             printf("%d. ", index);
//             Cetak1Bangunan(Info(a));
//             index++;
//             a= Next(a);        
//         }
//         while (Next(a)!= Nil);
// }

// void Cetak1Bangunan(BANGUNAN B){
//     switch (jenis(B))
//     {
//     case C:
//         printf("Castle ")
//         TulisPOINT(lokasi(B));
//         printf(" %d lv. %d", jumpas(B), level(B));
//         ountln();
//         break;
//     case T:
//         printf("Tower ")
//         TulisPOINT(lokasi(B));
//         printf(" %d lv. %d", jumpas(B), level(B));
//         ountln();
//         break;
//     case F:
//         printf("Fort ")
//         TulisPOINT(lokasi(B));
//         printf(" %d lv. %d", jumpas(B), level(B));
//         ountln();
//         break;
//     default:
//         printf("Village ")
//         TulisPOINT(lokasi(B));
//         printf(" %d lv. %d", jumpas(B), level(B));
//         ountln();
//         break;
//     }
void Adjust(){
        //Kamus
        int N, x, y, i,j;
        char C;
        POINT P;
        BANGUNAN B;
        
        TURN = 1;
        ENDGAME = false;
        Extra_turn =false;
        ENDTURN = false;
        CreateGraph(&GRAPH);

        // printf("%d", TURN);
        // NextTurn();
        // printf("%d", TURN);
        i = 1;

        set(true);
        STARTKATA();
        NBrsEff(Map) = toInt(CKata);
        // printf("%d", NBrsEff(M));
        // CetakKata(CKata);
        // outln();
        // printf("%d", toInt(CKata));
        // outln();
        ADVKATA();
        NKolEff(Map) = toInt(CKata);
        // printf("%d",NKolEff(M));
        ADVKATA();
        MakeMATRIKS(NBrsEff(Map), NKolEff(Map),&Map);
        N = toInt(CKata);
        MakeEmpty(&A, N);
        ADVKATA();
        C= toChar(CKata);
        ADVKATA();
        x= toInt(CKata);
        ADVKATA();
        y= toInt(CKata);
        P = MakePOINT(x,y);
        B = SetBangunan(C,1, P);
        Bangunan(A, i) = B;
        Elmt(Map,x,y) = i;
        InsertGNode(&GRAPH,i);
        i++;
        ADVKATA();
        C= toChar(CKata);
        ADVKATA();
        x= toInt(CKata);
        ADVKATA();
        y= toInt(CKata);
        P = MakePOINT(x,y);
        B = SetBangunan(C,2, P);
        Bangunan(A, i) = B;
        Elmt(Map,x,y) = i;
        InsertGNode(&GRAPH,i);
        ADVKATA();
        for (i=3; i <= N; i++){
            C= toChar(CKata);
            ADVKATA();
            x= toInt(CKata);
            ADVKATA();
            y= toInt(CKata);
            P = MakePOINT(x,y);
            B = SetBangunan(C,0, P);
            Neff(A)= i;
            Bangunan(A, i) = B;
            Elmt(Map,x,y) = i;
            InsertGNode(&GRAPH,i);
            //A[i] = B;
            //M[lokasi(B).x][lokasi(B).y]=B;
            ADVKATA();
        }
        for (i=1; i<=N; i++){   
            for(j=1; j<=N; j++){
                if(toInt(CKata)==1){
                    InsertEdge(&GRAPH,i,j);
                }
                ADVKATA();
            }
        }
        CreateEmpty(&L1);
        // PrintInfo(L1);
        ListBangunan(&L1,1);
        //PrintInfo(L1);
        //PrintListBangunan(L1);
        // for (i = 1; i<= N; i++) {
        //     PrintStatus(Bangunan(A, i));
        //     outln();
        // }
        CreateEmpty(&L2);
        ListBangunan(&L2,2);
        //PrintListBangunan(L2);
        //CreateEmpty(&LS);
        //ListBangunanSerang(&LS,1);
        //PrintListBangunan(LS);
        //TulisMATRIKS(Graph);
        //outln();
        CreateEmptyQueue(&Skill1,10);
        CreateEmptyQueue(&Skill2,10);
        AddQueue(&Skill1, TabCHartoKata("IU"));
        AddQueue(&Skill2, TabCHartoKata("IU"));
    }

void StartGame(){
    Adjust();
    do{
        CetakMap();
        CetakTurn();
        if(!Extra_turn){
            NextTurn();
        }
        TambahPasukan();
    }while(!ENDGAME);
    //PrintListBangunan(L1);
}