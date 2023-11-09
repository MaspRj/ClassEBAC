#include <stdio.h> //biblioteca de comunicação
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável pelas string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel pela cópia dos valores da string
	
	FILE *file; //Criar o arquivo 
	file = fopen(arquivo, "w"); //Cria o arquivo 
    fprintf(file,cpf); //Salva o valor da variável
    fclose(file); //Fecha o arquivo
    
    file = fopen(arquivo, "a"); // Atualiza a informação
    fprintf(file,", Nome: ");
    fclose(file);
    
	printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
        
    file = fopen(arquivo, "a");
    fprintf(file,", Sobrenome: ");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");     
    fprintf(file,sobrenome);
    fclose(file);
         
	file = fopen(arquivo, "a");
    fprintf(file,", Cargo: ");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //Solicita dado para consulta
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //Se não houver registro
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n"); //Exibe esta mensagem na tela 
	}
	
	while(fgets(conteudo,200,file) !=NULL) //Caso houver regisro
	{
		printf("\nEssas são as informações do usuário: "); //Exibe esta mensagem na tela
		printf("%s",conteudo);
		printf("\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); //Solicita dado para consulta
	scanf("%s",cpf);
	
	remove(cpf); //Deleta dados
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //Se não houver registro
	{
		printf("O usuário não foi encontrado no sistema!.\n"); //Exibe esta mensagem na tela
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo variáveis
	int x=1; //Valor da variável
	
	for(x=1;x=1;)
   {
  	 system("cls");
  	 
  	 setlocale(LC_ALL, "portuguese"); //Definindo linguagem
	
	 printf("Cartório da EBAC\n\n"); //Início do menu
	 printf("Escolha a opção desejada no menu:\n\n");
	 printf("\t1 - Registrar nomes\n"); //Opção 1
	 printf("\t2 - Consultar nomes\n"); //Opção 2
	 printf("\t3 - Deletar nomes\n\n"); //Opção 3
	 printf("Opção: "); //Fim do menu
	 
	 scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	 system("cls");
	 
	 switch(opcao)
  	  {
  	 	 case 1:
  	 	 registro();
  	 	 break;
  	 	
  	 	 case 2:
  	 	 consulta();
  	 	 break;
  	 	
  	 	 case 3:
  	 	 deletar();
  	 	 break;
  	 	   	 	  	
  	 	 default:
  	 	 printf("Opção inválida, tente novamente!\n");
  	 	 system("pause");
  	 	 break;
  	 	 
        }
   }
}
