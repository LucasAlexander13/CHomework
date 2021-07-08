/*
Trabalho para a disciplina de Lógica de Programação, cujo objetivo
era de criar uma tabela em que o usuário pudesse solicitar os itens
desejados e a quantidade, finalizando seu pedido e obtendo o valor
total do pedido. Optei por implementar uma funcionalidade para
mostrar também quais produtos o usuário pediu e sua quantidade.
*/

#include <stdio.h>
#include <locale.h>

int main(void)
{
  // Permitir acentuação e criação das variáveis
  setlocale(LC_ALL, "Portuguese");
  int produto, quantidade;
  float total = 0;
  float valor;
  
  // Matriz contendo os valores de Item, Código e Preço 
  float tabela[7][4] =
  {
    {1, 100, 5.00},
    {2, 101, 8.79},
    {3, 102, 9.99},
    {4, 103, 6.89},
    {5, 104, 4.80},
    {6, 105, 3.49},
    {7, 106, 4.99}
  };

  // Matriz contendo o nome do produto
  char nome[7][17] =
  {
    {"Cachorro-quente"},
    {"X-salada       "},
    {"X-bacon        "},
    {"Misto          "},
    {"Salada         "},
    {"Água           "},
    {"Refrigerante   "}

  };

  // Imprimir a tabela solicitada já formatada
  printf("====================================\n");
  printf("Item |Produto         |Código |Preço\n");
  printf("====================================\n");

  for(int i = 0; i < 7; i++)
  {
    printf(" %0.f   |%s |%0.f    |%0.2f\n", tabela[i][0], nome[i], tabela[i][1], tabela[i][2]);
  }
  printf("====================================\n");
  
  // Algoritmo para o cálculo do pedido
  produto = -1;
  while(produto != 0)
  {
    if(total == 0)
    {
      printf("\nDigite o número do item que gostaria de comprar: ");
    }
    else
    {
      printf("\nDigite o número do item ou zero para finalizar: ");
    }

    scanf("\n%d", &produto);
    switch(produto)
    {

      case 1 :
      valor = 5.00;
      
      printf("\nProduto selecionado: %s\n", nome[produto - 1]);
      printf("Digite a quantidade desejada: ");
      scanf("\n%d", &quantidade);
      
      tabela[0][3] = tabela[0][3] + quantidade;
      total = total + (quantidade * valor);
      break;

      case 2 :
      valor = 8.79;
      
      printf("\nProduto selecionado: %s\n", nome[produto - 1]);
      printf("Digite a quantidade desejada: ");
      scanf("\n%d", &quantidade);
      
      tabela[1][3] = tabela[1][3] + quantidade;
      total = total + (quantidade * valor);
      break;

      case 3 :
      valor = 9.99;
      
      printf("\nProduto selecionado: %s\n", nome[produto - 1]);
      printf("Digite a quantidade desejada: ");
      scanf("\n%d", &quantidade);
      
      tabela[2][3] = tabela[2][3] + quantidade;
      total = total + (quantidade * valor);
      break;

      case 4 :
      valor = 6.89;
      
      printf("\nProduto selecionado: %s\n", nome[produto - 1]);
      printf("Digite a quantidade desejada: ");
      scanf("\n%d", &quantidade);
      
      tabela[3][3] = tabela[3][3] + quantidade;
      total = total + (quantidade * valor);
      break;

      case 5 :
      valor = 4.80;
      
      printf("\nProduto selecionado: %s\n", nome[produto - 1]);
      printf("Digite a quantidade desejada: ");
      scanf("\n%d", &quantidade);
      
      tabela[4][3] = tabela[4][3] + quantidade;
      total = total + (quantidade * valor);
      break;

      case 6 :
      valor = 3.49;
      
      printf("\nProduto selecionado: %s\n", nome[produto - 1]);
      printf("Digite a quantidade desejada: ");
      scanf("\n%d", &quantidade);
      
      tabela[5][3] = tabela[5][3] + quantidade;
      total = total + (quantidade * valor);
      break;

      case 7 :
      valor = 4.99;
      
      printf("\nProduto selecionado: %s\n", nome[produto - 1]);
      printf("Digite a quantidade desejada: ");
      scanf("\n%d", &quantidade);
      
      tabela[6][3] = tabela[6][3] + quantidade;
      total = total + (quantidade * valor);
      break;

      default : 
      produto = 0;
    }
    
  }

  // Imprime a tabela contendo apenas os itens com quantidade diferente de zero
  printf("\n===============================================");
  printf("\nItem|Produto          |Código|Preço |Quantidade");
  printf("\n===============================================\n");
  for(int i = 0; i < 7; i++)
  {
    if(tabela[i][3] != 0)
    {
      printf(" %0.f  |%s  |%0.f   |%0.2f  |%0.f\n", tabela[i][0], nome[i], tabela[i][1], tabela[i][2], tabela[i][3]);
    }
  }
  printf("===============================================");
  printf("\nSeu pedido totalizou R$%0.2f", total);

  return 0;
}