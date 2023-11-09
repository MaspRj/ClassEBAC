#include <stdio.h> //biblioteca de comunica��o
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel pela c�pia dos valores da string
	
	FILE *file; //Criar o arquivo 
	file = fopen(arquivo, "w"); //Cria o arquivo 
    fprintf(file,cpf); //Salva o valor da vari�vel
    fclose(file); //Fecha o arquivo
    
    file = fopen(arquivo, "a"); // Atualiza a informa��o
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
	
	if(file == NULL) //Se n�o houver registro
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n"); //Exibe esta mensagem na tela 
	}
	
	while(fgets(conteudo,200,file) !=NULL) //Caso houver regisro
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //Exibe esta mensagem na tela
		printf("%s",conteudo);
		printf("\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //Solicita dado para consulta
	scanf("%s",cpf);
	
	remove(cpf); //Deleta dados
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //Se n�o houver registro
	{
		printf("O usu�rio n�o foi encontrado no sistema!.\n"); //Exibe esta mensagem na tela
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int x=1; //Valor da vari�vel
	
	for(x=1;x=1;)
   {
  	 system("cls");
  	 
  	 setlocale(LC_ALL, "portuguese"); //Definindo linguagem
	
	 printf("Cart�rio da EBAC\n\n"); //In�cio do menu
	 printf("Escolha a op��o desejada no menu:\n\n");
	 printf("\t1 - Registrar nomes\n"); //Op��o 1
	 printf("\t2 - Consultar nomes\n"); //Op��o 2
	 printf("\t3 - Deletar nomes\n\n"); //Op��o 3
	 printf("Op��o: "); //Fim do menu
	 
	 scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
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
  	 	 printf("Op��o inv�lida, tente novamente!\n");
  	 	 system("pause");
  	 	 break;
  	 	 
        }
   }
}
