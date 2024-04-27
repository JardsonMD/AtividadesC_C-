//INTERFACE
#define MAX 6
struct pilha{
	int dados[MAX];
	int topo;
};

typedef struct pilha Pilha;

void criar(Pilha* P);
int vazia(Pilha P);
int cheia(Pilha P);
void push(Pilha* P, int item);
int pop(Pilha* P);
int top(Pilha P);
void mostrar(Pilha P);
int iguais(Pilha p1, Pilha p2);
