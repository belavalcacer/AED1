#include <stdio.h>
#include <string.h>

// Função para inverter uma string
void reverseString(char str[]) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        // Trocar os caracteres no início e no final
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // Avançar para a próxima posição
        start++;
        end--;
    }
}

// Função para verificar se a string é da forma XY
int isXYForm(char str[]) {
    int length = strlen(str);

    // Verificar se a string é de tamanho ímpar (não pode ser da forma XY)
    if (length % 2 != 0) {
        return 0; // Retorna falso
    }

    // Dividir a string em duas partes X e Y
    int mid = length / 2;
    char X[mid + 1];
    char Y[mid + 1];

    // Copiar os primeiros mid caracteres para X
    strncpy(X, str, mid);
    X[mid] = '\0'; // Adicionar o caractere nulo ao final de X

    // Copiar os próximos mid caracteres para Y
    strncpy(Y, str + mid, mid);
    Y[mid] = '\0'; // Adicionar o caractere nulo ao final de Y

    // Inverter a string X
    reverseString(X);

    // Comparar X invertido com Y
    return strcmp(X, Y) == 0;
}

int main() {
    // Exemplo de uso
    char str[] = "ABCDDCBA";

    if (isXYForm(str)) {
        printf("A string e da forma XY.\n");
    } else {
        printf("A string nao e da forma XY.\n");
    }

    return 0;
}
