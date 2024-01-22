#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da fila
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Função para inicializar a fila
Queue* initializeQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Função para verificar se a fila está vazia
int isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Função para enfileirar um elemento
void enqueue(Queue* queue, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL;

    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Função para desenfileirar um elemento
int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Erro: Fila vazia\n");
        return -1; // Valor inválido para indicar erro
    }

    Node* frontNode = queue->front;
    int item = frontNode->data;

    queue->front = frontNode->next;
    free(frontNode);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return item;
}

// Função para empilhar um elemento
void push(Node** top, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = *top;
    *top = newNode;
}

// Função para desempilhar um elemento
int pop(Node** top) {
    if (*top == NULL) {
        printf("Erro: Pilha vazia\n");
        return -1; // Valor inválido para indicar erro
    }

    Node* temp = *top;
    int item = temp->data;
    *top = temp->next;
    free(temp);

    return item;
}

// Função para inverter a ordem dos elementos da fila
void reverseQueue(Queue* queue) {
    Node* stackTop = NULL;

    // Enfileirar elementos na pilha
    while (!isQueueEmpty(queue)) {
        int item = dequeue(queue);
        push(&stackTop, item);
    }

    // Desenfileirar elementos da pilha para inverter a ordem
    while (stackTop != NULL) {
        int item = pop(&stackTop);
        enqueue(queue, item);
    }
}

// Função para imprimir os elementos da fila
void printQueue(Queue* queue) {
    Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Inicializar a fila
    Queue* myQueue = initializeQueue();

    // Enfileirar alguns valores
    enqueue(myQueue, 5);
    enqueue(myQueue, 8);
    enqueue(myQueue, 4);
    enqueue(myQueue, 3);

    printf("Fila original: ");
    printQueue(myQueue);

    // Inverter a ordem da fila
    reverseQueue(myQueue);

    printf("Fila invertida: ");
    printQueue(myQueue);

    // Liberar a memória da fila
    while (!isQueueEmpty(myQueue)) {
        dequeue(myQueue);
    }
    free(myQueue);

    return 0;
}
