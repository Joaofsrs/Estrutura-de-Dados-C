#include "fila.h"
#define SUCESSO 1
#define FALHA 0

FILA** criaFila(){
    FILA **novo;

    novo = (FILA **) malloc(sizeof(FILA *));

    return novo;
}

int ehVaziaFILA(FILA **inicio){
    if(*inicio == NULL)
        return 1;
    return 0;
}

void LiberaFila(FILA **libera){
    FILA *aux, *aux2;
    aux = *libera;

    while(aux != NULL){
        aux2 = aux;
        free(aux2);
        aux2->prox = NULL;
        aux = aux->prox; 
    }
    free(aux);
    free(libera);
    *libera = NULL;
}

int insereFinalFila(FILA** finalfila, Data ultimo){
    int i=0;
    
    FILA *novono;
    FILA *aux;
    aux = *finalfila;

    novono = (FILA *) malloc(sizeof(FILA));
    if(novono == NULL)
        return 0;
    
    novono->prox = NULL;
    novono->elem = ultimo;
    
    if(ehVaziaFILA(finalfila))
    {
        *finalfila = novono;
    }
    else{
        while(aux->prox != NULL)
        {
            i++;
            aux = aux->prox;
        }
        aux->prox = novono;
    }
    return 1;
}  

int RemoveInicioFila(FILA **iniciofila){
    FILA *aux;
    aux = *iniciofila;

    if(ehVaziaFILA(iniciofila))
    {
        printf("Fila vazia nao tem como remover elemento");
        return 0;
    }
    else{
        free(aux);
        *iniciofila = (*iniciofila)->prox;
    }
    return 1;
}

int confereInicio(FILA **inicio){
    int elemento;

    elemento = ((*inicio)->elem).info;

    return elemento;
}

int imprimeFila(FILA **Filinha){
    int auxelem;
    Data elemento;

    FILA **aux;

    aux = criaFila();
    
    if((*Filinha) == NULL)
    {
        printf("Fila vazia\n");
        return 0;
    }

    while(ehVaziaFILA(Filinha) == FALHA){
        auxelem = confereInicio(Filinha);
        if((*Filinha)->prox == NULL){
            printf("%d ", auxelem);
        }
        else{
            printf("%d => ", auxelem);
        }
        elemento.info = auxelem;
        RemoveInicioFila(Filinha);
        insereFinalFila(aux,elemento);
    }

    while(ehVaziaFILA(aux) == FALHA){
        auxelem = confereInicio(aux);
        elemento.info = auxelem;
        RemoveInicioFila(aux);
        insereFinalFila(Filinha,elemento);
    }
    return 1;
}

int ZeraFila(FILA** Fila){
    FILA *aux, *libera;
    aux = *Fila;

    while(aux != NULL){
        libera = aux;
        free(libera);
        libera->prox = NULL;
        aux = aux->prox;
    }
    free(aux);
    *Fila = NULL;

    return 1;
}

