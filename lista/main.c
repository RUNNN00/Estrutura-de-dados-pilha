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
    lista_anexar(l1, 50);
    lista_anexar(l1, 60);
    lista_anexar(l1, 70);
    lista_toString(l1, str);
    printf("%s\n\n", str);

    printf("inserir\n");
    lista_inserir(l1, 1, -5);
    lista_toString(l1, str);
    printf("%s\n\n", str);

    lista_removerPosicao(l1, &elemento, 5);
    printf("remover posicao: %d\n", elemento);
    lista_toString(l1, str);
    printf("%s\n\n", str);

    posicao = lista_removerElemento(l1, 10);
    printf("remover elemento - posicao: %d\n", posicao);
    lista_toString(l1, str);
    printf("%s\n\n", str);

    printf("substituir\n");
    lista_substituir(l1, 3, -100);
    lista_toString(l1, str);
    printf("%s\n\n", str);

    posicao = lista_posicao(l1, 40);
    printf("posicao do elemento 40: %d\n\n", posicao);

    lista_buscar(l1, 2, &elemento);
    printf("buscar posicao 2: %d\n\n", elemento);
    
    return 0;
}