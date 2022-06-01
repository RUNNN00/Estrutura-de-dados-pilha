#include "lista.h"

int main()
{
    Lista* l1 = lista_criar();
    char str[100];

    lista_anexar(l1, 10);
    lista_anexar(l1, 20);
    lista_anexar(l1, 30);
    lista_anexar(l1, 40);

    printf("Ate aqui okay!\n");

    lista_toString(l1, str);
    printf("\n%s\n", str);

    return 0;
}