#include <stdio.h> // biblioteca de comunica��o com us�ario
#include <stdlib.h> // bibliotaca de aloca��o de espa�o em mem�ria
#include <locale.h> // bibliotaca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro()// Fun��o respons�vel por cadastra os usu�rio no sistema
{
	//icic�o da cria��o de vari�veis/strings
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
	//Final da cria��o de vari�veis/strings	

	
		printf("Digite o CPF a ser cadastrado: ");// coletando informa��o do usu�rio
		scanf("%s" , cpf);// %s refere-se a strings
		
		strcpy(arquivo, cpf); // Respons�vel por copiar valores das string
		
		FILE *file; // cria o arquivo
		file = fopen(arquivo, "w"); // cria o arquivo, "w" write significa escrever em ingl�s 
		fprintf(file,cpf); // salva o valor da vari�vel
		fclose(file); // fecha o arquivo
		
		file = fopen(arquivo, "a"); // "a" atualiza a informa��o 
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s", nome);
		
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
		
		system("pause");
		
		
		
		
}


	
int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //  "r" � de ler 
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200,file)  !=NULL) // while enquanto tiver conteudo dentro do arq. vai armazenado ali dentro  
	{
		printf("\nEssas s�o as informa��es do usu�rio: (cpf/nome/sobrenome/cargo )\n\n                                     ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

	
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n ");
		system("pause");
	}
}


int main() // Fun��o principal
{ 
    int opcao=0; // Definindo vari�veis	
    int laco=1; // Repete a op�ao 
    
    for(laco=1;laco=1;) // Repete a op�ao at� o usu�rio colocar a certa ou a quantidade definido 
    {
	
       system("cls"); //  limpa a tela 
	   
	   setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	   
       printf("####Cart�tio da EBAC #### \n\n"); // inic�o do menu
       printf("Escolha a op��o desejada do menu:\n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");				
	   printf("\t3 - Deletar nomes\n\n");
	   printf("Op��o: "); // fim do menu
       
	   scanf("%d", &opcao); //  armazenando a escolha do usu�rio
       
       system("cls"); // limpa a tela
       
       switch(opcao) // Inic�o da sele��o do menu / substitui o if para nao ficar escrevendo um a um 
	   {
	      case 1://
	      registro(); // chamada de fun��es
          break; // Fecha a op��o como se fosse as 'chaves'
          
          case 2:
          consulta();
          break;
           
          case 3:  
          deletar();
		  break;
		  
		  default: // se n�o for nenhuma das op��es acima
		  printf("Essa op��o n�o est� dispon�vel!\n");
	      system("pause");  
          break;    
        }
    }
	

}
    
    
    
    
    



