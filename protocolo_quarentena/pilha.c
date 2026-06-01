#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void pilha_inicializar(Pilha *p) {
    p->topo = NULL;
    p->tamanho = 0;
}
