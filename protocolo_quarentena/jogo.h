#ifndef JOGO_H
#define JOGO_H

#include "pilha.h"
#include "bst.h"

#define MAX_ESCOLHAS 4
#define MAX_TEXTO 800
#define MAX_ARTE 600
#define TOTAL_CENAS 12

typedef struct {
    char descricao[150];
    int  id_destino;
} Escolha;

typedef struct {
    int    id;
    char   titulo[100];
    char   arte_ascii[MAX_ARTE];
    char   texto[MAX_TEXTO];
    Escolha escolhas[MAX_ESCOLHAS];
    int    num_escolhas;
    char   termo_codex[50];
} Cena;

typedef struct {
    int   id_cena_atual;
    Pilha historico;
    BST   codex;
    int   jogo_ativo;
} EstadoJogo;

void jogo_inicializar(EstadoJogo *estado);
void jogo_exibir_cena(Cena *cena);
void jogo_processar_escolha(EstadoJogo *estado, Cena *cenas, int escolha);
int  jogo_voltar_cena(EstadoJogo *estado);
void jogo_exibir_codex(EstadoJogo *estado);
void jogo_liberar(EstadoJogo *estado);
Cena *jogo_buscar_cena(Cena *cenas, int id);

#endif