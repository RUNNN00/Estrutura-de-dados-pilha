#include "pilha.h"

#define TAM_INICIAL 5

/*************************************
 * DADOS */
struct pilha
{
	TipoElemento *vetor;
	int tamVetor;
	int qtdeElementos;
};

/*************************************
 * FUNÇÕES AUXILIARES */
int *vetor_criar(int tam)
{
	return (int *)calloc(tam, sizeof(int));
}

void vetor_destruir(int **vet)
{
	free(*vet);
}

bool vetor_copia(int* origem, int* saida, int tamOrigem, int tamSaida)
{
	if (tamOrigem == 0 || tamSaida == 0)
		return false;

	for (int i = 0; i < tamOrigem; i++)
	{
		saida[i] = origem[i];
	}

	return true;
}

/*************************************
 * IMPLEMENTAÇÃO */
// Desenvolva as funções
Pilha *pilha_criar()
{
	Pilha *p = (Pilha *)malloc(sizeof(Pilha));
	p->qtdeElementos = 0;
	p->tamVetor = 4;
	p->vetor = vetor_criar(4);

	return p;
}

void pilha_destruir(Pilha **endereco);
bool pilha_empilhar(Pilha *p, TipoElemento elemento)
{
	if (p->qtdeElementos >= p->tamVetor)
	{
		int tamDobrado = p->tamVetor * 2;
		int *vetorDobrado = vetor_criar(tamDobrado);

		if (vetorDobrado == NULL)
			return false;

		vetor_copia(p->vetor, vetorDobrado, p->tamVetor, tamDobrado);
		vetor_destruir(&(p->vetor));
		p->vetor = vetorDobrado;
		p->tamVetor = tamDobrado;
	}

	p->vetor[p->qtdeElementos] = elemento;
	p->qtdeElementos++;

	return true;
}

bool pilha_desempilhar(Pilha *p, TipoElemento *saida);
bool pilha_topo(Pilha *p, TipoElemento *saida);
bool pilha_vazia(Pilha *p);
void pilha_imprimir(Pilha *p)
{
	printf("[");
	for (int i = 0; i < p->qtdeElementos; i++)
	{
		printf("%d", p->vetor[i]);
		if (i < p->qtdeElementos - 1)
			printf(",");
	}
	printf("]\n");
}
int pilha_tamanho(Pilha *p);
Pilha *pilha_clone(Pilha *p);
void pilha_inverter(Pilha *p);
bool pilha_empilharTodos(Pilha *p, TipoElemento *vetor, int tamVetor);
bool pilha_toString(Pilha *f, char *str);
