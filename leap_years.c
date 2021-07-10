/* Exercício 5
Escreva um programa que deverá solicitar ao usuário o 
século desejado e imprimir na tela todos os anos bissextos do século 
informado. Utilize uma função resursiva para esta tarefa.
*/

#include <stdio.h>

int main(){
  // Declaração das variáveis
  int ano, seculo;

  // Entrada de dados pelo usuário
  printf("Digite o seculo desejado: ");
  scanf("%d", &seculo);

  // Algoritmo para imprimir o primeiro ano e anos bissexto
  ano = (100 * seculo) - 99;
  printf("O primeiro ano desse século é: %d", ano);
  printf("\nE os anos bissextos são:\n");
  for(int i = ano ; i <= (ano+99) ; i++)
  {
    if(i % 4 == 0)
      {
        printf("\n%d", i);
      }
  }
  return 0;
}