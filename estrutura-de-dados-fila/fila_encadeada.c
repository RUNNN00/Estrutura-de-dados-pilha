#include "fila.h"

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

void fila_destruir(Fila **enderecoFila);
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

bool fila_remover(Fila *f, TipoElemento *saida);  // estratégia do scanf
bool fila_primeiro(Fila *f, TipoElemento *saida); // estratégia do scanf
bool fila_vazia(Fila *f);
int fila_tamanho(Fila *f);
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

Fila *fila_clone(Fila *f);
bool fila_toString(Fila *f, char *str);
bool fila_inserirTodos(Fila *f, TipoElemento *vetor, int tamVetor);
