#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    int items[MAX_SIZE];
} Stack;

// Função para inicializar uma pilha
void initialize(Stack *stack) {
    stack->top = -1;
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Função para verificar se a pilha está cheia
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Função para adicionar um elemento à pilha
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Erro: a pilha está cheia\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = value;
}

// Função para remover e obter o elemento do topo da pilha
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Erro: a pilha está vazia\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Função para transferir elementos da pilha p1 para p2
void transfer(Stack *p1, Stack *p2) {
    while (!isEmpty(p1)) {
        int element = pop(p1);
        push(p2, element);
    }
}

int main1() {
    Stack p1, p2;
    int n, num;

    // Inicializar as pilhas
    initialize(&p1);
    initialize(&p2);

    // Solicitar ao usuário a quantidade de números a serem inseridos
    printf("Quantos números você deseja inserir na pilha p1? ");
    scanf("%d", &n);

    // Solicitar ao usuário inserir os números na pilha p1
    printf("Insira os números na pilha p1:\n");
    for (int i = 0; i < n; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &num);
        push(&p1, num);
    }

    // Transferir elementos de p1 para p2
    transfer(&p1, &p2);

    // Imprimir elementos de p2
    printf("Elementos em p2: ");
    while (!isEmpty(&p2)) {
        printf("%d ", pop(&p2));
    }

    return 0;
}
