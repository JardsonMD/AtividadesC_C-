#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "mapStr.h"



int main() {
	setlocale(LC_ALL, "");

	Map mapa1 = NULL;
	char resp;
	
	menu();
	scanf(" %c", &resp);
	resp = tolower(resp);
	while(resp != 's'){
		resp = tolower(resp);
		escolha(resp, &mapa1);
		menu();
		scanf(" %c", &resp);
	}
	
	
	return 0;
}

