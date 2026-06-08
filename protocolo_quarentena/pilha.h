#ifndef PILHA_H
#define PILHA_H

/*Um no da pilha guarda o ID da cena e aponta para o no abaixo*/
typedef struct NoPilha {
    int id_cena;
    struct NoPilha *anterior;

} NoPilha;

/* Saber quem esta no topo da pilha*/

typedef struct {
    NoPilha *topo;
    int tamanho;

} Pilha;

/* funcoes que a pilha vai fazer*/

void  pilha_inicializar(Pilha *p);/*Declara a função que prepara a pilha para uso*/
void  pilha_empilhar(Pilha *p, int id_cena);/*Declara a função que adiciona uma cena ao histórico*/
int   pilha_desempilhar(Pilha *p);
int   pilha_topo(Pilha *p);
int   pilha_vazia(Pilha *p);
void  pilha_liberar(Pilha *p);
void  pilha_imprimir(Pilha *p);/*APENAS PARA TESTES*/

#endif

