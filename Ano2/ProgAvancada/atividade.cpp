#include <stdio.h>
#include <stdlib.h>

void crescente(int a, int b, int c){
	int i, j, aux; 
	int vet [3] = {a, b, c};
	if(a == b && a == c){
		printf("Valores iguais!");
	}else{
		for(i = 0; i<2; i++){
			for(j = 0; j<3; j++){
				if (vet[j+1] > vet[j]){
					aux = vet[j];
					vet[j] = vet[j+1];
					vet[j+1] = aux;
				}
			}
		}
	
		printf("%d %d %d", vet[2], vet[1], vet[0]);
	}
}

int main(){
	
	int a, b ,c, resp;
	printf("Digite 3 valores inteiros: ");
	scanf("%d %d %d", &a, &b, &c);
	crescente(a, b, c);
	
	return 0;
}

