#ifndef UTILS_H
#define UTILS_H

#ifdef _WIN32
    #include <windows.h>
    #define LIMPAR_TELA() system("cls")
    #define DORMIR_MS(ms) Sleep(ms)
#else
    #include <stdlib.h>   /* system() */
    /*
     * usleep() e uma funcao POSIX. Com -std=c11 o compilador nao a declara
     * automaticamente. Declaramos o prototipo manualmente aqui para evitar
     * o warning "implicit declaration", mantendo o codigo C11 puro sem
     * precisar de _POSIX_C_SOURCE ou outros defines de feature-test.
     */
    int usleep(unsigned int microseconds);
    #define LIMPAR_TELA() system("clear")
    #define DORMIR_MS(ms) usleep((unsigned int)((ms) * 1000))
#endif

void animar_texto(const char *texto, int delay_ms);
void imprimir_separador(void);
void transicao_cena(void); /*Transicao de tela*/

#endif
