#include "mapeamento.h"

typedef struct dic* Dic;

struct dic{
	int tam;
	Map *vet;
};

int hash(Chave c, int m);
Dic dic(int m);
void insDic(Chave c, Valor v, Dic d);
void exibeDic(Dic d);
int remDic(Chave c, Dic d);
int pertDic(Chave c, Valor v, Dic d);
void trans(Chave c, Dic d);
