#include <stdio.h>
#include <stdlib.h>
#include "rubronegra.h"

No* cria_arvore_rb()
{
    No* raiz = ( No*) malloc(sizeof(No));
    if(raiz != NULL)
        raiz = NULL;
    return raiz;
}

void libera_no(No* no)
{
    if(no == NULL)
        return;
    libera_no(no->esq);
    libera_no(no->dir);
    free(no);
    no = NULL;
}

void libera_arvore_rb( No **raiz)
{
    if(raiz == NULL)
        return;
    libera_no(*raiz);
    free(raiz);
}

int busca_no( No **raiz, int valor)
{
    if(raiz == NULL)
        return 0;
    No* atual = *raiz;
    while(atual != NULL)
    {
        if(valor == atual->dado)
            return 1;
        if(valor < atual->dado)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    return 0;
}


void achar_no(No **raiz, int valor)
{
    if(busca_no(raiz, valor))
        printf("No %d encontrado!!!", valor);
    else
        printf("No %d nao encontrado!!", valor);
}


No* rotaciona_esquerda(No* A)
{
    No* B = A->dir;
    A->dir = B->esq;
    B->esq = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

No* rotaciona_direita(No* A)
{
    No* B = A->esq;
    A->esq = B->dir;
    B->dir = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

int cor( No* H)
{
    if(H == NULL)
        return BLACK;
    else
        return H->cor;
}


void troca_cor( No* H)
{
    H->cor = !H->cor;
    if(H->esq != NULL)
        H->esq->cor = !H->esq->cor;
    if(H->dir != NULL)
        H->dir->cor = !H->dir->cor;
}


No* insere_no( No* H, int valor, int *resp)
{
    if(H == NULL)
    {
        No *novo;
        novo = ( No*)malloc(sizeof( No));
        if(novo == NULL)
        {
            *resp = 0;
            return NULL;
        }

        novo->dado = valor;
        novo->cor = RED;
        novo->dir = NULL;
        novo->esq = NULL;
        *resp = 1;
        return novo;
    }

    if(valor == H->dado)
        *resp = 0;// Valor já existe
    else
    {
        if(valor < H->dado)
            H->esq =  insere_no(H->esq,valor,resp);
        else
            H->dir =  insere_no(H->dir,valor,resp);
    }

    //Se o filho à direita é vermelho e o filho à esquerda é preto, rotacionar à esquerda
    if(cor(H->dir) == RED && cor(H->esq) == BLACK)
        H = rotaciona_esquerda(H);

    //Se o filho e neto à esquerda são vermelhos, rotacionar à direita
    if(cor(H->esq) == RED && cor(H->esq->esq) == RED)
        H = rotaciona_direita(H);

    //Se os dois filhos são vermelhos, trocar a cor
    if(cor(H->esq) == RED && cor(H->dir) == RED)
        troca_cor(H);

    return H;
}

int insere_arvore_rb( No **raiz, int valor)
{
    int resp;

    *raiz =  insere_no(*raiz,valor,&resp);
    if((*raiz) != NULL)
        (*raiz)->cor = BLACK;

    return resp;
}


No* balancear( No* H)
{
    //Se o filho direito é vermelho, rotacionar à esquerda
    if(cor(H->dir) == RED)
        H = rotaciona_esquerda(H);

    //Se o filho e neto à esquerda são vermelhos, rotacionar à direita
    if(H->esq != NULL && cor(H->esq) == RED && cor(H->esq->esq) == RED)
        H = rotaciona_direita(H);

    //Se os dois filhos são vermelhos, trocar a cor
    if(cor(H->esq) == RED && cor(H->dir) == RED)
        troca_cor(H);

    return H;
}

No* move_esquerda_ver( No* H)
{
    troca_cor(H);
    if(cor(H->dir->esq) == RED)
    {
        H->dir = rotaciona_direita(H->dir);
        H = rotaciona_esquerda(H);
        troca_cor(H);
    }
    return H;
}

No* move_direita_ver( No* H)
{
    troca_cor(H);
    if(cor(H->esq->esq) == RED)
    {
        H = rotaciona_direita(H);
        troca_cor(H);
    }
    return H;
}

No* remover_menor( No* H)
{
    if(H->esq == NULL)
    {
        free(H);
        return NULL;
    }
    if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK)
        H = move_esquerda_ver(H);

    H->esq = remover_menor(H->esq);
    return balancear(H);
}

No* procura_menor( No* atual)
{
    No *no1 = atual;
    No *no2 = atual->esq;
    while(no2 != NULL)
    {
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}


No* remover( No* H, int valor)
{
    if(valor < H->dado)
    {
        if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK)
            H = move_esquerda_ver(H);

        H->esq = remover(H->esq, valor);
    }

    else
    {
        if(cor(H->esq) == RED)
            H = rotaciona_direita(H);

        if(valor == H->dado && (H->dir == NULL))
        {
            free(H);
            return NULL;
        }

        if(cor(H->dir) == BLACK && cor(H->dir->esq) == BLACK)
            H = move_direita_ver(H);

        if(valor == H->dado)
        {
            No* x = procura_menor(H->dir);
            H->dado = x->dado;
            H->dir = remover_menor(H->dir);
        }

        else
            H->dir = remover(H->dir, valor);
    }
    return balancear(H);
}


int remove_no(No **raiz, int valor)
{
    if(busca_no(raiz,valor))
    {
         No* h = *raiz;
        *raiz = remover(h,valor);
        if(*raiz != NULL)
            (*raiz)->cor = BLACK;
        return 1;
    }
    else
    {
        printf("Nao foi possivel remover o no\n");
        return 0;
    }
}


int esta_vazia( No **raiz)
{
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}



int quantidade_de_no(No **raiz)
{
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;

    int alt_esq = quantidade_de_no(&((*raiz)->esq));
    int alt_dir = quantidade_de_no(&((*raiz)->dir));
    return (alt_esq + alt_dir + 1);
}



int altura_arvore( No **raiz)
{
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_arvore(&((*raiz)->esq));
    int alt_dir = altura_arvore(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}


void imprimir(No *root,int esp)
{
    if(root)
    {
        esp+=10;
        imprimir(root->dir,esp);
        printf("\n\n");
            for(int i= 10; i<esp; i++)
                printf(" ");
        printf("%d(%d)",root->dado,root->cor);
        imprimir(root->esq,esp);
    }
}