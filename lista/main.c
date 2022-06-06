#include "lista.h"

int main()
{
    Lista* l1 = lista_criar();
    char str[100];
    int posicao = 0;
    int elemento = 0;

    lista_anexar(l1, 10);
    lista_anexar(l1, 20);
    lista_anexar(l1, 30);
    lista_anexar(l1, 40);
    lista_inserir(l1, 2, -5);
    lista_anexar(l1, 50);
    lista_inserir(l1, 0, 5);
    lista_inserir(l1, 7, -60);
    lista_inserir(l1, 5, -70);
    lista_removerPosicao(l1, &posicao, 5);
    lista_removerPosicao(l1, &posicao, 3);
    posicao = lista_removerElemento(l1, 10);
    lista_substituir(l1, 0, -100);
    posicao = lista_posicao(l1, 40);
    lista_buscar(l1, 2, &elemento);

    lista_toString(l1, str);
    printf("\n%s\nposicao do posicao 40: %d\n", str, posicao);
    printf("elemento buscado: %d\n", elemento);

    return 0;
}