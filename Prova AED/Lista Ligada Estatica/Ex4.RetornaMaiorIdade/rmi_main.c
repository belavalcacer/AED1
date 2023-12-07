#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rmi.h"

int main(){
    ListaInteira Aluno;
    InicializarEstrutura(&Aluno, 5);

    strcpy(Aluno.ListadeAlun[0].alun.nome, "Maria");
    strcpy(Aluno.ListadeAlun[1].alun.nome, "Joao");
    strcpy(Aluno.ListadeAlun[2].alun.nome,"Jose");
    strcpy(Aluno.ListadeAlun[3].alun.nome, "Ana");
    strcpy(Aluno.ListadeAlun[4].alun.nome, "Beatriz");

    Aluno.ListadeAlun[0].alun.idade = 21;
    Aluno.ListadeAlun[1].alun.idade = 54;
    Aluno.ListadeAlun[2].alun.idade = 12;
    Aluno.ListadeAlun[3].alun.idade = 67;
    Aluno.ListadeAlun[4].alun.idade = 22;

    Aluno.ListadeAlun[0].alun.matricula = 001;
    Aluno.ListadeAlun[1].alun.matricula = 002;
    Aluno.ListadeAlun[2].alun.matricula = 003;
    Aluno.ListadeAlun[3].alun.matricula = 004;
    Aluno.ListadeAlun[4].alun.matricula = 005;

    Aluno.ListadeAlun[0].alun.nfilhos = 0;
    Aluno.ListadeAlun[1].alun.nfilhos = 0;
    Aluno.ListadeAlun[2].alun.nfilhos = 1;
    Aluno.ListadeAlun[3].alun.nfilhos = 0;
    Aluno.ListadeAlun[4].alun.nfilhos = 1;
    int m = RetornarMaiorIdade(&Aluno);
    printf("O maior elemento e o : %d\n\n", m);

    ExibirLista(&Aluno);


    return 0;
}