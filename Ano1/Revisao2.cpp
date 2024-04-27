#include <stdio.h>
#include <stdlib.h>
#define TAM 2

typedef struct{
	int codigo;
	char nome[30];
	float renda;
}Cliente;

int main(){
	int i;
	Cliente vetor[TAM];
	for(i=0; i<TAM; i++){
		printf("Digite os dados do cliente numero %d\n", i+1);
		printf("Codigo: ");
		scanf("%d", &vetor[i].codigo);
		printf("Nome: ");
		scanf("%s", &vetor[i].nome);
		printf("Renda: ");
		scanf("%f", &vetor[i].renda);
	}
	for(i=0; i<TAM; i++){
		printf("Nome: %s\n", vetor[i].nome);
		printf("Limite de credito: %.2f\n", (float)vetor[i].renda*30/100);
	}

	return 0;
}

