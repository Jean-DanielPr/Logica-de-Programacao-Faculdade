#include <stdio.h>
#include <stdlib.h>

void leMatriz(int mtx[5][5], int *x);
int buscaPosicao(int mtx[5][5], int x, int *linha, int*coluna);

int main() {
    int matriz[5][5], numeroProcurado;
    int linha, coluna, validaBusca;

    leMatriz(matriz, &numeroProcurado);
    validaBusca = buscaPosicao(matriz, numeroProcurado, &linha, &coluna);
    
    if(validaBusca == 1){
        printf("O numero [%i] foi encontrado na linha [%i] e coluna [%i].\n", numeroProcurado, linha, coluna);
    } else {
        printf("Numero nao encontrado.\n");
    }

    return 0;
}

void leMatriz(int mtx[5][5], int *x) {
    int i, j;
    printf("Lendo sua matriz 5x5\n");
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("Digite o numero da linha [%i] e coluna [%i]: ", i+1, j+1);
            scanf("%i", &mtx[i][j]);
        }
    }
    printf("\nAgora digite um valor X para procurarmos a posicao dele na matriz: ");
    scanf("%i", x);
    printf("\n");
}

int buscaPosicao(int mtx[5][5], int x, int *linha, int*coluna) {
    int i, j;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            if(mtx[i][j] == x) {
                *linha = i+1;
                *coluna = j+1;
                return 1;           
            } 
        }
    }
    return 0;
}
