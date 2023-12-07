#include <stdio.h>
#include "lda.h"

int main (){
    ListaInteira lista;
    int opcao, matricula;
    Inicializar(&lista);
    do{
        printf("\nTabela:\n");
        printf("[1] Inserir um elemento\n");
        printf("[2] Exibir lista\n");
        printf("[3] Excluir um elemento\n");
        printf("[4] Buscar um elemento sequencialmente\n");
        printf("[5] Buscar um elemento ordenadamente\n");
        printf("[6] Quantidade de elementos\n");
        printf("[7] Finalizar.\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                Inserir(&lista);
                break;

            case 2:
                Exibir(&lista);
                break;
            case 3:
                printf("\nDigite a matricula que deseja excluir: ");
                scanf("%d", &matricula);
                ExcluirElemento(&lista, matricula);
                break;
            case 4:
                printf("\nDigite a matricula que deseja buscar: ");
                scanf("%d", &matricula);
                int a = BuscarSequencial(&lista, matricula);
                printf("posicao: %d", a);
                break;
            case 5:
                printf("\nDigite a matricula que deseja buscar: ");
                scanf("%d", &matricula);
                int b = BuscaSequencialOrdenada(&lista, matricula);
                printf("posicao: %d", b);
                break;          
            case 6:
                printf("tamanho: %d", Tamanho(&lista));
                break; 
            case 7:
                printf("\nFinalizando...");  
            default:
                printf("\nSelecione um valor valido da tabela.");
        }
    } while(opcao != 7);
    return 0;
}