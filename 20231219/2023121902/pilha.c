#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Função para inicializar a pilha
void inicializarPilha(Pilha *pilha) {
    pilha->topo = NULL;
}

// Função para verificar se a pilha está vazia
int pilhaVazia(Pilha *pilha) {
    return (pilha->topo == NULL);
}

// Função para adicionar um avião ao hangar
void adicionarAviao(Pilha *pilha, Aviao aviao) {
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->aviao = aviao;
    novoNo->prox = pilha->topo;
    pilha->topo = novoNo;

    printf("Aviao %s adicionado ao hangar.\n", aviao.nome);
}

// Função para listar o número de aviões aguardando no hangar
void listarNumeroDeAvioes(Pilha *pilha) {
    int contador = 0;
    No *atual = pilha->topo;

    while (atual != NULL) {
        contador++;
        atual = atual->prox;
    }

    printf("Numero de aviões aguardando no hangar: %d\n", contador);
}

// Função para tirar o avião do topo do hangar
void tirarAviao(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Nenhum aviao aguardando no hangar.\n");
    } else {
        No *removido = pilha->topo;
        printf("Aviao %s removido do hangar.\n", removido->aviao.nome);
        pilha->topo = removido->prox;

        free(removido);
    }
}

// Função para listar todos os aviões no hangar
void listarAvioesNoHangar(Pilha *pilha) {
    No *atual = pilha->topo;

    printf("Aviões no hangar:\n");

    while (atual != NULL) {
        printf(" - %s (ID: %d)\n", atual->aviao.nome, atual->aviao.identificador);
        atual = atual->prox;
    }
}

// Função para listar as características do primeiro avião do hangar
void listarCaracteristicasDoPrimeiroAviao(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Nenhum aviao aguardando no hangar.\n");
    } else {
        printf("Características do primeiro aviao no hangar:\n");
        printf(" - Nome: %s\n", pilha->topo->aviao.nome);
        printf(" - Identificador: %d\n", pilha->topo->aviao.identificador);
        // Adicione outras características conforme necessário
    }
}

// Função para tirar um avião do hangar pela posição
void tirarAviaoPelaPosicao(Pilha *pilha, int posicao) {
    if (pilhaVazia(pilha)) {
        printf("Nenhum aviao aguardando no hangar.\n");
    } else {
        Pilha auxiliar;
        inicializarPilha(&auxiliar);

        // Transferir os aviões que não serão removidos para a pilha auxiliar
        for (int i = 1; i < posicao; i++) {
            if (pilhaVazia(pilha)) {
                printf("Posição inválida.\n");
                return;
            }

            No *transferido = pilha->topo;
            pilha->topo = transferido->prox;
            transferido->prox = auxiliar.topo;
            auxiliar.topo = transferido;
        }

        // Remover o avião da posição desejada
        No *removido = pilha->topo;
        pilha->topo = removido->prox;
        printf("Aviao %s removido do hangar pela posição %d.\n", removido->aviao.nome, posicao);
        free(removido);

        // Transferir os aviões de volta para o hangar
        while (!pilhaVazia(&auxiliar)) {
            No *transferido = auxiliar.topo;
            auxiliar.topo = transferido->prox;
            transferido->prox = pilha->topo;
            pilha->topo = transferido;
        }
    }
}

