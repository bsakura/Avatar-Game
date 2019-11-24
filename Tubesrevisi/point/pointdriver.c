#include "point.c"
#include <stdio.h>
#include <stdlib.h>

int main(){
    POINT p2;
    float x,y;
    scanf("%f %f", &x, &y);
    p2 = MakePOINT(x,y);

    TulisPOINT(p2);
    return 0;
}