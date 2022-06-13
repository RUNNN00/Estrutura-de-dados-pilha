#include "lista.h"

int main()
{
    Lista* l1 = lista_criar();
    char str[100];
    int posicao = 0;
    int elemento = 0;
    int elementoBusca = 0;

    lista_anexar(l1, 10);
    lista_anexar(l1, 20);
    lista_anexar(l1, 30);
    lista_anexar(l1, 40);
    lista_inserir(l1, 2, -5);
    lista_anexar(l1, 50);
    lista_removerPosicao(l1, &elemento, 3);
    posicao = lista_removerElemento(l1, 10);
    /*lista_substituir(l1, 0, -100);
    posicao = lista_posicao(l1, 40);*/
    lista_buscar(l1, 2, &elementoBusca);
    printf("Elemento buscado: %d\n", elementoBusca);

    lista_toString(l1, str);
    printf("%s\n", str);
    //printf("\n%s\nposicao do posicao 40: %d\n", str, posicao);
    printf("elemento removido: %d\n", elemento);
    printf("posicao removido: %d\n", posicao);

    return 0;
}