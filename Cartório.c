#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os  usuários no sistema
{	
	setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
	
	//criação das variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int op=0;
	//fim das variáveis
	
	printf("Digite o CPF a ser cadastado: ");
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf); // Copiando a variável cpf para o nome da variável arquivo (Editando o nome do arquivo)
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo,"w"); // Abre o arquivo e escreve(W)
	fprintf(file,"CPF: ");
	fprintf(file,cpf); // salva o valor da variável cpf no arquivo criado
	fprintf(file,"\n");
	fclose(file); // Fecha o arquivo criado
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Nome: ");
	fprintf(file,nome);
	fprintf(file," ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Cargo: ");
	fprintf(file, cargo);
	fclose(file);
	
	printf("\n\n Cliente cadastrado com sucesso!\n\n");
	
	system("pause");
	
	system("cls");
	

}

int consulta() //Função responsável pela consulta de usuários
{
	setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\nNão foi possível abrir o arquivo, CPF não cadastrado.\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usuário a ser deletado: \n\n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	printf("Usuário removido com sucesso!\n\n");
	system("pause");
	
	if (file = NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}

}


int main()
{
	int opcao=0; // Definindo as variáveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("Cartório da EBAC\n\n");
	printf("Login de Administrador\n\nDigite a senha: \n\n");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system ("cls");
		
		for(laco=1;laco=1;)
		{
			system("cls"); // Responsável por limpar a tela
			
			setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
			
			printf("\t Cartório da EBAC\n\n");  // Início do menu
			printf("Escolha a opção desejada do menu: \n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do Sistema\n\n\n");
			printf("Opção: "); // Fim do menu
			
			scanf("%d", &opcao); //Armazenando as informações do usuário
			
			system("cls"); // Limpando a tela
			
			switch(opcao) //Inicio da seleção
			{
				case 1:
				registro(); // Chamada das funções
				break;
				
				case 2:
				consulta();
				break;
				
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema!\n\n");
				return 0;
				break;
				
				default:
				printf("Você escolheu uma opção inválida!\n\n");
				system("pause");
				break;
			} //Fim da seleção
		}//Fechamento do FOR
	}//Fechamento do IF
	
	else
		printf("Senha incorreta!");
}//Fechamento da MAIN

