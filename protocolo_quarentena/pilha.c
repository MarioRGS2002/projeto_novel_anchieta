#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void pilha_inicializar(Pilha *p) {/* recebe um ponteiro para a pilha*/
    p->topo = NULL; /*é usado para acessar campos de uma struct através de ponteiro. Estamos dizendo: a pilha começa sem nenhum nó no topo.*/
    p->tamanho = 0; /* e começa com zero itens.*/
}

void pilha_empilhar(Pilha *p, int id_cena) {
    NoPilha *novo = (NoPilha *)malloc(sizeof(NoPilha));
    if (novo == NULL) {
        printf("Erro: memoria insuficiente!\n");
        return;
    }
    novo->id_cena = id_cena;
    novo->anterior = p->topo;
    p->topo = novo;
    p->tamanho++;
}

int pilha_desempilhar(Pilha *p) {
    if (pilha_vazia(p)) {
        return -1;

    }
    NoPilha *removido = p->topo;
    int id = removido->id_cena;
    p->topo = removido ->anterior;
    free(removido);
    p->tamanho--;
    return id;
}

int pilha_topo(Pilha *p) {
    if (pilha_vazia(p)) {
        return -1;
    }
    return p->topo->id_cena;
}

int pilha_vazia(Pilha *p) {
    return p->topo ==NULL;
}

void pilha_liberar(Pilha *p) {
    while (!pilha_vazia(p)) {
        pilha_desempilhar(p);
    }
}

    void pilha_imprimir(Pilha *p) {
    if (pilha_vazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }
    NoPilha *atual = p->topo;
    printf("Pilha (topo -> base): ");
    while (atual != NULL) {
        printf("[Cena %d] ", atual->id_cena);
        atual = atual->anterior;
    }
    printf("\n");
}

