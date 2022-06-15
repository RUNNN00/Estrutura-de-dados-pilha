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

// AUXILIARES
No *localizaNo(Lista *l, int pos)
{
    if (pos > l->qtd * 0.5)
    {
        No *aux = l->sentinela->ant;
        for (int i = l->qtd - 1; i >= 0; i--)
        {
            if (i == pos)
                return aux;
            aux = aux->ant;
        }
    }
    else
    {
        No *aux = l->sentinela->prox;
        for (int i = 0; i < l->qtd; i++)
        {
            if (i == pos)
                return aux;
            aux = aux->prox;
        }
    }
    return NULL;
}

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

bool lista_inserir(Lista *l, int posicao, TipoElemento elemento)
{
    if (l == NULL)
        return false;
    if (posicao > l->qtd || posicao < 0)
        return false;
    if (posicao == l->qtd)
    {
        lista_anexar(l, elemento);
        return true;
    }

    No *new = (No *)malloc(sizeof(No));

    if (new == NULL)
        return false;

    new->dado = elemento;

    // ajuste nos posicionamentos dos nos
    No *selec = localizaNo(l, posicao);
    if (selec == NULL)
        return false;
    selec->ant->prox = new;
    new->ant = selec->ant;
    new->prox = selec;
    selec->ant = new;

    l->qtd++;
    return true;
}

bool lista_removerPosicao(Lista *l, int *saida, int posicao)
{
    if (l == NULL)
        return false;
    if (posicao > l->qtd || posicao < 0)
        return false;

    No *selec = localizaNo(l, posicao);
    if (selec == NULL)
        return false;
    *saida = selec->dado;

    // ajuste nos posicionamentos dos nos
    selec->ant->prox = selec->prox;
    selec->prox->ant = selec->ant;
    free(selec);

    l->qtd--;
    return true;
}

int lista_removerElemento(Lista *l, TipoElemento elemento)
{
    if (l == NULL)
        return -1;

    int index = 0;
    No *selec = NULL;
    No *aux = l->sentinela->prox;
    for (int i = 0; i < l->qtd; i++)
    {
        if (elemento == aux->dado)
        {
            selec = aux;
            index = i;
        }
        aux = aux->prox;
    }

    if (selec == NULL)
        return -1;

    // ajuste nos posicionamentos dos nos
    selec->ant->prox = selec->prox;
    selec->prox->ant = selec->ant;
    free(selec);

    l->qtd--;
    return index;
}

bool lista_substituir(Lista *l, int posicao, TipoElemento elemento)
{
    No* selec = localizaNo(l, posicao);

    if (selec == NULL)
        return false;

    selec->dado = elemento;
    return true;
}

int lista_posicao(Lista *l, TipoElemento elemento)
{
    No *aux = l->sentinela->prox;
    for (int i = 0; i < l->qtd; i++)
    {
        if (elemento == aux->dado)
            return i;
        aux = aux->prox;
    }
    return -1;
}

bool lista_buscar(Lista *l, int posicao, TipoElemento *saida)
{
    if (l == NULL)
        return false;
    if (posicao > l->qtd || posicao < 0)
        return false;

    No *selec = localizaNo(l, posicao);
    if (selec == NULL)
        return false;
    *saida = selec->dado;
    return true;
}

int lista_tamanho(Lista *l)
{
    return l->qtd;
}

bool lista_vazia(Lista *l)
{
    return l->qtd <= 0;
}

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