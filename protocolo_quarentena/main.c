#include <stdio.h>
#include "utils.h"
#include "pilha.h"

int main(void) {
    imprimir_separador();
    printf("   PROTOCOLO DE QUARENTENA\n");
    printf("   Testando sistema de historico\n");
    imprimir_separador();

    Pilha historico;
    pilha_inicializar(&historico);

    animar_texto("\nJogador entra na cena 1...", 40);
    pilha_empilhar(&historico, 1);
    pilha_imprimir(&historico);

    animar_texto("\nJogador vai para cena 3...", 40);
    pilha_empilhar(&historico, 3);
    pilha_imprimir(&historico);

    animar_texto("\nJogador vai para cena 5...", 40);
    pilha_empilhar(&historico, 5);
    pilha_imprimir(&historico);

    animar_texto("\nJogador aperta VOLTAR...", 40);
    pilha_desempilhar(&historico);
    pilha_imprimir(&historico);

    animar_texto("\nJogador aperta VOLTAR de novo...", 40);
    pilha_desempilhar(&historico);
    pilha_imprimir(&historico);

    pilha_liberar(&historico);
    printf("\nMemoria liberada com sucesso.\n");

    return 0;
}