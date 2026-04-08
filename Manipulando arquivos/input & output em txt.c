#include <stdio.h>

int main() {
	FILE *dados;
	char informacoes[100];

// Procedimento para criar o arquivo dados.txt    
    void criar_arquivo() {
        dados = fopen("dados.txt", "w");
	    if(dados == NULL) {
		    printf("Erro ao abrir o arquivo.");
		    exit(1);
	    }
	    printf("Arquivo criado com sucesso.\n");
	    printf("Pressione enter para continuar.");
	    while (getchar() == "\n")
	    fclose(dados);
        }

    criar_arquivo();
 
// Printando dados dentro do arquivo   
	dados = fopen("dados.txt", "a");
	if(dados == NULL) {
		printf("Erro ao abrir o arquivo.");
		exit(1);
	}
	printf("Arquivo aberto e pronto para gravar suas informacoes.\n\n");
	printf("Digite o nome do aluno a ser gravado: ");
	fgets(informacoes, 100, stdin);
	fprintf(dados, "%s", informacoes);

	printf("Digite o RA do aluno a ser gravado: ");
	fgets(informacoes, 100, stdin);
	fprintf(dados, "%s", informacoes);

	printf("Digite o (DDD) e Telefone do aluno a ser gravado: ");
	fgets(informacoes,100, stdin);
	fprintf(dados, "%s", informacoes);

	printf("Digite o Endereco do aluno a ser gravado: ");
	fgets(informacoes, 100, stdin);
	fprintf(dados, "%s", informacoes);
	
	printf("Dados gravados com sucesso.\n");
	printf("Pressione enter para continuar.\n");
	while(getchar() == "\n");
	fclose (dados);

 //Lendo os dados do arquivo    
    dados = fopen("dados.txt", "r");
	if(dados == NULL) {
		printf("Erro ao abrir o arquivo.");
		exit(1);
	}

    int i = 0;

    i = fgetc(dados);
    
    printf("Nome do aluno: ");
    while(!feof(dados)) {

        putchar(i);
        i = fgetc(dados);
    }    

    fclose(dados);
	return 0;	
}