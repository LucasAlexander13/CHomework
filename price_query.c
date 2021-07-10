/* Exercícios 1 e 2
Suponha que você está fazendo uma pesquisa de preços para a compra
de um tablet. Para auxiliá-lo, escreva um programa, em linguagem C, 
que permite o cadastro de 15 registros. Cada registro contendo o 
nome de uma loja, o seu telefone, e o preço do tablet naquela
loja. O programa deve calcular a média dos preços encontrados e 
mostrar uma relação contendo o nome e o telefone das lojas que 
tinham o tablet com preço abaixo da média. Faça um menu permitindo 
o usuário escolher inserir, excluir, informar melhores preços e
sair. 

Aproveitando o Exercício 1, adicione a opção de [ S ] Salvar em arquivo CSV.
Quando acionada essa opção deve ser salvo todos os registros em um arquivo 
chamado <preços.csv>. Como este é um arquivo csv (do inglês 
"Character-separated values") devemos escolher um separador(delimitador) 
para os seus valores. O separador escolhido é o “;” 
*/


#include <stdio.h>
#include <locale.h>
#include <string.h>

struct Registro
{
  char nome[31];
  char telefone[12];
  float preco;
  int codigo;
};

int main(void)
{
  // Permitir acentuação e criação das variáveis
  setlocale(LC_ALL, "Portuguese");
  struct Registro loja[15];
  char aux[] = "0";
  int i = 0;

  // Criar um laço de repetição para vários processos
  do
  {
    printf("\n======= Consulta de preços =======");
    printf("\n[I] - Inserir nova loja.");
    printf("\n[E] - Excluir loja registrada.");
    printf("\n[P] - Listar melhores preços.");
    printf("\n[L] - Listar e salvar registros.");
    printf("\n[S] - Sair do programa.\n");
  
    printf("\nDigite o comando a ser executado: ");
    scanf("%c", aux);
    printf("\n==================================\n");

    // Algoritmo para inserir uma nova loja no registro
    if(strcmp(aux, "I") == 0)
    {
      printf("Opção escolhida: Inserir nova loja.");
      printf("\nO código da loja será: %d\n\n", i);

      printf("Digite o nome da loja: ");
      scanf("%s", loja[i].nome);

      printf("Digite o telefone: ");
      scanf("%s", loja[i].telefone);

      printf("Digite o valor do produto: ");
      scanf("%f", &loja[i].preco);

      loja[i].codigo = i;
      i++;
      printf("\nLoja cadastrada com sucesso\n");
    }

    // Algoritmo para excluir uma loja registrada
    else if(strcmp(aux, "E") == 0)
    {
      printf("\nOpção escolhida: Excluir loja registrada.");
      int alter;

      printf("\nDigite o código da loja que deseja excluir: ");
      scanf("%d\n", &alter);

      for(int j = 0; j < i; j++)
      {
        if(loja[j].codigo == alter)
        {
          for(int k = j;k < i; k++)
          {
            strcpy(loja[k].nome, loja[k+1].nome);
            strcpy(loja[k].telefone, loja[k+1].telefone);
            loja[k].preco = loja[k+1].preco;
          }
          i--;
          printf("\nLoja removida. Os códigos foram atualizados.\n");
        }
      }
    }

    // Algoritmo para listar o melhor preço
    else if(strcmp(aux, "P") == 0)
    {
      printf("\nOpção escolhida: Listar melhores preços.");
      float melhor = loja[0].preco;
      char temp[31];

      for(int j = 0; j < i; j++)
      {
        if(loja[j].preco <= melhor)
        {
          melhor = loja[j].preco;
          strcpy(temp, loja[j].nome);
        }
      }
      printf("\nO melhor preço pertence a loja: %s.", temp);
      printf("\nCom o preço de: R$ %0.2f\n", melhor);
    }

    // Algoritmo para listar e salvar os registros em um arquivo .csv
    else if(strcmp(aux, "L") == 0)
    {
      printf("\nOpção escolhida: Listar e salvar registros.");
      FILE *file = fopen("preços.csv", "w");

      for(int j = 0; j < i; j++)
      {
        fprintf(file, "%s; ", loja[j].nome);
        fprintf(file, "%s; ", loja[j].telefone);
        fprintf(file, "%0.2f; ", loja[j].preco);
        fprintf(file, "%d;\n", loja[j].codigo);
      }
      fclose(file);
      printf("\nRegistros salvos com sucesso.\n");
    }

    // Laço de repetição que encerra o programa
    else if(strcmp(aux, "S") == 0)
    {
      printf("O programa foi encerrado.");
    }

  } while (strcmp(aux, "S") != 0);

  return 0;
}
