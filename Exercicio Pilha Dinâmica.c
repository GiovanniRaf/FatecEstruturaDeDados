/*
	Fatec Campinas - Análise e Desenvolvimento de Sistemas
	Estrutura de dados
	Nome: Giovanni Rafael Mota
*/

#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
    // outros campos...
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT topo;
} PILHA;

typedef int bool;

int tamanho(PILHA* p);
void exibirPilha(PILHA* p);
void inicializarPilha(PILHA* p);
bool estaVazia(PILHA* p);
bool inserirElemPilha(PILHA* p, REGISTRO reg);
bool excluirElemPilha(PILHA* p, REGISTRO* reg);
void reinicializarPilha(PILHA* p);

void main(){

    PILHA* pilha1 = (PILHA*) malloc(sizeof(PILHA));
    REGISTRO n1, n2, n3, n4;
    n1.chave = 7;
    n2.chave = 9;
    n3.chave = 5;
    n4.chave = 8;
    REGISTRO* e1, e2;

    inicializarPilha(&pilha1);
    printf("Tamanho: %d \n", tamanho(&pilha1));
    exibirPilha(&pilha1);

    inserirElemPilha(&pilha1, n1);
    printf("Tamanho: %d \n", tamanho(&pilha1));
    exibirPilha(&pilha1);

    inserirElemPilha(&pilha1, n2);
    printf("Tamanho: %d \n", tamanho(&pilha1));
    exibirPilha(&pilha1);

    inserirElemPilha(&pilha1, n3);
    printf("Tamanho: %d \n", tamanho(&pilha1));
    exibirPilha(&pilha1);

    inserirElemPilha(&pilha1, n4);
    printf("Tamanho: %d \n", tamanho(&pilha1));
    exibirPilha(&pilha1);

    excluirElemPilha(&pilha1, &e1);
    printf("Tamanho: %d \n", tamanho(&pilha1));
    exibirPilha(&pilha1);
    printf("Elemento excluido: %d \n", e1);
    
    reinicializarPilha(&pilha1);
    printf("Tamanho: %d \n", tamanho(&pilha1));
    exibirPilha(&pilha1);
    
    excluirElemPilha(&pilha1, &e2);
}

int tamanho(PILHA* p) {
    PONT end = p->topo;
    int tam = 0;

    while (end != NULL) {
        tam++;
        end = end->prox;
    }

    return tam;
}

void exibirPilha(PILHA* p) {
    PONT end = p->topo;
    printf("Pilha: \" ");
    
    while (end != NULL) {
        printf("%i ", end->reg.chave);
        end = end->prox;
    }

    printf("\"\n");
}

void inicializarPilha(PILHA* p) {
    p->topo = NULL;
}

bool estaVazia(PILHA* p) {
    if (p->topo == NULL) return true;
    return false;
}

bool inserirElemPilha(PILHA* p, REGISTRO reg) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

bool excluirElemPilha(PILHA* p, REGISTRO* reg) {
    if ( p->topo == NULL){
        printf("Impossivel excluir elemento! Pilha vazia! \n");
        return false;
    }

    *reg = p->topo->reg;
    PONT apagar = p->topo;
    p->topo = p->topo->prox;
    free(apagar);

    return true;
}

void reinicializarPilha(PILHA* p) {
    PONT apagar;
    PONT posicao = p->topo;
    
    while (posicao != NULL) {
        apagar = posicao;
        posicao = posicao->prox;
        free(apagar);
    }
    p->topo = NULL;
}