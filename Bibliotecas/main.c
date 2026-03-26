//Codigo principal
#include <stdio.h>
#include "calculadora.h"
#include <math.h>

float n1 = 0, n2 = 0;

int main (){

    printf("Digite 1 numero: ");
    scanf("%f", &n1);
    printf("Digite outro numero: ");
    scanf("%f", &n2);

    printf("O resultado da soma entre %.f+%.f = %.f.\n", n1, n2, soma(n1, n2));
    printf("O resultado da subtracao entre %.f-%.f = %.f.\n", n1, n2, subtracao(n1, n2));
    printf("O resultado da multiplicacao entre %.f*%.f = %.f.\n", n1, n2, multi(n1, n2));
    printf("O resultado da divisao entre %.2f/%.2f = %.2f.\n", n1, n2, divisao(n1, n2));

}