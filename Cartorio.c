#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço e memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//início criação de variáveis/string
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo(criando um banco de dados)
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salva o valor da variável cpf no file
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo e o "a" significa alterar
	fprintf(file,","); //coloca "," no final do arquivo para separar
	fclose(file); //fecha o arquivo
		
	printf("Digite o nome a ser cadastrado: "); //coletando informação de nome do usuário
	scanf("%s",nome); //Comando entrada de string na variável nome
	
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

int consulta() //Função responsável por consulta de usuário no sistema
{
	//início criação de variáveis/string
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	char cpf[40];
	char conteudo[200];
	//final criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: "); //coletando informação do usuário
	scanf("%s",cpf); //comando para ler o CPF como string("%s")
	
	FILE *file; 
	file = fopen(cpf,"r"); //Abre o arquivo e o "r" significa ler podemos dizer procure
	
	//Inícia uma condição
	if(file == NULL) 
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	//Termina uma condição
	
	//Inícia uma laço de repetição
	while(fgets(conteudo, 200, file) != NULL) //fgets é buscar no (conteudo 200 variáveis dentro do file(arquivo) que for diferente de Nulos
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo); //salva conteudo como string
		printf("\n\n"); //Pula 2 linhas
	}
	
	system("pause"); //comando espera
}

int deletar() //Função responsável por deletar usuário no sistema
{
	//início criação de variável/string
	char cpf[40];
	//final criação de variável/string
	
	printf("Digite o CPF do usuário a ser deletado: "); //coletando informação do usuário
	scanf("%s",cpf); //salva como string o cpf
	
	FILE *file;
	file = fopen(cpf,"r"); //Abre o arquivo e o "r" significa ler podemos dizer procure cpf

	//Início de condição
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");			
	}
	
	else
	{
	fclose(file); //fecha file
	remove(cpf); // remove cpf (remove o arquivo com o CPF encontrado)
	printf("O CPF foi deletado com sucesso! \n");
	system("pause"); //comando espera
	}
	//Fim da confição
}


int main()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
			
		system("cls");		
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("*** Cartório da EBAC ***\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Digite a Opção: "); //Fim do menu
		
		scanf("%d", &opcao); //Comando entrada de valores na variavel
		
		system("cls"); // Comando Limpar tela

		switch(opcao) //início da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
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
			printf("Essa opção naõ está disponível! \n\n");
			system("pause");
			break;
			//fim da seleção
		}
	}
}

