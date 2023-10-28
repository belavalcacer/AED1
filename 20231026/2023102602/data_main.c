#include <stdio.h>
#include "Data.h"

int main() {
    Data *dataa = (Data *) malloc(sizeof(Data));
    Data_cria(dataa);
    printf("Data preenchida: \n");
    Imprime_data(dataa);
    free(dataa);
    return 0;
}