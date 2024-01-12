#include <stdio.h>
#include "llhash.h"

int main() {
TB_HASH tabela; PACIENTE p, *pr; inicializar_hash (tabela);


p.cod_paciente = 1291;
p.nome = "Sandra";
p.cpf = "000000000000";
p.idade = 19;
inserir (tabela, p);

p.cod_paciente = 1543;
p.nome = "Nezi";
p.cpf = "111111111111";
p.idade = 20;
inserir (tabela, p);


p.cod_paciente = 1089;
p.nome = "Cassandra";
p.cpf = "222222222222";
p.idade = 24;
inserir (tabela, p);

//Mostra a Tabela Hash
  printf("Tabela hash: ");
  mostrar_hash(tabela);

  //Busca um paciente na tabela hash
    pr = buscar (tabela, 1543);
    printf("\n Nome da busca: %s", pr->nome);
}