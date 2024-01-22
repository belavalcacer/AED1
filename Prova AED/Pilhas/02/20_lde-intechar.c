#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
typedef struct Node {
    union {
        int intValue;
        char charValue;
    };
    struct Node* next;
} Node;

// Definição da estrutura da pilha
typedef struct {
    Node* top;
} DynamicListStack;

// Inicializa a pilha
void initStack(DynamicListStack* stack) {
    stack->top = NULL;
}

// Verifica se a pilha está vazia
int isEmpty(DynamicListStack* stack) {
    return stack->top == NULL;
}

// Empilha um elemento (inteiro ou caractere)
void push(DynamicListStack* stack, int value, char charValue, int isInt) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (isInt) {
        newNode->intValue = value;
    } else {
        newNode->charValue = charValue;
    }
    newNode->next = stack->top;
    stack->top = newNode;
}

// Desempilha um elemento e retorna o valor desempilhado
void pop(DynamicListStack* stack, int* intValue, char* charValue, int* isInt) {
    if (isEmpty(stack)) {
        printf("Erro: Pilha vazia.\n");
        return;
    }

    Node* temp = stack->top;

    if (isInt != NULL) {
        *intValue = temp->intValue;
        *isInt = 1;
    } else if (charValue != NULL) {
        *charValue = temp->charValue;
        *isInt = 0;
    }

    stack->top = temp->next;
    free(temp);
}

// Exibe os elementos da pilha
void printStack(DynamicListStack* stack) {
    if (isEmpty(stack)) {
        printf("Pilha vazia.\n");
        return;
    }

    Node* current = stack->top;
    printf("Elementos da pilha: ");
    while (current != NULL) {
        if (current->next == NULL) {
            if (current->intValue) {
                printf("%d", current->intValue);
            } else {
                printf("%c", current->charValue);
            }
        } else {
            if (current->intValue) {
                printf("%d, ", current->intValue);
            } else {
                printf("%c, ", current->charValue);
            }
        }
        current = current->next;
    }
    printf("\n");
}

// Libera a memória alocada para a pilha
void destroyStack(DynamicListStack* stack) {
    while (stack->top != NULL) {
        Node* temp = stack->top;
        stack->top = temp->next;
        free(temp);
    }
}

int main() {
    DynamicListStack stack;
    initStack(&stack);

    // Empilhando inteiros
    push(&stack, 10, '\0', 1);
    push(&stack, 20, '\0', 1);
    push(&stack, 30, '\0', 1);

    // Exibindo a pilha após o empilhamento de inteiros
    printStack(&stack);

    // Empilhando caracteres
    push(&stack, 0, 'D', 0);
    push(&stack, 0, 'S', 0);

    // Exibindo a pilha após o empilhamento de caracteres
    printStack(&stack);
    printf("(Obs: Os valores são os codigos dos caracteres na tabela ASCII)\n");

    // Liberando a memória alocada
    destroyStack(&stack);

    return 0;
}
