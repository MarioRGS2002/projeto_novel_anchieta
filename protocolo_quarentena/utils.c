#include <stdio.h>
#include "utils.h"

void animar_texto(const char *texto, int delay_ms) {
    int i = 0;
    while (texto[i] != '\0') {
        printf("%c", texto[i]);
        fflush(stdout);   /* Forca aparecer na tela imediatamente */
        DORMIR_MS(delay_ms);
        i++;
    }
    printf("\n");
}

void imprimir_separador(void) {
    printf("=================================\n");
}

void transicao_cena(void) {
    int i;
    for (i = 0; i < 20; i++) {
        printf("  ################################\n");
        DORMIR_MS(18);
    }
    LIMPAR_TELA();
}