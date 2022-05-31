#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef int TipoElemento;

// DEFINIÇÃO DOS DADOS
typedef struct lista Lista;
typedef struct no No;

// FUNÇÕES
Lista *lista_criar();
void lista_destruir(Lista **l);
bool lista_anexar(Lista *l, int elemento);
bool lista_inserir(Lista *l, int posicao, int elemento);
bool lista_removerPosicao(Lista *l, int *saida, int posicao);
bool lista_removerElemento(Lista *l, int elemento);
bool lista_substituir(Lista *l, int elemento);
int lista_posicao(Lista *l, int elemento);
int lista_buscar(Lista* l, int posicao);
int lista_tamanho(Lista* l);
bool lista_toString(Lista* l, char str[], int tam);

#endif