#include <stdio.h>
#include <stdlib.h>
#include "listEnc.h"

void criar(Lista* L){
	*L = NULL;
	printf("Lista inicializada\n");
}

int vazia(Lista L){
	if(L == NULL){
		return 1;
	}else{
		return 0;
	}
}


void inserirFim(Lista* L, int x){
	Lista novo, p, ant = NULL;
	novo = (Lista)malloc(sizeof(struct no));
	novo->item = x;
	p = *L;
	while(p != NULL){
		ant = p;
		p = p->prox;
	}
	if(ant == NULL){
		novo->prox = *L;
		*L = novo;
	}else{
		novo->prox = ant->prox;
		ant->prox = novo;
	}	
	printf("%d foi inserido no final da lista\n",x);	
}

void inserirIni(Lista* L, int x){
	Lista novo;
	novo = (Lista)malloc(sizeof(struct no));
	novo->item = x;
	novo->prox = *L;
	*L = novo;
	
	printf("%d foi inserido no inicio da lista\n", x);
}

void mostrar(Lista L){
	printf("[ ");
	while(L != NULL){
		printf("%d ", L->item);
		L = L->prox;
	}
	printf("]\n");
}

//REMOÇÃO
void remover(Lista* L, int n){
	if(vazia(*L)){
        printf("Impossivel remover: lista vazia!\n");
    }else{
        if((*L)->item == n){
            *L = (*L)->prox;
            printf("Item removido: %d\n",n);
        }else{
            Lista ant, aux;
            aux = *L;
            while(aux->prox != NULL && aux->item != n){
                ant = aux;
                aux = aux->prox;
            }
            if(aux->item == n){
                ant->prox = aux->prox;
                aux->prox = NULL;
                free(aux);
                printf("Item removido: %d\n",n);
            }else{
                printf("Item %d nao consta na lista\n",n);
            }
        }
    }
}

void removerFim(Lista* L){
	if(vazia(*L)){
        printf("Impossivel remover: lista vazia!\n");
    }else{
    	Lista aux, ant = NULL;
    	aux = *L;
    	while(aux->prox != NULL){
    		ant = aux;
			aux = aux->prox;
		}
		if(ant == NULL){
			*L = NULL;
			free(aux);
			printf("Item removido!\n");
		}else{
			ant->prox = NULL;
			free(aux);
	    	printf("Item removido!\n");
		}
		
    }
}

void removerIni(Lista* L){
	if(vazia(*L)){
        printf("Impossivel remover: lista vazia!\n");
    }else{
		Lista aux;
		aux = *L;
		*L = (*L)->prox;
		free(aux);
		printf("Item removido!\n");
	}
}

//PESQUISA
void pesquisar(Lista L, int x){
	if(vazia(L)){
		printf("Lista vazia. Elemento nao encontrado!\n");
	}else{
		int achou = 0, p = 0;
		while(L != NULL && achou == 0){
			if(L->item == x){
				achou = 1;
			}
			p++;
			L = L->prox;
		}
		if(achou){
			printf("%d se encontra na %d%c posicao da lista!\n", x, p, 166);
		}else{
			printf("%d nao se encontra na lista!\n", x);
		}
	}
}
