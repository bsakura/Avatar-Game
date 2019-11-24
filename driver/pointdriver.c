#include "../Tubesrevisi/point.c"
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



    POINT p2;
    float x,y;
    scanf("%f %f", &x, &y);
    p2 = MakePOINT(x,y);

    TulisPOINT(p2);





return 0;
}