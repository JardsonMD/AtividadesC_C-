/*
	Regular - 3
	Ruim - 2
	Péssimo - 1
*/
typedef struct no* Lista;

struct no{
	char nome[30];
	Lista prox;
	int estado;
};

void estado(int x);
void criar(Lista* L);
int vazia(Lista L);
void inserir(Lista* L, char nome[], int estado);
void mostrar(Lista L);
void remover(Lista* L, char nome[]);
void pesquisar(Lista L, char nome[]);














Lista separa(Lista L, int valor);
Lista concatena(Lista L1, Lista L2);
