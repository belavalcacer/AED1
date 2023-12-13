#include <stdio.h>
#include "ListaDinaicaAl.h"

int main (){
    ListaInteira lista;
    int opcao, matricula;
    Inicializar(&lista);
    do{
        printf("\nTabela:\n");
        printf("[1] Inserir um elemento\n");
        printf("[2] Exibir lista\n");
        printf("[3] Excluir um elemento\n");
        printf("[4] Quantidade de elementos validos\n");
        printf("[5] Finalizar.\n");
        printf("[6] Reiniciar.\n");
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
                printf("Quantidade de elementos validos: %d", Tamanho(&lista));
                break; 
            case 5:
                printf("\nFinalizando...");  
          case 6:
                Reiniciar(&lista);
                break;
            default:
                printf("\nSelecione um valor valido da tabela.");
        }
    } while(opcao != 5);
    return 0;
}