#include <stdio.h>
#include <string.h>
#include "jogo.h"
#include "utils.h"

void jogo_inicializar(EstadoJogo *estado) {
    estado->id_cena_atual = 1;
    estado->jogo_ativo    = 1;
    pilha_inicializar(&estado->historico);
    bst_inicializar(&estado->codex);
}

Cena *jogo_buscar_cena(Cena *cenas, int id) {
    int i;
    for (i = 0; i < TOTAL_CENAS; i++) {
        if (cenas[i].id == id) {
            return &cenas[i];
        }
    }
    return NULL;
}

void jogo_exibir_cena(Cena *cena) {/*Recebe um ponteiro para a cena a ser exibida*/
    transicao_cena();
    imprimir_separador();
    printf("  %s\n", cena->titulo);
    imprimir_separador();

    if (cena->arte_ascii[0] != '\0') {/*se o primeiro caractere não for o marcador de fim, a string tem conteúdo*/
        printf("%s\n", cena->arte_ascii);
        imprimir_separador();
        /*cenas sem arte pulam essa parte — evita imprimir linhas em branco*/
    }

    animar_texto(cena->texto, 25);

    if (cena->num_escolhas > 0) {
        int i;
        printf("\n");
        imprimir_separador();
        printf("  O que voce faz?\n");
        imprimir_separador();
        for (i = 0; i < cena->num_escolhas; i++) {
            printf("  %d. %s\n", i + 1, cena->escolhas[i].descricao);/*porque o array começa em 0 mas queremos mostrar 1, 2, 3 para o jogador*/
        }
        printf("  V. Voltar\n");
        printf("  C. Consultar Codex\n");
        printf("  S. Salvar e Sair\n");
        imprimir_separador();
    }
}

void jogo_processar_escolha(EstadoJogo *estado, Cena *cenas, int escolha) {/*Busca a cena atual pelo ID guardado no estado*/
    Cena *cena_atual = jogo_buscar_cena(cenas, estado->id_cena_atual);

    if (cena_atual == NULL) {
        return;
    }

    if (escolha < 1 || escolha > cena_atual->num_escolhas) {/*Valida se o número digitado é válido*/
        printf("  Opcao invalida. Tente novamente.\n");
        return;
    }

    int proximo_id = cena_atual->escolhas[escolha - 1].id_destino;/*porque o array começa em 0 mas o jogador digitou 1 ou 2*/

    pilha_empilhar(&estado->historico, estado->id_cena_atual);

    estado->id_cena_atual = proximo_id;
}

int jogo_voltar_cena(EstadoJogo *estado) {
    if (pilha_vazia(&estado->historico)) {
        printf("\n  Nao ha cena anterior para voltar.\n");
        return 0;
    }

    int cena_anterior = pilha_desempilhar(&estado->historico);
    estado->id_cena_atual = cena_anterior;
    return 1;
}

void jogo_exibir_codex(EstadoJogo *estado) {
    LIMPAR_TELA();
    imprimir_separador();
    printf("  CODEX - ENCICLOPEDIA DA ESTACAO\n");
    imprimir_separador();
    bst_imprimir_ordem(&estado->codex);
    imprimir_separador();
    printf("\n  Pressione ENTER para voltar...\n");
    getchar();
}

void jogo_liberar(EstadoJogo *estado) {
    pilha_liberar(&estado->historico);
    bst_liberar(&estado->codex);
}