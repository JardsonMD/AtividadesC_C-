//IMPLEMENTAÇÃO

#include <stdio.h>
#include <stdlib.h>
#include "Lencad.h"


Lista inserirNo(Item x, Lista L){
	Lista n = malloc(sizeof(struct no));
	n->dado = x;
	n->prox = L;
	return n;
}
void inserirOrd(Item x, Lista *L){
	while(*L != NULL && (*L)->dado < x){
		L = &(*L)->prox;
	}
		*L = inserirNo(x, *L);
}
void f(Lista *L){
	while(*L != NULL){
		Lista n = *L;
		*L = n->prox;
		free(n);
	}
}
void mostrar(Lista L){
		if(L == NULL){
			printf("\n");
			return;
		}else{
			printf("%d ", L->dado);
		}
		return mostrar(L->prox);
}
int tamanho(Lista L){
	if(L == NULL){
		return 0;
	}else{
		return 1 + tamanho(L->prox);
	}
}
int pertence(Item x, Lista L){
	if(L == NULL){
		return 0;
	}else if(x == L->dado){
		return 1;
	}
	return pertence(x, L->prox);
}
Lista clonar(Lista L){
	if(L == NULL){
		return NULL;
	}
	return inserirNo(L->dado, clonar(L->prox));
}
Lista inverter(Lista L){
	Lista n = NULL;
	while(L != NULL){
		n = inserirNo(L->dado, n);
		L = L->prox;
	}
	return n;
}
int ocorrencias(Item x, Lista L){
	int cont = 0;
	while(L != NULL){
		if(L->dado == x){
			cont++;
		}
		L = L->prox;
	}
	return cont;
}
Item ultimo(Lista L){
	while(L != NULL){
		if(L->prox == NULL){
			return L->dado;
		}
		L = L->prox;
	}
}
int soma(Lista L){
	if(L == NULL){
		return 0;
	}
	return L->dado + soma(L->prox);
}
void substitui(Item x, Item y, Lista *L){
	if((*L) == NULL){
		return;
	}else{
		if((*L)->dado == x){
			(*L)->dado = y;
		}
	}
	return substitui(x, y, &(*L)->prox);
}
int igual(Lista A, Lista B){
	if(A == NULL && B == NULL){
		return;
	}else{
		if(A->dado == B->dado){
			return 1;
		}else{
			return 0;
		}
	}
	return igual(A->prox, B->prox);
}





