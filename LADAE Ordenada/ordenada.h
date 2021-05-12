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

typedef struct node LADAE;

LADAE** criaLADAE();

int ehVaziaLADAE(LADAE **inicio);

void imprimeLADAE(LADAE **inicio);

int InsereOrdenada(LADAE **ordenada, Data novo);

void liberaLADAE(LADAE **inicio);

int RemoveOrdenada(LADAE **ordenada, int elemento);

int ZeraLADAE(LADAE **zera);

int BuscarLADAE(LADAE **lista, int elemento);