#include "pilha.h"

int main()
{
    Pilha* pilha = pilha_criar();
    printf("%u\n", pilha);
    pilha = NULL;
    printf("%u\n", pilha);

    /*pilha_empilhar(pilha, 10);
    pilha_empilhar(pilha, 20);
    pilha_empilhar(pilha, 30);

    pilha_imprimir(pilha);*/

    return 0;
}