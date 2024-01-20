//Definindo as estruturas necessarias

// Definindo a estrutura de um avião
typedef struct {
    char nome[50];
    int identificador;
    // Adicione outras características conforme necessário
} Aviao;

// Definindo a estrutura de um nó da pilha
typedef struct No {
    Aviao aviao;
    struct No *prox;
} No;

// Definindo a estrutura da pilha
typedef struct {
    No *topo;
} Pilha;

//Assinatura de funções

void inicializarPilha(Pilha *pilha);
int pilhaVazia(Pilha *pilha);
void adicionarAviao(Pilha *pilha, Aviao aviao);
void listarNumeroDeAvioes(Pilha *pilha);
void tirarAviao(Pilha *pilha);
void listarAvioesNoHangar(Pilha *pilha);
void listarCaracteristicasDoPrimeiroAviao(Pilha *pilha);
void tirarAviaoPelaPosicao(Pilha *pilha, int posicao);
