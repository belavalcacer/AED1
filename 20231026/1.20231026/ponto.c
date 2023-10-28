#include <stdio.h>
#include <math.h>
#include "Ponto.h" // inclui os prototipos

struct ponto{ //definição do tipo de dados
  float x;
  float y;
};

// Cria um novo ponto: 
Ponto* Ponto_cria(float x, float y) {
  Ponto* p = (Ponto*) malloc(sizeof(Ponto));
  if (p != NULL) {
    p->x = x;
    p->y = y;
  }
  return p;
}

void Ponto_libera (Ponto* p) {
  free(p);
}

int Ponto_acessa (Ponto* p, float* x, float* y) {
  if (p != NULL) {
    *x = p->x;
    *y = p->y;
    return 1;
  }
  return 0;
}

int Ponto_atribui (Ponto* p, float x, float y) {
  if (p != NULL) {
    p->x = x;
    p->y = y;
    return 1;
  }
  return 0;
}

float Ponto_distancia (Ponto* p1, Ponto* p2) {
  if (p1 != NULL && p2 != NULL) {
    float dx = p2->x - p1->x;
    float dy = p2->y - p1->y;
    return sqrt(dx*dx + dy*dy);
  }
  return 0.0;
}
