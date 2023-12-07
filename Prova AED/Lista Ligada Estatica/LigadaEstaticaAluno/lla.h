#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3

typedef struct
{
    int matricula;
    int idade;
    char nome[20];
    int nfilhos;
} Aluno ;

typedef struct 
{
    Aluno alun;
    int proximo;
} Elemento;

typedef struct 
{
    Elemento ListadeAlun[MAX];
    int disponivel;
    int inicio;
} ListaInteira;
