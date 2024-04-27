#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include "tp.h"


int main() {
	setlocale(LC_ALL, "");
	char eq[MAX], posf[MAX];
	printf("Digite a expressão: ");
	scanf("%[^\n]s", eq);
	convPosfixa(eq, posf);
	printf("Expressão em NPR: %s", posf);
	printf("\nResultado: %0.2f", posfResul(posf));



	
	

	
	
	return 0;
}
