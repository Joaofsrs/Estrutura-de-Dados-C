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

typedef struct node FILA;

FILA** criaFila();

int ehVaziaFILA(FILA **inicio);

int insereFinalFila(FILA** finalfila, Data ultimo);

int RemoveInicioFila(FILA **iniciofila);

int confereInicio(FILA **inicio);

int imprimeFila(FILA **Filinha);

int ZeraFila(FILA** Fila);

void LiberaFila(FILA** libera);