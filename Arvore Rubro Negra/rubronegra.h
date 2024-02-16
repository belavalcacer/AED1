#define RED 1
#define BLACK 0

typedef struct arvore_rb No;
struct arvore_rb
{
    int dado;
    No *esq;
    No *dir;
    int cor;
};

//Assinatura das funções

No* cria_arvore_rb();
void libera_arvore_rb( No **raiz);
void achar_no(No **raiz, int valor);
No* insere_no( No* H, int valor, int *resp);
int insere_arvore_rb( No **raiz, int valor);
No* remover( No* H, int valor);
void imprimir(No *root,int esp);
int remove_no(No **raiz, int valor);