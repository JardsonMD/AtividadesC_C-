#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct aluno Aluno;

struct aluno{
    char nome[81];
    float nota;
};

int comp(const void* a1, const void* a2){
	char* d1 = (char*)a1;
	char* d2 = (char*)a2;
	if(d1 > d2){
		return -1;
	}else if(d1 < d2){
		return 1;
	}else{
		return strcmp((char*)d1, (char*)d2);
	}
}

int main(){
	int i, j, num;
	//Aluno* vet;
	printf("Digite o numero de alunos: ");
	scanf("%d", &num);
	Aluno vet[num];
	//vet = (Aluno*)malloc(num * sizeof(Aluno));
	fflush(stdin);
	
	for(i=0; i<num; i++){
		printf("Digite o nome do aluno: ");
		scanf("%[^\n]", vet[i].nome);
		/*vet[i].nome[0] = toupper(vet[i].nome[0]);
		for(j=0; vet[i].nome[j]!='\0'; j++){
			if(vet[i].nome[j] == ' '){
				vet[i].nome[j+1] = toupper(vet[i].nome[j+1]);
			}
			fflush(stdin);
		}*/
		
		printf("Digite a nota do aluno: ");
		scanf("%f", &vet[i].nota);
		fflush(stdin);
	}
	
	qsort(vet, num, sizeof(Aluno), comp);
	
	for(i=0; i<num; i++){
		printf("\n%s", vet[i].nome);
		printf("\n%0.2f", vet[i].nota);
	}
	return 0;
}

