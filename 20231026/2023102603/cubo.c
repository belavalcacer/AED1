#include <stdio.h>
#include <stdlib.h>
#include "Cubo.h"

struct cubo {
  float lado;
};

// Cria um novo ponto: 
Cubo* Cubo_cria(float lado) {
  Cubo* c = (Cubo*) malloc(sizeof(Cubo));
  if (c != NULL) {
    c->lado = lado;
  }
  return c;
}

float Imprime_aresta(Cubo* c) {
  float aresta = c->lado;
  return aresta;
}


//OPERAÇÕES
//1. Calcula a area do cubo
float Cubo_area(Cubo* c){
  // Area = 6 * lado^2: 
  float area = 6* (c->lado * c->lado);
  return area;
}

//2. Calcula o volume do cubo
float Cubo_volume(Cubo* c){
  // Volume = a^3: 
  float volume = c->lado * c->lado * c->lado; 
  return volume;
}