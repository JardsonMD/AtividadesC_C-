#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

Arv no(Arv A, Item x, Arv B){
	Arv novo = malloc(sizeof(struct arv));
	novo->esq = A;
	novo->item = x;
	novo->dir = B;
	return novo;
}

void emOrdem(Arv A){
	if(A != NULL){
		emOrdem(A->esq);
		printf("%d ", A->item);
		emOrdem(A->dir);
	}	
}

void preOrdem(Arv A){
	if(A != NULL){
		printf("%d ", A->item);
		preOrdem(A->esq);
		preOrdem(A->dir);
	}
}


void posOrdem(Arv A){
	if(A != NULL){
		posOrdem(A->esq);
		posOrdem(A->dir);
		printf("%d ", A->item);	
	}	
}

void destroi(Arv *A){
	if(*A != NULL){
		destroi(&(*A)->esq);
		destroi(&(*A)->dir);
		free(*A);
		*A = NULL;
	}
}

void inserir(Item x, Arv *A){
	if(*A == NULL){
		*A = no(NULL, x, NULL);
	}else{
		if(x < (*A)->item){
			inserir(x, &(*A)->esq);
		}else{
			inserir(x, &(*A)->dir);
		}
	}
}

int busca(Item x, Arv A){
	if(A == NULL){
		return 0;
	} 
	
	if( x == A->item){
		return 1;
	} 
	
	if( x < A->item){
		return busca(x, A->esq);
	}else{
		return busca(x, A->dir);
	}
}

Item removeMax(Arv *A){
	if(*A == NULL){
		abort();
	}
	while( (*A)->dir != NULL){
		A = &(*A)->dir;
	}
	Arv aux = *A;
	Item x = aux->item;
	*A = aux->esq;
	free(aux);
	return x;	
}

void remover(Item x, Arv *A){
	if( *A == NULL){
		printf("\nChave %d nao se encontra na arvore!\n", x);
		return;
	}
	if( x == (*A)->item){
		Arv aux = *A;
		if( aux->esq == NULL){
			*A = aux->dir;
		}else{
			if( aux->dir == NULL){
				*A = aux->esq;
			}else{
				aux->item = removeMax(&aux->esq);
			}
			if( aux != *A){
				free(aux);
			}
		}
	}else{
		if ( x < (*A)->item){
			remover(x,&(*A)->esq);
		}else{
			remover(x,&(*A)->dir);
		}
	} 
}

void criarFila(Fila* F){
	*F = NULL;
}

void inserirFila(Fila* F, Arv item){
	Fila novo, aux, ant = NULL;
	novo = (Fila)malloc(sizeof(struct no));
	novo->item = item;
	aux = *F;
	while(aux != NULL){
		ant = aux;
		aux = aux->prox;
	}
	if(ant == NULL){
		novo->prox = *F;
		*F = novo;
	}else{
		novo->prox = ant->prox;
		ant->prox = novo;
	}
	
}
Arv removerFila(Fila* F){
	Fila aux;
	aux = *F;
	*F = (*F)->prox;
	
	return aux->item;
	
}

void emNivel(Arv A){
	Fila fila;
	Arv x;
	criarFila(&fila);
	inserirFila(&fila, A);
	
	while(fila != NULL){
		x = removerFila(&fila);
		printf("%d ", x->item);
		if(x->esq != NULL){
			inserirFila(&fila, x->esq);
		}
		if(x->dir != NULL){
			inserirFila(&fila, x->dir);
		}
	}
	
}


