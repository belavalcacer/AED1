#include <stdio.h>

int menor(int v[], int tam) {
  int m;
  if (tam == 1) {
    return v[0];
  }
    else{
      m = menor(v, tam - 1);
    }
      if(m < v[tam-1]){
        return m;
      }
        else{
          return v[tam-1];
  }
}

int main () {
  int vetor[] = {5, 8, 12, 7, 6};
  printf("Menor = %d", menor(vetor, 5));
  return 0;
}