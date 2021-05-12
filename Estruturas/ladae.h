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

int insereInicioLADAE(LADAE **inicio, Data novo);

int insereFinalLADAE(LADAE **final, Data novo);

void imprimeLADAE(LADAE **inicio);

void liberaLADAE(LADAE **inicio);

int BuscarLADAE(LADAE **lista, int elemento);

int RemoveInicioLADAE(LADAE **inicio);

int RemoveFinalLADAE(LADAE **final);

int ZeraLADAE(LADAE **zera);
