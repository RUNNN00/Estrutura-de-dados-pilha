#include "fila.h"
#include <string.h>

#define TAM_INICIAL 5
/**************************************
 * DADOS
 **************************************/
struct fila
{
    TipoElemento *vetor;
    int tamVetor;
    int inicio;
    int fim;
    int qtdeElementos;
};

/**************************************
 * FUNÇÕES AUXILIARES
 **************************************/
bool fila_checaAumentaDiminui(Fila *f)
{
    int tamNovo = 0;
    TipoElemento *vetNovo = NULL;

    if (f->qtdeElementos == f->tamVetor - 1)
        tamNovo = f->tamVetor * 2;
    else if (f->tamVetor / 2 >= 8 && f->qtdeElementos < f->tamVetor / 2)
        tamNovo = f->tamVetor / 2;
    else
        return true;

    vetNovo = (int *)calloc(tamNovo, sizeof(int));

    if (vetNovo == NULL)
        return false;

    int index = f->inicio;
    for (int i = 0; i < f->qtdeElementos; i++)
    {
        if (index >= f->tamVetor)
            index = 0;

        vetNovo[i] = f->vetor[index];
        index++;
    }

    free(f->vetor);
    f->vetor = vetNovo;
    f->tamVetor = tamNovo;
    f->inicio = 0;
    f->fim = f->qtdeElementos;
    return true;
}

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/
Fila *fila_criar()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->vetor = (int *)calloc(8, sizeof(int));
    f->inicio = f->vetor[0];
    f->fim = f->vetor[0];
    f->qtdeElementos = 0;
    f->tamVetor = 8;
}

void fila_destruir(Fila **enderecoFila)
{
    Fila *f = *enderecoFila;
    free(f->vetor);
    free(f);
    *enderecoFila = NULL;
}

bool fila_inserir(Fila *f, TipoElemento elemento)
{
    if (!fila_checaAumentaDiminui(f))
        return false;

    f->vetor[f->qtdeElementos] = elemento;
    f->qtdeElementos++;
    f->fim = f->qtdeElementos;
    return false;
}

bool fila_remover(Fila *f, TipoElemento *saida) // estratégia do scanf
{
    if (!fila_checaAumentaDiminui(f))
        return false;

    *saida = f->vetor[f->inicio];
    f->inicio++;
    if (f->inicio >= f->tamVetor)
        f->inicio = 0;
    f->qtdeElementos--;

    if (f->qtdeElementos <= 0)
    {
        f->inicio = 0;
        f->fim = 0;
    }

    return true;
}

bool fila_primeiro(Fila *f, TipoElemento *saida) // estratégia do scanf
{
    if (fila_vazia(f))
        return false;

    *saida = f->vetor[f->inicio];
    return true;
}

bool fila_vazia(Fila *f)
{
    return f->qtdeElementos <= 0;
}

int fila_tamanho(Fila *f)
{
    return f->tamVetor;
}

void fila_imprimir(Fila *f)
{
    printf("vetor: ");
    printf("[");
    int index = f->inicio;
    for (int i = 0; i < f->qtdeElementos; i++)
    {
        if (index >= f->tamVetor)
            index = 0;

        printf("%d", f->vetor[index]);
        if (i < f->qtdeElementos - 1)
            printf(",");

        index++;
    }
    printf("]\n");
    /*printf("vetor completo: ");
    printf("[");
    for (int i = 0; i < f->tamVetor; i++)
    {
        printf("%d", f->vetor[i]);
        if (i < f->tamVetor - 1)
            printf(",");
    }
    printf("]\n");*/
    printf("ultimo dado: %d\n", f->vetor[(int)f->fim - 1]);
    printf("quantidade: %d\n", f->qtdeElementos);
}

Fila *fila_clone(Fila *f)
{
    Fila* clone = fila_criar();

    int index = f->inicio;
    for (int i = 0; i < f->qtdeElementos; i++)
    {
        if (index >= f->tamVetor)
            index = 0;

        fila_inserir(clone, f->vetor[index]);
        index++;
    }

    return clone;
}

bool fila_toString(Fila *f, char *str)
{
    if (f->qtdeElementos <= 0)
        return false;

    str[0] = '\0';
    strcat(str, "[");
    char strAux[50];
    int index = f->inicio;
    for (int i = 0; i < f->qtdeElementos; i++)
    {
        if (index >= f->tamVetor)
            index = 0;

        sprintf(strAux, "%d", f->vetor[index]);
        strcat(str, strAux);
        index++;

        if (i < f->qtdeElementos - 1)
            strcat(str, ",");
    }
    strcat(str, "]");

    return true;
}

bool fila_inserirTodos(Fila *f, TipoElemento *vetor, int tamVetor)
{
    if (tamVetor <= 0)
        return false;

    for (int i = 0; i < tamVetor; i++)
    {
        fila_inserir(f, vetor[i]);
    }
    
    return true;
}