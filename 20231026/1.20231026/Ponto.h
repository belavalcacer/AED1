// Arquivo.h: Declarar tudo aquilo que será visivel para o programador \\

typedef struct ponto Ponto;
// Cria um novo ponto: (aloca memoria para as coordenadas x e y))
Ponto* Ponto_cria(float x, float y);

//Libera um ponto: (libera a memoria alocada por um ponto)
void Ponto_libera (Ponto* p);

// Acessa os valores "x" e "y" de um ponto:
int Ponto_acessa (Ponto* p, float* x, float* y);

// Atribui os valores "x" e "y" a um ponto
int Ponto_atribui (Ponto* p, float x, float y);

// Calcula a distancia entre dois pontos
float Ponto_distancia (Ponto* p1, Ponto* p2);

