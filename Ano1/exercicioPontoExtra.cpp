#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "");
	
	int b[20][20], i, j, l, c, k =0, aI, aJ;
	float a[5][5], soma=0;
	
	//Inicializando a Matriz B
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			k++;
			b[i][j]= k;
		}
	}
	
	//Printando a Matriz B
	printf("----------> Matriz B Dividida em Submatrizes<----------\n");
	for(i=0; i<20; i++){
		if(i%4 == 0 && i!=0){
			printf("\n");
		}
		for(j=0; j<20; j++){
			if(j%4 == 0 && j!=0){
				printf("\t");
			}
			printf("|%3d|", b[i][j] );
		}
		printf("\n");
	}
	
	//Adicionando as médias aritméticas das submatrizes da Matriz B para a Matriz A
	for(i=0, aI=0; i<20; i+=4, aI++){
		for(j=0, aJ=0; j<20; j+=4, aJ++){
			for(l=i; l<i+4; l++){
				for(c=j; c<j+4; c++){
					soma+=b[l][c];
				}
			}
			a[aI][aJ] = soma/16;
			soma=0;
		}
	}
	
	//Printando a Matriz A
	printf("\n\n----------> Matriz A <----------\n");
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("|%6.2f|", a[i][j]);
		}
		printf("\n");
	}
	printf("\nCada elemento é a Média Aritmética das Submatrizes de B");
	
	return 0;
}
