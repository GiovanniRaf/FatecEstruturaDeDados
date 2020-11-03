/*
	Fatec Campinas - Análise e Desenvolvimento de Sistemas
	Estrutura de dados
	Nome: Giovanni Rafael Mota
*/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define MAX 50
//define MAX 10 //Considere este define, e desconsidere o define anterior, para poder exibir a mensagem de "Pilha lotada"

#define true 1
#define false 0

typedef int bool;

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int topo;
} PILHA;

int tamanhoPilha(PILHA* p);
void exibirPilha(PILHA* p);
void inicializarPilha(PILHA* p);
bool inserirElementoPilha(PILHA* p, REGISTRO reg);
bool excluirElementoPilha(PILHA* p, REGISTRO* reg);
void reinicializarPilha(PILHA* p);

void main(){

    PILHA* pilha1 = (PILHA*) malloc(sizeof(PILHA));
    REGISTRO n1, n2, n3, n4, n5, n6, n7, n8;
    n1.chave = 1;
    n2.chave = 2;
    n3.chave = 3;
    n4.chave = 4;
    n5.chave = 5;
    n6.chave = 6;
    n7.chave = 7;
    n8.chave = 8;
    REGISTRO* e1, e2;

    inicializarPilha(pilha1->A);
    printf("Tamanho: %d \n", tamanhoPilha(pilha1->A));
    exibirPilha(pilha1->A);

    inserirElementoPilha(pilha1->A, n5);
    printf("Tamanho: %d \n", tamanhoPilha(pilha1->A));
    exibirPilha(pilha1->A);

    inserirElementoPilha(pilha1->A, n2);
    printf("Tamanho: %d \n", tamanhoPilha(pilha1->A));
    exibirPilha(pilha1->A);

    inserirElementoPilha(pilha1->A, n7);    printf("Tamanho: %d \n", tamanhoPilha(pilha1->A));
    exibirPilha(pilha1->A);

    inserirElementoPilha(pilha1->A, n8);
    printf("Tamanho: %d \n", tamanhoPilha(pilha1->A));
    exibirPilha(pilha1->A);

    excluirElementoPilha(pilha1->A, &e1);
    printf("Tamanho: %d \n", tamanhoPilha(pilha1->A));
    exibirPilha(pilha1->A);
    printf("Elemento excluido: %d \n", e1);

    inserirElementoPilha(pilha1->A, n1);
    inserirElementoPilha(pilha1->A, n2);
    inserirElementoPilha(pilha1->A, n3);
    inserirElementoPilha(pilha1->A, n4);
    inserirElementoPilha(pilha1->A, n5);
    inserirElementoPilha(pilha1->A, n6);
    inserirElementoPilha(pilha1->A, n7);
    inserirElementoPilha(pilha1->A, n8);
    printf("Tamanho: %d \n", tamanhoPilha(pilha1->A));
    exibirPilha(pilha1->A);

    reinicializarPilha(pilha1->A);
    printf("Tamanho: %d \n", tamanhoPilha(pilha1->A));
    exibirPilha(pilha1->A);

    excluirElementoPilha(pilha1->A, &e2);

}

int tamanhoPilha(PILHA* p) {
    return p->topo + 1;
}

void exibirPilha(PILHA* p) {
    printf("Pilha: \" ");
    int i;
    for (i=p->topo;i>=0;i--) {
        printf("%i ", p->A[i].chave);
    }
    printf("\"\n");
}

void inicializarPilha(PILHA* p) {
    p->topo = -1;
}

bool inserirElementoPilha(PILHA* p, REGISTRO reg) {
    if (p->topo >= MAX-1){
        printf("Nao foi possivel inserir outro elemento, a pilha esta lotada :/\n");
        return false;
    }

    p->topo = p->topo+1;
    p->A[p->topo] = reg;
    
    return true;
}

bool excluirElementoPilha(PILHA* p, REGISTRO* reg) {
    if (p->topo == -1){
        printf("Nao ha mais elementos para serem removidos. \n");
        return false;
    }

    *reg = p->A[p->topo];
    p->topo = p->topo-1;

    return true;
}

void reinicializarPilha(PILHA* p) {
    p->topo = -1;
}