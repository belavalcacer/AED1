#include <stdio.h>
#include <stdlib.h>

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

// Função para contar o número de elementos em uma pilha
int countElements(Stack* stack) {
    return stack->top + 1;
}

// Função para testar se a pilha P1 tem mais elementos que a pilha P2
int isP1GreaterThanP2(Stack* P1, Stack* P2) {
    return countElements(P1) > countElements(P2);
}

int main() {
    // Inicializar as pilhas
    Stack* P1 = initializeStack(5);
    Stack* P2 = initializeStack(3);

    // Empilhar alguns valores nas pilhas
    push(P1, 5);
    push(P1, 2);
    push(P1, 8);

    push(P2, 1);
    push(P2, 7);


    // Testar se P1 tem mais elementos que P2
    if (isP1GreaterThanP2(P1, P2)) {
        printf("P1 tem mais elementos que P2.\n");
    } else {
        printf("P1 não tem mais elementos que P2.\n");
    }

    // Liberar a memória das pilhas
    free(P1->array);
    free(P1);

    free(P2->array);
    free(P2);

    return 0;
}
