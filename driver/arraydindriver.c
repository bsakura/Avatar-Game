#include "../Tubesrevisi/arraydin.h"
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
    TabInt T1, T2;
    int maxel;
    MakeEmpty(&T1, maxel);
    MakeEmpty(&T2, maxel);
    CopyTab(T1,&T2);
    for (int i=GetFirstIdx(T2); i<=GetLastIdx(T2); i++){
        printf("%d", &TI(T2));
    }

}