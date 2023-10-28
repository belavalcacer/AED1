#include <stdio.h>
#include "Complexo.h"

int main() {
    Complexo *num1, *num2, *soma, *subtracao, *multiplicacao, *divisao;
    num1 = Complexo_cria();
    num2 = Complexo_cria();
    soma = Complexo_soma(num2, num2);
    subtracao = Complexo_subtracao(num1, num2);
    multiplicacao = Complexo_multiplicacao(num1, num2);
    divisao = Complexo_divisao(num1, num2);

    printf("Resultado das operacoes: \n");
    printf("Soma: %.2f + i%2f\n", soma->real, soma->img);
    printf("Subtracao: %.2f + i%.2f\n", subtracao->real, subtracao->img);
    printf("Multiplicacao: %.2f + i%.2f\n", multiplicacao->real,     
    multiplicacao->img);
    printf("Divisao: %.2f + i%.2f\n", divisao->real, divisao->img);
  
    Libera_complexo(num1);
    Libera_complexo(num2);
    Libera_complexo(soma);
    Libera_complexo(subtracao);
    Libera_complexo(multiplicacao);
    Libera_complexo(divisao);
    return 0;
}