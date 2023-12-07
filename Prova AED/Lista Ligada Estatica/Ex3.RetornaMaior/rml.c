#include <stdio.h>
#include <stdlib.h>
#include "rml.h"

void InicializarEstrutura(ListaLigada *m, int n)
{
    for (int i = 0; i < n; i++)
    {
        m->lista[i].proximo = i + 1;
        m->lista[i].valor = 0;
    }

    m->lista[n - 1].proximo = -1;
    m->disponivel = 0;
    m->inicio = 0;
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
    }
}


int RetornarMaior(ListaLigada* m){
    int maior;
    int i = m->inicio;
    int t = 0;
    while (i != -1){
        if (t == 0){
            maior = m->lista[i].valor;
        } else {
            if (m->lista[i].valor > maior) {
                maior = m->lista[i].valor;
            }

        }
        i = m->lista[i].proximo;
        t++;
    }

    ExcluirElemento(m, maior);

    return maior;

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