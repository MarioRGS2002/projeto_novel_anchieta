#include <stdio.h>
#include "utils.h"

int main(void) {
    imprimir_separador();
    printf("   PROTOCOLO DE QUARENTENA\n");
    printf("   Estacao Espacial NEXUS-7\n");
    imprimir_separador();

    animar_texto("\nSistema iniciado...", 50);
    animar_texto("Verificando protocolos de seguranca...", 40);
    animar_texto("Acesso concedido.", 60);

    return 0;
}