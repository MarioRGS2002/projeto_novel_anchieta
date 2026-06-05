#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include "salvar.h"

/*
 * ============================================================
 *  CAMINHO DO ARQUIVO DE SAVE
 * ============================================================
 *
 *  O problema de "dois cliques no .exe":
 *  Quando o Windows abre um executavel pelo Explorer, o diretorio
 *  de trabalho (working directory) nem sempre e a pasta do .exe.
 *  Isso faz fopen("save.csv", ...) procurar no lugar errado.
 *
 *  Solucao: descobrir onde o .exe esta e montar o caminho completo.
 *
 *  Exemplo:
 *    .exe esta em:  C:\jogos\protocolo_quarentena.exe
 *    save fica em:  C:\jogos\save.csv         <- sempre correto
 */

#define MAX_CAMINHO 512

/*
 * caminho_save e uma variavel global PRIVADA deste arquivo (.c).
 * O "static" garante que nenhum outro .c consegue acessa-la diretamente.
 * Ela e preenchida por salvar_inicializar() e usada por todas as
 * funcoes de save/load.
 */
static char caminho_save[MAX_CAMINHO];

/*
 * salvar_inicializar — monta o caminho absoluto do save.csv.
 *
 * No Windows: usa GetModuleFileNameA(), que retorna o caminho
 *             completo do .exe independente de como foi aberto.
 * No Linux/Mac: usa argv[0], que contem o caminho do executavel.
 *
 * Depois de obter o caminho do .exe, substituimos o nome do
 * executavel pelo nome do arquivo de save:
 *   "C:\jogos\jogo.exe"  →  "C:\jogos\save.csv"
 */
void salvar_inicializar(const char *argv0) {
    char base[MAX_CAMINHO];
    size_t i, ultima_barra;
    int tem_barra;

#ifdef _WIN32
    /*
     * GetModuleFileNameA: funcao da WinAPI que retorna o caminho
     * absoluto do executavel atual. NULL = processo atual.
     * Retorna 0 em caso de erro — usamos argv[0] como plano B.
     */
    if (GetModuleFileNameA(NULL, base, MAX_CAMINHO) == 0) {
        strncpy(base, argv0, MAX_CAMINHO - 1);
        base[MAX_CAMINHO - 1] = '\0';
    }
#else
    strncpy(base, argv0, MAX_CAMINHO - 1);
    base[MAX_CAMINHO - 1] = '\0';
#endif

    /*
     * Encontra a ultima barra no caminho (\ no Windows, / no Linux).
     * Tudo antes dela e durante ela e o "diretorio do .exe".
     *
     * Exemplo:  "C:\jogos\jogo.exe"
     *            0123456789...
     *            ultima_barra aponta para o '\' antes de "jogo.exe"
     */
    ultima_barra = 0;
    tem_barra    = 0;
    for (i = 0; base[i] != '\0'; i++) {
        if (base[i] == '/' || base[i] == '\\') {
            ultima_barra = i;
            tem_barra    = 1;
        }
    }

    if (tem_barra) {
        /*
         * Copia apenas ate a barra (inclusive), descartando o nome do .exe.
         * Depois concatena o nome do save.
         *
         * "C:\jogos\" + "save.csv" = "C:\jogos\save.csv"
         */
        strncpy(caminho_save, base, ultima_barra + 1);
        caminho_save[ultima_barra + 1] = '\0';
        strncat(caminho_save, NOME_SAVE,
                MAX_CAMINHO - ultima_barra - 2);
    } else {
        /*
         * Sem barra: o .exe foi chamado pelo nome simples (ex: "./jogo").
         * Usamos apenas o nome do save — ficara no diretorio atual,
         * que nesse caso e o correto.
         */
        strncpy(caminho_save, NOME_SAVE, MAX_CAMINHO - 1);
        caminho_save[MAX_CAMINHO - 1] = '\0';
    }
}

/* ── VERIFICAR EXISTENCIA ─────────────────────────────────── */

/*
 * arquivo_save_existe — tenta abrir o arquivo so para leitura.
 * fopen() retorna NULL se nao existir. Nao ha funcao "file_exists"
 * em C puro, entao essa e a forma padrao e portatil de checar.
 */
int arquivo_save_existe(void) {
    FILE *arq = fopen(caminho_save, "r");
    if (arq == NULL) {
        return 0;
    }
    fclose(arq);
    return 1;
}

/* ── SALVAR ──────────────────────────────────────────────── */

/* Auxiliar recursiva: percorre a BST em ordem e escreve os termos */
static void salvar_nos_bst(FILE *arq, NoBST *no) {
    if (no == NULL) return;
    salvar_nos_bst(arq, no->esquerda);
    fprintf(arq, ";%s", no->termo);
    salvar_nos_bst(arq, no->direita);
}

/*
 * salvar_jogo — grava as 3 linhas no arquivo.
 *
 * Formato:
 *   cena_atual;7
 *   historico;3;1;2
 *   codex;ARIA;Virus XR-7
 *
 * Usamos caminho_save (absoluto) em vez de NOME_SAVE (relativo),
 * garantindo que o arquivo va para a pasta certa.
 */
void salvar_jogo(const EstadoJogo *estado) {
    FILE *arq = fopen(caminho_save, "w");
    if (arq == NULL) {
        printf("  Erro: nao foi possivel salvar em:\n  %s\n", caminho_save);
        return;
    }

    /* Linha 1: cena atual */
    fprintf(arq, "cena_atual;%d\n", estado->id_cena_atual);

    /* Linha 2: pilha de historico (topo -> base) */
    fprintf(arq, "historico");
    NoPilha *atual = estado->historico.topo;
    while (atual != NULL) {
        fprintf(arq, ";%d", atual->id_cena);
        atual = atual->anterior;
    }
    fprintf(arq, "\n");

    /* Linha 3: termos do codex (BST em ordem) */
    fprintf(arq, "codex");
    salvar_nos_bst(arq, estado->codex.raiz);
    fprintf(arq, "\n");

    fclose(arq);
    printf("\n  [SAVE] Jogo salvo!\n  %s\n", caminho_save);
}

/* ── CARREGAR ────────────────────────────────────────────── */

/*
 * carregar_jogo — le o save.csv e reconstroi as estruturas em memoria.
 * Retorna 1 se carregou com sucesso, 0 se o arquivo nao existia.
 */
int carregar_jogo(EstadoJogo *estado) {
    FILE *arq = fopen(caminho_save, "r");
    if (arq == NULL) {
        return 0; /* primeira execucao, tudo normal */
    }

    char linha[2048];

    while (fgets(linha, sizeof(linha), arq) != NULL) {
        linha[strcspn(linha, "\n")] = '\0'; /* remove o '\n' do final */

        char *prefixo = strtok(linha, ";");
        if (prefixo == NULL) continue;

        if (strcmp(prefixo, "cena_atual") == 0) {
            char *valor = strtok(NULL, ";");
            if (valor != NULL) {
                estado->id_cena_atual = atoi(valor);
            }

        } else if (strcmp(prefixo, "historico") == 0) {
            /*
             * IDs salvos do topo para base: precisamos empilhar
             * de traz para frente para restaurar a ordem original.
             */
            int ids[256];
            int count = 0;
            char *token = strtok(NULL, ";");
            while (token != NULL && count < 256) {
                ids[count++] = atoi(token);
                token = strtok(NULL, ";");
            }
            int i;
            for (i = count - 1; i >= 0; i--) {
                pilha_empilhar(&estado->historico, ids[i]);
            }

        } else if (strcmp(prefixo, "codex") == 0) {
            char *token = strtok(NULL, ";");
            while (token != NULL) {
                bst_inserir(&estado->codex, token,
                            "Termo descoberto durante a exploracao.");
                token = strtok(NULL, ";");
            }
        }
    }

    fclose(arq);
    return 1;
}
