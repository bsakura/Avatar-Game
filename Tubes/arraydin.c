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

// void PrintBangunan(TabInt A, int pemain) {
//     int i;
//     for (i = 1; i <= MaxEl(A); i++) {
//         if (Kepemilikan(Bangunan(A, i)) == pemain) {
//             print("%d. ", i);
//             PrintStatus(Bangunan(A, i));
//         }
//     }
// }

// void Dealokasi(TabInt *T){
//     /* I.S. T terdefinisi; */
//     /* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
//     free(TI(*T));
//     Neff(*T) = 0;
//     MaxEl(*T) =0;
// }

// /* ********** SELEKTOR (TAMBAHAN) ********** */
// int NbElmt(TabInt T){
//     /* Mengirimkan banyaknya elemen efektif tabel */
//     /* Mengirimkan nol jika tabel kosong */
//     return Neff(T);
// }

// int MaxElement(TabInt T){
//     /* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
//     return MaxEl(T);
// }

// /* *** Selektor INDEKS *** */
// IdxType GetFirstIdx(TabInt T){
//     /* Prekondisi : Tabel T tidak kosong */
//     /* Mengirimkan indeks elemen T pertama */
//     return IdxMin;
// }
// IdxType GetLastIdx(TabInt T){
//     /* Prekondisi : Tabel T tidak kosong */
//     /* Mengirimkan indeks elemen T terakhir */
//     return(IdxMin+NbElmt(T)-1);
// }

// /* ********** Test Indeks yang valid ********** */
// boolean IsIdxValid(TabInt T, IdxType i){
//     /* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
//     /* yaitu antara indeks yang terdefinisi utk container*/
//     return(i>= IdxMin && i <= MaxEl(T));
// }
// boolean IsIdxEff(TabInt T, IdxType i){
//     /* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
//     /* yaitu antara FirstIdx(T)..LastIdx(T) */
//     return(i>= GetFirstIdx(T)&& i<= GetLastIdx(T));
// }

// /* ********** TEST KOSONG/PENUH ********** */
// /* *** Test tabel kosong *** */
// boolean IsEmpty(TabInt T){
//     /* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
//     /* *** Test tabel penuh *** */
//     return(NbElmt(T)==0);
// }
// boolean IsFull(TabInt T){
//     /* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
//     return(NbElmt(T)== MaxElement(T)-IdxMin+1);
// }
// void BacaIsi(TabInt *T){
//     /* I.S. T sembarang dan sudah dialokasikan sebelumnya */
//     /* F.S. Tabel T terdefinisi */
//     /* Proses : membaca banyaknya elemen T dan mengisi nilainya */
//     /* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
//     /*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
//     /*    Jika N tidak valid, tidak diberikan pesan kesalahan */
//     /* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
//           IdxMin satu per satu diakhiri enter */
//     /*    Jika N = 0; hanya terbentuk T kosong */
//     /*Kamus lokal*/
//     ElType N;
//     IdxType i;
//     /*ALgoritma*/
//     /*baca N*/
//     do{
//         scanf("%d",&N);
//     }while (!(N>=0 && N <= MaxElement(*T)));
//     Neff(*T) = N;
//     for(i=GetFirstIdx(*T);i<=GetLastIdx(*T);i++){
//         scanf("%d",&Elmt(*T,i));
//     }
// }

// void TulisIsiTab(TabInt T){
// /* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
//    antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
//    di tengah, atau di belakang, termasuk spasi dan enter */
// /* I.S. T boleh kosong */
// /* F.S. Jika T tidak kosong: [e1,e2,...,en] */
// /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
// /* Jika tabel kosong : menulis [] */
//         /*Kamus Lokal*/
//     IdxType i;
//     /*Algoritma*/
//     printf("[");
//     for (i=GetFirstIdx(T); i <= GetLastIdx(T); i++){
//         printf("%d",Elmt(T,i));
//         if (i != (GetLastIdx(T)) ) /*IdxEffAkhir*/{
//             printf(",");
//         }
//     }
//     printf("]");
// }

// TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus){
//     //Kamus lokal
//     IdxType i;
//     TabInt T;
//     /* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
//     /* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
//     /* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
//     MakeEmpty(&T, NbElmt(T1));
//     Neff(T)= NbElmt(T1);
//     if (plus){
//         for (i=GetFirstIdx(T); i<= GetLastIdx(T); i++){
//             Elmt(T,i) = Elmt(T1,i) + Elmt(T2,i);
//         }

//     }
//     else{
//         for (i=GetFirstIdx(T); i<=GetLastIdx(T); i++){
//             Elmt(T,i) = Elmt(T1,i) - Elmt(T2,i);
//         }
//     }
//     return T;
// }

// /* ********** OPERATOR RELASIONAL ********** */
// /* *** Operasi pembandingan tabel : < =, > *** */
// boolean IsEQ(TabInt T1, TabInt T2){
//     /* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
//     /*Kamus lokal*/
//     boolean is;
//     IdxType i;
//     /*Algoritma*/
//     is = true; /*inisialisasi*/
//     if (NbElmt(T1) != NbElmt(T2)){
//         is = false;
//     } else{
//         i=GetFirstIdx(T1);/*inisialisasi*/
//         while (is && (i<=GetLastIdx(T1))) {
//             if (Elmt(T1,i) != Elmt(T2,i)){
//                 is= false;
//             }
//             i++;
//         }
//     }
//     return is;
// }

// /* ********** SEARCHING ********** */
// /* ***  Perhatian : Tabel boleh kosong!! *** */
// IdxType Search1(TabInt T, ElType X){
//     /* Search apakah ada elemen tabel T yang bernilai X */
//     /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
//     /* Jika tidak ada, mengirimkan IdxUndef */
//     /* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
//     /* Skema Searching yang digunakan bebas */
//     /*Kamus Lokal*/
//     IdxType i, idx;
//     /*Algoritma*/
//     idx = IdxUndef ; /*Inisialissasi*/
//     for (i= GetLastIdx(T); i >= GetFirstIdx(T); i--){
//         if (Elmt(T,i)==X){
//             idx =i;
//         }
//     }
//     return idx;
// }

// boolean SearchB(TabInt T, ElType X){
//     /* Search apakah ada elemen tabel T yang bernilai X */
//     /* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
//     /* Skema searching yang digunakan bebas */
//     return (Search1(T,X)!=IdxUndef);
// }

// void MaxMin(TabInt T, ElType *Max, ElType *Min){
//     /* I.S. Tabel T tidak kosong */
//     /* F.S. Max berisi nilai maksimum T;
//         Min berisi nilai minimum T */
//         /*Kamus Lokal*/
//     IdxType i;
//     /*Algoritma*/
//     *Max = Elmt(T,IdxMin);/*inisialisasi*/
//     *Min =Elmt(T,IdxMin);
//     for (i=IdxMin +1; i <= GetLastIdx(T); i++ ){
//         if (Elmt(T,i) > *Max){
//             *Max= Elmt(T,i);
//         }
//         if (Elmt(T,i) < *Min){
//             *Min = Elmt(T,i);
//         }
//     }

// }

void CopyTab(TabInt Tin, TabInt *Tout){
    /* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
    /* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
    /* Proses : Menyalin isi Tin ke Tout */
    //kamus lokal
    int i;
    //algo
    MakeEmpty(Tout, Neff(Tin));
    Neff(*Tout)  = Neff(Tin);
    for (i=IdxMin; i<= Neff(*Tout);i++){
        Bangunan(*Tout,i) = Bangunan(Tin,i);
    }
    
 }

// ElType SumTab(TabInt T){
//     /* Menghasilkan hasil penjumlahan semua elemen T */
//     /* Jika T kosong menghasilkan 0 */
//     // Kamus Lokal
//     IdxType i;
//     int sum;
//     //algoritma
//     sum = 0;
//     for ( i= GetFirstIdx(T); i <= GetLastIdx(T); i++){
//         sum += Elmt(T,i);
//     }
//     return sum;
// }

// int CountX(TabInt T, ElType X){
//     /* Menghasilkan berapa banyak kemunculan X di T */
//     /* Jika T kosong menghasilkan 0 */
//     // Kamus Lokal
//     IdxType i;
//     int count;
//     //algoritma
//     count = 0;
//     for ( i= GetFirstIdx(T); i <= GetLastIdx(T); i++){
//         if (Elmt(T,i) ==X){
//             count++;
//         }
//     }
//     return count;
// }

// boolean IsAllGenap(TabInt T){
//     /* Menghailkan true jika semua elemen T genap. T boleh kosong */
//     //Kamus lokal
//     IdxType i;
//     //Algoritma
//     if (IsEmpty(T)){
//         return false;
//     }
//     for (i=GetFirstIdx(T); i<=GetLastIdx(T);i++){
//         if (Elmt(T,i)%2 != 0){
//             return false;
//         }
//     }
//     return true;
// }

// /* ********** SORTING ********** */
// void Sort(TabInt *T, boolean asc){
//     /* I.S. T boleh kosong */
//     /* F.S. Jika asc = true, T terurut membesar */
//     /*      Jika asc = false, T terurut mengecil */
//     /* Proses : Mengurutkan T dengan salah satu algoritma sorting,
//     algoritma bebas */
//     /*Kamus lokal*/
//     IdxType i, pass;
//     ElType temp;
//     /*Algoritma*/
//     if (NbElmt(*T)>1){
//     if(asc){
//         for(pass=IdxMin+1;pass<= GetLastIdx(*T);pass++){
//             temp = Elmt(*T, pass);
//             i= pass-1;
//             while ((temp < Elmt(*T,i)) && (i> IdxMin)){
//                 Elmt(*T, i+1) = Elmt(*T,i);
//                 i--;
//             }
//             if (temp >= Elmt(*T,i)){
//                 Elmt(*T, i+1) =temp;
//             } else {
//                 Elmt(*T, i+1) = Elmt(*T,i);
//                 Elmt(*T, i) = temp;
//             }
//         }
//     }else{
//         for(pass=IdxMin+1;pass<= GetLastIdx(*T);pass++){
//             temp = Elmt(*T, pass);
//             i= pass-1;
//             while ((temp > Elmt(*T,i)) && (i> IdxMin)){
//                 Elmt(*T, i+1) = Elmt(*T,i);
//                 i--;
//             }
//             if (temp <= Elmt(*T,i)){
//                 Elmt(*T, i+1) =temp;
//             } else {
//                 Elmt(*T, i+1) = Elmt(*T,i);
//                 Elmt(*T, i) = temp;
//             }
//         }
//     }
//     }
// }

// /* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
// /* *** Menambahkan elemen terakhir *** */
// void AddAsLastEl(TabInt *T, ElType X){
//     /* Proses: Menambahkan X sebagai elemen terakhir tabel */
//     /* I.S. Tabel T boleh kosong, tetapi tidak penuh */
//     /* F.S. X adalah elemen terakhir T yang baru */
//     if (IsFull(*T)){
//         GrowTab(T, 1);
//     }
//     Neff(*T) ++;
//     Elmt(*T, GetLastIdx(*T)) = X;
// }
// /* ********** MENGHAPUS ELEMEN ********** */
// void DelLastEl(TabInt *T, ElType *X){
// /* Proses : Menghapus elemen terakhir tabel */
// /* I.S. Tabel tidak kosong */
// /* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
// /*      Banyaknya elemen tabel berkurang satu */
// /*      Tabel T mungkin menjadi kosong */
//     *X = Elmt (*T, GetLastIdx(*T));
//     Neff(*T) --;  
// }

// void GrowTab(TabInt *T, int num){
//     /* Proses : Menambahkan max element sebanyTak num */
//     /* I.S. Tabel sudah terdefinisi */
//     /* F.S. Ukuran tabel bertambah sebanyak num */
//     MaxEl(*T) += num;
//     TI(*T) = realloc(TI(*T),(MaxEl(*T)+1)*sizeof(int));  
// }

// void ShrinkTab(TabInt *T, int num){
//     /* Proses : Mengurangi max element sebanyak num */
//     /* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
//     /* F.S. Ukuran tabel berkurang sebanyak num. */
//     MaxEl(*T) -= num ; 
//     TI(*T) = realloc(TI(*T),(MaxEl(*T)+1)*sizeof(int)); 
// }

// void CompactTab(TabInt *T){
//     /* Proses : Mengurangi max element sehingga Neff = MaxEl */
//     /* I.S. Tabel tidak kosong */
//     /* F.S. Ukuran MaxEl = Neff */
//     MaxEl(*T) = NbElmt(*T)+IdxMin-1 ; 
//     TI(*T) = realloc(TI(*T),(MaxEl(*T)+1)*sizeof(int)); 
// }