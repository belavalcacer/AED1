#include <stdio.h>
#include <stdlib.h>
#include "LinearAluno.h"

//INICIALIZAR LISTA: 
void inicializar(LISTA* lista){
lista->quantidade = 0;
}

// INSERIR NOVO ELEMENTO: 
int inserir(LISTA* lista){
if(lista->quantidade == 20){
    return -1;
}
ALUNO novo;
char nome[50];
printf("Insira o nome do aluno: ");
scanf("%s", nome);
strcpy(novo.nome, nome);
printf("Insira o codigo do aluno: ");
scanf("%d", &novo.codigo);
printf("Insira a idade do aluno: ");
scanf("%d", &novo.idade);
printf("Insira o numero de filhos: ");
scanf("%d", &novo.nfilhos);

// Verificar se o código do aluno já existe
    for (int i = 0; i < lista->quantidade; i++) {
        if (lista->lista[i].codigo == novo.codigo) {
            printf("\nErro: Aluno com código %d já existe na lista.\n", novo.codigo);
        }
    }

if(lista->quantidade == 0){
    lista->lista[0] = novo;

}
else{
    int i = lista->quantidade - 1;

    while(i>= 0 && novo.codigo < lista->lista[i].codigo){
        lista->lista[i+1] = lista->lista[i];
        i--;
    }
    lista->lista[i+1] = novo;

}
lista->quantidade++;
printf("\nAluno inserido com sucesso\n");
}

// IMPRIMIR LISTA: //////////////////////
void imprimir(LISTA *lista){
int i;
for(i = 0; i < lista->quantidade; i++){
    printf("Nome: %s\n", lista->lista[i].nome);
    printf("Codigo: %d\n", lista->lista[i].codigo);
    printf("Idade: %d\n", lista->lista[i].idade);
    printf("Numero de filhos: %d\n\n", lista->lista[i].nfilhos);
}}

// QUANTIDADE DE ELEMENTOS://////////////
void quantidade(LISTA* lista){
printf("\nAtualmente a lista possui: %d elementos\n", lista->quantidade);
}

// BUSCA SEQUENCIAL: /////////////////
void busca(LISTA* lista, int matricula){
int i;
for(i = 0; i < lista->quantidade; i++){
    if(lista->lista[i].codigo == matricula){
        printf("\nAluno encontrado na posicao %d\n", i);
        break;
    }
}}

// BUSCA BINARIA: ////////////////
void buscabin(LISTA* lista, int matricula){
int esquerda = 0;
int direita = lista->quantidade-1;
while(esquerda <= direita){
    int meio = (esquerda+direita)/2;
    if(lista->lista[meio].codigo == matricula){
        printf("\nAluno encontrado na posicao: %d\n", meio);
        break;
    }
    if(lista->lista[meio].codigo < matricula){
        esquerda = meio+1;
        }
    if(lista->lista[meio].codigo > matricula){
        direita = meio - 1;
    }
}}


// EXCLUIR ELEMENTO: ////////////////////
void excluir(LISTA* lista, int matricula){
int i, j;
int encontrado;
for(i = 0; i < lista->quantidade; i++){
    if(lista->lista[i].codigo == matricula){
        encontrado = i;
    }}

for(j = encontrado; j <lista->quantidade; j++){

    lista->lista[j] = lista->lista[j+1];
}
lista->quantidade--;
}
