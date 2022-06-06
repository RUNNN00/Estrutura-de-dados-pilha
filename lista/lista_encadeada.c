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

No *listaColetar(Lista *l, int posicao)
{
    if (posicao >= l->qtd)
        return NULL;

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

void noDestruir(Lista *l, No *n)
{
    if (n->ant != NULL)
        n->ant->prox = n->prox;
    else
        l->inicio = n->prox;

    if (n->prox != NULL)
        n->prox->ant = n->ant;
    else
        l->fim = n->ant;

    free(n);
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
    No *selecionado = listaColetar(l, posicao);

    if (selecionado == NULL)
        return false;

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
    if (l == NULL || lista_vazia(l))
        return false;
    if (posicao >= l->qtd || posicao < 0)
        return false;

    No *selecionado = listaColetar(l, posicao);

    if (selecionado == NULL)
        return false;

    *saida = selecionado->dado;
    noDestruir(l, selecionado);
    return true;
}

int lista_removerElemento(Lista *l, int elemento)
{
    if (l == NULL || lista_vazia(l))
        return 0;

    No *selecionado = l->inicio;
    while (selecionado != NULL)
    {
        if (elemento == selecionado->dado)
            break;
        selecionado = selecionado->prox;
    }

    noDestruir(l, selecionado);
    return elemento;
}

bool lista_substituir(Lista *l, int posicao, int elemento)
{
    if (l == NULL || lista_vazia(l))
        return false;

    No *selecionado = listaColetar(l, posicao);

    if (selecionado == NULL)
        return false;

    selecionado->dado = elemento;
    return true;
}

int lista_posicao(Lista *l, int elemento)
{
    if (l == NULL || lista_vazia(l))
        return -1;

    No *aux = l->inicio;
    int i = 0;
    while (aux != NULL)
    {
        if (aux->dado == elemento)
            return i;
        aux = aux->prox;
        i++;
    }
    return -1;
}

bool lista_buscar(Lista *l, int posicao, TipoElemento *saida)
{
    if (l == NULL || lista_vazia(l))
        return false;

    No *selecionado = listaColetar(l, posicao);

    if (selecionado == NULL)
        return false;

    *saida = selecionado->dado;
    return true;
}

int lista_tamanho(Lista *l)
{
    return l->qtd;
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