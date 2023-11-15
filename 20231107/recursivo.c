#include <stdio.h>
#include <stdlib.h>
#include "recursivo.h"

LISTA* criarLista(int tamanho) {
    LISTA* novaLista = (LISTA*)malloc(sizeof(LISTA));
    novaLista->vetor = (int*)malloc(tamanho * sizeof(int));
    novaLista->tamanho = tamanho;
    return novaLista;
}

void liberarLista(LISTA* lista) {
    free(lista->vetor);
    free(lista);
}

void inserirElemento(LISTA* lista, int elemento, int indice) {
    if (indice >= 0 && indice < lista->tamanho) {
        lista->vetor[indice] = elemento;
    } else {
        printf("Indice fora dos limites da lista.\n");
    }
}

void inserirElementoOrdenado(LISTA* lista, int elemento, int indice) {
    if (lista->tamanho <= 0) {
        printf("Lista vazia, nao foi possivel inserir o elemento ordenadamente.\n");
        return;
    }
    if (indice >= lista->tamanho || lista->vetor[indice] < elemento) {
        if (indice == lista->tamanho - 1 || lista->vetor[indice + 1] >= elemento) {
            lista->vetor[indice + 1] = elemento;
            return;
        }
        inserirElementoOrdenado(lista, elemento, indice + 1);
    } else {
        int temp = lista->vetor[indice];
        lista->vetor[indice] = elemento;
        inserirElementoOrdenado(lista, temp, indice + 1);
    }
}


int buscaBinariaRecursiva(int vetor[], int elemento, int inicio, int fim) {
    if (fim >= inicio) {
        int meio = inicio + (fim - inicio) / 2;
        if (vetor[meio] == elemento) {
            return meio;
        }
        if (vetor[meio] > elemento) {
            return buscaBinariaRecursiva(vetor, elemento, inicio, meio - 1);
        }
        return buscaBinariaRecursiva(vetor, elemento, meio + 1, fim);
    }
    return -1;
}

void imprimirListaRecursivo(LISTA* lista, int indice) {
    if (indice == lista->tamanho) {
        printf("\n");
        return;
    }
    printf("%d ", lista->vetor[indice]);
    imprimirListaRecursivo(lista, indice + 1);
}

int buscarMaiorRecursivo(LISTA* lista, int indice, int maiorAtual) {
    if (indice == lista->tamanho) {
        return maiorAtual;
    }
    if (lista->vetor[indice] > maiorAtual) {
        maiorAtual = lista->vetor[indice];
    }
    return buscarMaiorRecursivo(lista, indice + 1, maiorAtual);
}

int buscarMenorRecursivo(LISTA* lista, int indice, int menorAtual) {
    if (indice == lista->tamanho) {
        return menorAtual;
    }
    if (lista->vetor[indice] < menorAtual) {
        menorAtual = lista->vetor[indice];
    }
    return buscarMenorRecursivo(lista, indice + 1, menorAtual);
}

int somaElementosRecursivo(LISTA* lista, int indice, int somaAtual) {
    if (indice == lista->tamanho) {
        return somaAtual;
    }
    somaAtual += lista->vetor[indice];
    return somaElementosRecursivo(lista, indice + 1, somaAtual);
}

int produtoElementosRecursivo(LISTA* lista, int indice, int produtoAtual) {
    if (indice == lista->tamanho) {
        return produtoAtual;
    }
    produtoAtual *= lista->vetor[indice];
    return produtoElementosRecursivo(lista, indice + 1, produtoAtual);
}