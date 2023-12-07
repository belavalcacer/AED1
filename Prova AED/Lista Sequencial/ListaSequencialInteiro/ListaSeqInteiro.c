#include <stdio.h>
#include <stdlib.h>
#include "ListaSeqInteiro.h"

void InicializarEstrutura(ListaLigada *m)
{
    for (int i = 0; i < MAX; i++)
    {
        m->lista[i].proximo = i + 1;
    }

    m->lista[MAX - 1].proximo = -1;
    m->disponivel = 0;
    m->inicio = -1;
    m->quantidade = 0;
}

int Tamanho(ListaLigada *m)
{
    return m->quantidade;
}

void ExibirLista(ListaLigada *m)
{
    int i = m->inicio;
    while (i != -1)
    {
        printf("%d ", m->lista[i].valor);
        i = m->lista[i].proximo;
    }
    printf("\n");
}

int BuscarElemento(ListaLigada *m, int chave)
{
    int atual = m->inicio;
    while (atual != -1 && m->lista[atual].valor != chave)
    {
        atual = m->lista[atual].proximo;
    }
    return atual;
}

int ObterNo(ListaLigada *m)
{
    int livre = m->disponivel;
    if (livre != -1)
    {
        m->disponivel = m->lista[livre].proximo;
    }
    return livre;
}

int InserirElemento(ListaLigada *m, int novovalor)
{
    int i = m->inicio;
    int pos_inserir = -1;

    // caso não tenha espaço livre
    if (m->disponivel == -1)
    {
        return -1;
    }

    // encontrar a posição para inserir (ordem crescente)
    while (i != -1 && m->lista[i].valor < novovalor)
    {
        pos_inserir = i;
        i = m->lista[i].proximo;
    }

    // inserir o elemento
    i = ObterNo(m);
    m->lista[i].valor = novovalor;

    // se a pos_inserir for -1 significa que a lista está vazia
    if (pos_inserir == -1)
    {
        m->lista[i].proximo = m->inicio;
        m->inicio = i;
    }
    else
    {
        m->lista[i].proximo = m->lista[pos_inserir].proximo;
        m->lista[pos_inserir].proximo = i;
    }

    m->quantidade++;

    return 1;
}

void ExcluirElemento(ListaLigada *m, int valor)
{
    int pos = m->inicio;
    int pos_anterior = -1;

    while (pos != -1 && m->lista[pos].valor != valor)
    {
        pos_anterior = pos;
        pos = m->lista[pos].proximo;
    }

    if (pos != -1)
    {
        if (pos_anterior == -1)
        {
            m->inicio = m->lista[pos].proximo;
        }
        else
        {
            m->lista[pos_anterior].proximo = m->lista[pos].proximo;
        }

        m->lista[pos].proximo = m->disponivel;
        m->disponivel = pos;
        m->quantidade--;
    }
}