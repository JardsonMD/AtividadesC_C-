//INTERFACE
#define MAX 50

typedef struct pilha{
	double dados[MAX];
	int topo;
}Pilha;

void criar(Pilha* P);
int vazia(Pilha P);
int cheia(Pilha P);
void push(Pilha* P, double item);
double pop(Pilha* P);
double top(Pilha P);
void mostrar(Pilha P);
void convPosfixa(char* equacao, char* posF);
int prioridade(char x);
float posfResul(char* posF);
float operacao(float n1, float n2, char op);
