#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int buscaSeq(char **v, int tamanho, char nome[10]){
	int i;
	for(i=0; i<tamanho; i++){
		if(strcmp(v[i], nome) == 0){
			return 1;
		}
	}
	return 0;
}

int main(){
	int tam, i, resp;
	char nome[10], **lista;
	
	printf("Digite o tamanho da lista: ");
	scanf("%d", &tam);
	
	lista = (char**)malloc(tam * sizeof(char*));
	
	for(i=0; i<tam; i++){
		lista[i] = (char*)malloc(10 * sizeof(char));
	}
	
	for(i = 0; i<tam; i++){
		printf("Digite o %d nome (limite de 10 caracteres): ", i+1);
		scanf("%s", lista[i]);
	}
	printf("Digite o nome a ser procurado: ");
	scanf("%s", &nome);
	
	resp = buscaSeq(lista, tam, nome);
	
	if (resp){
		printf("A pessoa esta na lista!");
	}else{
		printf("A pessoa NAO esta na lista!");
	}
	
	

	return 0;
}

