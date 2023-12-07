#include <stdio.h>
#include <stdlib.h>
#include "rml.h"


int main(){
    ListaLigada Aluno;
    InicializarEstrutura(&Aluno, 4);
    Aluno.lista[0].valor = 6;
    Aluno.lista[1].valor = 12;
    Aluno.lista[2].valor = 78;
    Aluno.lista[3].valor = 5;
    Aluno.lista[4].valor = 34;
    int m = RetornarMaior(&Aluno);
    printf("O maior elemento e: %d\n", m);
    printf("A nova lista e: \n", m);
    ExibirLista(&Aluno);


    return 0;
}