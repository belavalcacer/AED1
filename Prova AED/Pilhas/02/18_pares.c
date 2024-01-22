#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

typedef struct {
    Node* top;
} Stack;

// Funções para manipular a FILA
void enqueue(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        return -1; // Fila vazia
    }

    int value = queue->front->data;
    Node* temp = queue->front;

    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }

    free(temp);
    return value;
}

// Funções para manipular a PILHA
void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        return -1; // Pilha vazia
    }

    int value = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);

    return value;
}

int main() {
    Queue evenQueue = {NULL, NULL};
    Queue oddQueue = {NULL, NULL};
    Stack positiveEvenStack = {NULL};

    int value;

    printf("Digite os numeros inteiros (0 para encerrar):\n");

    do {
        scanf("%d", &value);

        if (value != 0) {
            if (value % 2 == 0) {
                enqueue(&evenQueue, value);
                if (value > 0) {
                    push(&positiveEvenStack, value);
                }
            } else {
                enqueue(&oddQueue, value);
            }
        }
    } while (value != 0);

    // Exibindo elementos das filas ímpar e par
    printf("Elementos da fila impar:\n");
    while (oddQueue.front != NULL) {
        printf("%d\n", dequeue(&oddQueue));
    }

    printf("Elementos da fila par:\n");
    while (evenQueue.front != NULL) {
        printf("%d\n", dequeue(&evenQueue));
    }

    // Exibindo conteúdo da pilha com valores pares e positivos
    printf("Conteudo da pilha com valores pares e positivos:\n");
    while (positiveEvenStack.top != NULL) {
        printf("%d\n", pop(&positiveEvenStack));
    }

    return 0;
}
