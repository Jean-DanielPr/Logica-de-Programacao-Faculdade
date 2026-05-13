#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int opcao;

void telaInicial();
void criaArquivo();
void gravaDados();
void consultaArquivo();
void emprestaLivro();
void devolveLivro();
void listarLivro();
	
int main() {
	setlocale(LC_ALL, "Portuguese");
	
	telaInicial();
	
	while (opcao != 0) {
		
		switch (opcao) {	

		case 1:
			criaArquivo();
			gravaDados();
			break;

		case 2:
			consultaArquivo();
			break;

		case 3:
			emprestaLivro();
			break;

		case 4:
			devolveLivro();
			break;

		case 5:
			listarLivro();
			break;

		default:
			printf("Opção inválida.");
			break;

		}
		telaInicial();
	}
	printf("Saindo...\n");
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
	system("clear");
	
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

		printf("Biblioteca aberta e pronta para armazenar os dados dos livros.\n");
		printf("Informe o nome do livro: ");
		fgets(dados_temporarios, 1000, stdin);
		fprintf(gravando, "Nome do livro: %s", dados_temporarios);
						
		printf("Informe o nome do autor do livro: ");
		fgets(dados_temporarios, 1000, stdin);
		fprintf(gravando, "Autor do livro: %s", dados_temporarios);	
		
		printf("Informe o código do livro: ");
		fgets(dados_temporarios, 1000, stdin);
		fprintf(gravando, "Codigo do livro: %s", dados_temporarios);	
		
		fprintf(gravando, "Status: Disponivel \n");	

		printf("Livro cadastrado com suceeso!\n");
		
		fclose(gravando);
	}
			
}

void consultaArquivo() {
	char busca[1000];
	char linha_lida[1000];
	int resultado = 0;
	FILE *consulta = fopen("Biblioteca.txt", "r");
	
	if (consulta == NULL){

		printf("Erro ao abrir o arquivo");
		exit(1);

	} else {

		printf("Nome do livro que deseja consultar: ");
		fgets(busca, 1000, stdin);
		busca[strcspn(busca, "\n")] = '\0';

		printf("Procurando...\n");
		printf("Resultados para: '%s'.\n\n", busca);

		while (fgets(linha_lida, 1000, consulta) != NULL) {
        
        if (strstr(linha_lida, busca) != NULL) {
            
            printf("> %s", linha_lida);
            resultado = 1; 

// Pula para a linha do status e codigo 
			(fgets(linha_lida, 1000, consulta) != NULL);
        
            if (fgets(linha_lida, 1000, consulta) != NULL) {
				printf("> %s", linha_lida);
			}
            
            if (fgets(linha_lida, 1000, consulta) != NULL) {
                printf("> %s", linha_lida);
            }
    
            printf("\n");

        }
    }

    if (resultado == 0) {
        printf("Livro nao encontrado.\n");
    }

    printf("------------------------------\n");

    fclose(consulta);
	}

}

void emprestaLivro() {
    char busca[100];
    char linha_nome[1000];
    char linha_autor[1000];
    char linha_codigo[1000];
    char linha_status[1000];
    char linha_vazia[1000]; 
    
    int encontrou = 0;

    FILE *original = fopen("Biblioteca.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (original == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        return;
    }

    printf("Digite o CODIGO do livro que deseja pegar emprestado: ");
    
    fgets(busca, 100, stdin);
    busca[strcspn(busca, "\n")] = '\0'; 

    if (strlen(busca) == 0) {
        printf("Erro: Busca invalida. Tente novamente.\n");
        fclose(original);
        fclose(temp);
        remove("temp.txt");
        return;
    }

    while (fgets(linha_nome, 1000, original) != NULL) {
        fgets(linha_autor, 1000, original);
        fgets(linha_codigo, 1000, original);
        fgets(linha_status, 1000, original);
		fgets(linha_vazia, 1000, original);


        if (strstr(linha_codigo, busca) != NULL) {
            encontrou = 1;
            
            fprintf(temp, "%s", linha_nome);
            fprintf(temp, "%s", linha_autor);
            fprintf(temp, "%s", linha_codigo);
            fprintf(temp, "Status: Emprestado\n"); 
			fprintf(temp, "%s", linha_vazia);
            
            printf("O livro de codigo '%s' foi EMPRESTADO.\n", busca);
            
        } else {
            fprintf(temp, "%s", linha_nome);
            fprintf(temp, "%s", linha_autor);
            fprintf(temp, "%s", linha_codigo);
            fprintf(temp, "%s", linha_status);
			fprintf(temp, "%s", linha_vazia);
        }
    }

    fclose(original);
    fclose(temp);

    if (encontrou == 1) {
        remove("Biblioteca.txt");
        rename("temp.txt", "Biblioteca.txt");
    } else {
        remove("temp.txt");
        printf("Nenhum livro encontrado com o codigo '%s'.\n", busca);
    }
}

void devolveLivro() {
	char busca[100];
    char linha_nome[1000];
    char linha_autor[1000];
    char linha_codigo[1000];
    char linha_status[1000];
    char linha_vazia[1000]; 
    
    int encontrou = 0;

    FILE *original = fopen("Biblioteca.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (original == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        return;
    }

    printf("Digite o CODIGO do livro que deseja devolver: ");
    
    fgets(busca, 100, stdin);
    busca[strcspn(busca, "\n")] = '\0'; 

    if (strlen(busca) == 0) {
        printf("Erro: Busca invalida. Tente novamente.\n");
        fclose(original);
        fclose(temp);
        remove("temp.txt");
        return;
    }

    while (fgets(linha_nome, 1000, original) != NULL) {
        fgets(linha_autor, 1000, original);
        fgets(linha_codigo, 1000, original);
        fgets(linha_status, 1000, original);
		fgets(linha_vazia, 1000, original);


        if (strstr(linha_codigo, busca) != NULL) {
            encontrou = 1;
            
            fprintf(temp, "%s", linha_nome);
            fprintf(temp, "%s", linha_autor);
            fprintf(temp, "%s", linha_codigo);
            fprintf(temp, "Status: Disponivel\n"); 
			fprintf(temp, "%s", linha_vazia);
            
            printf("O livro de codigo '%s' foi DEVOLVIDO.\n", busca);
            
        } else {
            fprintf(temp, "%s", linha_nome);
            fprintf(temp, "%s", linha_autor);
            fprintf(temp, "%s", linha_codigo);
            fprintf(temp, "%s", linha_status);
			fprintf(temp, "%s", linha_vazia);
        }
    }

    fclose(original);
    fclose(temp);

    if (encontrou == 1) {
        remove("Biblioteca.txt");
        rename("temp.txt", "Biblioteca.txt");
    } else {
        remove("temp.txt");
        printf("Nenhum livro encontrado com o codigo '%s'.\n", busca);
    }
}		

void listarLivro() {
	FILE *lista = fopen("Biblioteca.txt", "r");
	
	if (lista == NULL){
		printf("Erro ao abrir o arquivo da biblioteca.");
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
