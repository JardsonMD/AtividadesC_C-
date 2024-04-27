#include <stdio.h>
#include <stdlib.h>

int soma(int n){
	int resultado;
	if(n <= 1){
		resultado = 1;
	}else{
		resultado = n + soma(n-1);
	}
	return resultado;
}

int main(){
	int x, resul, aux = 1;
	
	while(aux){
		printf("Digite o numero a ser somado: ");
		scanf("%d", &x);
		resul = soma(x);
		printf("O resultado sera: %d", resul);
		printf("\nDigite 0 para PARAR e 1 para CONTINUAR\n");
		scanf("%d", &aux);
		system("CLS");
	}
		


	return 0;
}

