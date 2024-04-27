#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include "pilhaCalc.h"


int main() {
	setlocale(LC_ALL, "");
	Pilha p1;
	char eq[MAX], posf[MAX];
	printf("Digite a expressão: ");
	scanf("%[^\n]s", eq);
	convPosfixa(eq, posf);
	


	
	

	
	
	return 0;
}
