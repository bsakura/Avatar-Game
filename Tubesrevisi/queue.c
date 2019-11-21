#include "boolean.h"
#include "queue.h"
#include "mesinkata.h"
#include <stdlib.h>
#include <stdio.h>
#include "console.h"
/* ********* Prototype ********* */
boolean IsEmptyQueue (Queue Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
    return (Head(Q)==0 && Tail(Q)==0) ;
}

boolean IsFullQueue (Queue Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
    return (NBElmtQueue(Q)==MaxElQ(Q));
}
int NBElmtQueue (Queue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    if (IsEmptyQueue(Q)){
        return 0;
    }
    else{
        return (Tail(Q)>=Head(Q) ? (Tail(Q)-Head(Q) +1) :(Tail(Q)+MaxElQ(Q)-Head(Q)+1));
    }
}
/* *** Kreator *** */
void CreateEmptyQueue (Queue * Q, int Max){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    int i;
    (*Q).T = (Kata*) malloc ((Max+1) * sizeof(Kata));
    for(int i=1;i<=Max; i++){
        (*Q).T[i] = TabCHartoKata("");
    }    
    MaxElQ(*Q) = Max;
    Head(*Q) = 0;
    Tail(*Q) = 0;
}
/* *** Destruktor *** */
void DeAlokasiQueue(Queue * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    free((*Q).T);
    MaxElQ(*Q) = 0;
    Head(*Q) = 0;
    Tail(*Q) = 0;
}
/* *** Primitif Add/Delete *** */
void AddQueue (Queue * Q, Kata X){
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
    if (IsEmptyQueue(*Q)){
        Tail(*Q)= 1;
        Head(*Q)= 1;
    } else{
        Tail(*Q) = Tail(*Q) == MaxElQ(*Q) ? 1  : (Tail(*Q) +1);
    }
    InfoTail(*Q) = X;
}
void DelQueue (Queue * Q, Kata * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
    *X = InfoHead(*Q);
    InfoHead(*Q)=TabCHartoKata("");
    if (NBElmtQueue(*Q)==1){
        Head(*Q)=0;
        Tail(*Q)=0;
    }
    else{
        Head(*Q) = Head(*Q) == MaxElQ(*Q) ? 1  : (Head(*Q) +1);
    }
}

void CopyQueue(Queue Qin, Queue *Qout){
/*Proses : Menduplikat Qin ke Qout
I.S Qin terdefinisi
F.S Qout akan sama dengan Qin*/
    CreateEmptyQueue(Qout,MaxElQ(Qin));
    for(int i=1;i<=MaxElQ(Qin); i++){
        (*Qout).T[i] = (Qin).T[i];
    }
    Head(*Qout) = Head(Qin);
    Tail(*Qout)= Tail(Qin);
    MaxElQ(*Qout )= MaxElQ(Qin);
}



// int main(){
//     Queue Q1,  Q2;
//     CreateEmptyQueue(&Q1,10);
//     AddQueue(&Q1,TabCHartoKata("AAAA"));
//     AddQueue(&Q1,TabCHartoKata("BBBB"));
//     AddQueue(&Q1,TabCHartoKata("CCCC"));
//     CopyQueue(Q1, &Q2);
//     Kata K;
//     DelQueue(&Q2, &K);
//     while(!IsEmptyQueue(Q1)){
//         DelQueue(&Q1,&K);
//         CetakKata(K);
//         outln;
//     }
//     while(!IsEmptyQueue(Q2)){
//         DelQueue(&Q2,&K);
//         CetakKata(K);
//         outln;
//     }
//     return 0;
// }