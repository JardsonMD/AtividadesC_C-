#include <stdio.h>
#include <stdlib.h>
#include "ppilha.h"


int main() {
	Pilha p1, p2;
	criar(&p1);
	criar(&p2);
	push(&p1, 1);
	push(&p1, 2);
	push(&p1, 3);
	push(&p2, 1);
	push(&p2, 2);
	push(&p2, 3);
	int x;
	x = iguais(p1,p2);
	printf("%d", x);
	
	return 0;
}
