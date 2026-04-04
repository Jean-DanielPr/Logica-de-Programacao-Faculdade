#include <stdio.h>
#include <locale.h>

int vet[10], i, maior = 0, menor = 0;
float med = 0;

void saltar_linha() {
	printf("\n");
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	for(i=0;i<10;i++) {
		printf("Digite o %iº valor: ", i+1);
		scanf("%i", &vet[i]);
		
		if(i==0) {
			maior = vet[i];
			menor = vet[i];
		}
		if(vet[i] > maior) {
			maior = vet[i];		
		}
		if(vet[i] < menor){
			menor = vet[i];
		}
		med+=vet[i];

	}	
	med = med/10;
	
	saltar_linha();
	printf("Maior valor digitado: %i.\n", maior);
	printf("Menor valor digitado: %i.\n", menor);
	printf("Média de todos os valores: %.2f.\n", med);
	printf("Valores acima da média: ");
	
	for(i=0;i<10;i++) {
		if(vet[i] > med) {
			printf("%i ", vet[i]);
		}
	}
	saltar_linha();
	return 0;
}