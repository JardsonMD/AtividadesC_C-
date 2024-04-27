#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 30


int posicao(int x, int v[TAM]){
	srand(time(NULL));
	int i;
	for(i=0; i<TAM; i++){
		if(v[i] == x){
			return i;
		}
	}
	return -1;
}

int main(){
	int x, i, resp, vetor[TAM];
	
	printf("Digite o que vc quer achar: ");
	scanf("%d", &x);
	
	resp = posicao(x, vetor);
	printf("(Comecando por 0): %d", resp);
	printf("Confira:\n");
	for(i=0; i<TAM; i++){
		vetor[i] = rand() %100;
		printf("|%d| ", vetor[i]);
	}
	
	

	return 0;
}

