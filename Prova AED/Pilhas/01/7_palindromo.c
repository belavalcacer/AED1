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

// Função para verificar se uma palavra é um palíndromo
int isPalindrome(char* word) {
    int length = strlen(word);
    int mid = length / 2;

    Stack* stack = initializeStack(mid);

    // Empilhar a primeira metade da palavra
    for (int i = 0; i < mid; i++) {
        push(stack, word[i]);
    }

    // Verificar se a palavra é de tamanho ímpar
    if (length % 2 != 0) {
        // Avançar para o próximo caractere na palavra (ignorando o caractere central em palavras ímpares)
        mid++;
    }

    // Comparar a segunda metade da palavra com a pilha
    for (int i = mid; i < length; i++) {
        if (word[i] != pop(stack)) {
            free(stack->array);
            free(stack);
            return 0; // Não é um palíndromo
        }
    }

    free(stack->array);
    free(stack);
    return 1; // É um palíndromo
}

int main() {
    char word[] = "natan";

    if (isPalindrome(word)) {
        printf("%s é um palíndromo.\n", word);
    } else {
        printf("%s não é um palíndromo.\n", word);
    }

    return 0;
}
