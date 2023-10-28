#include <stdio.h>
#include "Pessoa.h"

struct pessoa {
  char nome [100];
  char data [12];
  char cpf [13];
};

void Pessoa_cria(Pessoa* pessoa, const char* nome, const char* data, const char* cpf) {
    printf("Digite o nome da pessoa: ");
    fgets(pessoa->nome, 100, stdin);

    printf("Digite a data de nascimento (DD/MM/AAAA): ");
    fgets(pessoa->data, 12, stdin);

    printf("Digite o CPF (000.000.000-00): ");
    fgets(pessoa->cpf, 16, stdin);

  }
    
void Imprime_dados(const Pessoa* pessoa) {
    printf("Nome: %s", pessoa->nome);
    printf("Data de Nascimento: %s", pessoa->data);
    printf("CPF: %s", pessoa->cpf);
}