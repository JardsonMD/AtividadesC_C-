#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listEnc.h"

int main() {
	Lista exemplo;
	char nome[30];
	int est;
	
	criar(&exemplo);
	printf("Informe o paciente e o seu estado ou SAIR para encerrar \n1 - Pessimo\n2 - Ruim\n3 - Regular");
	printf("\nNome: ");
	scanf("%s", nome);
	printf("Estado: ");
	scanf("%d", &est);
	
	while(strcmp(nome, "SAIR") != 0){
		inserir(&exemplo, nome, est);
		
		printf("Informe o paciente e o seu estado ou SAIR para encerrar: ");
		printf("\nNome: ");
		scanf("%s", nome);
		printf("Estado: ");
		scanf("%d", &est);
	}
	mostrar(exemplo);
	printf("Informe o paciente a ser pesquisado: ");
	scanf("%s", nome);
	pesquisar(exemplo, nome);
	printf("Informe o paciente a ser removido: ");
	scanf("%s", nome);
	remover(&exemplo, nome);
	mostrar(exemplo);
	return 0;
}
