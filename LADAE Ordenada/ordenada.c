#include"ordenada.h"


LADAE** criaLADAE()
{
    LADAE **novo;

    novo = (LADAE **) malloc(sizeof(LADAE *));

    return novo;
}

int ehVaziaLADAE(LADAE **inicio)
{
    if(*inicio == NULL)
        return 1;
    return 0;
}

void liberaLADAE(LADAE **inicio)
{
    LADAE *aux,*liberar;
    aux = *inicio;    
    
    while(aux!=NULL)
    {
        liberar = aux;
        free(liberar);
        aux=aux->prox;
    }
    free(inicio);
    inicio = NULL;
}

void imprimeLADAE(LADAE **inicio)
{
    LADAE *aux;
    aux = *inicio;
    
    printf("\n\n\t\t\tImprime lista\n");
    
    
    if(aux == NULL)
    {
        printf("Lista vazia\n");
    }
    else
    {
        while(aux != NULL)
        {
            printf("%d => ",(aux->elem).info);
            aux = aux->prox;
        }
    }
    printf("\n\n\n");
}

int InsereOrdenada(LADAE **ordenada, Data novo){
    LADAE *aux, *antes, *novono;
    aux = *ordenada;

    novono = (LADAE *) malloc(sizeof(LADAE));

    if(novono == NULL)
        return 0;
    
    novono->prox = NULL;
    novono->elem = novo;
    
    if(ehVaziaLADAE(ordenada)){
        *ordenada = novono;
    }
    else if(aux->prox  == NULL){
        if ((aux->elem).info < (novono->elem).info){
            aux->prox = novono;
        }
        else{
            novono->prox = *ordenada;
            *ordenada = novono;
        }
    }
    else if((aux->elem).info >= (novono->elem).info){
        novono->prox = aux;
        *ordenada = novono;
    }
    else{
        while(aux->prox != NULL){
            printf("..\n");
            antes = aux;
            aux = aux->prox;
            if((aux->elem).info == (novono->elem).info){
                antes->prox = novono;
                novono->prox = aux;
                return 1;
            }
        }
        if(aux->prox == NULL){
            aux->prox = novono;
        }
    }
    return 1;
}

int RemoveOrdenada(LADAE **ordenada, int elemento){
    LADAE *aux, *antes;
    aux = *ordenada;

    if(ehVaziaLADAE(ordenada))
    {
        printf("Lista vazia nao tem como remover elemento\n");
        return 0;
    }
    else if((aux->elem).info == elemento){
        if(aux->prox != NULL){
            free(aux);
            *ordenada = (*ordenada)->prox;
        }
        else{
            free(aux);
            aux = NULL;
            *ordenada = NULL;
        }
    }
    else{
        while(aux->prox != NULL){
            printf("..\n");
            antes = aux;
            aux = aux->prox;
            if((aux->elem).info == elemento){
                antes->prox = aux->prox;
                free(aux);
                return 1;
            }
        }
        printf("Elemento não existe na lista\n");
        return 0;
    }
    return 1;
}

int BuscarLADAE(LADAE **lista, int elemento){
    int i = 0;
    LADAE *aux;
    aux = *lista;

    while(aux != NULL){
        i++;
        if((aux->elem).info == elemento){
            i--;
            return i;
        }
        aux = aux->prox;
    }
    return -1;

}

int ZeraLADAE(LADAE **zera){
    LADAE *aux,*liberar;
    aux = *zera;    
    
    while(aux!=NULL)
    {
        liberar = aux;
        free(liberar);
        liberar->prox = NULL;
        aux=aux->prox;
    }
    free(aux);
    *zera = NULL;
}