typedef struct no* Lista;

struct no{
	int item;
	Lista prox;
};


void criar(Lista* L);
int vazia(Lista L);
void inserirFim(Lista* L, int x);
void inserirIni(Lista* L, int x);
void mostrar(Lista L);
void remover(Lista* L, int n);
void removerFim(Lista* L);
void removerIni(Lista* L);
void pesquisar(Lista L, int x);














Lista separa(Lista L, int valor);
Lista concatena(Lista L1, Lista L2);
