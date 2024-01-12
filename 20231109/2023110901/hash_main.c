#include <stdio.h>
#include "hash.h"

int main() {
TB_HASH tabela; PACIENTE p, *pr; inicializar_hash (tabela);

  
p.cod_paciente = 1291;
p.nome = "Sandra";
p.cpf = "000000000000";
p.idade = 19;
inserir (tabela, p);
  
p.cod_paciente = 1191;
p.nome = "Nezi";
p.cpf = "111111111111";
p.idade = 20;
inserir (tabela, p);


p.cod_paciente = 1089;
p.nome = "Cassandra";
p.cpf = "222222222222";
p.idade = 24;
inserir (tabela, p);
  
pr = buscar (tabela, 1291);
printf("\n Achou nome: %s", pr->nome);


  printf("Tabela hash: ");
  mostrar_hash(tabela);
}