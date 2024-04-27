//INTERFACE

typedef int Item;
typedef struct no *Lista;

struct no{
	Item dado;
	Lista prox;
};


Lista inserirNo(Item x, Lista L);
void inserirOrd(Item x, Lista *L);
void f(Lista *L);
void mostrar(Lista L);
int tamanho(Lista L);
int pertence(Item x, Lista L);
Lista clonar(Lista L);
Lista inverter(Lista L);
int ocorrencias(Item x, Lista L);
Item ultimo(Lista L);
int soma(Lista L);
void substitui(Item x, Item y, Lista *L);
int igual( Lista A, Lista B);
