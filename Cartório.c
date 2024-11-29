#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os  usu�rios no sistema
{	
	setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
	
	//cria��o das vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int op=0;
	//fim das vari�veis
	
	printf("Digite o CPF a ser cadastado: ");
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf); // Copiando a vari�vel cpf para o nome da vari�vel arquivo (Editando o nome do arquivo)
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo,"w"); // Abre o arquivo e escreve(W)
	fprintf(file,"CPF: ");
	fprintf(file,cpf); // salva o valor da vari�vel cpf no arquivo criado
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

int consulta() //Fun��o respons�vel pela consulta de usu�rios
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
		printf("\nN�o foi poss�vel abrir o arquivo, CPF n�o cadastrado.\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usu�rio a ser deletado: \n\n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	printf("Usu�rio removido com sucesso!\n\n");
	system("pause");
	
	if (file = NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}

}


int main()
{
	int opcao=0; // Definindo as vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("Cart�rio da EBAC\n\n");
	printf("Login de Administrador\n\nDigite a senha: \n\n");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system ("cls");
		
		for(laco=1;laco=1;)
		{
			system("cls"); // Respons�vel por limpar a tela
			
			setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
			
			printf("\t Cart�rio da EBAC\n\n");  // In�cio do menu
			printf("Escolha a op��o desejada do menu: \n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do Sistema\n\n\n");
			printf("Op��o: "); // Fim do menu
			
			scanf("%d", &opcao); //Armazenando as informa��es do usu�rio
			
			system("cls"); // Limpando a tela
			
			switch(opcao) //Inicio da sele��o
			{
				case 1:
				registro(); // Chamada das fun��es
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
				printf("Voc� escolheu uma op��o inv�lida!\n\n");
				system("pause");
				break;
			} //Fim da sele��o
		}//Fechamento do FOR
	}//Fechamento do IF
	
	else
		printf("Senha incorreta!");
}//Fechamento da MAIN

