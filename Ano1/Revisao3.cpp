#include <stdio.h>
#include <stdlib.h>

float areaCubo(float i){
	float area;
	area = 6 * (i*i);
	return area;
}

int main(){
	float i, resp;
	printf("Digite um valor: ");
	scanf("%f",&i);
	resp = areaCubo(i);
	printf("Area: %0.2f", resp);
	
	return 0;
}

