
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

Turma* criarTurma(int quantidadeAlunos) {
    Turma* turma = (Turma*)malloc(sizeof(Turma));
    turma->alunos = (Aluno*)malloc(quantidadeAlunos * sizeof(Aluno));
    turma->quantidade = 0;
    return turma;
}

void liberarTurma(Turma* turma) {
    free(turma->alunos);
    free(turma);
}

void inserirAluno(Turma* turma, int codigo, char* nome, int idade, float coef) {
    if (turma->quantidade < sizeof(turma->alunos)) {
        Aluno aluno;
        aluno.codigo = codigo;
        strcpy(aluno.nome, nome);
        aluno.idade = idade;
        aluno.coef = coef;
        turma->alunos[turma->quantidade] = aluno;
        turma->quantidade++;
    } else {
        printf("Não é possível inserir alunos.\n");
    }
}

int Busca_aluno_sequencial(Turma* turma, int codigo) {
    for (int i = 0; i < turma->quantidade; i++) {
        if (turma->alunos[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void imprimirAluno(Aluno aluno) {
    printf("cod: %d\n", aluno.codigo);
    printf("nome: %s\n", aluno.nome);
    printf("idade: %d\n", aluno.idade);
    printf("coef: %.2f\n", aluno.coef);
}


void imprimirTurma(Turma* turma) {
    for (int i = 0; i < turma->quantidade; i++) {
        printf("Código: %d\n", turma->alunos[i].codigo);
        printf("Nome: %s\n", turma->alunos[i].nome);
        printf("\n");
    }
}

    
