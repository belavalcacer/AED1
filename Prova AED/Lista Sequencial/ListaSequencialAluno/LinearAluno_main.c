#include <stdio.h>
#include "LinearAluno.h"

int main()
{

    LISTA lista;
    int opcao, matricula;
    inicializar(&lista);
    do{
    printf("\nTabela:\n");
    printf("[1] Inserir um elemento\n");
    printf("[2] Exibir lista\n");
    printf("[3] Excluir um elemento\n");
    printf("[4] Buscar um elemento sequencialmente\n");
    printf("[5] Buscar um elemento por busca binaria\n");
    printf("[6] Quantidade de elementos\n");
    printf("[7] Finalizar.\n");
    scanf("%d", &opcao);
    switch(opcao){
        case 1:
            inserir(&lista);
            break;

        case 2:
            imprimir(&lista);
            break;
        case 3:
            printf("\nDigite a matricula que deseja excluir: ");
            scanf("%d", &matricula);
            excluir(&lista, matricula);
            break;
        case 4:
            printf("\nDigite a matricula que deseja buscar: ");
            scanf("%d", &matricula);
            busca(&lista, matricula);
            break;
        case 5:
            printf("\nDigite a matricula que deseja buscar: ");
            scanf("%d", &matricula);
            buscabin(&lista, matricula);
            break;
        case 6:
            quantidade(&lista);
            break;
        case 7:
            printf("\nFinalizando...");
        default:
            printf("\nSelecione um valor valido da tabela.");
            }
    }while(opcao!=7);
    return 0;
}