/*
	Fatec Campinas - Análise e Desenvolvimento de Sistemas
	Estrutura de dados
	Nome: Giovanni Rafael Mota
*/

#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0

typedef int bool;

typedef int TIPOCHAVE; 

typedef struct {
    TIPOCHAVE chave;
    // outros campos...
} REGISTRO; 

typedef struct aux {
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO, * PONT;

typedef struct {
    PONT inicio;
    PONT fim;
} FILA;

int tamanho(FILA* f);
void exibirFila(FILA* f);
void inicializarFila(FILA* f);
bool inserirNaFila(FILA* f, REGISTRO reg);
bool excluirDaFila(FILA* f, REGISTRO* reg);
void reinicializarFila(FILA* f);

void main(){
    FILA* fila1 = (FILA*) malloc(sizeof(FILA));
    REGISTRO n1, n2, n3, n4;
	n1.chave = 5;
	n2.chave = 9;
	n3.chave = 7;
	n4.chave = 8;
    REGISTRO* e1, e2;

    inicializarFila(fila1);
    printf("Tamanho: %d \n", tamanho(fila1));
    exibirFila(fila1);

    inserirNaFila(fila1, n1);
    printf("Tamanho: %d \n", tamanho(fila1));
    exibirFila(fila1);

    inserirNaFila(fila1, n2);
    printf("Tamanho: %d \n", tamanho(fila1));
    exibirFila(fila1);

    inserirNaFila(fila1, n3);
    printf("Tamanho: %d \n", tamanho(fila1));
    exibirFila(fila1);

    excluirDaFila(fila1, &e1);
    printf("Tamanho: %d \n", tamanho(fila1));
    exibirFila(fila1);
    printf("Elemento excluido: %d \n", e1);

    inserirNaFila(fila1, n4);
    printf("Tamanho: %d \n", tamanho(fila1));
    exibirFila(fila1);

    reinicializarFila(fila1);
    printf("Tamanho: %d \n", tamanho(fila1));
    exibirFila(fila1);

    excluirDaFila(fila1, &e2);
}

int tamanho(FILA* f) {
    PONT end = f->inicio;
    int tam = 0;

    while (end != NULL) {
        tam++;
        end = end->prox;
    }

    return tam;
}

void exibirFila(FILA* f) {
    PONT end = f->inicio;
    printf("Fila: \" ");

    while (end != NULL) {
        printf("%i ", end->reg.chave);
        end = end->prox;
    }

    printf("\"\n");
}

void inicializarFila(FILA* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

bool inserirNaFila(FILA* f, REGISTRO reg) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = NULL;

    if (f->inicio==NULL){
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }

    f->fim = novo;

    return true;
}

bool excluirDaFila(FILA* f, REGISTRO* reg) {
    if (f->inicio==NULL){
        printf("Impossivel inserir outro elemento! Fila Lotada! \n");
        return false;
    }

    *reg = f->inicio->reg;
    PONT apagar = f->inicio;
    f->inicio = f->inicio->prox;
    free(apagar);

    if (f->inicio == NULL) 
        f->fim = NULL;

    return true;
}

void reinicializarFila(FILA* f) {
    PONT end = f->inicio;

    while (end != NULL) {
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }

    f->inicio = NULL;
    f->fim = NULL;
}