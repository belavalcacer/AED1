#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int matriculas[MAX];
    int qtd_elem_validos;
} Lista;

Lista* inicializarLista() {
    Lista* m;
    m = malloc(sizeof(Lista));
    if (m != NULL) {
        m->qtd_elem_validos = 0;
    } else {
        return NULL;
    }
    return m;
}

int cheia(Lista* lista) {
    if (lista == NULL) {
        return 0;
    }
    if (lista->qtd_elem_validos == MAX) {
        return 1;
    } else {
        return 0;
    }
}

int inserirPosDesejada(Lista* lista, int novamat, int pos) {
    int i;
    if (cheia(lista) == 1 || pos > lista->qtd_elem_validos || pos < 0) {
        return 0;
    }
    for (i = lista->qtd_elem_validos - 1; i >= pos; i--) {
        lista->matriculas[i + 1] = lista->matriculas[i];
    }
    lista->matriculas[pos] = novamat;
    lista->qtd_elem_validos++;
    return 1;
}

int buscaSeqOrd(Lista* lista, int valor) {
    int i;
    for (i = 0; i < lista->qtd_elem_validos; i++) {
        if (lista->matriculas[i] >= valor) {
            //if (lista->matriculas[i] == valor) {
                return i;
            //}
        }
    }
    return lista->qtd_elem_validos;
}

int inserirOrdenado(Lista* lista, int novamat) {
    int pos;
    if (cheia(lista) == 1) {
        return 0;
    }
    pos = buscaSeqOrd(lista, novamat);
    return inserirPosDesejada(lista, novamat, pos);
}

void imprimir(Lista* lista) {
    int i;
    for (i = 0; i < lista->qtd_elem_validos; i++) {
        printf(" %d ", lista->matriculas[i]);
    }
}

int duplicado(Lista* lista, int n) {
    int i, cont = 0;
    for (i = 0; i < lista->qtd_elem_validos; i++) {
      if(lista->matriculas[i]==n){
        cont++;
    }
    }
    return cont;
}

void liberar(Lista* lista) {
    lista->qtd_elem_validos = 0;
    free(lista);
}

int main() {
    Lista* l1;
    l1 = inicializarLista();
    inserirOrdenado(l1, 2);
    inserirOrdenado(l1, 2);
    inserirOrdenado(l1, 2);
    inserirOrdenado(l1, 4);
    inserirOrdenado(l1, 1);
    imprimir(l1);
    printf("\n2 aparece %d vezes", duplicado(l1,2));
    liberar(l1);
    return 0;
}