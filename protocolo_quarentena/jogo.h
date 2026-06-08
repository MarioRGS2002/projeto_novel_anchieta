#ifndef JOGO_H
#define JOGO_H

#include "pilha.h"
#include "bst.h"

#define MAX_ESCOLHAS 4
#define MAX_TEXTO 800
#define MAX_ARTE 600
#define TOTAL_CENAS 12

typedef struct {
    char descricao[150];/*149 string tamanho*/
    int  id_destino;
} Escolha;
/*quando o jogador digita 1, o código pega escolhas[0].id_destino e vai para aquela cena*/

typedef struct {
    int    id;
    char   titulo[100];
    char   arte_ascii[MAX_ARTE];
    char   texto[MAX_TEXTO];/*impresso letra por letra pela animar_texto criando o efeito de digitação*/
    Escolha escolhas[MAX_ESCOLHAS];
    int    num_escolhas;/*o for que imprime as escolhas usa esse número para saber até onde percorrer — evita imprimir slots vazios*/
    char   termo_codex[50];/*verificado no loop principal do main.c — se não estiver vazio insere o termo na BST do Códex*/
} Cena;

typedef struct {/* guarda tudo que precisamos para salvar e carregar uma partida*/
    int   id_cena_atual;
    Pilha historico;
    BST   codex;/*A árvore com todos os termos desbloqueados*/
    int   jogo_ativo;/*controla o while (estado.jogo_ativo) no main.c — quando vira 0 o loop encerra e o programa termina*/
} EstadoJogo;

/*As declarações das funções*/

void jogo_inicializar(EstadoJogo *estado);/*define cena 1 como inicial, inicializa pilha e BST vazias*/
void jogo_exibir_cena(Cena *cena);
void jogo_processar_escolha(EstadoJogo *estado, Cena *cenas, int escolha);/*empilha a cena atual e atualiza o id_cena_atual*/
int  jogo_voltar_cena(EstadoJogo *estado);
void jogo_exibir_codex(EstadoJogo *estado);
void jogo_liberar(EstadoJogo *estado);
Cena *jogo_buscar_cena(Cena *cenas, int id);

#endif