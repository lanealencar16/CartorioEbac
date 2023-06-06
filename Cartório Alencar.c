#include <stdio.h>//biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>//biblioteca de aloca��es de texto por regi�o
#include <string.h>//biblioteca responsavel por criar as strings

int registro()//responsavel por cadastrar os usu�rios no sistema
{
	//cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��es
	scanf("%s", cpf);//%s armazena a string
	
	strcpy(arquivo, cpf);//reponsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo
	fprintf(file, cpf);//salva o valor da variavel
	fclose(file);//fecha arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo
	fprintf(file, ",");
	fclose(file);//fecha arquivo
	
	printf("Digite o nome a ser cadastrado; ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
		
}

int consultar()
{
	setlocale(LC_ALL,"Portuguese");//definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");//ler arquivo
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200,file)!= NULL)
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
	char conteudo[200];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");//ler arquivo

	
	if (file ==NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
	if(file=200)
	{
		printf("O usu�rio foi deletado do sistema!\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0;//definindo variaveis
	int x=1;
	
	for(x=1;x=1;)
	{
		system("cls");//limpar a tela

	setlocale(LC_ALL,"Portuguese");//definindo a linguagem
	
	printf("Cartorio Alencar\n\n");//inicio do menu
	printf("Escolha a op��o desejada no menu\n\n");
	printf("\t1-Registrar nomes\n");
	printf("\t2-Consultar nomes\n");
	printf("\t3-Deletar nomes\n\n");
	printf("Op��o:");//fim do menu
	
	scanf("%d", &opcao);//armazenando a escolha do usu�rio
	
	system("cls");//limpar a tela
	
	switch(opcao)
	{
		case 1:
		registro();
		break;
		
		case 2:	
		consultar();
		break;
			
		case 3:
	    deletar();
		break;
		
		default :
		printf("Essa op��o n�o est� disponivel!\n");
		system("pause");
		break;
	}
	}
}
