#include "point.h"
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

    POINT p1;
    BacaPOINT(&p1);

    POINT p2;
    BacaPOINT(&p2);

    TulisPOINT(p2);





return 0;
}