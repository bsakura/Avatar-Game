#include "../arraydin/arraydin.c"
#include "../bangunan/bangunan.c"
#include "../boolean/boolean.h"
#include "../command/command.c"
#include "../console/console.c"
#include "../consoleApp/consoleApp.c"
#include "../graph/graph.c"
#include "../input/input.c"
#include "../listlinier/listlinier.c"
#include "../matriks/matriks.c"
#include "../mesinkata/mesinkata.c"
#include "../pcolor/pcolor.c"
#include "../player/player.c"
#include "../point/point.c"
#include "../queue/queue.c"
#include "../skill/skill.c"
#include "../stackt/stackt.c"
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