#include<stdio.h>
#include<stdlib.h>

struct dados
{
    int info;
};

typedef struct dados Data;

struct node
{
    Data elem;
    struct node *prox;
};

typedef struct node PILHA;

PILHA** criaPilha();

int ehVaziaPilha(PILHA **inicio);

int inserePilha(PILHA **topo, Data novo);

int qualTopo(PILHA **topo);

int removePilha(PILHA **topo);

int imprimePilha(PILHA **pilinha);

int ZeraPilha(PILHA **zera);

void LiberaPilha(PILHA **libera);