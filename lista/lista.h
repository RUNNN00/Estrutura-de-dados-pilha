#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int TipoElemento;

// DEFINIÇÃO DOS DADOS
typedef struct lista Lista;
typedef struct no No;

// FUNÇÕES
Lista *lista_criar();
void lista_destruir(Lista **endereco);
bool lista_anexar(Lista *l, int elemento);
bool lista_inserir(Lista *l, int posicao, int elemento);
bool lista_removerPosicao(Lista *l, int *saida, int posicao);
int lista_removerElemento(Lista *l, int elemento);
bool lista_substituir(Lista *l, int elemento);
int lista_posicao(Lista *l, int elemento);
bool lista_buscar(Lista *l, int posicao, TipoElemento *saida);
int lista_tamanho(Lista *l);
bool lista_vazia(Lista *l);
bool lista_toString(Lista *l, char str[]);

#endif