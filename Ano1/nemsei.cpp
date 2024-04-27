#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "");
	srand((unsigned)time(NULL));
	int i, n, v[6], j, aux;
	for(i=0; i<6; i++){
		n=(rand()%60)+1;
		v[i]=n;
	}
	for(i=0;i<6;i++){
		n= v[i];
		for(j=0; j<6;j++){
			if(n==v[j] && i!=j){
				aux=(rand()%60)+1;
				v[j]=aux;
			}
		}
	}
	printf("--->>6 Números Aleatórios sem Repetições<<---\n");
	for(i=0; i<6; i++){
		printf("\t%dº número: ", i+1);
		printf("%2d\n", v[i]);
	}

	return 0;
}

