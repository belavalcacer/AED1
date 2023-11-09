#include <stdio.h>

int produto(int v[], int n) {
  if (n==1){
    return v[0];
  }
    else {
    return v[n-1] * produto(v, n-1);
  }
}
int main() {
  int v[] = {5, 8, 7, 12, 5};
printf("Produto = %d", produto(v, 5));

  return 0;
}