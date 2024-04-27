#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, dom, seg, ter, qua, qui, sex, sab;
	printf("Digite as temperaturas dos dias: ");
	printf("\nDomingo: ");
	scanf("%d", &dom);
	printf("Segunda: ");
	scanf("%d", &seg);
	printf("Terça: ");
	scanf("%d", &ter);
	printf("Quarta: ");
	scanf("%d", &qua);
	printf("Quinta: ");
	scanf("%d", &qui);
	printf("Sexta: ");
	scanf("%d", &sex);
	printf("Sabado: ");
	scanf("%d", &sab);
	
	printf("\nDOM: ");
	for(i=0; i<dom; i++){
		printf("#");
	}
	printf("\nSEG: ");
	for(i=0; i<seg; i++){
		printf("#");
	}
	printf("\nTER: ");
	for(i=0; i<ter; i++){
		printf("#");
	}
	printf("\nQUA: ");
	for(i=0; i<qua; i++){
		printf("#");
	}
	printf("\nQUI: ");
	for(i=0; i<qui; i++){
		printf("#");
	}
	printf("\nSEX: ");
	for(i=0; i<sex; i++){
		printf("#");
	}
	printf("\nSAB: ");
	for(i=0; i<sab; i++){
		printf("#");
	}
	
	


	return 0;
}

