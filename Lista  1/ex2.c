#include <stdio.h>

int n1 = 0, n2 = 0, i = 0, cont = 0;

int main() {
	printf("Digite um numero inteiro: ");
	scanf("%i", &n1);
	printf("Digite outro numero inteiro: ");
	scanf("%i", &n2);
	
	printf("Numeros pares entre %i e %i digitados: \n", n1, n2);
	
	for(i=n1;i<=n2;i++) {
		if(i % 2 == 0) {
			printf("%i ",i);
			cont++;
		}		
	}
	
	printf("\n");
	printf("Total de pares encontrados: %i\n", cont);
	
	return 0;
}