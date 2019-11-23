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
#include "player.h"
#include "matriks.h"
#include <math.h>

void Command()
/*I.S: Sembarang
  F.S: Setelah memproses input dari mesin kata, akan dilakukan aksi command dengan memanggil prosedur sesuai perintah.*/
{
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

void Attack()
/*I.S: Sembarang
  F.S: akan dikeluarkan output berupa daftar bangunan, bangunan yang dapat digunakan untuk menyerang,
       dan bangunan yang bisa diserang. Apabila tidak ada bangunan yang berhubungan langsung dengan 
       angunan penyerang, akan keluar output tidak ada bangunan yang dapat diserang.Jika ada bangunan 
       yang dapat diserang, akan keluar output hasil jumlah pasukan setelah penyerangan berhasil.*/
{
    //Kamus Lokal
    int N, X,Y, temp, intPas;
    double half, M,Kalku, doTemp, floorPas, empatpertiga;
    content con;
    TabInt T;
    Player P1, P2;
    List LA,LB;
    //Algoritma
    printf("Daftar bangunan:");
    outln();
    PrintListBangunan(GetListP(TURN));
    outln();
    printf("Bangunan yang digunakan untuk menyerang: ");
    scanf("%d",&N);
    NEED = true;
    address P= Searchindex((GetListP(TURN)),N);
    X= Info(P);
    if(Search(LAtk,X)==Nil){
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
            M = (double) Pasukan(Bangunan(A,Y));
            if(N<=Pasukan(Bangunan(A,X))){
                if ((IsPertahanan(Bangunan(A,Y)) || getShield(ENEMY())>0) && (!IsAtkP(TURN)) && (!IsCritP(TURN))){
                    Kalku = (double)  N * 3/4;
                }
                else if(IsCritP(TURN)){
                    Kalku = (double) N*2;
                }
                else{
                    Kalku = (double) N;
                }
                
                TambahPasukanManual(&(Bangunan(A,X)), -1*N);

                if (Kalku>=M){
                    //Syarat penambahan skill extra turn 
                    if(Jenis(Bangunan(A,Y))=='F' && Kepemilikan(Bangunan(A,Y))==ENEMY()){
                        AddSkill(ENEMY(),TabCHartoKata("ET"));
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

                    /*Penambahan skill shield*/
                    if (Kepemilikan(Bangunan(A,Y))==ENEMY()&&NbElmt(GetListP(ENEMY()))==2){
                        AddSkill(ENEMY(), TabCHartoKata("Shield"));
                    }

                    //Syarat skill attack up pada queue skill
                    if(Jenis(Bangunan(A,Y))=='T' && Kepemilikan(Bangunan(A,Y))==ENEMY()){
                        address P= First(GetListP(TURN));
                        int count=0;
                        while (P != Nil){
                            if(Jenis(Bangunan(A, Info(P)))=='T'){
                                count++;
                            }
                            P=Next(P);
                        }
                        if(count==3){
                            AddSkill(TURN, TabCHartoKata("AU"));
                        }

                    }

                    //Penambahan skill Barrage
                    if(NbElmt(GetListP(TURN))==10){
                        AddSkill(ENEMY(), TabCHartoKata("BR"));
                    }

                    if(IsCritP(TURN)){
                        doTemp = (double) (Kalku -M);
                        half = doTemp/2;
                        floorPas = floor(half);
                        intPas = (int)floorPas;
                        Bangunan(A,Y) = SetBangunan(Jenis(Bangunan(A,Y)),TURN,lokasi(Bangunan(A,Y)));
                        SetPasukan(&(Bangunan(A,Y)) , intPas);
                        printf("%d\n",intPas);
                    }
                    else if((IsPertahanan(Bangunan(A,Y)) || getShield(ENEMY())>0) && (!IsAtkP(TURN)) && (!IsCritP(TURN))){
                        doTemp = (double) (Kalku -M);
                        empatpertiga = doTemp * (4/3);
                        floorPas = floor(empatpertiga);
                        intPas = (int)floorPas;
                        Bangunan(A,Y) = SetBangunan(Jenis(Bangunan(A,Y)),TURN,lokasi(Bangunan(A,Y)));
                        SetPasukan(&(Bangunan(A,Y)) , intPas);
                    }
                    else{
                        intPas = (int) (Kalku-M);
                        Bangunan(A,Y) = SetBangunan(Jenis(Bangunan(A,Y)),TURN,lokasi(Bangunan(A,Y)));
                        SetPasukan(&(Bangunan(A,Y)), intPas);
                    }
                    
                    printf("Bangunan menjadi milikmu!");
                    outln();
                    if (IsEmpty(GetListP(ENEMY()))){
                        ENDGAME = true;
                    }
                }else{
                    intPas = (int) (Kalku);
                    TambahPasukanManual(&(Bangunan(A,Y)), -1*intPas);
                    printf("Bangunan gagal direbut.");
                    outln();
                }
                SetCritP(TURN,false);
                InsVLast(&LAtk, X);
            }else
            {
                printf("Jumlah pasukan melebihi yang ada pada bangunan");
                outln();
            }
           
        
        }
    }else{
        printf("Bangunan ini sudah digunakan untuk menyerang");
        outln();
    }
    
    CopyList(&LA, LMove);
    CopyList(&LB, LAtk);
    CopyTab(A, &T);
    CopyPlayer(&P1, Player1);
    CopyPlayer(&P2, Player2);
    CreateContent(&con, T, P1, P2, LA,LB);
    Push(&Undo,con);

}
void Level_up()
/*I.S: Bangunan
  F.S: Output berupa list bangunan yang bisa dilevel-up lalu akan dikembalikan properti-properti
       bangunan yang telah diupgrade di layar.*/
{
    //Kamus Lokal
	int x, y;
    content con;
    TabInt T;
    Player P1, P2;
    List LA,LB;
    //Algoritma
    printf("Daftar bangunan:");
    outln();
    PrintListBangunan(GetListP(TURN));
    //Kalkulasi
    //di adt bangunan ada fungsinya tapi aku blm baca lgi
    printf("Bangunan yang akan di level up: ");
    scanf("%d", &x);
    NEED = true;
    address P = Searchindex(GetListP(TURN), x);
    y = Info(P);
	if (Pasukan(Bangunan(A,y)) >= (Maksimum(Bangunan(A,y)) / 2)) {
        TambahPasukanManual(&(Bangunan(A,y)), -1*(Maksimum(Bangunan(A,y)) / 2));
		LevelUp(&(Bangunan(A,y)));
		printf("Level ");
        PrintJenisPoint(Bangunan(A,y));
        printf(" -mu meningkat menjadi %d!", Level(Bangunan(A,y)));
        outln();

	}
	else{
		printf("Jumlah pasukan ");
        PrintJenisPoint(Bangunan(A,y));
        printf(" kurang untuk level up");
        outln();
	}
    CopyList(&LA, LMove);
    CopyList(&LB, LAtk);
    CopyTab(A, &T);
    CopyPlayer(&P1, Player1);
    CopyPlayer(&P2, Player2);
    CreateContent(&con, T, P1, P2, LA,LB);
    Push(&Undo,con);
}


void Skill()
/*I.S.: Sembarang.
  F.S.: Dihasilkan stack kosong untuk memasukkan skill-skill yang diperoleh oleh pemain
        dan apabila pemain menggunakan skill, skill tersebut akan menghilang dan tidak 
        dapat digunakan lagi. */
{
    //Kamus
    content con;
    TabInt T;
    Player P1,P2;
    List LA,LB;
    //Algoritma
    useSkill();
    CreateEmptyStack(&Undo);
    CopyList(&LA, LMove);
    CopyList(&LB, LAtk);
    CopyTab(A, &T);
    CopyPlayer(&P1, Player1);
    CopyPlayer(&P2, Player2);
    CreateContent(&con, T, P1, P2, LA,LB);
    Push(&Undo,con);
}

void UNDO()
/*I.S.: Sembarang
  F.S.: Segala aksi yang dilakukan oleh pemain kembali ke keadaan sebelum pemain melakukan aksi.
        Jika sebelumnya tidak ada command, akan muncul keluaran berupa tidak ada perintah untuk 
        dibatalkan.*/
{
    //Kamus Lokal
    content con;
    //Algoritma
    Pop(&Undo,&con);
    if(!IsEmptyStack(Undo)){
        con = InfoTop(Undo);
        CopyTab(Tab(con), &A);
        CopyList(&LMove, LA(con));
        CopyList(&LAtk, LA(con));
        CopyPlayer(&Player1, P1(con));
        CopyPlayer(&Player2, P2(con));
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

void Move()
/*I.S: Sembarang.
  F.S: AKan ada keluaran berupa daftar bangunan dan bangunan terdekat yang dapat dipilih
       untuk memindahkan pasukkan. Jika pasukkan terlalu besar akan ada pembertitahuan bahwa
       pemindahan tidak berhasil. Apabila pemindahan berhasil akan keluar notifikasi tentang
       jumlah pasukan di bangunan tersebut.*/
{
    //Kamus Lokal
    int N, X,Y;
    content con;
    TabInt T;
    Player P1,P2;
    List LA,LB;
    //Algoritma
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
        if ((Pasukan(Bangunan(A,X))>=N)/* && ((Pasukan(Bangunan(A,Y))+N)<=Maksimum(Bangunan(A,Y)))*/){
            TambahPasukanManual(&(Bangunan(A,X)),-1*N);
            TambahPasukanManual(&(Bangunan(A,Y)),N);
            printf("%d pasukan dari ",N);
            PrintJenisPoint(Bangunan(A,X));
            printf(" telah berpindah ke ");
            PrintJenisPoint(Bangunan(A,Y));
            outln();
            InsVLast(&LMove, X);
        }else{
            printf("Jumlah pasukan yang akan dipindahkan kurang");
            outln();
        }
        
    }
    CopyList(&LA, LMove);
    CopyList(&LB, LAtk);
    CopyTab(A, &T);
    CopyPlayer(&P1, Player1);
    CopyPlayer(&P2, Player2);
    CreateContent(&con, T, P1, P2, LA,LB);
    Push(&Undo,con);
}
void End_turn()
/*I.S.: Sembarang.
  F.S.: Mengakhiri giliran pemain.*/
{
    //Algoritma
    ENDTURN = true;
    address P =First(GetListP(TURN));
    boolean IR = true;
    while (P!=Nil && IR)
    {
        if(Level(Bangunan(A,Info(P)))!=4){
            IR = false;
        }
        P = Next(P);
    }
    if (IR){
        AddSkill(TURN, TabCHartoKata("IR"));
    }
}
void Save(){
    /* Prosedur untuk menyimpan data permainan*/
    Queue Q;
    BANGUNAN B;
    int i,j;
    adrNode G;
    address P;
    Kata K;
    FILE *f=fopen("out.txt", "w");
    //Print Turn sama extra turn
    fprintf(f, "%d " ,TURN);
    if (Extra_turn){
        fprintf(f, "1\n");
    }else
    {
        fprintf(f, "0\n");
    }
    
    //Print dimensi map
    fprintf(f, "%d %d\n" ,NBrsEff(Map), NKolEff(Map));
    //print Array
    fprintf(f, "%d\n", Neff(A));
    for (i = 1; i <= Neff(A); i++)
    {
        B = Bangunan(A,i);
        fprintf(f, "%c %d %d %d %d %d %0.0f %0.0f\n", Jenis(B),Kepemilikan(B),Pasukan(B),Maksimum(B),PasukanAwal(B), Level(B), Absis(lokasi(B)),Ordinat(lokasi(B)));
    }
    //Print graph
    G = GRAPH.First;
    while (G!=Nil)
    {
        P = First(Trail(G));
        while (P!=Nil)
        {
            fprintf(f, "%d ", Info(P));
            P =Next(P);
        }
        fprintf(f, ".\n");
        G=NextN(G);
    }
    //Print player 1
    CopyQueue(skill(Player1), &Q);
    while (!IsEmptyQueue(Q))
    {
        DelQueue(&Q,&K);
        for(i=1; i<= K.Length; i++){
            fprintf(f, "%c", K.TabKata[i]);
        }  
        fprintf(f, " ", K.TabKata[i]);  
    }
    fprintf(f, ".\n");
    if (IsAtkP(1)){
        fprintf(f, "1 ");
    }else{
        fprintf(f, "0 ");
    }
    if (IsCritP(1)){
        fprintf(f, "1 ");
    }else{
        fprintf(f, "0 ");
    }
    fprintf(f, "%d\n", getShield(1));
    //Print player 2
    CopyQueue(skill(Player2), &Q);
    while (!IsEmptyQueue(Q))
    {
        DelQueue(&Q,&K);
        for(i=1; i<= K.Length; i++){
            fprintf(f, "%c", K.TabKata[i]);
        }  
        fprintf(f, " ", K.TabKata[i]);  
    }
    fprintf(f, ".\n");
    if (IsAtkP(2)){
        fprintf(f, "1 ");
    }else{
        fprintf(f, "0 ");
    }
    if (IsCritP(2)){
        fprintf(f, "1 ");
    }else{
        fprintf(f, "0 ");
    }
    fprintf(f, "%d\n", getShield(2));
    //Print Lmove
    P = First(LMove);
    while (P!=Nil)
    {
        fprintf(f, "%d ", Info(P));
        P =Next(P);
    }
    fprintf(f, ".\n");
    P = First(LAtk);
    while (P!=Nil)
    {
        fprintf(f, "%d ", Info(P));
        P =Next(P);
    }
    fprintf(f, ".");
    fclose(f);
}
void EXIT(){
    exit(0);
}

