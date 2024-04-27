typedef int Item;


typedef struct arv* Arv;
typedef struct no* Fila;


struct arv{
	Arv esq;
	Item item;
	Arv dir;
};

struct no{
	Arv item;
	Fila prox;
};


Arv no(Arv A, Item x, Arv B);
void emOrdem(Arv A);
void posOrdem(Arv A);
void preOrdem(Arv A);
void destroi(Arv *A);
void inserir(Item x, Arv *A);
int busca(Item x, Arv A);
Item removeMax(Arv *A);
void remover(Item x, Arv *A);
void criarFila(Fila* F);
void inserirFila(Fila* F, Arv item);
Arv removerFila(Fila* F);
void emNivel(Arv A);
