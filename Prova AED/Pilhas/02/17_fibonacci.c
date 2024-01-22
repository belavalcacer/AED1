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

// Função para acumular os primeiros n valores da sequência de Fibonacci na pilha
void accumulateFibonacci(Stack* stack, int n) {
    int a = 0, b = 1;

    for (int i = 0; i < n; i++) {
        push(stack, a);
        int temp = a;
        a = b;
        b += temp;
    }
}

// Função para imprimir os elementos da pilha
void printStack(Stack* stack) {
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Obter o valor de n
    printf("Digite o valor de n para acumular os primeiros n valores da sequencia de Fibonacci: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Por favor, insira um valor positivo para n.\n");
        return 1;
    }

    // Inicializar a pilha
    Stack* myStack = initializeStack(n);

    // Acumular os primeiros n valores da sequência de Fibonacci
    accumulateFibonacci(myStack, n);

    // Imprimir os valores acumulados na pilha
    printf("Valores acumulados na pilha: ");
    printStack(myStack);

    // Liberar a memória da pilha
    free(myStack->array);
    free(myStack);

    return 0;
}
