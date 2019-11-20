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
    int N,M,Kalku, X,Y;
    content con;
    TabInt T;
    Player P1, P2;
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
        Kalku = N;
        //printf("%d %d\n", N, Pasukan(Bangunan(A,X)));
        if(N<=Pasukan(Bangunan(A,X))){
            if (IsPertahanan(Bangunan(A,Y)) && !IsCritP(TURN)){
                M = Pasukan(Bangunan(A,Y)) * 4/3;
            }
            if (IsAtkP(TURN)){
                M = Pasukan(Bangunan(A,Y));
            }
            else{
                if(IsCritP(TURN)){
                    Kalku = Kalku*2;
                }
                M= Pasukan(Bangunan(A,Y));
            }
            if (Kalku>=M){
                if(IsCritP(TURN)){
                    if (N<=M){
                        TambahPasukanManual(&(Bangunan(A,X)),-1*(M-N));
                    }
                    else{
                        TambahPasukanManual(&(Bangunan(A,X)), (N-M));
                    }
                }
                else{
                    TambahPasukanManual(&(Bangunan(A,X)), -1*N);
                }
                if(Jenis(Bangunan(A,Y))=='F' && Kepemilikan(Bangunan(A,Y))==ENEMY()){
                    AddSkill(ENEMY(),TabCHartoKata("ET"));
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
                        AddSkill(ENEMY(), TabCHartoKata("AU"));
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
                Bangunan(A,Y) = SetBangunan(Jenis(Bangunan(A,Y)),TURN,lokasi(Bangunan(A,Y)));
                SetPasukan(&(Bangunan(A,Y)), (N-M));
                if(NbElmt(GetListP(TURN))==10){
                    AddSkill(ENEMY(), TabCHartoKata("BR"));
                }
                printf("Bangunan menjadi milikmu!");
                outln();
            }else{
                TambahPasukanManual(&(Bangunan(A,X)),-1*N);
                if (IsPertahanan(Bangunan(A,Y))&& !IsAtkP(TURN) && !IsCritP(TURN)){
                    TambahPasukanManual(&(Bangunan(A,Y)), N*-3/4);
                }else{
                    TambahPasukanManual(&(Bangunan(A,Y)), N*-1);
                }
                printf("Bangunan gagal direbut.");
                outln();
            }
            InsVLast(&LMove, X);
        }else
        {
            printf("Jumlah pasukan melebihi yang ada pada bangunan");
            outln();
        }
        SetCritP(TURN,false);
    }
    CopyTab(A, &T);
    CopyPlayer(&P1, Player1);
    CopyPlayer(&P2, Player2);
    CreateContent(&con, T, P1, P2);
    Push(&Undo,con);

}
void Level_up()
/*I.S: Bangunan
  F.S: Output berupa list bangunan yang bisa dilevel-up lalu akan dikembalikan properti-properti
       bangunan yang telah diupgrade di layar.*/
{
    //Kamus Lokal
	int x;
    content con;
    TabInt T;
    Player P1, P2;
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
    BANGUNAN B = Bangunan(A, Info(P));
	if (Pasukan(B) >= (Maksimum(B) / 2)) {
        TambahPasukanManual(&B, -1*(Maksimum(B) / 2));
		LevelUp(&B);
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
    
    CopyTab(A, &T);
    CopyPlayer(&P1, Player1);
    CopyPlayer(&P2, Player2);
    CreateContent(&con, T, P1, P2);
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
    //Algoritma
    useSkill();
    CreateEmptyStack(&Undo);
    CopyTab(A, &T);
    CopyPlayer(&P1, Player1);
    CopyPlayer(&P2, Player2);
    CreateContent(&con, T, P1, P2);
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
        CopyPlayer(&Player1, P1(con));
        CopyPlayer(&Player2, P2(con));
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
        }else 
            printf("Jumlah pasukan yang akan dipindahkan kurang");
            outln();
        
    }
    CopyTab(A, &T);
    CopyPlayer(&P1, Player1);
    CopyPlayer(&P2, Player2);
    CreateContent(&con, T, P1, P2);
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
    }
    if (IR){
        AddSkill(TURN, TabCHartoKata("IR"));
    }
}
void Save(){}
    //SaveGame(FileInput file) {
    //file.writeInt(ListBangunan);
//}
void EXIT(){
    exit(0);
}

