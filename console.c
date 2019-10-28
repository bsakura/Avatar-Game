#include <stdio.h>
#include "console.h"
#include "input.h"
void outln(){
    printf("\n");
}
int toInt(Kata K){
    int i, kali, res;
    res=0;
    kali = 1;
    for (i= K.Length; i>= 1; i--){
        res += ((int) K.TabKata[i] -'0')* kali;
        kali *= 10;
    }   
    return res;
}

void CetakKata(Kata K){
    int i;
    for(i=1; i<= K.Length; i++){
        printf("%c", K.TabKata[i]);
    }
}
char toChar(Kata K){
    return K.TabKata[1];
}
int main(){
    set(true);
    STARTKATA();
    // ADVKATA();
    // printf("%d", CKata.Length);
    // CetakKata(CKata);
    int M= toInt(CKata);
    printf("%d", M);
    return 0;
}