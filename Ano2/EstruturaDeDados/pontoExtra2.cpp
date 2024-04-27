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
	return strcmp((char*)a1, (char*)a2);
}

int main(){
	int i, j, num;
	char alunoProc[81];
	Aluno* vet;
	char* achou;
	
	printf("Digite o numero de alunos: ");
	scanf("%d", &num);
	vet = (Aluno*)malloc(num * sizeof(Aluno));
	fflush(stdin);
	
	for(i=0; i<num; i++){
		printf("Digite o nome do aluno: ");
		scanf("%[^\n]", vet[i].nome);
		vet[i].nome[0] = toupper(vet[i].nome[0]);
		for(j=0; vet[i].nome[j]!='\0'; j++){
			if(vet[i].nome[j] == ' '){
				vet[i].nome[j+1] = toupper(vet[i].nome[j+1]);
			}
			fflush(stdin);
		}
		
		printf("Digite a nota do aluno: ");
		scanf("%f", &vet[i].nota);
		fflush(stdin);
	}
	
	qsort(vet, num, sizeof(Aluno), comp);
	
	printf("Digite o nome do aluno a ser procurado: ");
	scanf("%[^\n]", alunoProc);
	alunoProc[0] = toupper(alunoProc[0]);
	for(j=0; alunoProc[j]!='\0'; j++){
		if(alunoProc[j] == ' '){
			alunoProc[j+1] = toupper(alunoProc[j+1]);
		}
		fflush(stdin);
	}
	
	for(i=0; i<num; i++){
		printf("\n%s", vet[i].nome);
		printf("\n%0.2f", vet[i].nota);
	}
	
	achou = (char*) bsearch(alunoProc, vet, num, sizeof(Aluno), comp);
	
	if(achou == NULL){
		printf("\nNome nao encontrado!\n");
	}else{
		printf("\nNome encontrado!\nPonteiro: %d\nPosicao: %d", achou, (achou - (char*)vet)/sizeof(Aluno)+1);
	}
	return 0;
}
