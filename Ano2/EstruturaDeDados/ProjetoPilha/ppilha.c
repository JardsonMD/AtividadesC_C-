//IMPLEMENTAÇÃO
#include <stdio.h>
#include <stdlib.h>
#include "ppilha.h"

void criar(Pilha* P){
	P->topo = -1;
	printf("Pilha inicializada!\n");
}
int vazia(Pilha P){
	return (P.topo == -1);
}
int cheia(Pilha P){
	return (P.topo == MAX-1);
}

void push(Pilha* P, int item){
	if(cheia(*P)){
		printf("OVERFLOW\n");
	}else{
		P->topo++;
		P->dados[P->topo] = item;
		printf("%d foi empilhado\n", item);
	}
}

int pop(Pilha* P){
	int x = -1;
	if(vazia(*P)){
		printf("UNDERFLOW\n");
	}else{		
		x = P->dados[P->topo];
		P->topo--;
	}
	return x;
}

int top(Pilha P){
	int x = -1;
	if(vazia(P)){
		printf("Pilha vazia\n");
	}else{		
		x = P.dados[P.topo];
	}
	return x;
}

void mostrar(Pilha P){
	printf("[ ");
	while(!vazia(P)){
		printf("%d ", pop(&P));
	}
	printf("]\n");
}
int iguais(Pilha p1, Pilha p2){
	while(pop(&p1) == pop(&p2)){
		if(vazia(p1) && vazia(p2)){
			return 1;
		}
	}
	return 0;
}
