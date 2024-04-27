#include <stdio.h>
#include <stdlib.h>

int buscaBinDec(int *v, int tam, int n){
	int inicio = 0, fim = tam-1, meio, verif = 0;
	while(inicio <= fim && verif == 0){
		meio = (inicio + fim)/2;
		if(n == v[meio]){
			verif = 1;
		}else{
			if(n > v[meio]){
				fim = meio -1;
			}else{
				inicio = meio +1;
			}
		}
	}
	return verif;
}

int buscaBin(int *v, int tam, int n){
	int inicio = 0, fim = tam-1, meio, verif = 0;
	while(inicio <= fim && verif == 0){
		meio = (inicio + fim)/2;
		if(n == v[meio]){
			verif = 1;
		}else{
			if(n > v[meio]){
				inicio = meio +1;
			}else{
				fim = meio -1;
			}
		}
	}
	return verif;
}

int main(){
	int L[18] = {10, 16, 27, 31, 33, 37, 41, 49, 53, 57, 68,69, 72, 77, 84, 89, 95, 99};
	int M[18] = {99, 95, 89, 84, 77, 72, 69, 68, 57, 53, 49, 41, 37, 33, 31, 27, 16, 10};
	int perg, i, resp, num;
	
	printf("Quantas perguntas serao feitas? ");
	scanf("%d", &perg);
	
	for(i=0; i < perg; i++){
		printf("Qual numero vc quer verificar? ");
		scanf("%d", &num);
		resp = buscaBinDec(M, 18, num);
		if(resp){
			printf("O numero esta no vetor!\n");
		}else{
			printf("O numero NAO esta no vetor!\n");
		}
	}
	
	

	return 0;
}

