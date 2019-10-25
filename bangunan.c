#include "bangunan.h"


void MakeBangunan(BANGUNAN *B,char jenis, int pemilik){
    jenis(*B)= jenis;
    pemilik(*B) = pemilik;
    level(*B)= 1; 
}