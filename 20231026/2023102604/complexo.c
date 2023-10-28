#include <stdio.h>
#include <stdlib.h>
#include "Complexo.h"

Complexo* Complexo_cria() {
    Complexo* num = (Complexo*) malloc(sizeof(Complexo));
    printf("Degite o numero real: ");
    scanf("%f", &num->real);
    printf("Digite o valor imaginario: ");
    scanf("%f", &num->img);
    return num;
}

Complexo* Complexo_soma(Complexo* num1, Complexo* num2) {
    Complexo* resultado = (Complexo*) malloc(sizeof(Complexo));
    resultado->real = num1->real + num2->real;
    resultado->img = num1->img + num2->img;
    return resultado;
}
Complexo* Complexo_subtracao(Complexo* num1, Complexo* num2) {
    Complexo* resultado = (Complexo*) malloc(sizeof(Complexo));
    resultado->real = num1->real - num2->real;
    resultado->img = num1->img - num2->img;
    return resultado;
}
Complexo* Complexo_multiplicacao(Complexo* num1, Complexo* num2) {
    Complexo* resultado = (Complexo*) malloc(sizeof(Complexo));
    resultado->real = num1->real * num2->real - num1->img * num2->img;
    resultado->img = num1->real * num2->img + num1->img * num2->real;
    return resultado;
}
Complexo* Complexo_divisao(Complexo* num1, Complexo* num2) {
    Complexo* resultado = (Complexo*) malloc(sizeof(Complexo));
    float denominador = num2->real * num2->real + num2->img * num2->img;
    resultado->real = (num1->real * num2->real + num1->img * num2->img)      /denominador;
    resultado->img = (num1->img * num2->real - num1->real * num2->img) 
    / denominador;
    return resultado;
}
void Libera_complexo(Complexo* c) {
    free(c);
}