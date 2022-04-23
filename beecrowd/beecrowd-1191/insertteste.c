#include <stdio.h>
#include <stdlib.h>
#include "bbteste.h"

int main (int argc, char *argv[])
{
    tp_arvore raiz = inicializa_arvore();
    insere_no(&raiz, 'D', 'r');
    insere_no(&raiz->esq, 'B', 'e');
    insere_no(&(raiz->esq)->esq, 'A', 'e');
    insere_no(&(raiz->esq)->dir, 'C', 'e');
    insere_no(&raiz->dir, 'E', 'e');
    insere_no(&(raiz->dir)->dir, 'G', 'e');
    insere_no(&((raiz->dir)->dir)->esq, 'F', 'e');
    pre_ordem(raiz); printf(" "); em_ordem(raiz);
    printf("\n");
    pos_ordem(raiz);
    printf("\n");
    return 0;
}
