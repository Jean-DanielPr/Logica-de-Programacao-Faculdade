#include <stdio.h>
#include <stdlib.h>

void leMatriz3(int mtx[3][3]);
void subtraiMatriz(int a[3][3], int b[3][3], int s[3][3]);
void transpostaMatriz(int s[3][3], int t[3][3]);
void imprimeMatriz(int mtx[3][3]);

int main() {
    int matrizA[3][3];
    int matrizB[3][3];
    int diferencaMatriz[3][3];
    int matrizTransposta[3][3];

    leMatriz3(matrizA);
    leMatriz3(matrizB);
    subtraiMatriz(matrizA, matrizB, diferencaMatriz);
    transpostaMatriz(diferencaMatriz, matrizTransposta);

    printf("A diferenca entre a matriz A - B: \n");
    imprimeMatriz(diferencaMatriz);

    printf("Agora a diferenca da matriz A - B transposta: \n");
    imprimeMatriz(matrizTransposta);

    return 0;
}

void leMatriz3(int mtx[3][3]) {
    int i, j;
    printf("Lendo sua matriz 3x3.\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Digite o numero da linha [%i] e coluna [%i]: ", i+1, j+1);
            scanf("%i", &mtx[i][j]);
        }
    }
    printf("\n");
}

void subtraiMatriz(int a[3][3], int b[3][3], int s[3][3]) {
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            s[i][j] = a[i][j] - b[i][j];
        }
    }
}

void transpostaMatriz(int s[3][3], int t[3][3]) {
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
        t[j][i] = s[i][j];    
        }
    }
}

void imprimeMatriz(int mtx[3][3]) {
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
        printf("%3i ", mtx[i][j]);    
        }
        printf("\n");
    }
    printf("\n");
}
