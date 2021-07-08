//inclusão de bibliotecas e criação do struct
#include <stdio.h>
#include <locale.h>
#include <string.h>

struct Veiculo
{
  char marca[30];
  char modelo[30];
  char placa[10];
  int ano;
};

int main(void) 
{
  // Permitir acentuação e criação das variáveis
  setlocale(LC_ALL, "Portuguese");
  
  struct Veiculo v[10];
  int aux, aux2;
  int opcao_ano;
  char modelo[30];

  // Menu de opções para interação com o programa
  for(int i = 0; i < 10;)
  {
    printf("\n===== Cadastro de Veículos =====");
    printf("\nPossiveis operações no programa:");
    printf("\n1 - Inserir um novo veículo.");
    printf("\n2 - Listar veículos cadastrados.");
    printf("\n3 - Filtrar veículos armazenados.\n");
    printf("\nDigite a opção escolhida: ");
    scanf("%d", &aux);
    printf("================================\n");
    
    switch(aux)
    {

      // Algoritmo para inserir novos veiculos usando vetor
      case 1:
      printf("\nDigite a marca do veículo: ");
      scanf("%s", v[i].marca);

      printf("Digite o modelo do veículo: ");
      scanf("%s", v[i].modelo);

      printf("Digite a placa do veículo: ");
      scanf("%s", v[i].placa);

      printf("Digite o ano de fabricação: ");
      scanf("%d", &v[i].ano);

      printf("Novo veículo cadastrado com sucesso.\n");
      i++;
      break;

      // Laço de repetição para listar os veículos cadastrados
      case 2:
      for(int j = 0; j < i; j++)
      {
        printf("\nMarca: %s", v[j].marca);
        printf("\nModelo: %s", v[j].modelo);
        printf("\nPlaca: %s", v[j].placa);
        printf("\nAno: %d\n", v[j].ano);
      }
      break;

      // Algoritmo para uma busca por filtros
      case 3:
      printf("Qual tipo de filtro gostaria de usar: ");
      printf("\n1 - Por ano de fabricação.");
      printf("\n2 - Por um modelo específico.");
      printf("\nDigite a opção escolhida: ");
      scanf("%d", &aux2);
      printf("================================\n");
      
      switch(aux2)
      {

        // Comparação de variáveis para obter os veículos por ano
        case 1:
        printf("Digite uma das opções a seguir: ");
        printf("\n1 - Veiculos fabricados acima de determinado ano.");
        printf("\n2 - Veiculos com um ano de fabricação especifico.");
        printf("\nDigite a opção escolhida: ");
        scanf("\n%d", &opcao_ano);

        if(opcao_ano == 1)
        {
          int ano;
          printf("\nDigite o ano escolhido: ");
          scanf("%d", &ano);
          printf("\nVeículos encontrados:");
          int contador = 0;

          for(int j = 0; j < i; j++)
          {
            if(v[j].ano >= ano)
            {
                printf("\nMarca: %s", v[j].marca);
                printf("\nModelo: %s", v[j].modelo);
                printf("\nPlaca: %s", v[j].placa);
                printf("\nAno: %d\n", v[j].ano);
                contador++;
            }
          }
          printf("\nForam encontrados %d veículos.\n", contador);
        }

        // Utilização de comparação de variáveis para obter os veículos
        if(opcao_ano == 2)
        {
          int ano;
          printf("\nDigite o ano escolhido: ");
          scanf("%d", &ano);
          printf("\nVeículos encontrados:");
          int contador = 0;

          for(int j = 0; j < i; j++)
          {
            if(v[j].ano == ano)
            {
                printf("\nMarca: %s", v[j].marca);
                printf("\nModelo: %s", v[j].modelo);
                printf("\nPlaca: %s", v[j].placa);
                printf("\nAno: %d\n", v[j].ano);
                contador++;
            }
          }
          printf("\nForam encontrados %d veículos.\n", contador);
        }
        break;

        // Comparando strings usando a biblioteca string.h para obter os veículos
        case 2:
        printf("\nDigite o modelo desejado: ");
        scanf("%s", modelo);
        printf("\nVeículos encontrados:");
        int contador = 0;

        for(int j = 0; j < i; j++)
        {
          if(strcmp(modelo, v[j].modelo) == 0)
          {
              printf("\nMarca: %s", v[j].marca);
              printf("\nModelo: %s", v[j].modelo);
              printf("\nPlaca: %s", v[j].placa);
              printf("\nAno: %d\n", v[j].ano);
              contador++;
          }
        }
        printf("\nForam encontrados %d veículos.\n", contador);
        break;
      }
      break;
    } 
  }  
  return 0;
}