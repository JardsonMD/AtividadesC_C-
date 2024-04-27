#include <stdio.h>
#include <stdlib.h>
#include "Lencad.h"


int main(){
	int x;
	Lista lista1 = NULL, lista2 = NULL;
	
	printf("Digite o numero a ser inserido (0 para parar): ");
	scanf("%d", &x);
	while(x != 0){
		inserirOrd(x, &lista1);
		printf("Digite o numero a ser inserido (0 para parar): ");
		scanf("%d", &x);
	}
	printf("%d\n", soma(lista1));
	lista2 = inverter(lista1);
	mostrar(lista1);
	substitui(20, 5, &lista1);
	mostrar(lista1);
	return 0;
}
