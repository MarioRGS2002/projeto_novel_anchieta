#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

void bst_inicializar(BST *b) {
    b->raiz = NULL;
}

void bst_inserir(BST *b, const char *termo, const char *descricao) {
    /* Cria o novo no */
    NoBST *novo = (NoBST *)malloc(sizeof(NoBST));
    if (novo == NULL) {
        printf("Erro: memoria insuficiente!\n");
        return;
    }
    strncpy(novo->termo,     termo,     MAX_TERMO - 1);
    strncpy(novo->descricao, descricao, MAX_DESCRICAO - 1);
    novo->termo[MAX_TERMO - 1]         = '\0';
    novo->descricao[MAX_DESCRICAO - 1] = '\0';
    novo->esquerda = NULL;
    novo->direita  = NULL;

    /* Se a arvore esta vazia, o novo no vira a raiz */
    if (b->raiz == NULL) {
        b->raiz = novo;
        return;
    }

    /* Caminha pela arvore ate achar o lugar certo */
    NoBST *atual = b->raiz;
    while (1) {
        int comparacao = strcmp(termo, atual->termo);

        if (comparacao == 0) {
            /* Termo ja existe, nao insere duplicata */
            free(novo);
            return;
        }

        if (comparacao < 0) {
            if (atual->esquerda == NULL) {
                atual->esquerda = novo;
                return;
            }
            atual = atual->esquerda;
        } else {
            if (atual->direita == NULL) {
                atual->direita = novo;
                return;
            }
            atual = atual->direita;
        }
    }
}

NoBST *bst_buscar(BST *b, const char *termo) {
    NoBST *atual = b->raiz;
    while (atual != NULL) {
        int comparacao = strcmp(termo, atual->termo);
        if (comparacao == 0) {
            return atual;
        } else if (comparacao < 0) {
            atual = atual->esquerda;
        } else {
            atual = atual->direita;
        }
    }
    return NULL;
}

void imprimir_em_ordem(NoBST *no) {
    if (no == NULL) {
        return;
    }
    imprimir_em_ordem(no->esquerda);
    printf("  > %-20s : %s\n", no->termo, no->descricao);
    imprimir_em_ordem(no->direita);
}

void bst_imprimir_ordem(BST *b) {
    if (b->raiz == NULL) {
        printf("  Codex vazio.\n");
        return;
    }
    imprimir_em_ordem(b->raiz);
}

void liberar_nos(NoBST *no) {
    if (no == NULL) {
        return;
    }
    liberar_nos(no->esquerda);
    liberar_nos(no->direita);
    free(no);
}

void bst_liberar(BST *b) {
    liberar_nos(b->raiz);
    b->raiz = NULL;
}