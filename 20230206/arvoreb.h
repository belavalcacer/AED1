//Declaração das estruturas

typedef struct No {
    int chave;
    struct No *esquerda;
    struct No *direita;
} No;

typedef struct ArvoreBinaria {
    No *raiz;
} ArvoreBinaria;

//Assinatura das funções
ArvoreBinaria* criarArvore();
No* criarNo(int chave);
void inserir(No **raiz, int chave);
void imprimirArvoreAux(No *raiz);
void imprimirArvore(ArvoreBinaria *arvore);
int contarElementosAux(No *raiz);
int contarElementos(ArvoreBinaria *arvore);
No* buscaElementoAux(No *raiz, int chave);
No* buscaElemento(ArvoreBinaria *arvore, int chave);
void preOrdem(No *raiz);
void inOrdem(No *raiz);
void posOrdem(No *raiz);