#include <stdio.h>
#include <stdlib.h>

float saldo_inicial = 0, saque = 0, deposito = 0;
int escolha = 0;

void tela_inicial() {
	printf("[1] - Consultar Saldo.\n");
	printf("[2] - Sacar Valor.\n");
	printf("[3] - Depositar Valor.\n");
	printf("[4] - SAIR.\n");
}

int main() {
	
	printf("Digite seu saldo: ");
	scanf("%f", &saldo_inicial);
	printf("\n");
	
	printf("Saldo inicial R$%.2f\n\n", saldo_inicial);		
	while (escolha != 4) {
		

		tela_inicial(); 
		printf("\n");
		scanf("%i", &escolha);
		switch (escolha) {
			
		case 1: 	
			printf("Seu saldo e R$%.2f\n", saldo_inicial);
			break;
			
		case 2:
			printf("Quanto deseja sacar? ");
			scanf("%f", &saque);
			if(saque > saldo_inicial) {
				printf("Saldo insuficiente!\n\n");
				break;
			}
			saldo_inicial -= saque;
			printf("Saldo apos saque R$%.2f \n\n", saldo_inicial);
			break;
			
		case 3: 
			printf("Quanto deseja depositar? ");
			scanf("%f", &deposito);
			saldo_inicial += deposito;
			printf("Saldo apos deposito R$%.2f \n\n", saldo_inicial);
			break;
			
		case 4:
			printf("Saindo...\n");
			break;
		}
	}
	
	printf("Saldo final R$: %.2f\n", saldo_inicial);

	return 0;	
}