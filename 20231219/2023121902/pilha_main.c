#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    Pilha hangar;
    inicializarPilha(&hangar);

    int opcao;
    Aviao novoAviao;
    int posicao;

    do {
        printf("\n----- Controle de Aviões no Hangar -----\n");
        printf("1. Listar número de aviões no hangar\n");
        printf("2. Tirar avião do hangar\n");
        printf("3. Adicionar avião ao hangar\n");
        printf("4. Listar aviões no hangar\n");
        printf("5. Listar características do primeiro avião no hangar\n");
        printf("6. Tirar avião do hangar pela posição\n");
        printf("0. Sair\n");
        printf("Escolha a opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listarNumeroDeAvioes(&hangar);
                break;
            case 2:
                tirarAviao(&hangar);
                break;
            case 3:
                printf("Digite o nome do aviao: ");
                scanf("%s", novoAviao.nome);
                printf("Digite o identificador do aviao: ");
                scanf("%d", &novoAviao.identificador);
                adicionarAviao(&hangar, novoAviao);
                break;
            case 4:
                listarAvioesNoHangar(&hangar);
                break;
            case 5:
                listarCaracteristicasDoPrimeiroAviao(&hangar);
                break;
            case 6:
                printf("Digite a posição do avião a ser removido: ");
                scanf("%d", &posicao);
                tirarAviaoPelaPosicao(&hangar, posicao);
                break;
            case 0:
                printf("Saindo do programa. Até mais!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);
    return 0;
}
