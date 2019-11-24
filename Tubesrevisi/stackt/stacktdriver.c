#include "stackt.c"
#include "../arraydin/arraydin.c"
#include "../console/console.c"
#include "../listlinier/listlinier.c"
#include "../player/player.c"
#include "../queue/queue.c"
#include <stdio.h>
#include <stdlib.h>

int main(){
	Stack S;
	content C;
	TabInt T;
	Player P1, P2;
	List LA, LB;
	int i;
	MakeEmpty(&T, 5);
	MakePlayer(&P1, 1);
	MakePlayer(&P2, 2);
	CreateEmpty(&LA);
	CreateEmpty(&LB);
	CreateEmptyStack (&S);
	CreateContent(&C, T, P1, P2, LA, LB);
	if (IsEmptyStack(S)) {
		printf("!\n");
	}
	i = 1;
	while(!IsFullStack(S)) {
		Push (&S, C);
		printf("%d\n", i);
		i++;
	}
	while (!IsEmptyStack(S)) {
		Pop (&S, &C);
		printf("%d\n", i);
		i--;
	}
	return 0;
}