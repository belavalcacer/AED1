#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[20];
    int matricula;
}Aluno;

typedef struct aux
{
    Aluno alun;
    struct aux* proximo;
}Elemento;

typedef struct 
{
    Elemento* inicio;
}ListaInteira;

