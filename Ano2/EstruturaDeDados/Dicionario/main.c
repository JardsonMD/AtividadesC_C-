#include <stdio.h>
#include <stdlib.h>
#include "dicionario.h"

int main() {
	int tamanho, ret;
	Valor nome, resultado;
	Chave matricula, pal;
	Dic meuDic;
	printf("Informe o tamanho do dicionario: ");
	scanf("%d",&tamanho);
	meuDic = dic(tamanho);
	printf("Digite a palavra em ingles ou 'sair' pra encerrar: ");
	scanf("%s",&matricula);
	while(strcmp(matricula, "sair") != 0){
		fflush(stdin);
		printf("Digite a palavra em portugues: ");
		gets(nome);
		insDic(matricula, nome, meuDic);
		printf("Digite a palavra em ingles ou 'sair' pra encerrar: ");
		scanf("%s",&matricula);
	}
	exibeDic(meuDic);
	printf("Digite a palavra a ser traduzida ou 'sair pra encerrar': ");
	scanf("%s", pal);
	while(strcmp(pal, "sair") != 0){
		fflush(stdin);
		trans(pal, meuDic);
		printf("Digite a palavra a ser traduzida ou 'sair pra encerrar': ");
		scanf("%s", pal);
	}
	/*
	printf("Digite a chave a ser removida: ");
	scanf("%d",&matricula);
	ret = remDic(matricula, meuDic);
	if(ret){
		printf("Chave removida\n");
	}else{
		printf("Chave inexistente\n");
	}
	exibeDic(meuDic);

	printf("Digite a chave a ser pesquisada: ");
	scanf("%d",&matricula);
	ret = pertDic(matricula, resultado, meuDic);
	if(ret){
		printf("Chave encontrada. O valor eh %s\n", resultado);
	}else{
		printf("Chave inexistente\n");
	}
	*/
	return 0;
}
