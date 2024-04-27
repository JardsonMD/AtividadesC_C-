//INTERFACE
#define MAX 10

struct lista{
	int itens[MAX];
	int n;
};

typedef struct lista Lista;

void criar(Lista* L);
int vazia(Lista L);
int cheia(Lista L);
void inserir(Lista* L, int item, int pos);
void remover(Lista* L, int pos);
void exibir(Lista L);
void elementos(Lista L);
int retornaElemento(Lista L, int pos);
int retornaPos(Lista L, int item);
void esvazia(Lista* L);
