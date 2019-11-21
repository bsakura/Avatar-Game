#include "consoleApp.h"
#include <stdio.h>
#include "console.h"
#include "boolean.h"
int main(){
    printf("1. New Game\n2. Load Game\nPilih Aksi: ");
    int N;
    scanf("%d",&N);
    switch (N)
    {
    case 1:
        newG = true;
        StartGame();
        break;
    
    default:
        newG= false;
        Load();
        break;
    }
    return 0;
}