//IMPLEMENTAÇÃO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

Map no_map(Chave c, Valor v, Map p){
	Map novo = (Map)malloc(sizeof(struct map));
	novo->chave = c;
	strcpy(novo->valor, v);
	novo->prox = p;
	return novo;
}

void inserir(Chave c, Valor v, Map *M){
	while(*M != NULL && (*M)->chave < c){
		M = &(*M)->prox;
	}
	if( *M != NULL && (*M)->chave == c){
		strcpy((*M)->valor, v);
	}else{
		*M = no_map(c,v,*M);
	}
}

int remover(Chave c, Map *M){
	while(*M != NULL && (*M)->chave < c){
		M = &(*M)->prox;
	}
	if( *M == NULL || (*M)->chave > c){
		return 0;
	}else{
		Map aux = *M;
		*M = aux->prox;
		free(aux);
		return 1;
	}
}

int pertence(Chave c, Valor v, Map M){
	while ( M != NULL && M->chave < c){
		M = M->prox;
	}
	if( M!= NULL && M->chave == c){
		strcpy(v, M->valor);
	}
	return( M != NULL && M->chave == c);
}

void exibe(Map M){
	printf("[");
	while( M != NULL){
		printf("(%d : %s)", M->chave, M->valor);
		if(M->prox != NULL){
			printf(", ");
		}
		M = M->prox;
	}
	printf("]\n");
}

void destroi(Map *M){
	Map aux;
	while( *M != NULL){
		aux = *M;
		*M = aux->prox;
		free(aux);
	}
}


void exibeEnd(Map M){
	printf("[");
	while( M != NULL){
		printf("(%X : %X : %X)", &M->chave, &M->valor, &M->prox);
		if(M->prox != NULL){
			printf(", ");
		}
		M = M->prox;
	}
	printf("]\n");
}

void menu(){
	printf("------------------- ~~ -------------------\n");
	printf("Escolha uma da opções abaixo:\n");
	printf("(I)nserir\n(R)emover\n(P)rocurar\n(L)istar\n(D)estruir\n(S)air\n");
	printf("------------------- ~~ -------------------\n");
}
void escolha(char resp, Map *M){
	Chave matricula;
	Valor nome;
	system("CLS");
	switch (resp){
		case 'i':
			printf("Digite a matricula: ");
			scanf("%d", &matricula);
			printf("Digite o nome: ");
			scanf("%s", nome);
			inserir(matricula, nome, M);
			break;
		case 'r':
			printf("Digite a matricula: ");
			scanf("%d", &matricula);
			remover(matricula, M);
			printf("Aluno removido!\n");
			break;
		case 'p':
			printf("Digite a matricula: ");
			scanf("%d", &matricula);
			printf("Digite o nome: ");
			scanf("%s", nome);
			if(pertence(matricula, nome, *M)){
				printf("Aluno está matriculado!\n");
			}else{
				printf("Aluno não matriculado!\n");
			}
			break;
		case 'l':
			exibe(*M);
			break;
		case 'd':
			destroi(M);
			printf("Destruido com sucesso!\n");
			break;
		case's':
			printf("Programa Encerrado!\n");
			break;
		default:
			printf("Resposta invalida!\n");
	}
			
}
