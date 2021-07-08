/*
Trabalho para a disciplina de Lógica de Programação, cujo objetivo
era de criar um programa que coletasse dados a respeito de um
reservatório de água, e quanto desse reservatório era usado
durante o mês vigente. O programa também deveria informar caso o
reservatório estivesse cheio e quando estivesse vazio, e ao final
do ano, mostrar uma tabela contendo os dados formatados.
*/

#include <stdio.h>
#include <locale.h>

int main(void)
{
  // Permitir acentuação e criação das variáveis
  setlocale(LC_ALL, "Portuguese");
  int milmax, milmes, milusados, milres;
  int miltab[12][3];

  char meses[12][12] = 
  {
    {"Janeiro"},
    {"Fevereiro"},
    {"Março"},
    {"Abril"},
    {"Maio"},
    {"Junho"},
    {"Julho"},
    {"Agosto"},
    {"Setembro"},
    {"Outubro"},
    {"Novembro"},
    {"Dezembro"}
  };

  char formatmeses[12][4] = 
  {
    {"Jan"},
    {"Fev"},
    {"Mar"},
    {"Abr"},
    {"Mai"},
    {"Jun"},
    {"Jul"},
    {"Ago"},
    {"Set"},
    {"Out"},
    {"Nov"},
    {"Dez"}
  };

  // Definindo a capacidade máxima
  printf("Digite a capacidade máxima do reservatório: ");
  scanf("\n%d", &milmax);

  for(int i = 0; i < 12; i++)
  {
    // Armazena os milímetros recebidos no mês na matriz
    printf("\nDigite os milímetros de chuva de %s: ", meses[i]);
    scanf("\n%d", &milmes);
    miltab[i][0] = milmes;

    // Armazena os milímetros usados na matriz
    printf("Digite os milimetros usados: ");
    scanf("\n%d", &milusados);
    miltab[i][1] = milusados;

    // Contabiliza a quantidade total atual do reservatório
    milres = milres + milmes - milusados;

    // Mantem o reservatório sob controle de capacidade
    if(milres > milmax)
    {
      printf("\nO reservatório está cheio.\n");
      milres = milmax;
    } 
    else if(milres <= 0)
    {
      printf("\nO reservatório ficou vazio.\n");
      milres = 0;
    }

    // Armazena a quantidade atual disponível em cada mês
    miltab[i][2] = milres;
  }

  // Imprime a tabela com os dados organizados e formatados
  printf("\nMês Obtido Usado Reserva");
  for(int i = 0; i < 12; i++)
  {
    printf("\n%s    %d     %d      %d", formatmeses[i], miltab[i][0], miltab[i][1], miltab[i][2]);
  }
  printf("\nDados em milímetros (mm)");

  return 0;
}