#include <stdio.h>
#include <stdlib.h>

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

// Função para verificar a validade da expressão
int checkParentheses(char* expression) {
    int i = 0;
    Stack* stack = initializeStack(strlen(expression));

    while (expression[i] != '\0') {
        if (expression[i] == '(') {
            push(stack, expression[i]);
        } else if (expression[i] == ')') {
            if (isEmpty(stack)) {
                // Existe um ")" sem correspondente "("
                free(stack->array);
                free(stack);
                return 0;
            } else {
                pop(stack);
            }
        }
        i++;
    }

    // Se a pilha estiver vazia, a expressão está correta
    int result = isEmpty(stack);
    free(stack->array);
    free(stack);
    return result;
}

int main() {
    char expression1[] = "((())))";
    char expression2[] = "((()))";
    char expression3[] = "()(()))";

    if (checkParentheses(expression1)) {
        printf("%s está com a parentização correta.\n", expression1);
    } else {
        printf("%s está com a parentização incorreta.\n", expression1);
    }

    if (checkParentheses(expression2)) {
        printf("%s está com a parentização correta.\n", expression2);
    } else {
        printf("%s está com a parentização incorreta.\n", expression2);
    }

    if (checkParentheses(expression3)) {
        printf("%s está com a parentização correta.\n", expression3);
    } else {
        printf("%s está com a parentização incorreta.\n", expression3);
    }

    return 0;
}
