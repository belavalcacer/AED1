#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct cubo Cubo;
//Criar o cubo:
Cubo* Cubo_cria(float lado);

//Liberar a memoria alocada
void Cubo_libera(Cubo* c);

//OPERAÇÔES 
float Imprime_aresta(Cubo* c);

//1. Calcula a area total do cubo:
float Cubo_area (Cubo* c);

//2. Calcula o volume do cubo:
float Cubo_volume (Cubo* c);