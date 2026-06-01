#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void pilha_inicializar(Pilha *p) {
    p->topo = NULL;
    p->tamanho = 0;
}

void pilha_empilhar(Pilha *p, int id_cena) {
    NoPilha *novo = (NoPilha *)malloc(sizeof(NoPilha));
    if (novo == NULL) {
        printif("EWrro: memoria insuficiente!\n");
        return;
    }
    novo->id_cena = id_cena;
    novo->anterior = p->topo;
    p->topo = novo;
    p->tamanho++;
}