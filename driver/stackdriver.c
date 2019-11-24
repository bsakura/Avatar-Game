
#include <stdio.h>
#include "../Tubesrevisi/stackt.c"
#include "../Tubesrevisi/arraydin.c"
#include "../Tubesrevisi/console.c"
#include "../Tubesrevisi/player.c"
#include "../Tubesrevisi/listlinier.c"
#include "../Tubesrevisi/queue.c"
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