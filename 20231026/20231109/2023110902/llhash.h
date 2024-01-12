//Definindo o tamanho da tabela hash. tam = 100
#define tam_hash 101

//Definindo o tipo de dado que será armazenado na tabela hash.

//1. EStrutura do PACIENTE
typedef struct {
  int cod_paciente;
  char *nome;
  char *cpf;
  int idade;
} PACIENTE;

//2. Estrutura do NO
typedef struct aux {
  PACIENTE paciente;
  struct aux *prox;
} ELEMENTO;

typedef ELEMENTO* TB_HASH[tam_hash];


int func_dispercao (int cod_paciente);
int inserir (TB_HASH tabela, PACIENTE paciente);
void inicializar_hash (TB_HASH tabela);
void mostrar_hash (TB_HASH tabela);
PACIENTE* buscar (TB_HASH tabela, int cod_paciente);
