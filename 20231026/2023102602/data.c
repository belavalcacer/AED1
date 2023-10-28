#include <stdio.h>
#include "Data.h"

struct dataa {
  char data [12];
};

void Data_cria(Data* dataa, const char* data) {
  printf("Digite a data: (DD/MM/AAAA): ");
  fgets(dataa->data, 12, stdin);
}

void Imprime_data(const Data* dataa) {
  printf("Data de Nascimento: %s", dataa->data);

}