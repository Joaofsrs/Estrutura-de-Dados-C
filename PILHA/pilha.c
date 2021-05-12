#include "pilha.h"
#define SUCESSO 1
#define FALHA 0

PILHA** criaPilha(){
    PILHA **novo;

    novo = (PILHA **) malloc(sizeof(PILHA *));

    return novo;
}

int ehVaziaPilha(PILHA **base){

    if(*base == NULL)
        return 1;
    return 0;
}

void LiberaPilha(PILHA **libera){
    PILHA *aux, *aux2;
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

int inserePilha(PILHA **topo, Data novo){
    PILHA *novono;
    
    novono = (PILHA *) malloc(sizeof(PILHA));
    
    if(novono == NULL)
        return 0;
    
    novono->prox = NULL;
    novono->elem = novo;

    if(ehVaziaPilha(topo)){
        *topo = novono;
    }
    else{
        novono->prox = *topo;
        *topo = novono;
    }
    return 1;
}

int qualTopo(PILHA **topo){
    int elemento;

    elemento = ((*topo)->elem).info;

    return elemento;
}

int removePilha(PILHA **topo){
    PILHA *aux;
    aux = *topo;

    if(ehVaziaPilha(topo) == SUCESSO){
        printf("Essa pilha esta vazia.\n");
        return 0;
    }
    else{
        *topo = aux->prox;
        free(aux);
        aux = NULL;
    }
    return 1;
}

int imprimePilha(PILHA **pilinha){
    int bandeira = 0;
    PILHA **aux;
    int auxelem;
    Data elemento;  
    
    aux = criaPilha();
    
    if(ehVaziaPilha(pilinha) == SUCESSO){
        printf("\n\n\n\n\t\t\tPilha Vazia\n\n\n\n");
        return 0;
    }

    while(ehVaziaPilha(pilinha) == FALHA){
        auxelem = qualTopo(pilinha);
        if((*pilinha)->prox == NULL){
            printf("%d =>Base\n", auxelem);
        }
        else if(bandeira == 0){
            printf("%d =>Topo\n", auxelem);
            bandeira = 1;
        }
        else{
            printf("%d\n",auxelem);
        }
        elemento.info = auxelem;
        removePilha(pilinha);
        inserePilha(aux, elemento);
    }
    while(ehVaziaPilha(aux) == FALHA){
        auxelem = qualTopo(aux);
        elemento.info = auxelem;
        removePilha(aux);
        inserePilha(pilinha, elemento);
    }
    
    return 1;
}

int ZeraPilha(PILHA **zera){
    PILHA *aux, *libera;
    aux = *zera;

    while(aux != NULL){
        libera = aux;
        free(libera);
        libera->prox = NULL;
        aux = aux->prox;
    }
    free(aux);
    *zera = NULL;

    return 1;
}
