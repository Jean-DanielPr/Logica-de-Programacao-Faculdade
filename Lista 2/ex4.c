#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int opcao;

void telaInicial();
void criaArquivo();
void gravaDados();
void consultaArquivo();
void listarLivro();
	
int main() {
	setlocale(LC_ALL, "Portuguese");
	
	telaInicial();
	
	while (opcao != 0) {
		
		switch (opcao) {	
		case 1:
			criaArquivo();
			gravaDados();
			telaInicial();
			break;
		case 2:
			consultaArquivo();
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			listarLivro();
			telaInicial();
			break;
		default:
			printf("Opção inválida.");
			break;
		}
		
	}
	printf("Saindo...");
	return 0;
}

void telaInicial() {
	
	printf("===== BIBLIOTECA =====\n");
	printf("[1] - Cadastrar livro.\n");
	printf("[2] - Consultar livro.\n");
	printf("[3] - Emprestar livro.\n");
	printf("[4] - Devolver livro.\n");
	printf("[5] - Listar livros.\n");
	printf("[0] - Sair.\n\n");
	scanf("%i", &opcao);
	while (getchar () != '\n');
	system("cls");
	
}

void criaArquivo() {
	
	FILE *livro = fopen("Biblioteca.txt", "r");
		
	if (livro == NULL){
		livro = fopen("Biblioteca.txt", "w");
		if (livro == NULL){
			printf("Erro ao criar arquivo");
			exit(1);
		}	
		printf("Arquivo Biblioteca criado com sucesso!\n");	
		printf("Pressione enter para continuar.\n");
		while (getchar () != '\n');
	}
	
	fclose(livro);
}

void gravaDados() {
	char dados_temporarios[1000];
	FILE *gravando = fopen("Biblioteca.txt", "a");
	
	if (gravando == NULL){
		printf("Erro ao abrir o arquivo");
		exit(1);
	} else {
		printf("Informe o nome do livro: ");
		fgets(dados_temporarios, 1000, stdin);
		fprintf(gravando, "Nome do livro: %s", dados_temporarios);
						
		printf("Informe o nome do autor do livro: ");
		fgets(dados_temporarios, 1000, stdin);
		fprintf(gravando, "Autor do livro: %s", dados_temporarios);	
		
		printf("Informe o código do livro: ");
		fgets(dados_temporarios, 1000, stdin);
		fprintf(gravando, "Codigo do livro: %s", dados_temporarios);	
		
		fprintf(gravando, "Status: Disponivel \n\n", dados_temporarios);	
		
		fclose(gravando);
	}
			
}

void consultaArquivo() {
	FILE *consulta = fopen("Biblioteca.txt", "r");
	
		if (consulta == NULL){
		printf("Erro ao abrir o arquivo");
		exit(1);
	} else {
		
	}
	
}

void listarLivro() {
	FILE *lista = fopen("Biblioteca.txt", "r");
	
	if (lista == NULL){
		printf("Erro ao abrir o arquivo");
		exit(1);
	} else {
		int letra = 0;
		letra = fgetc(lista);
    	while (!feof(lista)) {
        	putchar(letra);
        	letra = fgetc(lista);
    	}
        fclose(lista); 
    }    
}
