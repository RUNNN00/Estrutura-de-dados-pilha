#include "lista.h"

#define TAMANHO_PADRAO 8

// DADOS
struct lista
{
    No *inicio;
    No *fim;
    int qtd;
};

struct no
{
    TipoElemento dado;
    No *ant;
    No *prox;
};

// FUNCOES AUXILIARES

// IMPLEMENTAÇÃO
Lista *lista_criar()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->qtd = 0;
    l->inicio = NULL;
    l->fim = NULL;
}

void lista_destruir(Lista **enderecoLista)
{
    if (*enderecoLista == NULL)
        return;

    Lista* l = *enderecoLista;
    No* aux = l->fim;
    No* aux2 = NULL;
    while(aux != NULL)
    {
        aux2 = aux->ant;
        free(aux);
        aux = aux2;
    }
    free(l);
    *enderecoLista == NULL;
}

bool lista_anexar(Lista *l, int elemento)
{
    if (l == NULL)
        return false;

    No *new = (No *)malloc(sizeof(No));
    new->dado = elemento;
    new->prox = NULL;

    if (lista_vazia(l))
    {
        new->ant = NULL;
        l->fim = new;
        l->inicio = new;
        l->qtd++;
        return true;
    }

    new->ant = l->fim;
    l->fim->prox = new;
    l->fim = new;
    l->qtd++;
    return true;
}

bool lista_toString(Lista *l, char *str)
{
    if (l == NULL || lista_vazia(l))
        return false;

    str[0] = '\0';
    strcat(str, "[");
    char strAux[50];
    No *aux = l->inicio;
    while (aux != NULL)
    {
        sprintf(strAux, "%d", aux->dado);
        strcat(str, strAux);
        if (aux->prox != NULL)
            strcat(str, ",");
        aux = aux->prox;
    }
    strcat(str, "]");
}

bool lista_vazia(Lista *l)
{
    return l->qtd <= 0;
}