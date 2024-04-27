//CLIENTE
#include <stdio.h>
#include <stdlib.h>
#include "lst.h"
int main(int argc, char *argv[]) {
	Lista lista1;
	int teste1, teste2;
	criar(&lista1);
	printf("Vazia?: %d\n", vazia(lista1));
	printf("Cheia?: %d\n", cheia(lista1));
	
	exibir(lista1);
	inserir(&lista1, 10, 0);
	exibir(lista1);
	inserir(&lista1, 5, 0);
	exibir(lista1);
	inserir(&lista1, 50, 1);
	inserir(&lista1, 15, 1);
	inserir(&lista1, 8, 1);
	exibir(lista1);
	remover(&lista1, 1);
	exibir(lista1);
	inserir(&lista1, 7, 2);
	exibir(lista1);
	elementos(lista1);
	teste1 = retornaItem(lista1, 4);
	printf("Item na posicao 4: %d\n", teste1);
	teste2 = retornaPos(lista1, 7);
	printf("7 na posicao: %d\n", teste2);
	esvazia(&lista1);
	exibir(lista1);
	
	return 0;
}
