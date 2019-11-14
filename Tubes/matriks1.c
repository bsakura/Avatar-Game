// Nama: Naufal Arfananda Ghifari
// NIM : 13518096
// Tanggal : 17-9 2019

#include <stdio.h>
#include "boolean.h"
#include "matriks1.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
 void MakeMATRIKSS (int NB, int NK, MATRIKSS * M){
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
    NBrsEfff(*M) = NB;
    NKolEfff(*M) = NK;
}
// /* *** Selektor "DUNIA MATRIKS" *** */
// boolean IsIdxValid (int i, int j){
// /* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
//     return (i>=BrsMin && i<=BrsMax && j>=KolMin && j<=KolMax);
// }
// /* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
// indeks GetFirstIdxBrs (MATRIKS M){
// /* Mengirimkan indeks baris terkecil M */
//     return BrsMin;
// }
// indeks GetFirstIdxKol (MATRIKS M){
// /* Mengirimkan indeks kolom terkecil M */
//     return KolMin;
// }
// indeks GetLastIdxBrs (MATRIKS M){
// /* Mengirimkan indeks baris terbesar M */
//     return (BrsMin + NBrsEff(M) -1);
// }
// indeks GetLastIdxKol (MATRIKS M){
// /* Mengirimkan indeks kolom terbesar M */
//     return (KolMin + NKolEff(M) -1);
// }
// boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
// /* Mengirimkan true jika i, j adalah indeks efektif bagi M */
//     return (i>=GetFirstIdxBrs(M) && i<=GetLastIdxBrs(M) && j>=GetFirstIdxKol(M) && j<=GetLastIdxKol(M));
// }
// ElType GetElmtDiagonal (MATRIKS M, indeks i){
// /* Mengirimkan elemen M(i,i) */
//     return (Elmt(M,i,i));
// }

// /* ********** Assignment  MATRIKS ********** */
// void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
// /* Melakukan assignment MHsl  MIn */
//     *MHsl = MIn;
// }
// /* ********** KELOMPOK BACA/TULIS ********** */
// void BacaMATRIKS (MATRIKS * M, int NB, int NK){
// /* I.S. IsIdxValid(NB,NK) */
// /* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
// /* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
// /* Selanjutnya membaca nilai elemen per baris dan kolom */
// /* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
// 1 2 3
// 4 5 6
// 8 9 10
// */
//     NBrsEff(*M) = NB;
//     NKolEff(*M) = NK;
//     for (int i=GetFirstIdxBrs(*M); i<=GetLastIdxBrs(*M);i++){
//         for (int j=GetFirstIdxKol(*M) ; j<=GetLastIdxKol(*M); j++){
//             scanf("%d",&Elmt(*M,i,j));
//         }
//     }
// }
void TulisMATRIKSS (MATRIKSS M){
// /* I.S. M terdefinisi */
// /* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
//    dipisahkan sebuah spasi */
// /* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
// /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
// 1 2 3
// 4 5 6
// 8 9 10
// */
    for (int i=BrsMin; i<=BrsMin + NBrsEfff(M) -1;i++){
        for (int j=KolMin ; j<=KolMin + NKolEfff(M) -1; j++){
            printf("%d",Elmnt(M,i,j));
            if (j!=KolMin+NKolEfff(M) -1 ){
                printf(" ");
            }
        }
        if (i!=NBrsEfff(M) +BrsMin -1){
            printf("\n");
        }
    }
}
// /* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
// MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
// /* Prekondisi : M1  berukuran sama dengan M2 */
// /* Mengirim hasil penjumlahan matriks: M1 + M2 */
//     //Kamus Lokal 
//     MATRIKS M;
//     //Algoritma
//     NBrsEff(M) = NBrsEff(M1);
//     NKolEff(M) = NKolEff(M1);
//     for (int i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M);i++){
//         for (int j=GetFirstIdxKol(M) ; j<=GetLastIdxKol(M); j++){
//             Elmt(M,i,j) = Elmt(M1,i,j) + Elmt(M2,i,j);
//         }
//     }
//     return M;
// }
// MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
// /* Prekondisi : M berukuran sama dengan M */
// /* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
//     //Kamus Lokal 
//     MATRIKS M;
//     //Algoritma
//     NBrsEff(M) = NBrsEff(M1);
//     NKolEff(M) = NKolEff(M1);
//     for (int i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M);i++){
//         for (int j=GetFirstIdxKol(M) ; j<=GetLastIdxKol(M); j++){
//             Elmt(M,i,j) = Elmt(M1,i,j) - Elmt(M2,i,j);
//         }
//     }
//     return M;
// }
// MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
// /* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
// /* Mengirim hasil perkalian matriks: salinan M1 * M2 */
//     //Kamus
//     MATRIKS M;
//     int BK;
//     //ALgoritma
//     NBrsEff(M) = NBrsEff(M1);
//     NKolEff(M) = NKolEff (M2);
//     BK= NKolEff(M1);
//     for (int i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M);i++){
//         for (int j=GetFirstIdxKol(M) ; j<=GetLastIdxKol(M); j++){
//             Elmt(M,i,j) = 0;
//             for (int k=1; k<=BK;k++){
//                 Elmt(M,i,j) += Elmt(M1,i,k) * Elmt(M2,k,j);
//             }
//         }
//     }
//     return M;
// }    
// MATRIKS KaliKons (MATRIKS M, ElType X){
// /* Mengirim hasil perkalian setiap elemen M dengan X */
//     for (int i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M);i++){
//         for (int j=GetFirstIdxKol(M) ; j<=GetLastIdxKol(M); j++){
//             Elmt(M,i,j) *= X;
//         }
//     }
//     return M;
// }
// void PKaliKons (MATRIKS * M, ElType K){
// /* I.S. M terdefinisi, K terdefinisi */
// /* F.S. Mengalikan setiap elemen M dengan K */
//     for (int i=GetFirstIdxBrs(*M); i<=GetLastIdxBrs(*M);i++){
//         for (int j=GetFirstIdxKol(*M) ; j<=GetLastIdxKol(*M); j++){
//             Elmt(*M,i,j) *= K;
//         }
//     }
// }
// /* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
// boolean EQ (MATRIKS M1, MATRIKS M2){
// /* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
// /* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
// /* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
//    dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
//     if (!(EQSize(M1,M2))){
//         return false;
//     } else{
//         for (int i=GetFirstIdxBrs(M1); i<=GetLastIdxBrs(M1);i++){
//             for (int j=GetFirstIdxKol(M1) ; j<=GetLastIdxKol(M1); j++){
//                 if(Elmt(M1,i,j)!=Elmt(M2,i,j)){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// }
// boolean NEQ (MATRIKS M1, MATRIKS M2){
// /* Mengirimkan true jika M1 tidak sama dengan M2 */
//     return (!(EQ(M1,M2)));
// }
// boolean EQSize (MATRIKS M1, MATRIKS M2){
// /* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
// /* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
//     return (NBrsEff(M1)==NBrsEff(M2) && NKolEff(M1)==NKolEff(M2));
// }


// /* ********** Operasi lain ********** */
// int NBElmt (MATRIKS M){
// /* Mengirimkan banyaknya elemen M */
//     return (NBrsEff(M)*NKolEff(M));
// }
// /* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
// boolean IsBujurSangkar (MATRIKS M){
// /* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
//     return (NBrsEff(M)==NKolEff(M));
// }
// boolean IsSimetri (MATRIKS M){
// /* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
//    dan untuk setiap elemen M, M(i,j)=M(j,i) */
//     if (!IsBujurSangkar(M)){
//         return false;
//     } else {
//         for (int i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M);i++){
//             for (int j=GetFirstIdxKol(M) ; j<=GetLastIdxKol(M); j++){
//                 if(Elmt(M,i,j)!=Elmt(M,j,i)){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// }
// boolean IsSatuan (MATRIKS M){
// /* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
//    setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
//     if (!IsBujurSangkar(M)){
//         return false;
//     } else {
//         for (int i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M);i++){
//             for (int j=GetFirstIdxKol(M) ; j<=GetLastIdxKol(M); j++){
//                 if((i==j && Elmt(M,i,j)!=1)||(i!=j&&Elmt(M,i,j)!=0)){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// }
// boolean IsSparse (MATRIKS M){
// /* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
//    hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
//     //Kamus lokal
//     int Nmax , count;
//     //Algoritma
//     Nmax = 5 *NBElmt(M) /100;
//     count=0;
//     for (int i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M);i++){
//         for (int j=GetFirstIdxKol(M) ; j<=GetLastIdxKol(M); j++){
//             if(Elmt(M,i,j)!=0){
//                 count++;
//             }
//         }
//     }
//     return (Nmax>=count);
// }

// MATRIKS Inverse1 (MATRIKS M){
// /* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
//     return KaliKons(M,-1);
// }
// float Determinan (MATRIKS M){
// /* Prekondisi: IsBujurSangkar(M) */
// /* Menghitung nilai determinan M */
//     //mengguanakan metode OBE
//     //kamus lokal
//     int i , j, k,l;
//     float det;
//     int temp;
//     int Per,Peng;
//     //algoritma
//     det=1;
//     for (j=1;j<=GetLastIdxKol(M)-1;j++){
//         l=j;
//         while (Elmt(M,l,j)==0 && l<=GetLastIdxBrs(M)){
//             l++;
//         }
//         Per= Elmt(M,l,j);
//         for (i=l+1; i<=GetLastIdxBrs(M);i++){
//             Peng = Elmt(M,i,j);
//             for(k=j; k<=GetLastIdxKol(M);k++){
//                 Elmt(M,i,k) = Elmt(M,i,k)*Per - Elmt(M,l,k)*Peng;
//             }
            
//             det /=Per;
//         }
//         if (l!=j){
//             det *=-1;
//             for (i=1; 1<=GetLastIdxKol(M);i++){
//                 temp=Elmt(M,j,i);
//                 Elmt(M,j,i)=Elmt(M,l,i);
//                 Elmt(M,l,i) = temp;
//             }
//         }
        
//     }
//     for (i=1;i<=GetLastIdxBrs(M);i++){
//         det *= GetElmtDiagonal(M,i);
//     }
//     return det;
// }
// void PInverse1 (MATRIKS * M){
// /* I.S. M terdefinisi */
// /* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
//     PKaliKons(M,-1);
// }
// void Transpose (MATRIKS * M){
// /* I.S. M terdefinisi dan IsBujursangkar(M) */
// /* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
//     MATRIKS Ma = *M;
//     for (int i=GetFirstIdxBrs(Ma); i<=GetLastIdxBrs(Ma);i++){
//         for (int j=GetFirstIdxKol(Ma) ; j<=GetLastIdxKol(Ma); j++){
//             Elmt(Ma,i,j) =Elmt(*M,j,i);
//         }
//     }
//     *M=Ma;
// }
