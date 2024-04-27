/*
--| Nomes |-- 
Jardson Martins Damasceno
Eraldo Carneiro de Andrade Arraes Junior
Luis Felipe Silva de Melo
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int main(){
setlocale(LC_ALL, "");

int escolha, i, linhas = 1, *inteiro, aux, bin[8];
char *numero, nomeArq[20], espaco = '\n', c;
FILE *arq, *arqs;



//Cria um arquivo de entrada de teste com numeros de 1 a 30 e o nome de 'entrada.txt'
/*arq = fopen("entrada.txt", "wt");

if(arq == NULL){
	printf("ERRO\nNão foi possivel criar o arquivo.");
}else{
	printf("Arquivo criado com sucesso!\n");
	for(i=1; i<31; i++){
		fprintf(arq, "%d\n", i);
	}
	fclose(arq);
}
*/

//Pede o nome do arquivo de entrada
printf("Digite o nome do arquivo de entrada (Com o formato, Ex. 'entrada.txt'): ");
scanf("%s", &nomeArq);
system("CLS");

//Para contar o número de linhas do arquivo
arq = fopen(nomeArq, "r");
while(fread(&c, sizeof(char), 1, arq) != NULL){
	if(c == espaco){
		linhas++;
	}
}
fclose(arq);

//Allocando memória para vetores
inteiro = (int*)malloc(linhas * sizeof(int));
numero = (char*)malloc(linhas * sizeof(char));

//Menu de opções
printf("|Opções de Bases|\n");
printf("1 - Binário \n");
printf("2 - Octal \n");
printf("3 - Hexadecimal \n");
printf("Escolha um número e aperte ENTER\n");
scanf("%d", &escolha);
system("CLS");

//Transformas todos os numeros do arquivo de entrada em inteiros e armazena eles no vetor 'inteiro'
	arq = fopen(nomeArq, "rt");
	if(arq == NULL){
		printf("Ocorreu um erro inesperado!");
	}else{
		i=0;
		while(fgets(numero, linhas, arq) != NULL){
			inteiro[i] = atoi(numero);
			i++;
		}
		fclose(arq);
	}
	
//Switch para cada escolha do menu de opções
switch(escolha){
	case 1: 
		printf("Opção escolhida 1 - Converter para Binário\n");
			
		//Cria um arquivo de saida transforma os numeros do vetor 'inteiro' em binario e armazena no arquivo
		arqs = fopen("saida.txt", "wt");
		if(arqs == NULL){
			printf("Falha ao abrir o arquivo de saida!");
		}else{
			fprintf(arqs, "Números em Binário:\n");
			for(i=0; i<linhas; i++){
				for (aux = 7; aux >= 0; aux--)
			   {
			      if (inteiro[i] % 2 == 0)
			         bin[aux] = 0;
			      else
			         bin[aux] = 1;
			      inteiro[i] = inteiro[i] / 2;
			   }
			
			   for (aux = 0; aux < 8; aux++)
			       fprintf(arqs, "%d", bin[aux]);
			    fprintf(arqs, "\n");
			}
		}
		fclose(arqs);
			
		//Apenas um delay e limpeza de tela antes da mensagem para ter melhor comprendimento
		Sleep(2000);
		system("CLS");
		printf("Conversão feita com sucesso! Verifique o arquivo com o nome de 'saida.txt'.");
	
		break;
	case 2:
		printf("Opção escolhida 2 - Converter para Octal\n");
	
		//Cria um arquivo de saida e coloca nele os inteiros do vetor 'inteiro' em formato octal
		arqs = fopen("saida.txt", "wt");
		if(arqs ==NULL){
			printf("Falha ao abrir o arquivo de saida!");
		}else{
			fprintf(arqs, "Números em Octal:\n");
			for(i=0; i<linhas; i++){
				fprintf(arqs, "%o\n", inteiro[i]);
			}
			fclose(arqs);
		}
			
		//Apenas um delay e limpeza de tela antes da mensagem para ter melhor comprendimento
		Sleep(2000);
		system("CLS");
		printf("Conversão feita com sucesso! Verifique o arquivo com o nome de 'saida.txt'.");
	
		break;
	case 3:
		printf("Opção escolhida 3 - Converter para Hexadecimal\n");
	
		//Cria um arquivo de saida e coloca nele os inteiros do vetor 'inteiro' em formato hexadecimal
		arqs = fopen("saida.txt", "wt");
		if(arqs ==NULL){
			printf("Falha ao abrir o arquivo de saida!");
		}else{
			fprintf(arqs, "Números em Hexadecimal:\n");
			for(i=0; i<linhas; i++){
				fprintf(arqs, "%X\n", inteiro[i]);
			}
			fclose(arqs);
		}
		
		//Apenas um delay e limpeza de tela antes da mensagem para ter melhor comprendimento
		Sleep(2000);
		system("CLS");
		printf("Conversão feita com sucesso! Verifique o arquivo com o nome de 'saida.txt'.");
		
		break;
	default:
		printf("Programa Encerrado.");
}

free(inteiro);
free(numero);

	return 0;
}

