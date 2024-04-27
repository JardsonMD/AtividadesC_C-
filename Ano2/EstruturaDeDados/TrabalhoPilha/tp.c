//IMPLEMANTAÇÃO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tp.h"
#define MAX 50



void criar(Pilha* P){
	P->topo = -1;
	//printf("Pilha inicializada!\n");
}
int vazia(Pilha P){
	return (P.topo == -1);
}
int cheia(Pilha P){
	return (P.topo == MAX-1);
}

void push(Pilha* P, double item){
	if(cheia(*P)){
		printf("OVERFLOW\n");
	}else{
		P->topo++;
		P->dados[P->topo] = (double)item;
	}
}

double pop(Pilha* P){
	double x;
	if(vazia(*P)){
		printf("UNDERFLOW\n");
	}else{		
		x = P->dados[P->topo];
		P->topo--;
	}
	return x;
}

double top(Pilha P){
	double x;
	if(vazia(P)){
		printf("Pilha vazia\n");
	}else{		
		x = P.dados[P.topo];
	}
	return x;
}

void mostrar(Pilha P){
	printf("[");
	while(!vazia(P)){
		printf("%f ", pop(&P));
	}
	printf("]n");
}
float operacao(float n1, float n2, char op) {
    switch(op) {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            if (n2 == 0) {
                printf("\tErro: divisao por zero!\n");
                return 0.0;
            }
            return n1 / n2;
        default:
            printf("\tErro: operador invalido!\n");
            return 0.0;
    }
}

void convPosfixa(char* equacao, char* posF){
	Pilha p1;
    int i, j;
    criar(&p1);
    char x;

    for (i = 0, j = 0; equacao[i] != '\0'; i++) {
        x = equacao[i];
        if (isdigit(x)) {
            posF[j++] = x;
            while (isdigit(equacao[i + 1])) {
                posF[j++] = equacao[++i];
            }
            posF[j++] = ' ';
        } else if (x == '(') {
            push(&p1, (float)x);
        } else if (x == ')') {
            while (!vazia(p1) && top(p1) != '(') {
                posF[j++] = (char)pop(&p1);
                posF[j++] = ' ';
            }
            if (!vazia(p1) && top(p1) == '(') {
                pop(&p1);
            }
        } else if (x == '+' || x == '-' || x == '*' || x == '/') {
            while (!vazia(p1) && prioridade(x) <= prioridade(top(p1))) {
                posF[j++] = (char)pop(&p1);
                posF[j++] = ' ';
            }
            push(&p1, x);
        }
    }
    while (!vazia(p1)) {
        posF[j++] = (char)pop(&p1);
        posF[j++] = ' ';
    }
    posF[j] = '\0';
}
int prioridade(char x){
	switch(x){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '(':
			return 0;
		default:
			return -1;
	}
}

float posfResul(char* posF){
	char *pt;
    float resp ;
    float n1, n2;
    Pilha pilha;
    criar(&pilha);

    pt = strtok(posF, " ");
    while (pt != NULL) {
        if (isdigit(*pt)) {
            resp = atof(pt);
            push(&pilha, resp);
        } else {
            n2 = pop(&pilha);
            n1 = pop(&pilha);
            resp = operacao(n1, n2, *pt);
            push(&pilha, resp);
        }
        pt = strtok(NULL, " ");
    }
    if (vazia(pilha)) {
        printf("\tErro: nenhum calculo encontrado!\n");
    }

    resp = pop(&pilha);
    if (!vazia(pilha)) {
        printf("\tErro: sobrou mais de um valor na pilha!\n");
    }
    return resp;
}
































