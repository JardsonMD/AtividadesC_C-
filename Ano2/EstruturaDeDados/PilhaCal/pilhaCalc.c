//IMPLEMANTAÇÃO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pilhaCalc.h"



void criar(Pilha* P){
	P->topo = -1;
	printf("Pilha inicializada!\n");
}
int vazia(Pilha P){
	return (P.topo == -1);
}
int cheia(Pilha P){
	return (P.topo == MAX-1);
}

void push(Pilha* P, float item){
	if(cheia(*P)){
		printf("OVERFLOW\n");
	}else{
		P->topo++;
		P->dados[P->topo] = item;
	}
}

float pop(Pilha* P){
	int x = -1;
	if(vazia(*P)){
		printf("UNDERFLOW\n");
	}else{		
		x = P->dados[P->topo];
		P->topo--;
	}
	return x;
}

float top(Pilha P){
	int x = -1;
	if(vazia(P)){
		printf("Pilha vazia\n");
	}else{		
		x = P.dados[P.topo];
	}
	return x;
}

void mostrar(Pilha P){
	printf("");
	while(!vazia(P)){
		printf("%d ", pop(&P));
	}
	printf("\n");
}
int verifOp(char op){
	switch(op){
		case '+':
		case '-':
			return 1;
		case '*':
			return 1;
		case '/':
			return 1;
		case '(':
			return 1;
		default:
			return 0;
	}
}

void convPosfixa(char* equacao, char* posF){
	Pilha p1;
    int i, j;
    iniciar(&p1);
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
            push(&p1,  (float)x);
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







