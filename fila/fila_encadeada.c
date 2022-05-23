#include "fila.h"
#include <string.h>

/**************************************
 * DADOS
 **************************************/
typedef struct no
{
    int dado;
    struct no *prox;
} No;

struct fila
{
    No *inicio;
    No *fim;
    int qtde;
};

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/
Fila *fila_criar()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->qtde = 0;
    f->fim = NULL;
    f->inicio = NULL;
}

void fila_destruir(Fila **enderecoFila)
{
    Fila *f = *enderecoFila;

    No *aux = f->inicio;
    No *aux2 = NULL;
    while (aux != NULL)
    {
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }

    free(f);
    *enderecoFila = NULL;
}

bool fila_inserir(Fila *f, TipoElemento elemento)
{
    No *new = (No *)malloc(sizeof(No));
    new->dado = elemento;
    new->prox = NULL;

    if (new == NULL)
        return false;

    if (f->inicio == NULL)
    {
        f->inicio = new;
        f->fim = new;
        f->qtde++;
        return true;
    }

    f->fim->prox = new;
    f->fim = new;
    f->qtde++;
    return true;
}

bool fila_remover(Fila *f, TipoElemento *saida) // estratégia do scanf
{
    if (fila_vazia(f))
        return false;

    *saida = f->inicio->dado;
    No* lixo = f->inicio;
    f->inicio = f->inicio->prox;
    free(lixo);
    f->qtde--;
    return true;
}

bool fila_primeiro(Fila *f, TipoElemento *saida) // estratégia do scanf
{
    if (fila_vazia(f))
        return false;

    *saida = f->inicio->dado;
}

bool fila_vazia(Fila *f)
{
    return f->qtde <= 0;
}

int fila_tamanho(Fila *f)
{
    return f->qtde;
}

void fila_imprimir(Fila *f)
{
    printf("[");
    No *aux = f->inicio;
    int i = 0;
    while (aux != NULL)
    {
        printf("%d", aux->dado);
        aux = aux->prox;
        if (i < f->qtde - 1)
            printf(",");

        i++;
    }
    printf("]\n");
}

Fila *fila_clone(Fila *f)
{
    if (fila_vazia(f))
        return NULL;

    Fila *clone = fila_criar();
    No *aux = f->inicio;
    while (aux != NULL)
    {
        fila_inserir(clone, aux->dado);
        aux = aux->prox;
    }
    return clone;
}

bool fila_toString(Fila *f, char *str)
{
    if (fila_vazia(f))
        return false;

    str[0] = '\0';
    strcat(str, "toString[");
    No *aux = f->inicio;
    char strAux[50];
    int i = 0;
    while (aux != NULL)
    {
        sprintf(strAux, "%d", aux->dado);
        strcat(str, strAux);
        aux = aux->prox;
        if (i < f->qtde - 1)
            strcat(str, ",");
        i++;
    }
    strcat(str, "]");

    return true;
}

bool fila_inserirTodos(Fila *f, TipoElemento *vetor, int tamVetor)
{
    if (tamVetor == 0)
        return false;

    for (int i = 0; i < tamVetor; i++)
    {
        fila_inserir(f, vetor[i]);
    }

    return true;
}