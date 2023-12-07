#include <stdio.h>
#include "lla.h"

int main (){
    ListaInteira lista;
    int opcao, matricula;
    InicializarEstrutura(&lista);
    do{
        printf("\nTabela:\n");
        printf("[1] Inserir um elemento\n");
        printf("[2] Exibir lista\n");
        printf("[3] Excluir um elemento\n");
        printf("[4] Buscar um elemento sequencialmente\n");
        printf("[5] Quantidade de elementos\n");
        printf("[6] Finalizar.\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                Inserir(&lista);
                break;

            case 2:
                ExibirLista(&lista);
                break;
            case 3:
                printf("\nDigite a matricula que deseja excluir: ");
                scanf("%d", &matricula);
                ExcluirElemento(&lista, matricula);
                break;
            case 4:
                printf("\nDigite a matricula que deseja buscar: ");
                scanf("%d", &matricula);
                int a = BuscarElemento(&lista, matricula);
                printf("posiçao: %d", a);
                break;
            case 5:
                printf("tamanho: %d", Tamanho(&lista));
                break;                
            case 6:
                printf("\nFinalizando...");  
            default:
                printf("\nSelecione um valor valido da tabela.");
        }
    } while(opcao != 6);
    return 0;
}