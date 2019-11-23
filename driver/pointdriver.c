#include "../Tubesrevisi/point.h"
#include <stdio.h>

void print_bool(boolean B){

    if (B) {
        printf("true");
    }
    else {
        printf("false");
    }
    }

void print_point(POINT P){
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
    }


int main(){



    POINT p2;
    float x,y;
    
    MakePOINT(x,y);

    TulisPOINT(p2);





return 0;
}