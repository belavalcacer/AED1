#include <stdio.h>
#include <stdlib.h>
#include "llhash.h"


//Função que cria uma tabela hash
void inicializar_hash(TB_HASH tabela) {
  int i;
  for (i = 0; i < tam_hash; i++) {
    tabela[i] = NULL;
  }
}

//Funçao de dispersao --> mapeia uma chave de busca, nesse caso foi definido os dois ultimos n* sequenciais. Retorna um indice da tabela.

int func_dispersao(int cod_paciente) {
  return (cod_paciente % 100);
}

int inserir(TB_HASH tabela, PACIENTE paciente) {
  int indice = func_dispersao(paciente.cod_paciente);
  ELEMENTO* anterior = NULL;
  ELEMENTO* atual = tabela[indice];
  while (atual != NULL) {
    if (atual->paciente.cod_paciente == paciente.cod_paciente) {
      return 0;
    }
    anterior = atual;
    atual = atual->prox;
  }
  if (atual == NULL) {
    atual = (ELEMENTO*)malloc(sizeof(ELEMENTO));
    atual->paciente = paciente;
    atual->prox = NULL;
  }
    if (anterior == NULL) {
      tabela[indice] = atual;
    } else
    {
      anterior->prox = atual;
    }
    return 1;
}


PACIENTE* buscar(TB_HASH tabela, int cod_paciente) {
  int indice = func_dispersao(cod_paciente);
  ELEMENTO* atual = tabela[indice];
  while (atual != NULL) {
    if (atual->paciente.cod_paciente == cod_paciente) {
      return &atual->paciente;
    }
    atual = atual->prox;
  }
  return NULL;
}

void mostrar_hash(TB_HASH tabela) {
  ELEMENTO* atual;
  int i;

  for(i = 0; i < tam_hash; i++) {
    if (tabela[i] != NULL) {
      atual = tabela[i];
      printf("\nPaciente: %d", i);
      while (atual != NULL) {
        printf("\nNome: %s -->", tabela[i]->paciente.nome);
        atual = atual->prox;
  }
      printf("NULL");
  }
      else 
      printf("\nPaciente: %d --> NULL", i);
}
}

  