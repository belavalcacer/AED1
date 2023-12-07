#include <stdio.h>
#include "ListaSeqInteiro.h"

int main()
{
    ListaLigada lista;
    int opcao, valor;
    InicializarEstrutura(&lista);

    do
    {
        printf("\nTabela:\n");
        printf("[1] Inserir um elemento\n");
        printf("[2] Exibir lista\n");
        printf("[3] Excluir um elemento\n");
        printf("[4] Buscar um elemento\n");
        printf("[5] Quantidade de elementos\n");
        printf("[6] Finalizar\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Insira um valor inteiro: ");
            scanf("%d", &valor);
            if (InserirElemento(&lista, valor) == -1)
            {
                printf("Erro: Lista está cheia.\n");
            }
            break;
        case 2:
            ExibirLista(&lista);
            break;
        case 3:
            printf("Digite o valor que deseja excluir: ");
            scanf("%d", &valor);
            ExcluirElemento(&lista, valor);
            break;
        case 4:
            printf("Digite o valor que deseja buscar: ");
            scanf("%d", &valor);
            int posicao = BuscarElemento(&lista, valor);
            if (posicao != -1)
            {
                printf("Valor %d encontrado na posição %d.\n", valor, posicao);
            }
            else
            {
                printf("Valor %d não encontrado.\n", valor);
            }
            break;
        case 5:
            printf("Quantidade de elementos na lista: %d\n", Tamanho(&lista));
            break;
        case 6:
            printf("Finalizando...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}