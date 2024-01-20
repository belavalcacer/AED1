//Definindo as estruturas necesárias

// Definindo a estrutura de um avião
typedef struct {
    char nome[50];
    int identificador;
} Aviao;

// Definindo a estrutura de um nó da fila
typedef struct No {
    Aviao aviao;
    struct No *prox;
} No;

// Definindo a estrutura da fila
typedef struct {
    No *inicio;
    No *fim;
} Fila;

//Assinatura das funções

void inicializarFila(Fila *fila);
int filaVazia(Fila *fila);
void adicionarAviao(Fila *fila, Aviao aviao);
void listarNumeroDeAvioes(Fila *fila);
void autorizarDecolagem(Fila *fila);
void listarAvioesNaFila(Fila *fila);
void listarCaracteristicasDoPrimeiroAviao(Fila *fila);