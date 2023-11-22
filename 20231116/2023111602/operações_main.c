#include <stdio.h>
#include "operações.h"

int main() {
    Vetor vetor1 = {2.0, 12.0, 7.0};
    Vetor vetor2 = {6.0, 0.5, 4.0};
    Vetor resultado_soma;

    soma(&vetor1, &vetor2, &resultado_soma);

    printf("Resultado da soma: (%.2f, %.2f, %.2f)\n", resultado_soma.x, resultado_soma.y, resultado_soma.z);

    float resultado_escalar = produto_escalar(&vetor1, &vetor2);

    printf("Produto escalar: %.2f\n", resultado_escalar);

    return 0;
}