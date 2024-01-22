#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Definição da estrutura da pilha
typedef struct {
    Node* top;
} DoublyLinkedListStack;

// Inicializa a pilha
void initStack(DoublyLinkedListStack* stack) {
    stack->top = NULL;
}

// Verifica se a pilha está vazia
int isEmpty(DoublyLinkedListStack* stack) {
    return stack->top == NULL;
}

// Empilha um elemento
void push(DoublyLinkedListStack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = stack->top;
    newNode->prev = NULL;

    if (stack->top != NULL) {
        stack->top->prev = newNode;
    }

    stack->top = newNode;
}

// Desempilha um elemento e retorna o valor desempilhado
int pop(DoublyLinkedListStack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: Pilha vazia.\n");
        return -1;
    }

    Node* temp = stack->top;
    int value = temp->data;

    stack->top = temp->next;

    if (stack->top != NULL) {
        stack->top->prev = NULL;
    }

    free(temp);
    return value;
}

// Retorna o valor no topo da pilha sem desempilhar
int peek(DoublyLinkedListStack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: Pilha vazia.\n");
        return -1;
    }

    return stack->top->data;
}

// Libera a memória alocada para a pilha
void destroyStack(DoublyLinkedListStack* stack) {
    while (stack->top != NULL) {
        Node* temp = stack->top;
        stack->top = temp->next;
        free(temp);
    }
}

// Exibe os elementos da pilha
void printStack(DoublyLinkedListStack* stack) {
    if (isEmpty(stack)) {
        printf("Pilha vazia.\n");
        return;
    }

    Node* current = stack->top;
    printf("Elementos da pilha: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    DoublyLinkedListStack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printStack(&stack);

    printf("Elemento no topo: %d\n", peek(&stack));

    printf("Desempilhando: %d\n", pop(&stack));

    printStack(&stack);

    destroyStack(&stack);

    return 0;
}
