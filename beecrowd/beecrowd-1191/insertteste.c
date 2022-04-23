#include <stdio.h>
#include <stdlib.h>
#include "bbteste.h"

int main (int argc, char *argv[])
{
    tp_arvore raiz = inicializa_arvore();
    insere_no(&raiz, 'D');
    insere_no(&raiz->esq, 'B');
    insere_no(&(raiz->esq)->esq, 'A');
    insere_no(&(raiz->esq)->dir, 'C');
    insere_no(&raiz->dir, 'E');
    insere_no(&(raiz->dir)->dir, 'G');
    insere_no(&((raiz->dir)->dir)->esq, 'F');
    pre_ordem(raiz); printf(" "); em_ordem(raiz);
    printf("\n");
    pos_ordem(raiz);
    printf("\n");
    return 0;
}
