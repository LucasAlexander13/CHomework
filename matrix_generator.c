#include <stdio.h>
#include <locale.h>

int main(void) 
{
  // Permitir acentuação e criação das variáveis
  setlocale(LC_ALL, "Portuguese");
  int m, n;
  int error = 1;

  // Usamos uma variável de controle para definir uma condição
  // que deve ser cumprida para a continuação do programa
  while(error == 1)
  {
    printf("\nDigite o valor para M: ");
    scanf("\n%d", &m);
    printf("Digite o valor para N: ");
    scanf("\n%d", &n);
    
    // Se todas as condições forem cumpridas, interrompemos o laço
    if(m > 0 && m <= 10 && n > 0 && n <= 10)
    {
      error = 0;
    } 
    else 
    {
      printf("\nMatriz máxima: 10x10.\nMatriz mínima: 1x1.\nTente de novo.\n");
    }
  }

  // Criação da matriz 
  char matriz[m][n];

  // Preenchimento da matriz utilizando o laço for
  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j < n; j++)
    {
      printf("Digite um caráctere para [%d][%d]: ", i, j);
      scanf("\n%c", &matriz[i][j]);
    }
  }

  // Exibição da matriz
  printf("\nA matriz digitada foi:\n");
  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j < n; j++)
    {
      printf("%c ", matriz[i][j]);
    }
    printf("\n");
  }
  return 0;
}