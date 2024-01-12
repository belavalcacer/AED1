#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

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

//Função de inserir

int inserir (TB_HASH tabela, PACIENTE paciente){
  int indice;
  indice = func_dispersao(paciente.cod_paciente);

  while (tabela[indice] != NULL){
    //serve para percorrer a tabela, se for igual retorna logo 0
    if(tabela[indice]->cod_paciente == paciente.cod_paciente){
      return 0;
    }
    //se nao for igual, vai para a proxima posição e assim segue até encontrar
    indice = (indice + 1) % tam_hash;
  }
  if(tabela[indice] == NULL){ // não encontrou o elemento
    tabela[indice] = malloc(sizeof(PACIENTE));
    *tabela[indice] = paciente;
  }
  else{
    indice++;
    while(tabela[indice] != NULL){
      indice++;
    }
    tabela[indice] = malloc(sizeof(PACIENTE));
    paciente.disponivel = 0;
    *tabela[indice] = paciente;
  }
  return 1;
}

PACIENTE* buscar (TB_HASH tabela, int cod_paciente) {
  int indice = func_dispersao(cod_paciente);
  while (tabela[indice] != NULL) {
    if (tabela[indice]->cod_paciente == cod_paciente)
      return tabela[indice];
    indice = (indice+1) % tam_hash;
      }
  return NULL;
}

void mostrar_hash (TB_HASH tabela) {
 for(int i=0;i<tam_hash;i++) {
  if (tabela[i] != NULL) {
    printf ("\nPaciente: %d \n", i);
    printf ("Codigo do paciente: %d", tabela[i]->cod_paciente);
    printf ("Nome: %s", tabela[i]->nome);
    printf (" CPF: %s", tabela[i]->cpf);
    printf ("Idade: %d\n", tabela[i]->idade);
  }
    else
     printf ("Paciente: %d NULL\n", i);
    }
}



    





