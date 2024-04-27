#include <stdio.h>
#include <stdlib.h>
#include "listEnc.h"

int main() {
	Lista exemplo;
	int valor, escolha;
	criar(&exemplo);
	printf("Inserir no final (1) ou Inicio (2) [0 para sair]: ");
	scanf("%d", &escolha);
	while(escolha != 0){
		if(escolha == 2){
			printf("Informe o valor: ");
			scanf("%d", &valor);
			inserirIni(&exemplo, valor);
		}else if(escolha == 1){
			printf("Informe o valor: ");
			scanf("%d", &valor);
			inserirFim(&exemplo, valor);
		}
		printf("Inserir no final (1) ou Inicio (2) [0 para sair]: ");
		scanf("%d", &escolha);
	}
	mostrar(exemplo);
	
	printf("Remover no final (1) ou Inicio (2) [0 para sair]: ");
	scanf("%d", &escolha);
	
	while(escolha != 0){
		if(escolha == 1){
			removerFim(&exemplo);
		}else if(escolha == 2){
			removerIni(&exemplo);
		}
		mostrar(exemplo);
		printf("Remover no final (1) ou Inicio (2) [0 para sair]: ");
		scanf("%d", &escolha);
	}
	
	return 0;
}
