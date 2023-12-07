#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lla.h"

void InicializarEstrutura(ListaInteira *m){
    for (int i = 0; i < MAX; i++) {
        m->ListadeAlun[i].proximo = i + 1;
    }

    m->ListadeAlun[MAX - 1].proximo = -1;
    m->disponivel = 0;
    m->inicio = -1;
}

int Tamanho(ListaInteira *m){
    int tam=0;
    int atual = m->inicio;
    while (atual != -1)
    {
        tam++;
        atual = m->ListadeAlun[atual].proximo;
    }

    return tam;
}

void ExibirLista (ListaInteira *m){
    int i = m->inicio;
    while (i != -1)
    {
        printf("Nome: %s\n", m->ListadeAlun[i].alun.nome);
        printf("Idade: %d\n", m->ListadeAlun[i].alun.idade);
        printf("Matricula: %d\n", m->ListadeAlun[i].alun.matricula);
        i = m->ListadeAlun[i].proximo;
    }

}

int BuscarElemento (ListaInteira *m, int chave) {
    int atual = m->inicio;
    while (atual != -1 && m->ListadeAlun[atual].alun.matricula < chave)
    {
        atual = m->ListadeAlun[atual].proximo;
    }
    if (atual != -1 && m->ListadeAlun[atual].alun.matricula == chave){
        return atual;
    }
    else
    {
        return -1;
    }  
}


int ObterNo(ListaInteira *m) {
    int livre = m->disponivel;
    if(livre != -1){
        m->disponivel = m->ListadeAlun[livre].proximo;
    }
    return livre;
}

int InserirElementoOrdenado(ListaInteira *m, Aluno novoalun){
    int i = m->inicio;
    int pos_inserir = -1;

    //caso não tenha casa livre (1° exc)
    if (m->disponivel == -1)
    {
        return -1;
    }


    //encontrar a posição para inserir (baseado na ordem crescente)
    while (i != -1 && m->ListadeAlun[i].alun.matricula < novoalun.matricula) {
        pos_inserir = i;
        i = m->ListadeAlun[i].proximo;
        // caso o aluno já esteja na lista (2° exc)
        if ( m->ListadeAlun[i].alun.matricula == novoalun.matricula)
        {
            return 0;
        }
    }


    //inserir o elemento
    i = ObterNo(m);
    m->ListadeAlun[i].alun = novoalun;

    // se a pos_inserir for menos um significa que ele é o menor elemento da lista
    // (3° exc)
    if (pos_inserir == -1)
    {
        m->ListadeAlun[i].proximo = m->inicio;
        m->inicio = i;
    }
    //ajeitar os indices
    else {
        m->ListadeAlun[i].proximo = m->ListadeAlun[pos_inserir].proximo;
        m->ListadeAlun[pos_inserir].proximo = i;
    }

    return 1;
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

    InserirElementoOrdenado(m, novo);
}

void ExcluirElemento(ListaInteira *m, int cod) {
    int pos = BuscarElemento(m, cod);
    int i = m->inicio;
    int pos_exc = -1;
    while (i != -1 && m->ListadeAlun[i].alun.matricula < cod)
    {
        pos_exc = i;
        i = m->ListadeAlun[i].proximo;

    }

    printf("%d, %d, %d", pos_exc, i, pos);
    // quer dizer que ele é o menor da lista
    if (pos_exc == -1)
    {
        m->inicio = m->ListadeAlun[pos].proximo;
    } else {
        m->ListadeAlun[pos_exc].proximo = m->ListadeAlun[pos].proximo;
    }
    m->ListadeAlun[pos].proximo = m->disponivel;
    m->disponivel = pos;
}
