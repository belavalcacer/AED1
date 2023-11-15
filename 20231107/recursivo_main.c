#include <stdio.h>
#include <stdlib.h>
#include "recursivo.h"


int main() {
    LISTA* lista = criarLista(8);

    // Inserindo elementos na lista
    inserirElemento(lista, 12, 0);
    inserirElemento(lista, 8, 1);
    inserirElemento(lista, 3, 2);
    inserirElemento(lista, 9, 3);
    inserirElemento(lista, 6, 4);
    inserirElemento(lista, 1, 5);
    inserirElemento(lista, 5, 6);
    inserirElemento(lista, 13, 7);



    inserirElementoOrdenado(lista, 4, 0);

    printf("Elementos da lista (recursivo): ");
    imprimirListaRecursivo(lista, 0);

  
    int elementoBusca = 15;
    int resultadoBusca = buscaBinariaRecursiva(lista->vetor, elementoBusca, 0, lista->tamanho - 1);
    if (resultadoBusca != elementoBusca) {
        printf("Elemento %d encontrado na posicao %d.\n", elementoBusca, resultadoBusca);
    } else {
        printf("Elemento %d nao encontrado na lista.\n", elementoBusca);
    }

    int maiorElemento = buscarMaiorRecursivo(lista, 0, lista->vetor[0]);
    printf("Maior elemento na lista: %d\n", maiorElemento);


    int menorElemento = buscarMenorRecursivo(lista, 0, lista->vetor[0]);
    printf("Menor elemento na lista: %d\n", menorElemento);


    int somaElementos = somaElementosRecursivo(lista, 0, 0);
    printf("Soma de todos os elementos: %d\n", somaElementos);


    int produtoElementos = produtoElementosRecursivo(lista, 0, 1);
    printf("Produto de todos os elementos: %d\n", produtoElementos);

    liberarLista(lista);

    return 0;
}