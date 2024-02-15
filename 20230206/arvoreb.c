#include <stdio.h>
#include <stdlib.h>
#include "arvoreb.h"

ArvoreBinaria* criarArvore() {
    ArvoreBinaria* novaArvore = (ArvoreBinaria*)malloc(sizeof(ArvoreBinaria));
    novaArvore->raiz = NULL;
    return novaArvore;
}

No* criarNo(int chave) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->chave = chave;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

void inserir(No **raiz, int chave) {
    if (*raiz == NULL) {
        *raiz = criarNo(chave);
    } else {
        if (chave < (*raiz)->chave) {
            inserir(&((*raiz)->esquerda), chave);
        } else if (chave > (*raiz)->chave) {
            inserir(&((*raiz)->direita), chave);
        }
    }
}

void imprimirArvoreAux(No *raiz) {
    if (raiz != NULL) {
        imprimirArvoreAux(raiz->esquerda);
        printf("%d ", raiz->chave);
        imprimirArvoreAux(raiz->direita);
    }
}

void imprimirArvore(ArvoreBinaria *arvore) {
    imprimirArvoreAux(arvore->raiz);
    printf("\n");
}

int contarElementosAux(No *raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        return 1 + contarElementosAux(raiz->esquerda) + contarElementosAux(raiz->direita);
    }
}

int contarElementos(ArvoreBinaria *arvore) {
    return contarElementosAux(arvore->raiz);
}

No* buscaElementoAux(No *raiz, int chave) {
    if (raiz == NULL || raiz->chave == chave) {
        return raiz;
    }
    if (chave < raiz->chave) {
        return buscaElementoAux(raiz->esquerda, chave);
    }
    return buscaElementoAux(raiz->direita, chave);
}

No* buscaElemento(ArvoreBinaria *arvore, int chave) {
    return buscaElementoAux(arvore->raiz, chave);
}

void preOrdem(No *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void inOrdem(No *raiz) {
    if (raiz != NULL) {
        inOrdem(raiz->esquerda);
        printf("%d ", raiz->chave);
        inOrdem(raiz->direita);
    }
}

void posOrdem(No *raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->chave);
    }
}

