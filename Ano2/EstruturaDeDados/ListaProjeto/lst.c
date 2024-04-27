//IMPLEMENTAÇÃO
#include <stdio.h>
#include <stdlib.h>
#include "lst.h"

void criar(Lista* L){
	L->n = 0;
	printf("Lista inicializada com sucesso!!!\n");
}

int vazia(Lista L){
	return(L.n == 0);
}
int cheia(Lista L){
	return(L.n == MAX);
}

void inserir(Lista* L, int item, int pos){
	if(cheia(*L) || pos > L->n || pos < 0){
		printf("Nao eh possivel inserir.\n");
	}else{
		int i;
		for(i=L->n - 1; i >= pos; i--){
			L->itens[i+1] = L->itens[i];
		}
		L->itens[pos] = item;
		L->n++;
		printf("%d foi inserido no indice %d.\n", item, pos);
	}
}

void remover(Lista* L, int pos){
	if(vazia(*L) || pos < 0 || pos >= L->n){
		printf("Nao foi possivel remover\n");
	}else{
		int i;
		for(i=pos; i < L->n - 1; i++){
			L->itens[i] = L->itens[i+1];
		}
		L->n--;
		printf("O item do indice %d foi removido\n", pos);
	}
}

void exibir(Lista L){
	int i;
	printf("[ ");
	for(i=0; i<L.n; i++){
		printf("%d ", L.itens[i]);
	}
	printf("]\n");
}
void elementos(Lista L){
	printf("Existem %d elementos na lista!\n", L.n);
}
int retornaItem(Lista L, int pos){
	if(vazia(L) || pos < 0 || pos >= L.n){
		printf("Posicao invalida!\n");
	}else{
		return L.itens[pos];
	}
}
int retornaPos(Lista L, int item){
	int i;
	for(i=0; i < L.n; i++){
		if(L.itens[i] == item){
			return i;
		}
	}
	printf("Item nao encoontrado!\n");
}
void esvazia(Lista* L){
	if(vazia(*L)){
		printf("Lista ja esta vazia!\n");
	}else{
		L->n = 0;
		printf("Lista esvaziada!\n");
	}
}
