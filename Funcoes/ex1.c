#include <stdio.h>

int soma(int a, int b) {
    return a + b;
}

int referencia(int *x) {
    *x = *x + *x;
    return *x;
}

int main() {
    int n1 = 4, n2 = 4;

    printf("O resultado da soma entre %i + %i = %i.\n",n1, n2, soma(n1, n2));
    int n3 = 3;

    printf("n3 antes da funcao %i\n", n3);
    referencia(&n3);
    printf("n3 depois da funcao por referencia %i\n", n3);

    return 0;
}