#include <stdio.h>
#include "Pessoa.h"

int main() {
    Pessoa *pessoa = (Pessoa *) malloc(sizeof(Pessoa));
    Pessoa_cria(pessoa);
    printf("Dados preenchidos: \n");
    Imprime_dados(pessoa);
    free(pessoa);
    return 0;
}