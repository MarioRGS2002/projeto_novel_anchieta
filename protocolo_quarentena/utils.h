#ifndef UTILS_H
#define UTILS_H

/* Para detectar o sistema operacional automaticamente*/
#ifdef _WIN32
    #include <windows.h>
    #define LIMPAR_TELA() system("cls")
    #define DORMIR_MS(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define LIMPAR_TELA() system("clear")
    #define DORMIR_MS(ms) usleep((ms) * 1000)
#endif

/* funcao para imprimir o texto caractrer por caracter com efeito de difitacao, delay*/
void animar_texto(const char*texto, int delay_ms);

/* Imprime uma linha de separacao*/

void imprimir_separador(void);

#endif



