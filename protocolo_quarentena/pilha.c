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
    novo->id_cena = id_cena;/*Guarda o número da cena dentro do novo nó*/
    novo->anterior = p->topo;/*O novo nó aponta para quem era o topo antes*/
    p->topo = novo;/*O novo nó vira o topo da pilha*/
    /*a cena mais recente fica sempre no topo, pronta para ser recuperada pelo Voltar*/
    p->tamanho++;/*Incrementa o contador de nós*/
}

int pilha_desempilhar(Pilha *p) {/*Retorna int — o ID da cena removida*/
    if (pilha_vazia(p)) {/*Verifica se a pilha está vazia antes de tentar remover*/
        return -1;
        /*evita tentar acessar memória inválida quando o jogador está na primeira cena*/
    }
    NoPilha *removido = p->topo;/*Guarda o endereço do nó do topo numa variável temporária*/
    int id = removido->id_cena;
    p->topo = removido ->anterior;
    free(removido);
    p->tamanho--;
    return id;
    /*o jogo_voltar_cena usa esse ID para atualizar o id_cena_atual do estado*/
}
/*permite verificar a última cena visitada sem alterar o histórico*/
int pilha_topo(Pilha *p) {
    if (pilha_vazia(p)) {
        return -1;
    }
    return p->topo->id_cena;/*acessa o nó do topo e lê o campo id_cena*/
}

int pilha_vazia(Pilha *p) {
    return p->topo ==NULL;
}

void pilha_liberar(Pilha *p) {
    while (!pilha_vazia(p)) {
        pilha_desempilhar(p);
    }
}


    /*usada apenas durante o desenvolvimento*/
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
    /*usada apenas durante o desenvolvimento*/
}

