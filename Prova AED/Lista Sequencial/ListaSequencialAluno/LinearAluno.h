#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
char nome[50];
int codigo;
int idade;
int nfilhos;
}ALUNO;

typedef struct{
ALUNO lista[20];
int quantidade;
}LISTA;
