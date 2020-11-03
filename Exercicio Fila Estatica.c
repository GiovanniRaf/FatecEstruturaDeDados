/*
	Fatec Campinas - Análise e Desenvolvimento de Sistemas
	Estrutura de dados
	Nome: Giovanni Rafael Mota
*/

#include<stdio.h>
#include<malloc.h>

#define MAX 5

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int inicio;
    int nroElem;
} FILA;

int tamanhoFila(FILA* f);
void exibirFila(FILA* f);
void inicializarFila(FILA* f);
bool inserirElementoFila(FILA* f, REGISTRO reg);
bool excluirElementoFila(FILA* f, REGISTRO* reg);
void reinicializarFila(FILA* f);

void main(){

    FILA* fila1 = (FILA*) malloc(sizeof(FILA));
    REGISTRO n1, n2, n3, n4, n5, n6, n7;
	n1.chave = 32;
	n2.chave = 44;
	n3.chave = 56;
	n4.chave = 71;
    n5.chave = 89;
	n6.chave = 11;
	n7.chave = 99;
    REGISTRO* e1, e2;

    inicializarFila(fila1->A);
    printf("Tamanho: %d \n", tamanhoFila(fila1->A));
    exibirFila(fila1->A);

    inserirElementoFila(fila1->A, n1);
    printf("Tamanho: %d \n", tamanhoFila(fila1->A));
    exibirFila(fila1->A);

    inserirElementoFila(fila1->A, n2);
    printf("Tamanho: %d \n", tamanhoFila(fila1->A));
    exibirFila(fila1->A);

    inserirElementoFila(fila1->A, n3);
    printf("Tamanho: %d \n", tamanhoFila(fila1->A));
    exibirFila(fila1->A);

    inserirElementoFila(fila1->A, n4);
    printf("Tamanho: %d \n", tamanhoFila(fila1->A));
    exibirFila(fila1->A);

    excluirElementoFila(fila1->A, &e1);
    printf("Tamanho: %d \n", tamanhoFila(fila1->A));
    exibirFila(fila1->A);
    printf("Elemento excluido: %d \n", e1);

    inserirElementoFila(fila1->A, n5);
    printf("Tamanho: %d \n", tamanhoFila(fila1->A));
    exibirFila(fila1->A);

    inserirElementoFila(fila1->A, n6);
    printf("Tamanho: %d \n", tamanhoFila(fila1->A));
    exibirFila(fila1->A);

    inserirElementoFila(fila1->A, n7);
    printf("Tamanho: %d \n", tamanhoFila(fila1->A));
    exibirFila(fila1->A);

    reinicializarFila(fila1->A);
    printf("Tamanho: %d \n", tamanhoFila(fila1->A));
    exibirFila(fila1->A);
}

int tamanhoFila(FILA* f) {
    return f->nroElem;
}

void exibirFila(FILA* f) {
    printf("Fila: \" ");
    int i = f->inicio;
    int temp;
    for (temp = 0; temp < f->nroElem; temp++) {
        printf("%i ", f->A[i].chave);
        i = (i + 1) % MAX;
    }
    printf("\"\n");
}

void inicializarFila(FILA* f) {
    f->inicio=0;
    f->nroElem=0;
}

bool inserirElementoFila(FILA* f, REGISTRO reg) {
    if (f->nroElem >= MAX){
        printf("Nao foi possivel inserir outro elemento, a fila esta lotada :/\n");
        return false;
    }
    int posicao = (f->inicio + f->nroElem) % MAX;
    f->A[posicao] = reg;
    f->nroElem++;
    return true;
}

bool excluirElementoFila(FILA* f, REGISTRO* reg) {
    if (f->nroElem==0)
        return false;
    *reg = f->A[f->inicio];
    f->inicio = (f->inicio+1) % MAX;
    f->nroElem--;
    return true;
}

void reinicializarFila(FILA* f) {
    inicializarFila(f);
}