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

bool vetor_copia(int *origem, int *saida, int tamOrigem, int tamSaida)
{
	if (tamOrigem == 0 || tamSaida == 0)
		return false;

	for (int i = 0; i < tamOrigem; i++)
	{
		saida[i] = origem[i];
	}

	return true;
}

bool pilha_cheia(Pilha *p)
{
	return p->qtdeElementos == p->tamVetor;
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

void pilha_destruir(Pilha **endereco)
{
	Pilha *p = *endereco;
	free(p->vetor);
	p->vetor = NULL;
	free(p);
	*endereco = NULL;
}

bool pilha_empilhar(Pilha *p, TipoElemento elemento)
{
	if (pilha_cheia(p))
	{
		printf("antes do calloc\n");
		int tamDobrado = p->tamVetor * 2;
		int *vetorDobrado = vetor_criar(tamDobrado);
		printf("depois do calloc\n");

		if (vetorDobrado == NULL)
			return false;

		vetor_copia(p->vetor, vetorDobrado, p->tamVetor, tamDobrado);
		free(p->vetor);
		p->vetor = vetorDobrado;
		p->tamVetor = tamDobrado;
	}

	p->vetor[p->qtdeElementos] = elemento;
	p->qtdeElementos++;

	return true;
}

bool pilha_desempilhar(Pilha *p, TipoElemento *saida)
{
	if (p->qtdeElementos == 0)
		return false;

	p->qtdeElementos--;
	*saida = p->vetor[p->qtdeElementos];
	p->vetor[p->qtdeElementos] = 0;

	int halfTam = (int)p->tamVetor / 2;
	if (p->qtdeElementos <= halfTam)
	{
		int *vetorHalf = vetor_criar(halfTam);
		vetor_copia(p->vetor, vetorHalf, p->tamVetor, halfTam);
		free(p->vetor);
		p->vetor = vetorHalf;
		p->tamVetor = halfTam;
	}

	return true;
}

bool pilha_topo(Pilha *p, TipoElemento *saida)
{
	if (p->qtdeElementos == 0)
		return false;

	*saida = p->vetor[p->qtdeElementos - 1];

	return false;
}

bool pilha_vazia(Pilha *p)
{
	if (p->qtdeElementos == 0)
		return true;

	return false;
}

void pilha_imprimir(Pilha *p)
{
	printf("[");
	for (int i = 0; i < p->tamVetor; i++)
	{
		printf("%d", p->vetor[i]);
		if (i < p->tamVetor - 1)
			printf(",");
	}
	printf("]\n");
}

int pilha_tamanho(Pilha *p)
{
	return p->qtdeElementos;
}

Pilha *pilha_clone(Pilha *p)
{
	Pilha *clone = pilha_criar();

	for (int i = 0; i < p->qtdeElementos; i++)
	{
		pilha_empilhar(clone, p->vetor[i]);
	}

	return clone;
}

void pilha_inverter(Pilha *p);
bool pilha_empilharTodos(Pilha *p, TipoElemento *vetor, int tamVetor);
bool pilha_toString(Pilha *f, char *str);
