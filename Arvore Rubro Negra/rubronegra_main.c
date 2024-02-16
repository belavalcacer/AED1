#include <stdio.h>
#include <stdlib.h>
#include "rubronegra.h"


int main ()
{
    No *raiz = cria_arvore_rb();
    int esc=10, alt=0,num,qnt;


    while(esc!=0)
    {   
        printf("1 - Inserir\n2 - Imprimir\n3 - Remover no\n4 - Buscar no\n0 - Sair\n");
        scanf("%d", &esc);

        switch (esc)
        {
        case 1:
            scanf("%d", &num);
            insere_arvore_rb(&raiz, num);
            break;
        case 2:
            imprimir(raiz,0);
            printf("\n");
            break;
        case 3:
            printf("Insira o numeroque deseja remover: ");
            scanf("%d", &num);
            remove_no(&raiz, num);
            break;
        case 4:
            printf("Insira o numero que deseja procurar: \n");
            scanf("%d", &num);
            achar_no(&raiz, num);
            break;
        case 0:
            printf("\n\n\n\nSaindo...\n\n\n\n"); 
            break; 
        default:
            printf("Entrada invalida\n");
            break;
        }
    }
}