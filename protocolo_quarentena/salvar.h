#ifndef SALVAR_H
#define SALVAR_H

#include "jogo.h"

/*
 * Nome do arquivo de save (apenas o nome, sem caminho).
 * O caminho completo e calculado em tempo de execucao por
 * salvar_inicializar(), que garante que o arquivo fique
 * sempre na mesma pasta do .exe.
 */
#define NOME_SAVE "save.csv"

/*
 * salvar_inicializar — deve ser chamada UMA VEZ no inicio do main(),
 * passando argv[0]. Ela descobre onde o .exe esta e monta o caminho
 * completo para o save.csv nessa mesma pasta.
 *
 * Por que isso e necessario?
 * Ao dar dois cliques no .exe no Windows Explorer, o "diretorio de
 * trabalho" pode ser diferente da pasta do .exe (ex: C:\Windows\System32).
 * Usando GetModuleFileNameA() no Windows (ou argv[0] no Linux/Mac),
 * sempre encontramos a pasta correta.
 */
void salvar_inicializar(const char *argv0);

/* Grava o estado atual no arquivo. Chamada ao pressionar 'S'. */
void salvar_jogo(const EstadoJogo *estado);

/* Le o arquivo e reconstroi o estado. Retorna 1 se carregou, 0 se nao havia save. */
int carregar_jogo(EstadoJogo *estado);

/* Verifica se o save existe. Usado para mostrar/ocultar "Continuar" no menu. */
int arquivo_save_existe(void);

#endif
