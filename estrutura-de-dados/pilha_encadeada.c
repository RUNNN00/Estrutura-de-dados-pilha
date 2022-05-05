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

bool pilha_empilhar(Pilha* p, TipoElemento elemento)
{
    No* no = (No*) malloc(sizeof(No));
    no->dado = elemento;
    no->prox = NULL;
    
}