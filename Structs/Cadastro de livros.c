#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
	int qtd;
	
	printf("=======CADASTRO DE LIVROS========\n");
	printf("Quantos livros deseja cadastrar? \n");
	scanf("%i", &qtd);
	while(getchar () != '\n');
	
	typedef struct {
		char nome[100];
		int id_livro;
		char autor[100];
		char editora[100];
	} Livros;
	
	Livros livros[qtd];
	int i;
	
	for(i = 0; i < qtd; i++) {
		
		printf("Nome do %i° livro: ", i+1);
		fgets(livros[i].nome, 100, stdin);
		livros[i].nome[strcspn(livros[i].nome, "\n")] = '\0';
		
		livros[i].id_livro = i;
				
		printf("Autor do %i° livro: ", i+1);
		fgets(livros[i].autor, 100, stdin);
		livros[i].autor[strcspn(livros[i].autor, "\n")] = '\0';
		
		printf("Editora do %i° livro: ", i+1);
		fgets(livros[i].editora, 100, stdin);
		livros[i].editora[strcspn(livros[i].editora, "\n")] = '\0';
		
		system("cls");		
		
	}
	
	printf("Exibindo os livros cadastrados.\n");
	
	for(i = 0; i < qtd; i++) {
		
		printf("\n");
		printf("%i° Livro.\n", i+1);
		printf("Nome: %s.\n", livros[i].nome);
		printf("ID: %i.\n", livros[i].id_livro);
		printf("Autor: %s.\n", livros[i].autor);
		printf("Editora: %s.\n", livros[i].editora);
		
	}
	
	return 0;
}
