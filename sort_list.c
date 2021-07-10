/* Exercício 3
Escreva um programa que leia 5 inteiros e os armazene em um vetor.
A partir disso, utilizando ponteiros para navegar no vetor, os 
valores armazenados no vetor devem ser ordenados do menor para o maior.
O vetor ordenado deve ser apresentado na tela.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct valores
{
	int q;
	int w;
	int e;
	int r;
	int t;
};

int main()
{
	// Aceitar acentuação e declaração de variáveis
	setlocale(LC_ALL, "Portuguese");

	// Criação das structs e declarção das variáveis
	struct valores numero, * p_numero;	
	p_numero = &numero;
	int vetor[5];
	int vetor_ord[5];

	// Recolhendo dados do usuário
	printf("======= Ordenador de Vetores =======\n");	
	for(int i = 0; i < 5; i++)
  {
		printf("Digite o número para a posição %i: ", i);
		scanf("%d", &vetor[i]);
	}
  printf("====================================\n");

	// Alocar os valores do vetor original no vetor a ser ordenado
	for(int i = 0; i < 5; i++)
  {
		vetor_ord[i] = vetor[i];
	}

	// Algoritmo para ordenar os valores
	for(int i = 0; i < 5; i++)
  {
		for(int j = i + 1; j < 5; j++)
		{
			if(vetor_ord[i] > vetor[j])
			{
				int aux = vetor_ord[i];
				vetor_ord[i] = vetor_ord[j];
				vetor_ord[j] = aux;
			}
		}
	}

	// Passamos os valores do vetor ordenado para os ponteiros
	(*p_numero).q = vetor_ord[0];
	(*p_numero).w = vetor_ord[1];
	(*p_numero).e = vetor_ord[2];
	(*p_numero).r = vetor_ord[3];
	(*p_numero).t = vetor_ord[4];

	// Exibir o vetor original
	printf("Valores do vetor original: \n[");
	for(int i = 0; i < 5; i++)
	{
		printf("%d", vetor[i]);
    if(i < 4)
    {
      printf(", ");
    }
	}
	printf("]\n\n");

	// Exibir o vetor em ordem crescente
	printf("Vetor em ordem crescente:\n");
	printf("[%d, ", (*p_numero).q);
	printf("%d, ", (*p_numero).w);
	printf("%d, ", (*p_numero).e);
	printf("%d, ", (*p_numero).r);
	printf("%d]", (*p_numero).t);

	return 0;
}