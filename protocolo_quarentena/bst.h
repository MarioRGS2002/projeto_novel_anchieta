#ifndef BST_H
#define BST_H

#define MAX_TERMO     50
#define MAX_DESCRICAO 300

typedef struct NoBST {
    char termo[MAX_TERMO];
    char descricao[MAX_DESCRICAO];
    struct NoBST *esquerda;
    struct NoBST *direita;  
} NoBST;

typedef struct {
    NoBST *raiz;
} BST;

void   bst_inicializar(BST *b);
void   bst_inserir(BST *b, const char *termo, const char *descricao);
NoBST *bst_buscar(BST *b, const char *termo);
void   bst_imprimir_ordem(BST *b);
void   bst_liberar(BST *b);

#endif