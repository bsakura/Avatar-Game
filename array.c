/*Nama: Naufal Arfananda Ghifari*/
/*NIM: 13518096*/
/*Tanggal: 3 09 2019 */
/*Implementasi prosedur fungsi array*/

#include<stdio.h>
#include "array.h"

/*prosedur MakeEmpty (TabInt * T)*/
void MakeEmpty (TabInt * T){
    Neff(*T) = 0;
}
/*fungsi NbElmt (TabInt T)*/
int NbElmt (TabInt T){
    return Neff(T);
}
/*fungsi MaxNbEl (TabInt T)*/
int MaxNbEl (TabInt T){
    return IdxMax+IdxMin-1 ;
}
/*fungsi GetFirstIdx (TabInt T)*/
IdxType GetFirstIdx (TabInt T){
    return IdxMin;
}
/*fungsi GetLastIdx (TabInt T) */
IdxType GetLastIdx (TabInt T){
    return Neff(T)+IdxMin-1;
}
/*fungsi IsIdxValid (TabInt T, IdxType i)*/
boolean IsIdxValid (TabInt T, IdxType i){
    return(i<=IdxMax && i>=IdxMin);
}
/*fungsi IsIdxEff (TabInt T, IdxType i)*/
boolean IsIdxEff (TabInt T, IdxType i){
    return(i<=Neff(T)+IdxMin-1 && i>=IdxMin);
}
/*fungsi IsEmpty (TabInt T) test 17*/
boolean IsEmpty (TabInt T){
    return(Neff(T)==0);
}
/* fungsi IsFull (TabInt T)*/
boolean IsFull (TabInt T){
    return(Neff(T)==IdxMax-IdxMin+1);
}
/*prosedur BacaIsi (TabInt * T)*/
void BacaIsi (TabInt * T){
    /*Kamus lokal*/
    ElType N;
    IdxType i;
    /*ALgoritma*/
    /*baca N*/
    do{
        scanf("%d",&N);
    }while (!(N>=0 && N <= MaxNbEl(*T)));
    Neff(*T) = N;
    for(i=IdxMin;i<=(N+IdxMin-1);i++){
        scanf("%d",&Elmt(*T,i));
    }
}
/*prosedur BacaIsiTab (TabInt * T) 61-69*/
void BacaIsiTab (TabInt * T){
    /*Kamus lokal*/
    IdxType i ;
    ElType E;
    /*ALgoritma*/
    i = IdxMin; /* Inisialisasi*/
    Neff(*T) = 0; /* Inisialisasi*/
    scanf("%d", &E);
    while(E != -9999 && (Neff(*T) != IdxMax-IdxMin +1)){
        Elmt(*T, i) = E;
        Neff(*T)++;
        i++;
        scanf("%d", &E);
    }
}
/*TulisIsi (TabInt T)*/
void TulisIsi (TabInt T){
    /*Kamus Lokal*/
    IdxType i;
    /*Algoritma*/
    if (IsEmpty(T)){
        printf("Tabel kosong\n");
    }
    for (i=IdxMin; i <= (Neff(T)+IdxMin -1); i++ ){
        printf("[%d]%d\n",i, Elmt(T,i));
    }
}
/*prosedur TulisIsiTab (TabInt T)*/
void TulisIsiTab (TabInt T){
    /*Kamus Lokal*/
    IdxType i;
    /*Algoritma*/
    printf("[");
    for (i=IdxMin; i <= (Neff(T)+IdxMin -1); i++){
        printf("%d",Elmt(T,i));
        if (i != (Neff(T)+IdxMin -1) ) /*IdxEffAkhir*/{
            printf(",");
        }
    }
    printf("]");
}
/*fungsi PlusTab (TabInt T1, TabInt T2)*/
TabInt PlusTab (TabInt T1, TabInt T2){
    /*Kamus Lokal*/
    IdxType i;
    TabInt T;
    /*Algoritma*/
    Neff(T) =Neff(T1); /*inisialisasi*/
    for (i=IdxMin; i <= (Neff(T)+IdxMin -1); i++ ){
        Elmt(T,i) = Elmt(T1,i) + Elmt(T2,i);
    }
    return T;
}
/*fungsi MinusTab (TabInt T1, TabInt T2)*/
TabInt MinusTab (TabInt T1, TabInt T2){
    /*Kamus Lokal*/
    IdxType i;
    TabInt T;
    /*Algoritma*/
    Neff(T) =Neff(T1); /*inisialisasi*/
    for (i=IdxMin; i <= (Neff(T)+IdxMin -1); i++ ){
        Elmt(T,i) = Elmt(T1,i) - Elmt(T2,i);
    }
    return T;
}
/*fungsi KaliTab (TabInt T1, TabInt T2)*/
TabInt KaliTab (TabInt T1, TabInt T2){
    /*Kamus Lokal*/
    IdxType i;
    TabInt T;
    /*Algoritma*/
    Neff(T) =Neff(T1); /*inisialisasi*/
    for (i=IdxMin; i <= (Neff(T)+IdxMin -1); i++ ){
        Elmt(T,i) = Elmt(T1,i) * Elmt(T2,i);
    }
    return T;
}
/*fungsi KaliKons (TabInt Tin, ElType c)*/
TabInt KaliKons (TabInt Tin, ElType c){
    /*Kamus Lokal*/
    IdxType i;
    TabInt T;
    /*Algoritma*/
    Neff(T) =Neff(Tin); /*inisialisasi*/
    for (i=IdxMin; i <= (Neff(T)+IdxMin -1); i++ ){
        Elmt(T,i) = c * Elmt(Tin,i);
    }
    return T;
}
/*fungsi IsEQ (TabInt T1, TabInt T2) */
boolean IsEQ (TabInt T1, TabInt T2){
    /*Kamus lokal*/
    boolean is;
    IdxType i;
    /*Algoritma*/
    is = true; /*inisialisasi*/
    if (Neff(T1) != Neff(T2)){
        is = false;
    } else{
        i=IdxMin;/*inisialisasi*/
        while (is && (i<=(Neff(T1)+IdxMin-1))) {
            if (Elmt(T1,i) != Elmt(T2,i)){
                is= false;
            }
            i++;
        }
    }
    return is;
}
/*fungsi IsELess(TabInt T1, TabInt T2) */
boolean IsLess(TabInt T1, TabInt T2){
    /*Kamus lokal*/
    /*boolean is;*/
    IdxType i;
    /*Algoritma*/
    for ( i = IdxMin; i < IdxMin+Neff(T1); i++) {
    if (Elmt(T1,i) == Elmt(T2,i))
            continue;
        return Elmt(T1,i) < Elmt(T2,i);
    }
    return NbElmt(T1) < NbElmt(T2);
    /*is=true;
    if(Neff(T1) < Neff(T2)){
            i = IdxMin;
            while (is && (i<=(Neff(T1)+IdxMin-1))) {
            if (Elmt(T1,i) > Elmt(T2,i)){
                is= false;
            }
            i++;
        }
        if (Elmt(T1, Neff(T1)) == Elmt (T2, Neff(T1))){
            is= false;
        }
    }else {
            i = IdxMin;
            while (is && (i<=(Neff(T2)+IdxMin-1))) {
            if (Elmt(T1,i) > Elmt(T2,i)){
                is= false;
            }
            i++;
        }
        if (Elmt(T1, Neff(T2) )== Elmt (T2, Neff(T2))){
            is= false;
        }
    }
    return is;*/
}
/*fungsi Search1 (TabInt T, ElType X)*/
IdxType Search1 (TabInt T, ElType X){
    /*Kamus Lokal*/
    IdxType i, idx;
    /*Algoritma*/
    idx = IdxUndef ; /*Inisialissasi*/
    for (i= Neff(T)+IdxMin-1; i >= IdxMin; i--){
        if (Elmt(T,i)==X){
            idx =i;
        }
    }
    return idx;
}
/*fungsi Search2 (TabInt T, ElType X)  test run 71-73*/  
IdxType Search2 (TabInt T, ElType X){
    /*Kamus Lokal*/
    IdxType i, idx;
    boolean found;
    /*Algoritma*/
    i = IdxMin; /*inisialisasi*/
    idx = IdxUndef; /*inisialisasi*/
    found =false;/*inisialisasi*/
    while (!(found) && i <=(Neff(T)+IdxMin-1)){
        if (Elmt(T,i)==X){
            found = true;
            idx = i;
        }
        i++;
    }
    return idx;
}
/* SearchB (TabInt T, ElType X)*/
boolean SearchB (TabInt T, ElType X){
    return (!(Search2(T,X)==IdxUndef));
}
/*SearchSentinel (TabInt T, ElType X) 75 -80*/
boolean SearchSentinel (TabInt T, ElType X){
    /*Kamus Lokal*/
    IdxType i;
    /*Algoritma*/
    i = Neff(T) - 1 +IdxMin;
    while ((i != (IdxMin-1)) && (Elmt(T,i) != X)){
        i--;
    }

    return i>=IdxMin;
}
/*fungsi ValMax (TabInt T)*/
ElType ValMax (TabInt T){
    /*Kamus Lokal*/
    IdxType i;
    ElType maks;
    /*Algoritma*/
    maks = Elmt(T,IdxMin);/*inisialisasi*/
    for (i=IdxMin +1; i <= (Neff(T)+IdxMin -1); i++ ){
        if (Elmt(T,i) > maks){
            maks = Elmt(T,i);
        }
    }
    return maks;
}
/*fungsi ValMin (TabInt T)*/
ElType ValMin (TabInt T){
    /*Kamus Lokal*/
    IdxType i;
    ElType  min;
    /*Algoritma*/
    min = Elmt(T,IdxMin);/*inisialisasi*/
    for (i=IdxMin +1; i <= (Neff(T)+IdxMin -1); i++ ){
        if (Elmt(T,i) < min){
            min = Elmt(T,i);
        }
    }
    return min;
}
/*fungsi IdxMaxTab (TabInt T) 83-85*/
IdxType IdxMaxTab (TabInt T){
    /*Kamus lokal*/
    IdxType idx;
    /*Algoritma*/
    idx = Search2(T,ValMax(T));
    return idx;
}
/*fungsi IdxMinTab (TabInt T) test case 83-85*/ 
IdxType IdxMinTab (TabInt T){
    /*Kamus lokal*/
    IdxType idx;
    /*Algoritma*/
    idx = Search2(T,ValMin(T));
    return idx;
}
/*prosedur CopyTab (TabInt Tin, TabInt * Tout)*/
void CopyTab (TabInt Tin, TabInt * Tout){
    *Tout = Tin;
}
/*fungsi InverseTab (TabInt T) 88-89*/
TabInt InverseTab (TabInt T){
    /*Kamus Lokal*/
    TabInt Tout;
    IdxType i;
    /*algo*/
    Neff(Tout) = Neff(T);
    for (i=IdxMin; i <= (Neff(T)+IdxMin -1); i++ ){
        Elmt(Tout,i) = Elmt(T,(Neff(T)+2*IdxMin-1-i));
    }
    return Tout;
}
/*fungsi IsSimetris (TabInt T) */
boolean IsSimetris (TabInt T){
    /*Kamus lokal*/
    boolean is;
    IdxType i;
    /*Algoritma*/
    is = true; /*inisialisasi*/
    i=IdxMin;/*inisialisasi*/
    while (is && (i<=(((Neff(T)+1)/2)+IdxMin-1))) {
        if (Elmt(T,i) != Elmt(T,(Neff(T)+2*IdxMin-1-i))){
                is= false;
        }
        i++;
    }
    return is;
}
/*MaxSortDesc (TabInt * T)*/
void MaxSortDesc (TabInt * T){
    /*Kamus lokal*/
    IdxType i, pass, iMax;
    ElType temp;
    /* Algoritma*/
    if (Neff(*T)>1){
        for (pass= IdxMin; pass <= Neff(*T)+IdxMin-2;pass++){
            iMax = pass;
            for(i=pass+1; i<= Neff(*T)+IdxMin-1;i++){
                if (Elmt(*T,iMax)< Elmt(*T,i)){
                    iMax = i;

                }
            }
            temp=Elmt(*T, iMax);
            Elmt(*T, iMax) = Elmt(*T, pass);
            Elmt(*T,pass) = temp;
        }
    }
}
/*prosedur InsSortAsc (TabInt * T)*/
void InsSortAsc (TabInt * T){
    /*Kamus lokal*/
    IdxType i, pass;
    ElType temp;
    /*Algoritma*/
    if (Neff(*T)>1){
        for(pass=IdxMin+1;pass<= Neff(*T)+IdxMin-1;pass++){
            temp = Elmt(*T, pass);
            i= pass-1;
            while ((temp < Elmt(*T,i)) && (i> IdxMin)){
                Elmt(*T, i+1) = Elmt(*T,i);
                i--;
            }
            if (temp >= Elmt(*T,i)){
                Elmt(*T, i+1) =temp;
            } else {
                Elmt(*T, i+1) = Elmt(*T,i);
                Elmt(*T, i) = temp;
            }
        }
    }

}
/*prosedur AddAsLastEl (TabInt * T, ElType X)*/
void AddAsLastEl (TabInt * T, ElType X){
    Neff(*T) ++;
    Elmt(*T, Neff(*T)+IdxMin-1) = X;
}
/*prosedur AddEli (TabInt * T, ElType X, IdxType i)*/
void AddEli (TabInt * T, ElType X, IdxType i){
    /*kamus lokal*/
    IdxType j;
    /*algoritma*/
    Neff(*T) ++;
    for (j=Neff(*T)+IdxMin-1;j>i;j--){
        Elmt(*T,j) = Elmt(*T, j-1);
    }
    Elmt(*T, i) =X;
}
/*prosedur DelLastEl (TabInt * T, ElType * X)*/
void DelLastEl (TabInt * T, ElType * X){
    *X = Elmt (*T, Neff(*T)+IdxMin-1);
    Neff(*T) --;     
}
/*prosedurDelEli (TabInt * T, IdxType i, ElType * X)*/
void DelEli (TabInt * T, IdxType i, ElType * X){
    /*kamus lokal*/
    IdxType j;
    /*algo*/
    *X = Elmt (*T, i);
    Neff(*T) --;   
    for (j=i;j<=Neff(*T)+IdxMin-1;j++){
        Elmt(*T,j) = Elmt(*T, j+1);        
    }
}
/*prosedur AddElUnik (TabInt * T, ElType X) 114-116*/
void AddElUnik (TabInt * T, ElType X){
    if (SearchSentinel(*T,X)){
        printf("nilai sudah ada\n");
    }else{
        Neff(*T) ++;
        Elmt(*T, Neff(*T)+IdxMin-1) = X;
    }
}
/*fungsi SearchUrut (TabInt T, ElType X test run 118-121*/
IdxType SearchUrut (TabInt T, ElType X){
    return(Search2(T,X));
}
/*fungsi MaxUrut (TabInt T) */
ElType MaxUrut (TabInt T){
    return(Elmt(T, Neff(T)+IdxMin-1));
}
/*fungsi MinUrut (TabInt T) */
ElType MinUrut (TabInt T){
    return(Elmt(T, IdxMin));
}
/*procedure MaxMinUrut (TabInt T, ElType * Max, ElType * Min)*/
void MaxMinUrut (TabInt T, ElType * Max, ElType * Min){
    *Max = MaxUrut (T);
    *Min = MinUrut (T);
}
/* procedure Add1Urut (TabInt * T, ElType X) test run 128-130*/
void Add1Urut (TabInt * T, ElType X){
    /*Kamus Lokal*/
    IdxType i;
    /* Algoritma*/
    if (IsFull(*T)){
        return;
    }
    for (i=IdxMin; i <= IdxMin + Neff(*T) -1; i++){
        if (Elmt(*T, i)> X){
            AddEli(T, X, i);
            return;
        }
    }
    AddEli(T, X, IdxMin + Neff(*T));
}
/* Del1Urut (TabInt * T, ElType X); test run 131 -134*/
void Del1Urut (TabInt * T, ElType X){
    /*Kamus lokal*/
    IdxType i;
    ElType Gaguna;
    /*Algoritma*/
    if (SearchB(*T,X)){
        i = Search2(*T,X);
        DelEli(T, i, &Gaguna);
    }
}
int NbOccX(TabInt T, Eltype X){
    //Kamus
    IdxType i;
    int count;
    //ALgoritma
    for (i = IdxMin; i< IdxMin +Neff(T);i++){
        If (X==ELMT(T,i)){
            count++;
        }
    }
    return count;
}

void ClosestPair (TabInt T, int *P1,int *P2){
    //Kamus
    int i;
    if (IsEmpty(T)||(Neff(T)==0)){
        *P1 = -999;
        *P2 = -999;
    } else {
        *P1 = Elmt(T, 1);
        *P2 = Elmt(T,2);
        for (i=IdxMin+1; i < IdxMin +Neff(T)-1; i++){
            if (abs(Elmt(T,i)-Elmt(T,i+1)) > abs(*P1-*P2){
                *P1= Elmt(T,i);
                *P2 = Elmt(T, i+1);
            }
        }
    }
}


boolean IsFront(TabInt T1,TabInt T2){
    //Kamus
    int i;
    if (Neff(T2)< Neff (T1)){
        return false;
    } else {
        i = IdxMin;
        while (Elmt(T1,i) == Elmt(T2, i) && (i<IdxMin+ Neff(T1)))  ){
            i++;
        }
        return (i == IdxMin + Neff(T) -1);
    }
}

































