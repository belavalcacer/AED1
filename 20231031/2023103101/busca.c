#include <stdio.h>
#include <stdlib.h>
#include "busca.h"

LISTA *Criar_lista(int tamanho) {
    LISTA *nova_lista = (LISTA *)malloc(sizeof(LISTA));
    if (nova_lista == NULL) {
        return NULL; 
    }
    nova_lista->tamanho = tamanho;
    nova_lista->vetor = (int *)malloc(tamanho * sizeof(int));
    if (nova_lista->vetor == NULL) {
        free(nova_lista);
        return NULL; 
    }
    return nova_lista;
}

void Libera_lista(LISTA *lista) {
    free(lista->vetor);
    free(lista);
}

void Inserir_elemento(LISTA *lista, int elemento, int posicao) {
    if (posicao >= 0 && posicao < lista->tamanho) {
        lista->vetor[posicao] = elemento;
    }
}
void Imprimir_lista(LISTA *lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->vetor[i]);
    }
    printf("\n");
}

int Busca_sequencial(LISTA *lista, int elemento) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->vetor[i] == elemento) {
            return i; 
        }
    }
    return -1; 
}
int Busca_sequencial_ordenada(LISTA *lista, int elemento) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->vetor[i] == elemento) {
            return i; 
        } else if (lista->vetor[i] > elemento) {
            return -1; 
        }
    }
    return -1;
}

int Busca_binaria(LISTA *lista, int elemento) {
    int inicio = 0;
    int fim = lista->tamanho - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (lista->vetor[meio] == elemento) {
            return meio; 
        } else if (lista->vetor[meio] < elemento) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1; 
}

int Busca_maior(LISTA *lista) {
    int maior = lista->vetor[0];
    for (int i = 1; i < lista->tamanho; i++) {
        if (lista->vetor[i] > maior) {
            maior = lista->vetor[i];
        }
    }
    return maior;
}

int Busca_menor(LISTA *lista) {
    int menor = lista->vetor[0];
    for (int i = 1; i < lista->tamanho; i++) {
        if (lista->vetor[i] < menor) {
            menor = lista->vetor[i];
        }
    }
    return menor;
}

int Calcula_soma(LISTA *lista) {
    int soma = 0;
    for (int i = 0; i < lista->tamanho; i++) {
        soma += lista->vetor[i];
    }
    return soma;
}

int Calcula_produto(LISTA *lista) {
    int produto = 1;
    for (int i = 0; i < lista->tamanho; i++) {
        produto *= lista->vetor[i];
    }
    return produto;
}