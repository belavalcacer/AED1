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

// Função para obter e remover o valor no topo da pilha
int popAndReturnTop(DynamicListStack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: Pilha vazia.\n");
        return -1; // Ou outro valor que indique um erro, caso necessário
    }

    int value;
    Node* temp = stack->top;
    value = temp->intValue;

    stack->top = temp->next;
    free(temp);

    return value;
}

// Função para contar o número de elementos pares na pilha
int countEvenElements(DynamicListStack* stack) {
    Node* current = stack->top;
    int evenCount = 0;

    while (current != NULL) {
        if (current->intValue % 2 == 0) {
            evenCount++;
        }
        current = current->next;
    }

    return evenCount;
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
    push(&stack, 13, '\0', 1);  // Valor ímpar
    push(&stack, 30, '\0', 1);
    push(&stack, 42, '\0', 1);  // Valor par
    push(&stack, 55, '\0', 1);  // Valor ímpar

    // Exibindo a pilha após o empilhamento de inteiros
    printStack(&stack);

    // Contando o número de elementos pares
    int evenCount = countEvenElements(&stack);
    printf("Numero de elementos pares na pilha: %d\n", evenCount);

    // Liberando a memória alocada
    destroyStack(&stack);

    return 0;
}
