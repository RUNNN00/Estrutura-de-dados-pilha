#include "lista.h"

#define TAMANHO_PADRAO 8

// DADOS
struct lista
{
    TipoElemento *vetor;
    int tam;
    int qtd;
};

struct no
{
    TipoElemento dado;
    struct No *ant;
    struct No *prox;
};

// FUNCOES AUXILIARES
bool listaValida(Lista *l)
{
    if (l != NULL && l->vetor != NULL)
        return true;

    return false;
}

// IMPLEMENTAÇÃO
Lista *lista_criar()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->vetor = (int *)calloc(TAMANHO_PADRAO, sizeof(int));
    l->tam = TAMANHO_PADRAO;
    l->qtd = 0;
}

void lista_destruir(Lista **enderecoLista)
{
    if (listaValida(*enderecoLista))
        return;

    Lista* l = *enderecoLista;
    free(l->vetor);
    free(l);
    *enderecoLista = NULL;
}