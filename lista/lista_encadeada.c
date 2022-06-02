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
No *noCriar(int elemento)
{
    No *new = (No *)malloc(sizeof(No));
    new->dado = elemento;
    new->prox = NULL;
    new->ant = NULL;
    return new;
}

No *noColetar(Lista *l, int posicao)
{
    No *aux = l->inicio;
    int i = 0;
    while (aux != NULL)
    {
        if (i == posicao)
            return aux;
        aux = aux->prox;
        i++;
    }
    return NULL;
}

// IMPLEMENTAÇÃO
Lista *lista_criar()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->qtd = 0;
    l->inicio = NULL;
    l->fim = NULL;
}

void lista_destruir(Lista **endereco)
{
    if (*endereco == NULL)
        return;

    Lista *l = *endereco;
    No *aux = NULL;
    No *destruir = l->fim;
    while (destruir != NULL)
    {
        aux = destruir->ant;
        free(destruir);
        destruir = aux;
    }
    free(l);
    *endereco = NULL;
}

bool lista_anexar(Lista *l, int elemento)
{
    if (l == NULL)
        return false;

    No *new = noCriar(elemento);

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

bool lista_inserir(Lista *l, int posicao, int elemento)
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

    No *new = noCriar(elemento);
    No *selecionado = noColetar(l, posicao);

    new->prox = selecionado;
    new->ant = selecionado->ant;
    if (selecionado->ant != NULL)
        selecionado->ant->prox = new;
    else
        l->inicio = new;
    selecionado->ant = new;
    l->qtd++;

    return true;
}

bool lista_removerPosicao(Lista *l, int *saida, int posicao)
{
    if (l == NULL)
        return false;
    if (lista_vazia(l))
        return false;
    if (posicao >= l->qtd || posicao < 0)
        return false;

    No *selecionado = noColetar(l, posicao);
    *saida = selecionado->dado;

    if (selecionado->ant != NULL)
        selecionado->ant->prox = selecionado->prox;
    else
        l->inicio = selecionado->prox;

    if (selecionado->prox != NULL)
        selecionado->prox->ant = selecionado->ant;
    else
        l->fim = selecionado->ant;

    free(selecionado);
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