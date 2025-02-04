#include "input.h"
#include "../bangunan/bangunan.h"
#include "../console/console.h"
#include <stdio.h>
#include <stdlib.h>

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
            pita = fopen("../text/newgame.txt","r");
        }else{
            pita = fopen("../text/loadgame.txt","r");
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
    if (!useFile && CC=='\n'){
        EOP = -1;
    }else if(useFile) {
        EOP = retval;

        if (EOP==-1){
            fclose(pita);
        }
    }
}

