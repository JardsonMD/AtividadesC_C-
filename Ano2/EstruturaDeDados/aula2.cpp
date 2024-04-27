#include <stdio.h>
#include <stdlib.h>

int main(){
	
	float salario;
	printf("Digite o salario: ");
	scanf("%f", &salario);
	if(salario <= 5000){
		salario+= 1000;
	}
	printf("Salario final: %0.2fR$", salario);

	return 0;
}

