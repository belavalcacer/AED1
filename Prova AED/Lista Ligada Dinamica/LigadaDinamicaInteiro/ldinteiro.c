#include <stdio.h>
#include <stdlib.h>

typedef struct No{
  int valor;
  struct No *proximo;
}No;

typedef struct {
  No *inicio;
}Lista;

void inicializarLista(Lista *l){
  l->inicio = NULL;
}
int qtdElemValidos(Lista *l){
  int tam=0;
  No *inicio = l->inicio;
  while(inicio != NULL){
    tam++;
    inicio = inicio->proximo;
  }
  return tam;
}
void imprimir(Lista *lista){
  No *inicio = lista->inicio;
  while(inicio != NULL){
    printf("\nlista= %d", inicio->valor);
    inicio = inicio->proximo;
  }
}
No *buscaElemEPred(Lista *m, int valor, No** pred){
  *pred = NULL;
  No* atual = m->inicio;
  while(atual != NULL && (atual->valor < valor)){ 
    *pred = atual;
    atual = atual->proximo;
  }
  if((atual != NULL)&&(atual->valor == valor)){
    return atual;
  }
  return NULL;//nao encontrou
}
No *buscaElemEPredDesord(Lista *m, int valor, No** pred){
  *pred = NULL;
  No* atual = m->inicio;
  while(atual != NULL){ 
    *pred = atual;
    if(atual->valor == valor){
          return atual;
      }
    atual = atual->proximo;
  }
  return NULL;//nao encontrou
}
int inserir(Lista *m, int valor){//de forma ordenada
  No* pred;
  No* elem;
  elem = buscaElemEPred(m,valor,&pred);//verifica se ja existe
  if(elem != NULL){//se o valor ja existe
    return 0;
  }
  No *novono = malloc(sizeof(No));
  novono->valor = valor;
  if(pred == NULL){//significa que  o valor sera o 1o da lista
    novono->proximo = m->inicio;
    m->inicio = novono;
  }else{
    novono->proximo = pred->proximo;
    pred->proximo = novono;
  }
  return 1;
}

int inserirInicio(Lista *m, int valor){
  No* pred;
  No* elem;
  elem = buscaElemEPred(m,valor,&pred);//verifica se ja existe
  if(elem != NULL){//se o valor ja existe
    return 0;
  }
  No *novono = malloc(sizeof(No));
  novono->valor = valor;
  novono->proximo = m->inicio;
  m->inicio = novono;
  return 1;
}

int inserirFim(Lista *m, int valor) {
    No *pred;
    No *elem;
    elem = buscaElemEPred(m, valor, &pred); //verifica se já existe
    if (elem != NULL) { //se o valor já existe
        return 0;
    }
    No *i = m->inicio;
    while (i != NULL && i->proximo != NULL) {//pega o ultimo nó
        i = i->proximo;
    }
    No *novono = malloc(sizeof(No));
    novono->valor = valor;
    if (i == NULL) {//se for o 1o da lista
        novono->proximo = NULL;
        m->inicio = novono;
    } else {
        novono->proximo = NULL;
        i->proximo = novono;
    }
    return 1;
}

int inserirEntreOrdem(Lista *m, int valor, int valorAnterior, int valorPosterior) {//em uma lista ordenada
    No *predAnterior, *predPosterior;
    No *elemAnterior = buscaElemEPred(m, valorAnterior, &predAnterior);
    if (elemAnterior == NULL) {
        // O elemento anterior não foi encontrado na lista
        return 0;
    }
    No *elemPosterior = buscaElemEPred(m, valorPosterior, &predPosterior);
    if (elemPosterior == NULL) {
        // O elemento posterior não foi encontrado na lista
        return 0;
    }
    No *novono = malloc(sizeof(No));
    novono->valor = valor;

    // Verifica se o elemento anterior é o último elemento da lista
    if (elemAnterior->proximo == NULL) {
        elemAnterior->proximo = novono;
        novono->proximo = NULL;
    } else {
        novono->proximo = elemPosterior;
        elemAnterior->proximo = novono;
    }
    return 1;
}
int inserirEntreDesordem(Lista *m, int valor, int valorAnterior, int valorPosterior) {//em uma lista desordenada
    No *predAnterior, *predPosterior;
    No *elemAnterior = buscaElemEPredDesord(m, valorAnterior, &predAnterior);
    if (elemAnterior == NULL) {
        // O elemento anterior não foi encontrado na lista
        return 0;
    }
    No *elemPosterior = buscaElemEPredDesord(m, valorPosterior, &predPosterior);
    if (elemPosterior == NULL) {
        // O elemento posterior não foi encontrado na lista
        return 0;
    }
    No *novono = malloc(sizeof(No));
    novono->valor = valor;

    // Verifica se o elemento anterior é o último elemento da lista
    if (elemAnterior->proximo == NULL) {
        elemAnterior->proximo = novono;
        novono->proximo = NULL;
    } else {
        novono->proximo = elemPosterior;
        elemAnterior->proximo = novono;
    }
    return 1;
}

int excluir(Lista* m, int valor){
  No* pred;
  No* busca;
  busca = buscaElemEPred(m,valor,&pred);
  if(busca == NULL){//se nao encontrou o valor
    return 0;
  }
  if(pred == NULL){//se for o primeiro elem
    m->inicio = busca->proximo;
  }else{
    pred->proximo = busca->proximo;
  }
  free(busca);
  return 1;
}

int excluirInicio(Lista* m){
    if (m->inicio == NULL) {
        // A lista está vazia, não há elementos para excluir
        return 0;
    }
    No* primeiro = m->inicio;
    m->inicio = primeiro->proximo;
    free(primeiro);
    return 1;
}

int excluirFim(Lista* m){
    if (m->inicio == NULL) {
        // A lista está vazia, não há elementos para excluir
        return 0;
    }

    No* atual = m->inicio;
    No* busca = m->inicio;
    No* pred = NULL;
    while (atual->proximo != NULL) {
        pred = busca;
        busca = busca->proximo;
        atual = atual->proximo;
    }

    if (pred == NULL) {
        // A lista possui apenas um elemento
        free(busca);
        m->inicio = NULL;
    } else {
        pred->proximo = NULL;
        free(busca);
    }

    return 1;
}

int excluirEntre(Lista* m, int valorAnterior, int valorPosterior) {
    No* predAnterior;//serve pra ordenada e desordenada por causa da minha funcao p buscar
    No* predPosterior;
    No* elemAnterior = buscaElemEPredDesord(m, valorAnterior, &predAnterior);
    if (elemAnterior == NULL) {
        // O elemento anterior não foi encontrado na lista
        return 0;
    }
    No* elemPosterior = buscaElemEPredDesord(m, valorPosterior, &predPosterior);
    if (elemPosterior == NULL) {
        // O elemento posterior não foi encontrado na lista
        return 0;
    }
    No* elemExcluir = elemAnterior->proximo;
    if (elemExcluir == NULL || elemExcluir == elemPosterior) {
        // Não há elementos para excluir entre os dois valores
        return 0;
    }
    elemAnterior->proximo = elemExcluir->proximo;
    free(elemExcluir);
    return 1;
}

int alterar(Lista* m, int valor, int novovalor){
  No* pred;
  No* busca;
  busca = buscaElemEPred(m,valor,&pred);
  if(busca == NULL){//se nao encontrou o valor
    return 0;
  }
  busca->valor = novovalor;
  return 1;
}

void reinicializar(Lista* m){
  No* apagar;
  No* elem = m->inicio;
  while(elem != NULL){
    apagar = elem;
    elem = elem->proximo;
    free(apagar);
  }
  m->inicio = NULL;
}

int main(){
  Lista l1;
  inicializarLista(&l1);
  printf("\nQtd de elementos validos: %d", qtdElemValidos(&l1));
  printf("\nOrdenada:\n");
  inserir(&l1, 3);
  inserir(&l1, 2);
  inserir(&l1, 1);
  inserir(&l1, 4);
  excluir(&l1, 2);
  inserirEntreOrdem(&l1, 2, 1, 3);
  inserirInicio(&l1, 321);
  inserirFim(&l1, 123);
  printf("\nNão Ordenada:\n");
  inserirEntreDesordem(&l1,666,2,3);
  imprimir(&l1);
  printf("\nexcluindo entre\n");
  excluirEntre(&l1, 2, 3);
  imprimir(&l1);
  printf("\nordenada de novo\n");
  excluir(&l1, 666);
  excluir(&l1, 321);
  excluir(&l1, 123);
  imprimir(&l1);
  printf("\nexcluindo entre\n");
  excluirEntre(&l1, 1, 3);
  imprimir(&l1);
  printf("\nalterando\n");
  alterar(&l1, 3, 333);
  imprimir(&l1);
  /*printf("\n==excluindo inicio e fim==\n");
  excluirInicio(&l1);
  excluirFim(&l1);
  imprimir(&l1);*/
  //printf("\nQtd de elementos validos: %d", qtdElemValidos(&l1));
  reinicializar(&l1);
  //printf("\nQtd de elementos validos: %d", qtdElemValidos(&l1));
  return 0;
}