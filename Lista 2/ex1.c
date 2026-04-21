#include <stdio.h>
#include <stdlib.h>

void leMatriz(int mtx[4][4]) {
	int i=0, j=0;
	printf("Lendo sua matriz 4x4");
	printf("\n");
	for(i=0;i<4;i++) {
		for(j=0;j<4;j++){
			printf("Digite o valor da linha [%i] e coluna [%i]: ", i+1, j+1);
			scanf("%i", &mtx[i][j]);
		}
	}
	printf("\n");
}

void imprimeMatriz(int mtx[4][4]) {
	int i=0, j=0;
	printf("Imprimindo matriz... \n");
	for(i=0;i<4;i++) {
		for(j=0;j<4;j++){
			printf("%3i ", mtx[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int calculaTraco(int mtx[4][4]) {
	int i=0, j=0, somatracofuncao;
	printf("Imprimindo traco... \n");
	for(i=0;i<4;i++) {
		for(j=0;j<4;j++){
			if(j==i) {
				printf("%3i ", mtx[i][j]);
				somatracofuncao += mtx[i][j]; 
			} else {
				printf("  - ");
			}
		}
		printf("\n");
	}
	printf("\n");	
	return somatracofuncao;
}

int somaAcimaDiagonal(int mtx[4][4]) {
	int i=0, j=0, somaAcimaFuncao;
	for(i=0;i<4;i++) {
		for(j=0;j<4;j++){
			if(j>i) {
				somaAcimaFuncao += mtx[i][j]; 
			}
		}
	}
	return somaAcimaFuncao;
}
int main(){
	int m[4][4];
	leMatriz(m);
	imprimeMatriz(m);
	printf("A soma do traco e = %i.\n", calculaTraco(m));
	printf("A soma dos numeros acima do traco e = %i.\n", somaAcimaDiagonal(m));
	return 0;
	
}
