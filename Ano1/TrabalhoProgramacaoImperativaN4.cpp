#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int main(){
setlocale(LC_ALL, "");

int escolha, i, *inteiro;
char *numero, nomeArq[20];
FILE *arq, *arqs;

inteiro = (int*)calloc(50, sizeof(int));
numero = (char*)calloc(50, sizeof(char));

//Cria um arquivo de entrada de teste com numeros de 1 a 30 e o nome de 'entrada.txt'
/*arq = fopen("entrada.txt", "wt");

if(arq == NULL){
	printf("ERRO\nN�o foi possivel criar o arquivo.");
}else{
	printf("Arquivo criado com sucesso!\n");
	for(i=1; i<31; i++){
		fprintf(arq, "%d\n", i);
	}
	fclose(arq);
}
*/

//Pede o nome do arquivo de entrada
printf("Digite o nome do arquivo (Com o formato, Ex. 'entrada.txt'): ");
scanf("%s", &nomeArq);
system("CLS");

//Menu de op��es
printf("Op��es de Bases\n");
printf("1 - Bin�rio \n");
printf("2 - Octal \n");
printf("3 - Hexadecimal \n");
printf("Escolha um n�mero e aperte ENTER\n");
scanf("%d", &escolha);
system("CLS");

//Switch para cada escolha do menu de op��es (default = 0)
switch(escolha){
	case 1: 
		printf("Op��o escolhida 1 - Converter para Bin�rio\n");
		
		//Transformas todos os numeros do arquivo de entrada em inteiros e armazena eles no vetor 'inteiro'
		arq = fopen(nomeArq, "rt");
		if(arq == NULL){
			printf("Ocorreu um erro inesperado!");
		}else{
			i=0;
			while(fgets(numero, 50, arq) != NULL){
				inteiro[i] = atoi(numero);
				i++;
			}
			fclose(arq);
			
			//Crie o algoritmo de convers�o para BINARIO aqui
			.
			.
			.
			.
			
			//Apenas um delay e limpeza de tela antes da mensagem para ter melhor comprendimento
			Sleep(2000);
			system("CLS");
			printf("Convers�o feita com sucesso!");
		}
		break;
	case 2:
		printf("Op��o escolhida 2 - Converter para Octal\n");
	
		//Transformas todos os numeros do arquivo de entrada em inteiros e armazena eles no vetor 'inteiro'
		arq = fopen(nomeArq, "rt");
		if(arq == NULL){
			printf("Ocorreu um erro inesperado!");
		}else{
			i=0;
			while(fgets(numero, 50, arq) != NULL){
				inteiro[i] = atoi(numero);
				i++;
			}
			fclose(arq);
			
			//Crie o algoritmo de convers�o para OCTAL aqui
			.
			.
			.
			.
			
			//Apenas um delay e limpeza de tela antes da mensagem para ter melhor comprendimento
			Sleep(2000);
			system("CLS");
			printf("Convers�o feita com sucesso!");
		}
		break;
	case 3:
		printf("Op��o escolhida 3 - Converter para Hexadecimal\n");
	
		//Transformas todos os numeros do arquivo de entrada em inteiros e armazena eles no vetor 'inteiro'	
		arq = fopen(nomeArq, "rt");
		if(arq == NULL){
			printf("Ocorreu um erro inesperado!");
		}else{
			i=0;
			while(fgets(numero, 50, arq) != NULL){
				inteiro[i] = atoi(numero);
				i++;
			}
			fclose(arq);
			//Cria um arquivo de saida e coloca nele os inteiros do vetor 'inteiro' em formato hexadecimal
			arqs = fopen("saida.txt", "wt");
			if(arqs ==NULL){
				printf("Falha ao abrir o arquivo de saida!");
			}else{
				fprintf(arqs, "N�meros em Hexadecimal:\n");
				for(i=0; inteiro[i]!='\0'; i++){
					fprintf(arqs, "%X\n", inteiro[i]);
				}
				fclose(arqs);
			}
			//Apenas um delay e limpeza de tela antes da mensagem para ter melhor comprendimento
			Sleep(2000);
			system("CLS");
			printf("Convers�o feita com sucesso!");
		}
		
		break;
	default:
		printf("Programa Encerrado.");
}

	return 0;
}

