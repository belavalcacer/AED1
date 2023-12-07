#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rmi.h"
#define MAX 10

void InicializarEstrutura(ListaInteira *m, int n){
    for (int i = 0; i < n; i++) {
        m->ListadeAlun[i].proximo = i + 1;
    }

    m->ListadeAlun[n - 1].proximo = -1;
    m->disponivel = 0;
    m->inicio = 0;
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

void ExcluirElemento(ListaInteira *m, int cod) {
    int pos = BuscarElemento(m, cod);
    int i = m->inicio;
    int pos_exc = -1;
    while (i != -1 && m->ListadeAlun[i].alun.matricula != cod) {
        pos_exc = i;
        i = m->ListadeAlun[i].proximo;
    }

    if (pos_exc == -1) {
        m->inicio = m->ListadeAlun[pos].proximo;
    } else {
        m->ListadeAlun[pos_exc].proximo = m->ListadeAlun[pos].proximo;
    }
    m->ListadeAlun[pos].proximo = m->disponivel;
    m->disponivel = pos;
}


int RetornarMaiorIdade(ListaInteira* m){
    int maior = 0;
    int pos_maior = -1;
    int i = m->inicio;
    int t = 0;

    while (i != -1){
        if (t == 0 || m->ListadeAlun[i].alun.idade > maior) {
            maior = m->ListadeAlun[i].alun.idade;
            pos_maior = i;
        }
        i = m->ListadeAlun[i].proximo;
        t++;
    }


    return pos_maior;
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
