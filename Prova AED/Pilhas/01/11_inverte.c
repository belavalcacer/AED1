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

// Função para inverter a posição dos elementos de uma pilha
void reverseStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: Pilha vazia\n");
        return;
    }

    int* tempArray = (int*)malloc(stack->capacity * sizeof(int));
    int tempTop = stack->top;

    // Transferir elementos para um array temporário
    for (int i = 0; i <= tempTop; i++) {
        tempArray[i] = pop(stack);
    }

    // Transferir elementos de volta para a pilha na ordem inversa
    for (int i = 0; i <= tempTop; i++) {
        push(stack, tempArray[i]);
    }

    // Liberar a memória do array temporário
    free(tempArray);
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
    push(myStack, 4);
    push(myStack, 9);
    push(myStack, 12);
    push(myStack, 6);
    push(myStack, 3);

    printf("Pilha original: ");
    printStack(myStack);

    // Inverter a pilha
    reverseStack(myStack);

    printf("Pilha invertida: ");
    printStack(myStack);

    // Liberar a memória da pilha
    free(myStack->array);
    free(myStack);

    return 0;
}
