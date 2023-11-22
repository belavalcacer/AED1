#include <stdio.h>

int k_esimo_digito(int d, int k) {
    if (k == 1) {
        return d % 10;
    }
    else {
        return k_esimo_digito(d / 10, k - 1);
    }
}

int main() {
    int digito = 21845;
    int k = 3;

    int resultado = k_esimo_digito(digito, k);
    printf("O k-ésimo dígito é: %d\n", resultado);

    return 0;
}