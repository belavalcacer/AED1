typedef struct {
    int codigo;
    char nome[50];
    int idade;
    float coef;
} Aluno;

///TDA para turma
typedef struct {
    Aluno *alunos;
    int quantidade;
} Turma;
