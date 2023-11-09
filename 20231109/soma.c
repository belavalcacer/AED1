#include <stdio.h>

int soma(int v[], int n) {
  if (n==1){
    return v[0];
  }
    else {
    return v[n-1] + soma(v, n-1);
  }
}
int main() {
  int v[] = {5, 8, 7, 12, 5};
printf("Soma = %d", soma(v, 5));
  
  return 0;
}