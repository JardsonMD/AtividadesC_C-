//INTERFACE
#define MAX 50

typedef struct pilha{
	char dados[MAX];
	int topo;
}Pilha;

void criar(Pilha* P);
int vazia(Pilha P);
int cheia(Pilha P);
void push(Pilha* P, float item);
float pop(Pilha* P);
float top(Pilha P);
void mostrar(Pilha P);
void convPosfixa(char* equacao, char* posF);
int prioridade(char x);





