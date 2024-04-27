//INTERFACE

struct conta{
	int numero;
	char titular[30];
	float saldo;
};

typedef struct conta Conta;

void abrirConta(Conta* c);
void creditar(Conta* c, float v);
void debitar(Conta* c, float v);
void transferir(Conta* c1, Conta* c2, float v);
void transferir2(Conta* c1, Conta* c2, float v);
void mostrar(Conta c);
