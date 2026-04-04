#include <stdio.h>
#include <stdlib.h>

float saldo_inicial = 0, saque = 0, deposito = 0;
int escolha = 0;

void tela_inicial() {
	printf("[1] - Consultar Saldo.\n");
	printf("[2] - Sacar Valor.\n");
	printf("[3] - Depositar Valor.\n");
	printf("[4] - SAIR.\n");
	printf("Escolha entre 1 e 4:\n");
}

int main() {
	
	printf("Digite seu saldo: ");
	scanf("%f", &saldo_inicial);
	printf("\n");
			
	while (escolha != 4) {
		
		tela_inicial(); 
		printf("\n");
		scanf("%i", &escolha);
		system("clear");
		switch (escolha) {
			
		case 1: 	
			printf("Saldo atual R$%.2f\n\n", saldo_inicial);
			break;
			
		case 2:
			printf("Saldo atual R$%.2f\n", saldo_inicial);
			printf("Quanto deseja sacar? ");
			scanf("%f", &saque);
			if(saque < 0) {
				printf("Valor invalido. \nTente novamente.\n\n");
				break;
			}
			if(saque > saldo_inicial) {
				printf("Saldo insuficiente!\n\n");
				break;
			}
			saldo_inicial -= saque;
			printf("Saldo apos saque R$%.2f \n\n", saldo_inicial);
			break;
			
		case 3: 
			printf("Saldo atual R$%.2f\n\n", saldo_inicial);
			printf("Quanto deseja depositar? ");
			scanf("%f", &deposito);
			if(deposito < 0) {
				printf("Valor invalido. \nTente novamente.\n\n");
				break;
			}
			saldo_inicial += deposito;
			printf("Saldo apos deposito R$%.2f \n\n", saldo_inicial);
			break;
			
		case 4:
			printf("Ate mais! \nSaindo...\n");
			break;

		default: 
			printf("ERRO!\n");
			printf("Escolha invalida.\n");
			printf("Tente novamente.\n\n");
		}
	}

	return 0;	
}