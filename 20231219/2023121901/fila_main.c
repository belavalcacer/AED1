#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
    Fila fila;
    inicializarFila(&fila);

    int opcao;
    Aviao novoAviao;

    do {
        printf("1. Digite o número de aviões na fila\n");
        printf("2. Autorizar decolagem\n");
        printf("3. Adicionar avião à fila\n");
        printf("4. Digite os aviões na fila de espera\n");
        printf("5. Digite as características do primeiro avião\n");
        printf("0. Sair\n");
        printf("Escolha a opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listarNumeroDeAvioes(&fila);
                break;
            case 2:
                autorizarDecolagem(&fila);
                break;
            case 3:
                printf("Digite o nome do aviao: ");
                scanf("%s", novoAviao.nome);
                printf("Digite o identificador do aviao: ");
                scanf("%d", &novoAviao.identificador);
                adicionarAviao(&fila, novoAviao);
                break;
            case 4:
                listarAvioesNaFila(&fila);
                break;
            case 5:
                listarCaracteristicasDoPrimeiroAviao(&fila);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
