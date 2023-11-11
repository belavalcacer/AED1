#include <stdio.h>
#include <string.h>
#include "aluno.h"

int main() {
    int quantidadeAlunos;
    printf("Digite o numero de alunos: ");
    scanf("%d", &quantidadeAlunos);

    Turma* turma = criarTurma(quantidadeAlunos);

    for (int i = 0; i < quantidadeAlunos; i++) {
        int codigo, idade;
        char nome[50];
        float coef;

        printf("\nAluno %d\n", i+1);
        printf("Código: ");
        scanf("%d", &codigo);
        printf("Nome: ");
        scanf(" %[^\n]", nome);
        printf("Idade: ");
        scanf("%d", &idade);
        printf("Coeficiente: ");
        scanf("%f", &coef);

        inserirAluno(turma, codigo, nome, idade, coef);
    }
  
    int codigoBusca;
    printf("Digite o código do aluno: ");
    scanf("%d", &codigoBusca);

    int posicao = Busca_aluno_sequencial(turma, codigoBusca);
    if (posicao != -1) {
        printf("Aluno encontrado:\n");
        imprimirAluno(turma->alunos[posicao]);
    }

    printf("Informacao dos alunos da turma:\n");
    imprimirTurma(turma);

    liberarTurma(turma);

    return 0;
}