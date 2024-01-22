#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da pilha
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Definição da estrutura da pilha
typedef struct {
    Node* top;
} Stack;

// Inicializa a pilha
void initStack(Stack* stack) {
    stack->top = NULL;
}

// Verifica se a pilha está vazia
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Empilha um elemento na pilha
void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Desempilha um elemento da pilha
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: Pilha vazia.\n");
        return -1; // Ou outro valor que indique um erro, caso necessário
    }

    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);

    return data;
}

// Função para converter um número decimal para binário
void decimalToBinary(int decimal) {
    Stack stack;
    initStack(&stack);

    while (decimal > 0) {
        int remainder = decimal % 2;
        push(&stack, remainder);
        decimal /= 2;
    }

    printf("Binario: ");
    while (!isEmpty(&stack)) {
        printf("%d", pop(&stack));
    }
    printf("\n");
}

// Função para converter um número decimal para octal
void decimalToOctal(int decimal) {
    Stack stack;
    initStack(&stack);

    while (decimal > 0) {
        int remainder = decimal % 8;
        push(&stack, remainder);
        decimal /= 8;
    }

    printf("Octal: ");
    while (!isEmpty(&stack)) {
        printf("%d", pop(&stack));
    }
    printf("\n");
}

// Função para converter um número decimal para hexadecimal
void decimalToHexadecimal(int decimal) {
    Stack stack;
    initStack(&stack);

    while (decimal > 0) {
        int remainder = decimal % 16;
        push(&stack, remainder);
        decimal /= 16;
    }

    printf("Hexadecimal: ");
    while (!isEmpty(&stack)) {
        int value = pop(&stack);
        if (value < 10) {
            printf("%d", value);
        } else {
            printf("%c", 'A' + (value - 10));
        }
    }
    printf("\n");
}

int main() {
    int decimal;
    char option;

    printf("Digite um numero decimal: ");
    scanf("%d", &decimal);

    printf("Escolha a opcao de conversao:\n");
    printf("(a) Decimal para Binario\n");
    printf("(b) Decimal para Octal\n");
    printf("(c) Decimal para Hexadecimal\n");

    printf("Opcao: ");
    scanf(" %c", &option);

    switch (option) {
        case 'a':
            decimalToBinary(decimal);
            break;
        case 'b':
            decimalToOctal(decimal);
            break;
        case 'c':
            decimalToHexadecimal(decimal);
            break;
        default:
            printf("Opcao invalida.\n");
    }

    return 0;
}
