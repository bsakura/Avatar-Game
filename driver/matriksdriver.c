#include "../Tubesrevisi/matriks.h"
#include <stdio.h>

void print_bool(boolean B){

    if (B) {
        printf("true");
    }
    else {
        printf("false");
    }
}

int main(){
    MATRIKS M;
    MakeMATRIKS(&M,3,3);
    TulisMATRIKS(M);
    return 0;
}