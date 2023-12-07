#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lda.h"

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
        printf("Idade: %d\n", i->alun.idade);
        printf("Matricula: %d\n",i->alun.matricula);
        printf("\n");
        i = i->proximo;
    }
}

//Buscar elementos da estrutura Sequencial
int BuscarSequencial(ListaInteira*m, int alun){
    Elemento* i= m->inicio;
    int indice=0;
    while (i != NULL)
    {
        if (i->alun.matricula == alun)
        {
            return indice;
        }
        else {
            i = i->proximo;
        }
        indice++;
    }
    //caso a chave n seja encontrada
    return NULL;

}

int BuscaSequencialOrdenada (ListaInteira* m, int alun){
    Elemento* pos = m->inicio;
    int indice=0;
    if (pos == NULL)
    {
        return NULL;
    }

    while (pos != NULL && pos->alun.matricula < alun){   
        pos = pos->proximo; 
        int indice=0;
    }

    if (pos->alun.matricula == alun){
        return indice;
    }
    else
    {
        return NULL;
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
    printf("Insira a idade do aluno: ");
    scanf("%d", &novo.idade);
    printf("Insira o numero de filhos: ");
    scanf("%d", &novo.nfilhos);

    InserirElemento(m, novo);
}

ExcluirElemento (ListaInteira *m, int matricula){
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