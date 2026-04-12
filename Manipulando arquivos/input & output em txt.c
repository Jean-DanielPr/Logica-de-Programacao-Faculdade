#include <stdio.h>
#include <stdlib.h>

// Procedimento para criar o arquivo dados.txt    
void criar_arquivo() {
	FILE *arquivo_temp = fopen("dados.txt", "w");
    arquivo_temp = fopen("dados.txt", "w");
	if(arquivo_temp == NULL) {
		printf("Erro ao abrir o arquivo.");
		exit(1);
	}
	printf("Arquivo criado com sucesso.\n");
	printf("Pressione enter para continuar.\n");
	while (getchar() != '\n');
	fclose(arquivo_temp);
    }

int main() {
	FILE *dados;
	char informacoes[100];

// Chamando procedimento
    criar_arquivo();
 
// Printando dados dentro do arquivo   
	dados = fopen("dados.txt", "a");
	if(dados == NULL) {
		printf("Erro ao abrir o arquivo.");
		exit(1);
	}
	printf("Arquivo aberto e pronto para gravar suas informacoes.\n");
	printf("Digite o nome do aluno a ser gravado: ");
	fgets(informacoes, 100, stdin);
	fprintf(dados, "Nome: %s", informacoes);

	printf("Digite o RA do aluno a ser gravado: ");
	fgets(informacoes, 100, stdin);
	fprintf(dados, "RA: %s", informacoes);

	printf("Digite o (DDD) e Telefone do aluno a ser gravado: ");
	fgets(informacoes,100, stdin);
	fprintf(dados, "Telefone: %s", informacoes);

	printf("Digite o Endereco do aluno a ser gravado: ");
	fgets(informacoes, 100, stdin);
	fprintf(dados, "Endereco: %s\n", informacoes);
	
	printf("\nDados gravados com sucesso.\n");
	printf("Pressione enter para continuar.\n");
	while(getchar() != '\n');
	fclose (dados);

 //Lendo e imprimindo os dados do arquivo    
    dados = fopen("dados.txt", "r");
	if(dados == NULL) {
		printf("Erro ao abrir o arquivo.");
		exit(1);
	}

    int letra = 0;

    letra = fgetc(dados);
    while(!feof(dados)) {
        putchar(letra);
        letra = fgetc(dados);
    }    

    fclose(dados);
	return 0;	
}