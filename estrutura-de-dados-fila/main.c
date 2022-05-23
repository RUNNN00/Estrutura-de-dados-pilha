#include <stdio.h>
#include <string.h>

#include "fila.h"

int main()
{
    char str[200];
    TipoElemento elemento;

    /**************************************
     * Teste insercao e primeiro
     **************************************/
    printf("\n");
    Fila *f1 = fila_criar();
    fila_inserir(f1, 10);
    fila_inserir(f1, 20);
    fila_inserir(f1, 30);
    fila_toString(f1, str);
    printf("%s\n", str);

    fila_primeiro(f1, &elemento);
    printf("primeiro dado: %d\n", elemento);
    printf("\n");

    /**************************************
     * Teste remocao
     **************************************/
    fila_remover(f1, &elemento);
    fila_imprimir(f1);
    printf("dado removido: %d\n", elemento);
    printf("\n");

    fila_remover(f1, &elemento);
    fila_imprimir(f1);
    printf("dado removido: %d\n", elemento);
    printf("\n");

    fila_remover(f1, &elemento);
    fila_imprimir(f1);
    printf("dado removido: %d\n", elemento);
    printf("\n");

    bool resultado = fila_remover(f1, &elemento);
    if (!resultado)
        printf("fila vazia\n\n");

    fila_destruir(&f1);

    /**************************************
     * Teste inserir todos e clone
     **************************************/
    int vetor[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    f1 = fila_criar();
    fila_inserirTodos(f1, vetor, 12);

    fila_toString(f1, str);
    printf("%s\n\n", str);

    Fila* f2 = fila_clone(f1);
    printf("Fila 1: ");
    fila_imprimir(f1);
    printf("Fila 2: ");
    fila_imprimir(f2);
    printf("\n");

    fila_remover(f2, &elemento);
    fila_imprimir(f2);
    printf("dado removido: %d\n", elemento);
    fila_remover(f2, &elemento);
    fila_imprimir(f2);
    printf("dado removido: %d\n", elemento);
    fila_remover(f2, &elemento);
    fila_imprimir(f2);
    printf("dado removido: %d\n\n", elemento);
    fila_inserir(f2, 20);
    fila_imprimir(f2);
    fila_inserir(f2, 21);
    fila_imprimir(f2);
    fila_inserir(f2, 22);
    fila_imprimir(f2);

    fila_toString(f2, str);
    printf("\n%s\n\n", str);

    fila_destruir(&f1);
    fila_destruir(&f2);
}