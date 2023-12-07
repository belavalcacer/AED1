#include <stdio.h>
#include <stdlib.h>

#define MAX 20

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
    int quantidade;
} ListaLigada;