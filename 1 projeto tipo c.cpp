#include <stdio.h> // biblioteca de comunicação com usúario
#include <stdlib.h> // bibliotaca de alocação de espaço em memória
#include <locale.h> // bibliotaca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro()// Função responsável por cadastra os usuário no sistema
{
	//icicío da criação de variáveis/strings
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
	//Final da criação de variáveis/strings	

	
		printf("Digite o CPF a ser cadastrado: ");// coletando informação do usuário
		scanf("%s" , cpf);// %s refere-se a strings
		
		strcpy(arquivo, cpf); // Responsável por copiar valores das string
		
		FILE *file; // cria o arquivo
		file = fopen(arquivo, "w"); // cria o arquivo, "w" write significa escrever em inglês 
		fprintf(file,cpf); // salva o valor da variável
		fclose(file); // fecha o arquivo
		
		file = fopen(arquivo, "a"); // "a" atualiza a informação 
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
	file = fopen(cpf,"r"); //  "r" é de ler 
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200,file)  !=NULL) // while enquanto tiver conteudo dentro do arq. vai armazenado ali dentro  
	{
		printf("\nEssas são as informações do usuário: (cpf/nome/sobrenome/cargo )\n\n                                     ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

	
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n ");
		system("pause");
	}
}


int main() // Função principal
{ 
    int opcao=0; // Definindo variáveis	
    int laco=1; // Repete a opçao 
    
    for(laco=1;laco=1;) // Repete a opçao até o usuário colocar a certa ou a quantidade definido 
    {
	
       system("cls"); //  limpa a tela 
	   
	   setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	   
       printf("####Cartótio da EBAC #### \n\n"); // inicío do menu
       printf("Escolha a opção desejada do menu:\n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");				
	   printf("\t3 - Deletar nomes\n\n");
	   printf("Sair do sistema!\n\n"); 
	   printf("Opção: "); // fim do menu
       
	   scanf("%d", &opcao); //  armazenando a escolha do usuário
       
       system("cls"); // limpa a tela
       
       switch(opcao) // Inicío da seleção do menu / substitui o if para nao ficar escrevendo um a um 
	   {
	      case 1://
	      registro(); // chamada de funções
              break; // Fecha a opção como se fosse as 'chaves'
          
          case 2:
              consulta();
              break;
           
          case 3:  
              deletar();
	      break;

	  case 4:
	      printf("Obrigado por utilizar o sistema\n\n");
	      return 0;
	      break;
		   
          default: // se não for nenhuma das opções acima
	      printf("Essa opção não está disponível!\n");
	      system("pause");  
              break;    
        }
    }
	

}
    
    
    
    
    



