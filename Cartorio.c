#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o e mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/string
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo(criando um banco de dados)
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salva o valor da vari�vel cpf no file
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo e o "a" significa alterar
	fprintf(file,","); //coloca "," no final do arquivo para separar
	fclose(file); //fecha o arquivo
		
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o de nome do usu�rio
	scanf("%s",nome); //Comando entrada de string na vari�vel nome
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file); 
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); //comando espera
}

int consulta() //Fun��o respons�vel por consulta de usu�rio no sistema
{
	//in�cio cria��o de vari�veis/string
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	char cpf[40];
	char conteudo[200];
	//final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //comando para ler o CPF como string("%s")
	
	FILE *file; 
	file = fopen(cpf,"r"); //Abre o arquivo e o "r" significa ler podemos dizer procure
	
	//In�cia uma condi��o
	if(file == NULL) 
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	//Termina uma condi��o
	
	//In�cia uma la�o de repeti��o
	while(fgets(conteudo, 200, file) != NULL) //fgets � buscar no (conteudo 200 vari�veis dentro do file(arquivo) que for diferente de Nulos
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo); //salva conteudo como string
		printf("\n\n"); //Pula 2 linhas
	}
	
	system("pause"); //comando espera
}

int deletar() //Fun��o respons�vel por deletar usu�rio no sistema
{
	//in�cio cria��o de vari�vel/string
	char cpf[40];
	//final cria��o de vari�vel/string
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //salva como string o cpf
	
	FILE *file;
	file = fopen(cpf,"r"); //Abre o arquivo e o "r" significa ler podemos dizer procure cpf

	//In�cio de condi��o
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");			
	}
	
	else
	{
	fclose(file); //fecha file
	remove(cpf); // remove cpf (remove o arquivo com o CPF encontrado)
	printf("O CPF foi deletado com sucesso! \n");
	system("pause"); //comando espera
	}
	//Fim da confi��o
}


int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
			
		system("cls");		
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("*** Cart�rio da EBAC ***\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Digite a Op��o: "); //Fim do menu
		
		scanf("%d", &opcao); //Comando entrada de valores na variavel
		
		system("cls"); // Comando Limpar tela

		switch(opcao) //in�cio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;		

			default:
			printf("Essa op��o na� est� dispon�vel! \n\n");
			system("pause");
			break;
			//fim da sele��o
		}
	}
}

