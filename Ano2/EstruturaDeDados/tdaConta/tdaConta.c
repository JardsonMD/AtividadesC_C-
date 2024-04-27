//IMPLEMENTAÇÃO
#include <stdio.h>
#include <stdlib.h>
#include "tdaConta.h"

void abrirConta(Conta* c){
	printf("Informe o numero da conta: ");
	scanf("%d", &c->numero);
	fflush(stdin);
	printf("Informe o nome do titular: ");
	gets(c->titular);
	printf("Informe o saldo inicial: ");
	scanf("%f", &c->saldo);
	printf("Abertura de conta efetuada com sucesso!\n");
}

void creditar(Conta* c, float v){
	c->saldo = c->saldo + v;
	printf("Credito efetuado!\n");
}

void debitar(Conta* c, float v){
	if(c->saldo >= v){
		c->saldo = c->saldo - v - (0.0038 * v);
		printf("Debito efetuado!\n");
	}else{
		printf("Saldo insuficiente!\n");
	}
}

void transferir(Conta* c1, Conta* c2, float v){
	if(c1->saldo >= v){
		c1->saldo = c1->saldo - v;
		c2->saldo = c2->saldo + v;
		printf("Transferencia efetuada!\n");
	}else{
		printf("Saldo insuficiente. Nao foi possivel transferir!\n");
	}
}

void transferir2(Conta* c1, Conta* c2, float v){
	debitar(c1, v);
	creditar(c2, v);
}

void mostrar(Conta c){
	printf("Dados da conta %d\n", c.numero);
	printf("Nome do titular: %s\n", c.titular);
	printf("Saldo da conta: R$ %0.2f\n", c.saldo);
}

