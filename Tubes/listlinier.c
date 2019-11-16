// Nama : Naufal Arfananda Ghifari
//NIM: 13518096
//Tanggal : 22-10  2019
#include "boolean.h"
#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>
#include "bangunan.h"


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
/* Mengirim true jika list kosong */
    return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    address P =(address) malloc (sizeof(ElmtList));
    if (P == Nil){
        return Nil;
    }
    Info(P) = X;
    Next(P) = Nil;
    return P;
}
void Dealokasi (address P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    Next(P) = Nil;
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    if (IsEmpty(L)){
        return Nil;
    } else{
        address a;
        a = First(L);
        while ( Next(a)!= Nil && Info(a)!= X){
            a = Next(a);
        }
        if (Info(a)==X){
            return a;
        }else{
            return Nil;
        }
    }
}

address Searchindex(List L,int idx){
/*List tidak kosong index i terdefinisi pada L*/
    int i =1;
    address P = First(L);
    while (i<idx)
    {
        P = Next(P);
        i++;
    }
    return P;

}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    address P = Alokasi(X);
    InsertFirst (L,P);
}
void InsVLast (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    address P = Alokasi(X);
    InsertLast (L,P);
}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    address P;
    *X = Info(First(*L));
    P = Next(First(*L));
    Dealokasi(First(*L));
    First(*L)= P;
}
void DelVLast (List *L, infotype *X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    address P;
    DelLast(L,&P);
    *X = Info(P);
    Dealokasi(P);
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    Next(P) = First(*L);
    First(*L)= P;
}

void InsertAfter (List *L, address P, address Prec){
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    address a;
    a = First(*L);
    while (a != Prec){
        a = Next(a);
    }
    Next(P)= Next(a);
    Next(a) = P;
}
void InsertLast (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if(IsEmpty(*L)){
        InsertFirst(L, P);
    }
    else{
        address a;
        a = First(*L);
        while (Next(a) != Nil){
            a = Next(a);
        }
        Next(a)= P;
        Next(P) = Nil;
    }
}
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    *P = First(*L);
    First(*L) = Next(First(*L));
}
void DelP (List *L, infotype X);//{
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
/*    if (Search(*L, X) != Nil){
        address a;
        address P;
        a = First(*L);
        if (Info(a) == X){
            DelFirst(L,&P);
        } else{
            while (Info(Next(a)) != X){
                a = Next(a);
            }
            P = Next(Next(a));
            Dealokasi(&Next(a));
            Next(a) = P;
        }

    }

}*/
void DelLast (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
    address a;
    a = First(*L);
    if (Next(a)==Nil){
        DelFirst(L,P);
    }
    else{
        while (Next(Next(a)) != Nil){
            a = Next(a);
        }
        *P = Next(a);
        Next(a) = Nil;
    }
}
void DelAfter (List *L, address *Pdel, address Prec){
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    address a;
    a = First(*L);
    while (a != Prec){
        a = Next(a);
    }
    *Pdel = Next(a);
    Next(a) = Next(Next(a));
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!(IsEmpty(L))){
        address a;
        a= First(L);
        while (Next(a)!= Nil)
        {
            printf("%d,", Info(a));
            a = Next(a);
        }
        printf("%d", Info(a));
    }
    printf("]");
}
int NbElmt (List L){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
    int count;
    if (IsEmpty(L)){
        return 0;
    }
    else{
        count =1;
        address a;
        a = First(L);
        while (Next(a) != Nil){
            a = Next(a);
            count++;
        }
        return count;
    }
}
infotype Max (List L);//{
/* Mengirimkan nilai Info(P) yang maksimum */
/*    infotype Max;
    if (IsEmpty(L)){
        return Nil;
    } else{
        Max = Info(First(L));
        address a;
        a = First(L);
        while ( Next(a)!= Nil){
            if (Info(a)> Max){
                Max = Info(a);
            }
            a = Next(a);
        }
        if (Info(a)>Max){
            return Info(a);
        }else{
            return Max;
        }
    }
}*/

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3){
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    if(IsEmpty(*L1)){
        First(*L3) = First(*L2);
    }else{
        First(*L3) = First (*L1);
        address a;
        a = First(*L1);
        while (Next(a) != Nil){
            a = Next(a);
        }
        Next(a)= First(*L2);
    }
    CreateEmpty(L1);
    CreateEmpty(L2);
}

void ListBangunan (List *L, Pemain P) {
    int i;
    for (i = 1; i <= Neff(A); i++) {
        
        if (Kepemilikan(Bangunan(A, i)) == P) {
            InsVLast(L, i);
           // PrintInfo(*L);
        }
    }
}

void ListBangunanSerang (List *L, Pemain P) {
    int i;
    List L1, L2;
    CreateEmpty(&L1);
    CreateEmpty(&L2);
    ListBangunan (&L1, 0);
    if (P == 1) {
        ListBangunan (&L2,2);
    }
    else {
        ListBangunan (&L2, 1);
    }
    Konkat1 (&L1, &L2, L);
}

void PrintListBangunan (List L) {
    address a;
    int i;
    a = First(L);
    i = 1;
    while (a != Nil) {
        printf("%d. ", i);
        PrintStatus(Bangunan(A, Info(a)));
        printf("\n");
        i++;
        a = Next(a);
    }
}

List GetListP(Pemain P){
    if (P==1){
        return L1;
    }else{
        return L2;
    }
}
// int main(){
//     List L;
//     CreateEmpty(&L);
//     address P1;
//     address P2;
//     InsVFirst(&L,2);
//    // InsVFirst(&L,3);
//     PrintInfo(L);
//     address P;
//     DelLast(&L,&P);
//     PrintInfo(L);
//     return 0;
// }