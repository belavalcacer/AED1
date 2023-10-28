#include <stdio.h>
#include <stdlib.h>
#include "Cubo.h"

int main() {
  float area, volume, aresta;
  Cubo *c1;
  c1 = Cubo_cria(4.0);
  aresta = Imprime_aresta(c1);
  area = Cubo_area(c1);
  volume = Cubo_volume(c1);

  //Chamando as funções das operações e printando o resultado:
  printf("O tamanho da aresta eh: %.1f\n", aresta);
  printf("A area do cubo eh: %.1f\n", area);
  printf("O volume do cubo eh: %.1f\n", volume);

  return 0; 
}