#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definição da estrutura da pilha
typedef struct {
    int *array;
    int top;
    int capacity;
} Stack;

// Função para inicializar a pilha
Stack* initializeStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Função para verificar se a pilha está cheia
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Função para empilhar um número
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Erro: Pilha cheia\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Função para desempilhar um número
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: Pilha vazia\n");
        return -1; // Valor inválido para indicar erro
    }
    return stack->array[stack->top--];
}

// Função para obter o maior, o menor e a média dos elementos da pilha
void getStats(Stack* stack, int* maior, int* menor, double* media) {
    if (isEmpty(stack)) {
        printf("Erro: Pilha vazia\n");
        return;
    }

    int soma = 0;
    *maior = INT_MIN;
    *menor = INT_MAX;

    // Percorrer a pilha para calcular as estatísticas
    for (int i = 0; i <= stack->top; i++) {
        int elemento = stack->array[i];

        // Atualizar o maior e o menor
        if (elemento > *maior) {
            *maior = elemento;
        }
        if (elemento < *menor) {
            *menor = elemento;
        }

        // Somar os elementos
        soma += elemento;
    }

    // Calcular a média
    *media = (double)soma / (stack->top + 1);
}

int main() {
    Stack* myStack = initializeStack(5);

    // Empilhar alguns valores
    push(myStack, 5);
    push(myStack, 40);
    push(myStack, 8);
    push(myStack, 2);
    push(myStack, 7);

    // Obter estatísticas da pilha
    int maior, menor;
    double media;

    getStats(myStack, &maior, &menor, &media);

    // Imprimir estatísticas
    printf("Maior elemento: %d\n", maior);
    printf("Menor elemento: %d\n", menor);
    printf("Média aritmética: %.2f\n", media);

    // Liberar a memória da pilha
    free(myStack->array);
    free(myStack);

    return 0;
}
