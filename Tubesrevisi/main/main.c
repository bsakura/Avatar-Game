#include "../boolean/boolean.h"
#include "../console/console.h"
#include "../consoleApp/consoleApp.h"
#include "../listlinier/listlinier.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("1. New Game\n2. Load Game\nPilih Aksi: ");
    int N;
    scanf("%d",&N);
    switch (N)
    {
    case 1:
        newG = true;
        newGame();
        break;
    
    default:
        newG= false;
        Load();
        break;
    }

    if (IsEmpty(L1)){
        printf("Player 2 Menang");
        outln();
    }else{
        printf("Player 1 Menang");
        outln();
    }
    return 0;
}
