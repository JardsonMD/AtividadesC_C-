typedef struct no* Map; 
typedef char Chave[30];
typedef char Valor[30];

struct no{
	Chave chave;
	Valor valor;
	Map prox;
};

//void inseriNo(Chave c, Valor v, Map* M);
Map no_map(Chave c, Valor v, Map M);
void inserir(Chave c, Valor v, Map* M);
void exibe(Map M);
int remover(Chave c, Map *M);
int pertence(Chave c, Valor v, Map M);
void pegVal(Chave c, Map M);
