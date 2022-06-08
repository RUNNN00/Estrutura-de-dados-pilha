#include "lista.h"

// DADO
struct lista
{
    No* sentinela;
};

struct no
{
    TipoElemento* dado;
    No* ant;
    No* prox;
};

// IMPLEMENTAÇÃO
Lista *lista_criar()
{
    
}

void lista_destruir(Lista **endereco);
bool lista_anexar(Lista *l, int elemento);
bool lista_inserir(Lista *l, int posicao, int elemento);
bool lista_removerPosicao(Lista *l, int *saida, int posicao);
int lista_removerElemento(Lista *l, int elemento);
bool lista_substituir(Lista *l, int posicao, int elemento);
int lista_posicao(Lista *l, int elemento);
bool lista_buscar(Lista *l, int posicao, TipoElemento *saida);
int lista_tamanho(Lista *l);
bool lista_vazia(Lista *l);
bool lista_toString(Lista *l, char str[]);