#include <stdio.h>
#include <stdlib.h>

typedef struct janela{
	float xIni, yIni, xFim, yFim;
} Janela;

typedef struct linha{
	float xIni, yIni, xFim, yFim;
} Linha;

int main(){
	Janela espaco;
	Linha reta;
	printf("Digite o ponto Inicial e Final da janela de selecao: \nInicial: ");
	scanf("%f %f", &espaco.xIni, &espaco.yIni);
	printf("Fim: ");
	scanf("%f %f", &espaco.xFim, &espaco.yFim);
	
	int x, i;
	printf("Digite quantas retas serao colocadas: ");
	scanf("%d", &x);
	
	
	


	return 0;
}

