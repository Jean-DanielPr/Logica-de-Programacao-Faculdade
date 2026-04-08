#include <stdio.h>

int main() {
    FILE *dados;
    char nome[100];
    char ra[20];
    char telefone[20];
    char endereco[20];

    dados = fopen("dados.txt", "r"); 
    if(dados == NULL) {
        printf("Arquivo nao pode ser encontrado.");
        getchar();
        exit(1);
    }

    fgets(nome, 100, dados);
    fgets(ra, 20, dados);
    fgets(telefone, 20, dados);
    fgets(endereco, 20, dados);

    printf("nome %sra %stel %send %s\n", nome, ra, telefone, endereco);

    fclose(dados);
    return 0;
}