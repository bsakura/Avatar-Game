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
#include "player.h"


TabInt A;
List L1, L2, LMove, LAtk;
MATRIKS Map;
Kata STDIN;
Stack Undo;
Graph GRAPH;
boolean Extra_turn,ENDTURN,ENDGAME, NEED;

void CetakMap()
/*I.S: Sembarang
  F.s: Mencetak map ke layar.*/
{
    //Kamus lokal
    int i,j;
    //Algoritma
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

void setstd()
/*I.S: Sembarang
  F.S: Mengebalikan kondisi standard.*/
{
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

void CetakCommand()
/*I.S: Sembarang
  F.S: Mencetak player sesuai giliran, skill yang tersedia, lalu menerima input command.*/
{
    //Algoritma
    CetakMap();
    printf("Player %d", TURN);
    outln();
    PrintListBangunan(GetListP(TURN));
    printf("Skill Available: ");
    infoSkill(TURN);
    outln();
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


void CetakTurn()
/*I.S: Sembarang
  F.S: Mencetak giliran dengan mencetak command jika giliran dan game belum berakhir*/
{
    //Kamus Lokal
    content con;
    TabInt T;
    Player P1,P2;
    //Algoritma
    CreateEmpty(&LMove);
    CreateEmpty(&LAtk);
    CreateEmptyStack(&Undo);
    CopyTab(A, &T);
    CopyPlayer(&P1, Player1);
    CopyPlayer(&P2, Player2);
    CreateContent(&con, T, P1, P2);
    Push(&Undo,con);
    SetatkP(TURN, false);
    ENDTURN = false;
    while(!ENDTURN &&!ENDGAME){
        CetakCommand();
        // PrintStatus(Bangunan(A,1));
        // outln();
        // PrintStatus(Bangunan(A, 13));
        // outln();
    }
}

void Adjust()
/*I.S: Sembarang
  F.S: Mengatur graf, player, dan dasar permainan*/
{
    //Kamus Lokal
    int N, x, y, i,j;
    char C;
    //Algoritma
    TURN = 1;
    ENDGAME = false;
    Extra_turn =false;
    ENDTURN = false;
    NEED = true;
    CreateGraph(&GRAPH);
    CreateEmpty(&L1);
    CreateEmpty(&L2);
    MakePlayer(&Player1, 1);
    MakePlayer(&Player2, 2);

    set(true);
    STARTKATA();
    NBrsEff(Map) = toInt(CKata);
    ADVKATA();
    NKolEff(Map) = toInt(CKata);
    ADVKATA();
    MakeMATRIKS(NBrsEff(Map), NKolEff(Map),&Map);
        
    newA();
        
    ReadGraph();
    MakeMap();
    ListBangunan(&L1,1);
    ListBangunan(&L2,2);
    AddSkill(1, TabCHartoKata("IU"));
    AddSkill(2, TabCHartoKata("IU"));
}


void newA()
{
    //Kamus Lokal
    int N, i;
    char C;
    //Algoritma
    N = toInt(CKata);
    MakeEmpty(&A, N);
    i = 1;
    ADVKATA();
    // Baca Bangunan Player 1
    BacaBangunan(i, 1);
    i++;
    // Baca Bangunan Player 1
    BacaBangunan(i,2);
    i++;
    //Baca Bangunan Lainnya
    for (i=3; i <= N; i++){
        BacaBangunan(i,0);
    }

}

void BacaBangunan(int i ,int X)
/*I.S: Sembarang
  F.S: Memvaca bangunan pada koordinat*/
{
    //Kamus Lokal
    int x, y;
    char C;
    BANGUNAN B;
    POINT P;
    //Algoritma
    C= toChar(CKata);
    ADVKATA();
    x= toInt(CKata);
    ADVKATA();
    y= toInt(CKata);
    P = MakePOINT(x,y);
    B = SetBangunan(C,X, P);
    Neff(A)= i;
    Bangunan(A, i) = B;
    ADVKATA();
}
void ReadGraph()
/*I.S: Sembarang
  F.S: Membaca graf*/
{
    //Kamus Lokal
    int i,j;
    //Algoritma
    for (i=1 ; i<= Neff(A); i++){
        InsertGNode(&GRAPH,i);
    }
    for (i=1; i<=Neff(A); i++){   
        for(j=1; j<=Neff(A); j++){
            if(toInt(CKata)==1){
               InsertEdge(&GRAPH,i,j);
             }
            ADVKATA();
        }
    }
}
void MakeMap()
/*I.S: Sembarang
  F.S: Membuat map.*/
{
    //Kamus Lokal
    int i;
    //Algoritma
    for (i =1; i<= Neff(A); i++){
        int x;
        int y;
        x =  Absis(lokasi(Bangunan(A,i)));
        y = Ordinat(lokasi(Bangunan(A,i)));
        Elmt(Map,x,y) = i;
    }
}


void StartGame()
/*I.S: Sembarang
  F.S: Memulai game.*/
{
    //Algoritma
    Adjust();
    do{
        TambahPasukan();
        CetakTurn();
        if(!Extra_turn){
            NextTurn();
        }
    }while(!ENDGAME);
    //PrintListBangunan(L1);
}

void Load(){
    //Kamus
    int i, N;
    //Algoritma
    ENDGAME = false;
    ENDTURN = false;
    NEED = true;
    CreateGraph(&GRAPH);
    CreateEmpty(&L1);
    CreateEmpty(&L2);
    CreateEmpty(&LAtk);
    CreateEmpty(&LMove);
    MakePlayer(&Player1, 1);
    MakePlayer(&Player2, 2);
    //printf("%d\n", 50);
    set(true);
    STARTKATA();
    TURN = toInt(CKata);
    ADVKATA();
    Extra_turn = tobool(CKata);
    ADVKATA();
    NBrsEff(Map) = toInt(CKata);
    ADVKATA();
    NKolEff(Map) = toInt(CKata);
    ADVKATA();
    MakeMATRIKS(NBrsEff(Map), NKolEff(Map),&Map);
    //load A
    N = toInt(CKata);
    MakeEmpty(&A, N);
    Neff(A) = N;
    ADVKATA();
    for (i = 1; i <= Neff(A); i++)
    {
        loadBangunan(i);
    }
    MakeMap();
    ListBangunan(&L1,1);
    ListBangunan(&L2,2);
    loadgraph();
    loadPlayer(1);
    loadPlayer(2);
    outln();
    loadList(&LMove);
    loadList(&LAtk);
    //Kamus Lokal
    content con;
    TabInt T;
    Player P1,P2;
    //Algoritma
    CreateEmptyStack(&Undo);
    CopyTab(A, &T);
    CopyPlayer(&P1, Player1);
    CopyPlayer(&P2, Player2);
    CreateContent(&con, T, P1, P2);
    Push(&Undo,con);
    while(!ENDTURN &&!ENDGAME){
        CetakCommand();
    }
    // if(!ENDGAME && !Extra_turn){
    //     NextTurn();
    // }
    // while (!ENDGAME)
    // {
    //     TambahPasukan();
    //     CetakTurn();
    //     if(!Extra_turn){
    //         NextTurn();
    //     }
    // }
}   


void loadBangunan(int i){
    char C;
    int P, AA, M, PA, L, x, y;
    C = toChar(CKata);
    //CetakKata(CKata);
    ADVKATA();
    P = toInt(CKata);
    ADVKATA();
    AA = toInt(CKata);
    ADVKATA();
    M = toInt(CKata);
    ADVKATA();
   
    PA = toInt(CKata);
    ADVKATA();

    L= toInt(CKata);
    ADVKATA();

    x = toInt(CKata);
    ADVKATA();
    y = toInt(CKata);
    ADVKATA();
     
    MakeBangunan(&Bangunan(A,i), C, P, AA, M, PA, L, x, y);
}

void loadgraph(){
    adrNode N;
    int i;
    for (i=1 ; i<= Neff(A); i++){
        InsertGNode(&GRAPH,i);
    }
    N = GRAPH.First;
    for (i=1; i<=Neff(A); i++){   
        while (toChar(CKata)!='.')
        {
            InsVLast(&(Trail(N)), toInt(CKata));
            ADVKATA();
        }
        N = NextN(N);
        ADVKATA();
    }
   // CetakKata(CKata);
}

void loadPlayer(int X){
    while(toChar(CKata) != '.'){
        AddSkill(X, CKata);
        ADVKATA();
    }
    ADVKATA();
    SetatkP(X, tobool(CKata));
    ADVKATA();
    SetCritP(X, tobool(CKata));
    ADVKATA();
    //CetakKata(CKata);
    SetShieldP(X, toInt(CKata));
    ADVKATA();
}

void loadList(List *L){
    while (toChar(CKata)!= '.')
    {
        InsVLast(L, toInt(CKata));
        ADVKATA();
    }
    ADVKATA();
}