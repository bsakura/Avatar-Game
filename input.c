#include <stdio.h>
#include "mesinkar2.h"
int main(){
    START();
    char C;
    while (EOP!=-1){
        C= CC;
        if (CC=='\n'){
            printf("\n.\n");
        }else{
            printf("%c", CC);
        }
        ADV();
    }

    return 0;
}