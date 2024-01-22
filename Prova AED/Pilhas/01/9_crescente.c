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

// Função para transferir elementos de uma pilha para outra
void transfer(Stack* source, Stack* destination) {
    while (!isEmpty(source)) {
        push(destination, pop(source));
    }
}

// Função para ordenar a pilha em ordem crescente
void sortStack(Stack* stack) {
    Stack* tempStack = initializeStack(stack->capacity);

    while (!isEmpty(stack)) {
        int currentElement = pop(stack);

        while (!isEmpty(tempStack) && tempStack->array[tempStack->top] > currentElement) {
            push(stack, pop(tempStack));
        }

        push(tempStack, currentElement);
    }

    // Transferir os elementos ordenados de volta para a pilha original
    transfer(tempStack, stack);

    // Liberar a memória da pilha temporária
    free(tempStack->array);
    free(tempStack);
}

// Função para imprimir os elementos da pilha
void printStack(Stack* stack) {
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

int main() {
    Stack* myStack = initializeStack(5);

    // Empilhar alguns valores
    push(myStack, 90);
    push(myStack, 3);
    push(myStack, 5);
    push(myStack, 10);
    push(myStack, 2);

    printf("Pilha original: ");
    printStack(myStack);

    // Ordenar a pilha
    sortStack(myStack);

    printf("Pilha ordenada: ");
    printStack(myStack);

    // Liberar a memória da pilha original
    free(myStack->array);
    free(myStack);

    return 0;
}
