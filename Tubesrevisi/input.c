#include <stdio.h>
#include "bangunan.h"
#include <stdio.h>
#include "input.h"
#include "console.h"
char CC;
int EOP;
char MARK;
boolean useFile;
static FILE * pita;
static int retval;

void set(boolean use){
/*Konfigurasi mesin kata digunakan untuk membaca file atau std in
use true jika memakai file*/
    useFile = use;
    if (use){
        MARK = '\0';
    }else{
        MARK = '\n';
    }
}

void START() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    if (useFile){
        if (newG){
            pita = fopen("input.txt","r");
        }else{
            pita = fopen("out.txt","r");
        }
    } else{
        pita= stdin;
    }
    ADV();
}

void ADV() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela =
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK.
          Jika  CC = MARK maka EOP akan menyala (true) */
    /* Algoritma */
    retval = fscanf(pita,"%c",&CC);
    //EOP = retval;
    if (!useFile && CC=='\n'){
        EOP = -1;
    }else if(useFile) {
        EOP = retval;

        if (EOP==-1){
            fclose(pita);
        }
    }
}


// int main(){
//     set(true);
//     START();
//      char C;
//     // int N= CC;
//     // ADV();
//     // ADV();
//     // int M= CC;
//     // ADV());
//     while (EOP!=-1){
//         C= CC;
//         if (CC=='\n'){
//             printf("\n.\n");
//         }else{
//             printf("%c", CC);
//         }
//         ADV();
//     }

//     return 0;
// }

