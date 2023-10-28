#include "Ponto.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  float d;
  Ponto *p, *q;

  p = Ponto_cria(10, 21);
  q = Ponto_cria(7, 25);

  d = Ponto_distancia(p, q);
  printf("Distancia entre pontos: %.1f \n", d);
  Ponto_libera(q);
  Ponto_libera(p);
  return 0;
}