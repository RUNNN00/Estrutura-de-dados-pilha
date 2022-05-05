#include "pilha.h"

typedef struct no
{
    TipoElemento dado;
    struct no *prox;
} No;

struct pilha
{
    No *topo;
    int qtdeElemento;
};

Pilha *pilha_criar()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->qtdeElemento = 0;
    p->topo = NULL;

    return p;
}

void pilha_destruir(Pilha **endereco)
{
}

bool pilha_empilhar(Pilha *p, TipoElemento elemento)
{
    No *new = (No *)malloc(sizeof(No));

    if (new == NULL)
        return false;

    new->dado = elemento;
    new->prox = p->topo;

    p->topo = new;
    p->qtdeElemento++;

    return true;
}

bool pilha_desempilhar(Pilha* p, TipoElemento* saida)
{
    No *old = p->topo;
    *saida = old->dado;
    p->topo = old->prox;
    free(old);
}

void pilha_imprimir(Pilha *p)
{
    printf("[");
    No *aux = p->topo;
    while (aux != NULL)
    {
        printf("%d", aux->dado);
        if (aux->prox != NULL)
            printf(",");
        aux = aux->prox;
    }
    printf("]\n");
}