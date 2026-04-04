#include <stdio.h>
#include <stdlib.h>
int n1 = 1, n2 = 0, i = 0, cont = 0;

void menu_inicial() {
	printf("Menor numero : ");
	scanf("%i", &n1);
	printf("Maior numero: ");
	scanf("%i", &n2);
	while (getchar() != '\n');
}

int main() {

	while(n1 > n2) {
		system("clear");
		menu_inicial();
		if(n1 > n2) {
			printf("O primeiro valor deve ser menor do que o segundo valor digitado.\n");
			printf("Pressione enter para continuar...\n");
			while (getchar() != '\n');
		}
	}	

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