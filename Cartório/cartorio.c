#include <stdio.h> //biblioteca de comunição com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> //bibliote de alocações de texto por região
#include <string.h> //biblioteca resoponsavel pelas strings

int registro() //função responsavel por cadastrar os usuaráios no sistema
{
	//inicio criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a armazenar string
	
	strcpy(arquivo, cpf);//responsavel por copiar os valores das strings
	
	FILE *file;//cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo //"w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
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
	
	system("cls");
	printf("Usuário registrado!\n");
	
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");//seleciona a linguagem
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel localizar o arquivo!.\n");
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
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra sistema!.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ### \n\n");
	printf("login de administrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		
	
	
		for(laco=1;laco=1;)
		{
			
			system("cls");//resposavel por limpar a tela
	
	
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
			printf("### Cartório da EBAC ### \n\n"); //inicio do menu
			printf("Escolha a opção desejada do menu: \n\n");
			printf("\t1 - Registrar nome\n");
			printf("\t2 - Consutar nome\n");
			printf("\t3 - Deletar nome\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção: "); //fim do menu
		
			scanf("%d", &opcao); //armazendando a escolha do usuário
	
			system("cls");
		
			switch(opcao)
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
				printf("obrigado por utilizar esse sistema\n");
				return 0;
				break;
			
				default:
				printf("Essa opção não está disponivel!\n");
				system("pause");
				break;
			}	
		}
	}
	
	else
	printf("Senha incorreta");
	
}


