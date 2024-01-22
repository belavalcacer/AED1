#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura da pilha
typedef struct {
    char *array;
    int top;
    int capacity;
} Stack;

// Função para inicializar a pilha
Stack* initializeStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
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

// Função para empilhar um caractere
void push(Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Erro: Pilha cheia\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Função para desempilhar um caractere
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: Pilha vazia\n");
        return '\0'; // Valor nulo para indicar erro
    }
    return stack->array[stack->top--];
}

// Função para inverter as letras de cada palavra em um texto
void invertLettersInWords(char* text) {
    int length = strlen(text);
    Stack* stack = initializeStack(length);

    for (int i = 0; i < length; i++) {
        if (text[i] != ' ' && text[i] != '.') {
            push(stack, text[i]);
        } else {
            while (!isEmpty(stack)) {
                printf("%c", pop(stack));
            }
            printf("%c", text[i]); // Imprimir espaço ou ponto
        }
    }

    free(stack->array);
    free(stack);
}

int main() {
    char text[] = "ESTE EXERCICIO E MUITO FACIL.";

    printf("Entrada: %s\n", text);
    printf("Saída: ");
    invertLettersInWords(text);

    return 0;
}
