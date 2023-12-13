#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ListaDinaicaAl.h"

//Inicializar a estrutura
void Inicializar(ListaInteira* m){
    m->inicio = NULL;
}

//Retornar quantidade de elementos validos
int Tamanho(ListaInteira* m){
    int tam=0;
    Elemento* i = m->inicio;
    while (i != NULL){
        tam ++;
        i = i->proximo;
    }
    return tam;
}

//Exibir elementos da estrutura
void Exibir(ListaInteira* m){
    Elemento* i = m->inicio;
    while (i != NULL)
    {
        printf("Nome: %s\n", i->alun.nome);
        printf("Matricula: %d\n",i->alun.matricula);
        printf("\n");
        i = i->proximo;
    }
}


//Inserir elementos ordenados e sem repetição
void InserirElemento(ListaInteira*m, Aluno alun){
    Elemento* i = m->inicio;
    Elemento* pos_inserir = NULL;
    //exc: negação
    if (i == NULL){
        i = malloc(sizeof(Elemento));
        i->alun = alun;
        i->proximo = NULL;
        m->inicio = i;
        return;
    }

    while (i != NULL && m->inicio->alun.matricula<alun.matricula)
    {
        //exc: igualdade
        if (i->alun.matricula == alun.matricula)
        {
            return;
        }
        pos_inserir = i;
        i = i->proximo;    

    }
    i = malloc (sizeof(Elemento));
    i->alun = alun;
    i->proximo = NULL;

    if (pos_inserir == NULL)
    {
        i->proximo = m->inicio;
        m->inicio = i;
    }else{
        i->proximo = pos_inserir->proximo;
        pos_inserir->proximo = i;
    }
}


void Inserir(ListaInteira* m){
    Aluno novo;
    char nome[50];
    printf("Insira o nome do aluno: ");
    scanf("%s", nome);
    strcpy(novo.nome, nome);
    printf("Insira o codigo do aluno: ");
    scanf("%d", &novo.matricula);
    InserirElemento(m, novo);
}

void ExcluirElemento (ListaInteira *m, int matricula){
    Elemento* anterior = NULL;
    Elemento* atual = m->inicio;

    while (atual != NULL) {
        if (atual->alun.matricula == matricula) {
            if (anterior == NULL) {
                m->inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

void Reiniciar(ListaInteira *m) {
    Elemento* apagar;
    Elemento* elem = m->inicio;
    while (elem != NULL) {
        Elemento* apagar = elem;
        elem = elem->proximo;
        free(apagar);
    }
    m->inicio = NULL;
}

void ListaVazia(ListaInteira *m){
    if (m->inicio == NULL){
        printf("Lista vazia\n");
    }
}