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