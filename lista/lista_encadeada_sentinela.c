#include "lista.h"
#include <string.h>

// DADO
struct lista
{
    No *sentinela;
    int qtd;
};

struct no
{
    TipoElemento dado;
    No *ant;
    No *prox;
};

// IMPLEMENTAÇÃO
Lista *lista_criar()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->sentinela = (No *)malloc(sizeof(No));
    l->sentinela->prox = l->sentinela;
    l->sentinela->ant = l->sentinela;
    l->qtd = 0;
    return l;
}

void lista_destruir(Lista **endereco)
{
    if (*endereco == NULL)
        return;

    Lista *l = *endereco;
    No *aux = l->sentinela->prox;
    No *destruir = l->sentinela->prox;
    for (int i = 0; i < l->qtd; i++)
    {
        aux = aux->prox;
        free(destruir);
        destruir = aux;
    }
    free(l->sentinela);
    free(l);
    *endereco = NULL;
}

bool lista_anexar(Lista *l, TipoElemento elemento)
{
    if (l == NULL)
        return false;

    No *new = (No *)malloc(sizeof(No));

    if (new == NULL)
        return false;

    new->dado = elemento;

    // ajuste nos posicionamentos dos nos
    l->sentinela->ant->prox = new;
    new->prox = l->sentinela;
    new->ant = l->sentinela->ant;
    l->sentinela->ant = new;

    l->qtd++;
    return true;
}

bool lista_inserir(Lista *l, int posicao, TipoElemento elemento);
bool lista_removerPosicao(Lista *l, int *saida, int posicao);
int lista_removerElemento(Lista *l, TipoElemento elemento);
bool lista_substituir(Lista *l, int posicao, TipoElemento elemento);
int lista_posicao(Lista *l, TipoElemento elemento);
bool lista_buscar(Lista *l, int posicao, TipoElemento *saida);
int lista_tamanho(Lista *l);
bool lista_vazia(Lista *l);
bool lista_toString(Lista *l, char str[])
{
    str[0] = '\0';
    strcat(str, "[");
    No *aux = l->sentinela->prox;
    char strAux[50];
    for (int i = 0; i < l->qtd; i++)
    {
        sprintf(strAux, "%d", aux->dado);
        strcat(str, strAux);
        if (i < l->qtd - 1)
            strcat(str, ",");
        aux = aux->prox;
    }
    strcat(str, "]");
}