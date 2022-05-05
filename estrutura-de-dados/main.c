#include "pilha.h"

int main()
{
    Pilha* pilha = pilha_criar();
    int n = 0;

    pilha_empilhar(pilha, 10);
    pilha_empilhar(pilha, 20);
    pilha_empilhar(pilha, 30);
    pilha_empilhar(pilha, 40);
    pilha_desempilhar(pilha, &n);
    pilha_empilhar(pilha, 50);

    pilha_imprimir(pilha);
    printf("%d\n", n);

    return 0;
}