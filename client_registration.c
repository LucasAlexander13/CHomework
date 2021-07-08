//inclusão de bibliotecas e criação do struct
#include <stdio.h>
#include <locale.h>
#include <string.h>

struct Cliente
{
  char nome[31];
  int nascimento;
  float montante;
  int codigo;
};

int main(void) 
{
  // Permitir acentuação e criação das variáveis.
  setlocale(LC_ALL, "Portuguese");
  
  struct Cliente c[10];
  float compara = 0;
  char comprador[31];
  int aux, alter;
  

  // Menu de opções para interação com o programa.
  for(int i = 0; i < 10;)
  {
    printf("\n\n===== Cadastro de clientes =====");
    printf("\nPossiveis operações no programa:");
    printf("\n1 - Incluir um novo cliente.");
    printf("\n2 - Remover um cliente.");
    printf("\n3 - Listar o melhor comprador.");
    printf("\n4 - Zerar todos os montantes.");
    printf("\n5 - Atualizar um montante.");
    printf("\n6 - Exibir um montante.");
    printf("\n7 - Listar os registros.\n");
    printf("\nDigite a opção escolhida: ");
    scanf("%d", &aux);
    printf("================================\n");
    
    switch(aux)
    {
      // Algoritmo para incluir um novo cliente.
      case 1:
      printf("\nO código do cliente será: %d\n", i + 1);
      c[i].codigo = i + 1;

      printf("\nDigite o nome do cliente: ");
      scanf("%s", c[i].nome);

      printf("Digite o ano de nascimento dele: ");
      scanf("%d", &c[i].nascimento);

      printf("Digite o montante gasto: R$ ");
      scanf("%f", &c[i].montante);

      printf("\nNovo cliente cadastrado com sucesso.\n");
      i++;
      break;

      // Algorítmo para remover um cliente.
      case 2:
      if(i > 0){
        printf("\nDigite o código do cliente que deseja excluir:");
        scanf("%d", &alter);

        for(int j = 0; j < i; j++)
        {
          if(c[j].codigo == alter)
          {
            for(int k = j;k < i; k++)
            {
              strcpy(c[k].nome, c[k+1].nome);
              c[k].nascimento = c[k+1].nascimento;
              c[k].montante = c[k+1].montante;
            }
            printf("\nCliente removido. As posições foram atualizadas.");
            i--;
          }
        }
      } 
      else 
      {
        printf("\nVocê não possui nenhum cliente cadastrado.");
      }
      break;

      // Algoritmo para mostrar o melhor comprador.
      case 3:

      for(int j = 0; j < i; j++)
      {
        if(c[j].montante > compara)
        {
          compara = c[j].montante;
          strcpy(comprador, c[j].nome);
        }
      }
      printf("\nO maior comprador foi: %s", comprador);
      printf("\nCom um montante gasto de R$ %0.2f", compara);
      compara = 0;
      break;
      
      // Algoritmo para zerar todos os montantes.
      case 4:

      for(int j = 0; j < i; j++)
      {
        c[j].montante = 0;
      }
      printf("\nTodos os montantes foram zerados.");
      break;

      //Algoritmo para atualizar um montante.
      case 5:

      printf("\nDigite o codigo do cliente para atualizar o montante: ");
      scanf("%d", &alter);

      for(int j = 0; j < i; j++)
      {
        if(c[j].codigo == alter)
        {
          printf("\nO cliente encontrado se chama: %s.", c[j].nome);
          printf("\nDigite o novo valor para o montante: ");
          scanf("%f", &c[j].montante);

          printf("\nValor atualizado com sucesso.");
        }
      }
      break;

      // Algoritmo para mostrar um montante.
      case 6:

      printf("\nDigite o código do cliente para saber o montante: ");
      scanf("%d", &alter);

      for(int j = 0; j < i; j++)
      {
        if(c[j].codigo == alter)
        {
          printf("\nO cliente encontrado se chama: %s.", c[j].nome);
          printf("\nE possui um montante de: R$ %0.2f", c[j].montante);
        }
      }
      break;

      //Listar todos os códigos, nomes e montantes dos clientes.
      case 7:

      for(int j = 0; j < i; j++)
      {
        printf("%d\n%s\n%1.2f\n\n", c[j].codigo, c[j].nome, c[j].montante);
      }
      break;
    } 
  }  
  return 0;
}