#include <stdio.h>
#include <stdlib.h>

int main(){

	int x;
	printf("Digite um inteiro: ");
	scanf("%d", &x);
	if(x==0){
		printf("O numero inteiro eh ZERO!");
	}else{
		printf("O numero NAO eh ZERO!");
	}
	return 0;
}

