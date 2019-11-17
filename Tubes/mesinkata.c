// Nama: Naufal Arfananda Ghifari
// NIM : 13518096
// Tanggal : 122-9 2019
#include <stdio.h>
#include "mesinkata.h"

boolean EndKata;
Kata CKata;
void IgnoreBlank(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
   if (useFile){
        while (CC== BLANK || CC == '\n'){
            ADV();   
        } 
   }else{
        while (CC== BLANK ){
            ADV();
   }
   }
}

void STARTKATA(){
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
    START();
    //IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    } else /* CC != MARK */ {
        EndKata = false;
        SalinKata();
    }
    if (useFile){
        IgnoreBlank();
    }
}
void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    } else /* CC != MARK */ {
        SalinKata();
    }
    IgnoreBlank();
}
void SalinKata(){
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    //kamus lokal
    int i;
    //algo
    i = 1; /* inisialisasi */
    /* Algoritma*/
    while ((CC != MARK) && (CC != BLANK)&&(i != NMax+1)&&(CC != '\n')) {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    } /* CC = MARK or CC = BLANK */
    CKata.Length = i-1;
}

// int main(){
//     set(true);
//     STARTKATA();
// }