//Definindo o tamanho da tabela hash. tam = 100
#define tam_hash 101

//Definindo o tipo de dado que será armazenado na tabela hash.

//1. EStrutura do PACIENTE
typedef struct {
  int cod_paciente;
  char *nome;
  char *cpf;
  int idade;
  int disponivel; //0 = nao disponivel e 1 = disponivel
} PACIENTE;

typedef PACIENTE* TB_HASH[tam_hash];

//Assinatura das funções

int func_dispercao (int cod_paciente);
int inserir (TB_HASH tabela, PACIENTE paciente);
void inicializar_hash (TB_HASH tabela);
void mostrar_hash (TB_HASH tabela);
PACIENTE* buscar (TB_HASH tabela, int cod_paciente);
