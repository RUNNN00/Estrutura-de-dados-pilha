#include "pilha.h"
#include <string.h>

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
bool pilha_cheia(Pilha *p)
{
	return p->qtdeElementos == p->tamVetor;
}

bool verifica_aumentaDiminui(Pilha *p)
{
	int novoTam = 0;

	if (p->qtdeElementos == p->tamVetor)
		novoTam = p->tamVetor * 2;
	else if (p->tamVetor > 4 && p->qtdeElementos <= p->tamVetor / 2)
		novoTam = p->tamVetor / 2;
	else
		return false;

	int *novoVetor = (int *)calloc(novoTam, sizeof(int));

	if (novoVetor == NULL)
		return false;

	memcpy(novoVetor, p->vetor, p->qtdeElementos * sizeof(int));
	free(p->vetor);
	p->vetor = novoVetor;
	p->tamVetor = novoTam;

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
	p->vetor = (int *)calloc(4, sizeof(int));

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
	verifica_aumentaDiminui(p);
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
	verifica_aumentaDiminui(p);

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

void pilha_inverter(Pilha *p)
{
	Pilha* aux = pilha_criar();

	for (int i = p->qtdeElementos - 1; i >= 0; i--)
	{
		pilha_empilhar(aux, p->vetor[i]);
	}

	free(p->vetor);
	p->vetor = aux->vetor;
}

bool pilha_empilharTodos(Pilha *p, TipoElemento *vetor, int tamVetor);
bool pilha_toString(Pilha *f, char *str);
