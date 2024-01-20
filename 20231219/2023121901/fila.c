#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Função para inicializar a fila
void inicializarFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

// Função para verificar se a fila está vazia
int filaVazia(Fila *fila) {
    return (fila->inicio == NULL);
}

// Função para adicionar um avião à fila
void adicionarAviao(Fila *fila, Aviao aviao) {
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->aviao = aviao;
    novoNo->prox = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        fila->fim->prox = novoNo;
        fila->fim = novoNo;
    }

    printf("Aviao %s adicionado à fila.\n", aviao.nome);
}

// Função para listar o número de aviões aguardando na fila
void listarNumeroDeAvioes(Fila *fila) {
    int contador = 0;
    No *atual = fila->inicio;

    while (atual != NULL) {
        contador++;
        atual = atual->prox;
    }

    printf("Numero de aviões aguardando na fila: %d\n", contador);
}

// Função para autorizar a decolagem do primeiro avião da fila
void autorizarDecolagem(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Nenhum aviao aguardando na fila para decolagem.\n");
    } else {
        No *removido = fila->inicio;
        printf("Decolagem autorizada para o aviao %s (ID: %d).\n", removido->aviao.nome, removido->aviao.identificador);
        fila->inicio = removido->prox;

        free(removido);
    }
}

// Função para listar todos os aviões na fila de espera
void listarAvioesNaFila(Fila *fila) {
    No *atual = fila->inicio;

    printf("Aviões na fila de espera:\n");

    while (atual != NULL) {
        printf(" - %s (ID: %d)\n", atual->aviao.nome, atual->aviao.identificador);
        atual = atual->prox;
    }
}

// Função para listar as características do primeiro avião da fila
void listarCaracteristicasDoPrimeiroAviao(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Nenhum aviao aguardando na fila.\n");
    } else {
        printf("Características do primeiro aviao na fila:\n");
        printf(" - Nome: %s\n", fila->inicio->aviao.nome);
        printf(" - Identificador: %d\n", fila->inicio->aviao.identificador);
        // Adicione outras características conforme necessário
    }
}

