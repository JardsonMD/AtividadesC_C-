#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void estado(int x){
	switch(x){
		case 1:
			printf("Pessimo");
			break;
		case 2:
			printf("Ruim");
			break;
			
		case 3:
			printf("Regular");
			break;
	}
}

void inserir(Lista* L, char nome[], int estado){
	Lista novo, p, ant = NULL;
	novo = (Lista)malloc(sizeof(struct no));
	novo->estado = estado;
	strcpy(novo->nome, nome);
	p = *L;
	while(p != NULL && p->estado <= estado){
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
	printf("%s foi inserido na lista\n", nome);
}
void mostrar(Lista L){
	system("CLS");
	printf("[ ");
	while(L != NULL){
		printf("%s - ", L->nome);
		estado(L->estado);
		L = L->prox;
		if(L != NULL){
			printf(" | ");
		}
	}
	printf(" ]\n");
}

//REMOÇÃO
void remover(Lista* L, char nome[]){
	if(vazia(*L)){
        printf("Impossivel remover: lista vazia!\n");
    }else{
        if(strcmp((*L)->nome, nome) == 0){
            *L = (*L)->prox;
            printf("Item removido: %s\n", nome);
        }else{
            Lista ant, aux;
            aux = *L;
            while(aux->prox != NULL && strcmp(aux->nome, nome) != 0){
                ant = aux;
                aux = aux->prox;
            }
            if(strcmp(aux->nome, nome) == 0){
                ant->prox = aux->prox;
                aux->prox = NULL;
                free(aux);
                printf("Item removido: %s\n",nome);
            }else{
                printf("Item %s nao consta na lista\n",nome);
            }
        }
    }
}

//PESQUISA
void pesquisar(Lista L, char nome[]){
	if(vazia(L)){
		printf("Lista vazia. Elemento nao encontrado!\n");
	}else{
		int achou = 0, p = 0;
		while(L != NULL && achou == 0){
			if(strcmp(L->nome, nome) == 0){
				achou = 1;
			}
			p++;
			L = L->prox;
		}
		if(achou){
			printf("%s se encontra na %d%c posicao da lista!\n", nome, p, 166);
		}else{
			printf("%s nao se encontra na lista!\n", nome);
		}
	}
}
