#include <stdio.h>
#include <stdlib.h>
#include "busca.h"


int main() {
    LISTA *minha_lista = Criar_lista(8);

    for (int i = 0; i < minha_lista->tamanho; i++) {
        Inserir_elemento(minha_lista, (i+1) * 3, i);
    }

    printf("Elementos da lista: ");
    Imprimir_lista(minha_lista);

    int elemento = 12;
    int posicao = Busca_sequencial(minha_lista, elemento);
    if (posicao != -1) {
        printf("Elemento %d na posição %d \n", elemento, posicao);
    } else {
        printf("Elemento %d não encontrado \n", elemento);
    }

    int elemento_ordenado = 8;
    posicao = Busca_sequencial_ordenada(minha_lista, elemento_ordenado);
    if (posicao != -1) {
        printf("Elemento %d na posição %d\n", elemento_ordenado, posicao);
    } else {
        printf("Elemento %d não encontrado .\n", elemento_ordenado);
    }

    int elemento_binario = 7;
    posicao = Busca_binaria(minha_lista, elemento_binario);
    if (posicao != -1) {
        printf("Elemento %d na posição %d \n", elemento_binario, posicao);
    } else {
        printf("Elemento %d não encontrado.\n", elemento_binario);
    }

    int maior = Busca_maior(minha_lista);
    printf("Maior elemento: %d\n", maior);

    int menor = Busca_menor(minha_lista);
    printf("Menor elemento: %d\n", menor);

    int soma = Calcula_soma(minha_lista);
    printf("Soma dos elementos: %d\n", soma);

    int produto = Calcula_produto(minha_lista);
    printf("Produto dos elementos: %d\n", produto);

    Libera_lista(minha_lista);

    return 0;
}