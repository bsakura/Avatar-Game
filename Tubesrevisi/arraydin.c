// Nama : Naufal Arfananda Ghifari
//NIM: 13518096
//Tanggal : 10 Sept 2019
//Topik: implementasi p/f array dinamis

#include "boolean.h"
#include <stdio.h>
#include "arraydin.h"
#include "bangunan.h"

#include <stdlib.h>


// /* ********** KONSTRUKTOR ********** */
// /* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel){
    /* I.S. T sembarang, maxel > 0 */
    /* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
    TI(*T) = (BANGUNAN*) malloc ((maxel+1) * sizeof(BANGUNAN));
    Neff(*T) = 0;
    MaxEl(*T) = maxel;
}


int MaxElement(TabInt T){
    /* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    return MaxEl(T);
}

int NbElmtTab(TabInt T){
    /* Mengirimkan nila efektif  tabel */
    return Neff(T);
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T){
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen T pertama */
    return IdxMin;
}
IdxType GetLastIdx(TabInt T){
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen T terakhir */
    return(IdxMin+NbElmtTab(T)-1);
}


void CopyTab(TabInt Tin, TabInt *Tout){
    /* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
    /* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
    /* Proses : Menyalin isi Tin ke Tout */
    //kamus lokal
    int i;
    //algo
    MakeEmpty(Tout, NbElmtTab(Tin));
    Neff(*Tout)  = NbElmtTab(Tin);
    for (i=GetFirstIdx(Tin); i<= GetLastIdx(Tin);i++){
        Bangunan(*Tout,i) = Bangunan(Tin,i);
    }
    
 }
