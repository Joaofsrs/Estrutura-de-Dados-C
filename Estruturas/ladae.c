#include"ladae.h"

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

int insereInicioLADAE(LADAE **inicio, Data novo)
{
    LADAE *novono;
    
    novono = (LADAE *) malloc(sizeof(LADAE));
    if(novono == NULL)
        return 0;
    
    novono->prox = NULL;
    novono->elem = novo;
    
    if(ehVaziaLADAE(inicio))
    {
        *inicio = novono;
    }
    else
    {
        novono->prox = *inicio;
        *inicio = novono;
        /* .. faco outra coisa */
    }
    return 1;
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

int BuscarLADAE(LADAE **lista, int elemento)
{
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
int insereFinalLADAE(LADAE **final, Data novo){
    int i=0;
    LADAE *novono;
    LADAE *aux;
    aux = *final;

    novono = (LADAE *) malloc(sizeof(LADAE));
    if(novono == NULL)
        return 0;
    
    novono->prox = NULL;
    novono->elem = novo;
    
    if(ehVaziaLADAE(final))
    {
        *final = novono;
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

int RemoveInicioLADAE(LADAE **inicio){
    LADAE *aux;
    aux = *inicio;

    if(ehVaziaLADAE(inicio))
    {
        printf("Lista vazia nao tem como remover elemento");
        return 0;
    }
    else{
        free(aux);
        *inicio = (*inicio)->prox;
    }
    return 1;
}

int RemoveFinalLADAE(LADAE **final){
    LADAE *aux, *libera;
    aux = *final;

    if(aux == NULL)
        return 0;

    if(ehVaziaLADAE(final))
    {
        printf("Lista vazia nao tem como remover elemento");
        return 0;
    }
    else{
        while(aux->prox != NULL)
        {
            libera = aux;
            aux = aux->prox;
        }
        if(aux == *final){
            *final = aux->prox;
        }
        else{
            libera->prox = NULL;
        }
        free(aux);
        aux = NULL;
    }
    return 1; 
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