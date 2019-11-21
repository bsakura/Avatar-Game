// Nama: Naufal Arfananda Ghifari
// NIM : 13518096
// Tanggal : 17-9 2019

#include <stdio.h>
#include "boolean.h"
#include "matriks.h"
#include "point.h"
#include "bangunan.h"
/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
 void MakeMATRIKS (int NB, int NK, MATRIKS * M){
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
    NBrsEff(*M) = NB ;
    NKolEff(*M) = NK ;
    
    for(int i = 1; i<= NB; i++){
        for(int j=1 ; j<= NK; j++){
            Elmt(*M,i,j) = 0;
        }
    }
   
}
/* *** Selektor "DUNIA MATRIKS" *** */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terkecil M */
    return BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terkecil M */
    return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terbesar M */
    return (BrsMin + NBrsEff(M) -1);
}
indeks GetLastIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terbesar M */
    return (KolMin + NKolEff(M) -1);
}
