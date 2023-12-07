#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct
{
    int valor;
    int proximo;
} Elemento;

typedef struct
{
    Elemento lista[MAX];
    int disponivel;
    int inicio;
} ListaLigada;