#include "lista.h"
#include <string.h>
#define TAM_INICIAL 8

// DADOS
struct lista
{
    TipoElemento *vetor;
    int tam;
    int qtd;
};

// AUXILIARES
bool listaValida(Lista *l)
{
    if (l == NULL)
        return false;
    if (l->vetor == NULL)
        return false;
    return true;
}

bool modificaTamLista(Lista *l, int tam)
{
    TipoElemento *new = (TipoElemento *)calloc(tam, sizeof(TipoElemento));

    if (new == NULL)
        return false;

    // copia os elementos para o novo vetor
    for (int i = 0; i < l->qtd; i++)
    {
        new[i] = l->vetor[i];
    }

    free(l->vetor);
    l->vetor = new;
    l->tam = tam;
    return true;
}

// IMPLEMENTAÇÃO
Lista *lista_criar()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->vetor = (TipoElemento *)calloc(TAM_INICIAL, sizeof(TipoElemento));
    l->tam = TAM_INICIAL;
    l->qtd = 0;
}

void lista_destruir(Lista **endereco)
{
    if (!listaValida(*endereco))
        return;

    Lista *l = *endereco;
    free(l->vetor);
    free(l);
    *endereco = NULL;
}

bool lista_anexar(Lista *l, TipoElemento elemento)
{
    if (!listaValida(l))
        return false;

    // verifica tamanho
    if (l->qtd >= l->tam - 1)
    {
        int newTam = l->tam + TAM_INICIAL;
        if (!modificaTamLista(l, newTam))
            return false;
    }

    l->vetor[l->qtd] = elemento;
    l->qtd++;
    return true;
}

bool lista_inserir(Lista *l, int posicao, TipoElemento elemento)
{
    if (!listaValida(l))
        return false;
    if (posicao > l->tam || posicao < 0)
        return false;

    // verifica tamanho
    if (l->qtd >= l->tam - 1)
    {
        int newTam = l->tam + TAM_INICIAL;
        if (!modificaTamLista(l, newTam))
            return false;
    }

    if (posicao >= l->qtd)
    {
        lista_anexar(l, elemento);
        return true;
    }

    // desloca elementos para frente
    for (int i = l->qtd; i > posicao; i--)
    {
        l->vetor[i] = l->vetor[i - 1];
    }

    l->vetor[posicao] = elemento;
    l->qtd++;
    return true;
}

bool lista_removerPosicao(Lista *l, int *saida, int posicao)
{
    if (!listaValida(l) || lista_vazia(l))
        return false;
    if (posicao >= l->qtd || posicao < 0)
        return false;

    *saida = l->vetor[posicao];
    for (int i = posicao; i < l->qtd; i++)
    {
        // desloca elementos para traz
        l->vetor[i] = l->vetor[i + 1];
    }
    l->vetor[l->qtd] = 0;
    l->qtd--;

    // verifica tamanho
    if (l->tam - l->qtd >= TAM_INICIAL + 1)
    {
        int newTam = l->tam - TAM_INICIAL;
        if (!modificaTamLista(l, newTam))
            return false;
    }

    return true;
}

int lista_removerElemento(Lista *l, TipoElemento elemento)
{
    if (!listaValida(l) || lista_vazia(l))
        return -1;

    for (int i = 0; i < l->qtd; i++)
    {
        if (elemento == l->vetor[i])
        {
            for (int j = i; j < l->qtd; j++)
            {
                // desloca elementos para traz
                l->vetor[j] = l->vetor[j + 1];
            }
            l->vetor[l->qtd] = 0;
            l->qtd--;
            return i;
        }
    }
    return -1;
}

bool lista_substituir(Lista *l, int posicao, TipoElemento elemento)
{
    if (!listaValida(l) || lista_vazia(l))
        return false;
    if (posicao >= l->qtd || posicao < 0)
        return false;

    l->vetor[posicao] = elemento;
    return true;
}

int lista_posicao(Lista *l, TipoElemento elemento)
{
    if (!listaValida(l) || lista_vazia(l))
        return -1;

    for (int i = 0; i < l->qtd; i++)
    {
        if (l->vetor[i] == elemento)
            return i;
    }
    return -1;
}

bool lista_buscar(Lista *l, int posicao, TipoElemento *saida)
{
    if (!listaValida(l) || lista_vazia(l))
        return false;
    if (posicao >= l->qtd || posicao < 0)
        return false;

    *saida = l->vetor[posicao];
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
    char strAux[50];
    for (int i = 0; i < l->tam; i++)
    {
        sprintf(strAux, "%d", l->vetor[i]);
        strcat(str, strAux);
        if (i < l->tam - 1)
            strcat(str, ",");
    }
    strcat(str, "]");
}