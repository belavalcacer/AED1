#include <stdio.h>
#include <stdlib.h>
#include "arvoreb.h"


int main() {
    ArvoreBinaria* minhaArvore = criarArvore();

    int elementos[] = {24, 10, 32, 5, 12, 29, 35};
    int numElementos = sizeof(elementos) / sizeof(elementos[0]);

    for (int i = 0; i < numElementos; i++) {
        inserir(&(minhaArvore->raiz), elementos[i]);
    }

    printf("Árvore em Pré-ordem: ");
    preOrdem(minhaArvore->raiz);
    printf("\n");

    printf("Árvore em In-ordem: ");
    inOrdem(minhaArvore->raiz);
    printf("\n");

    printf("Árvore em Pós-ordem: ");
    posOrdem(minhaArvore->raiz);
    printf("\n");

    printf("Número de elementos na árvore: %d\n", contarElementos(minhaArvore));

    return 0;
}