#include "arvore.h"

int lugar = 0;

Arvore** Cria(){
    Arvore **nova;

    nova = (Arvore **) malloc(sizeof(Arvore *));

    if(nova != NULL){
        *nova = NULL;
    }
    return nova;
}

int existe_arv(Arvore **arv){
    if(arv == NULL)
        return 0;
    return 1;
}

int ehvazia_arv(Arvore **arv){
    if(existe_arv(arv) == 0)
        return -1;
    if(*arv == NULL)
        return 1;
    return 0;
}

void caminhaProfund_arv(Arvore **arv, int opcao){
    if(ehvazia_arv(arv) == 0){
        if(opcao == 2){
            caminhaEmOrdem_arv(*arv);
        }
    }
}

void removelem_arv(Arvore *nodo){
    free(nodo);
    nodo = NULL;
}

void removeEmOrdem_arv(Arvore *nodo){
    if(nodo == NULL){
        return;
    }
    removeEmOrdem_arv(nodo->esq);
    removelem_arv(nodo);
    removeEmOrdem_arv(nodo->dir);
}

void caminhaEmOrdem_arv(Arvore *nodo){
    if(nodo == NULL){
        return;
    }
    caminhaEmOrdem_arv(nodo->esq);
    visita_Nodo(nodo);
    caminhaEmOrdem_arv(nodo->dir);
}

void visita_Nodo(Arvore *nodo){
    printf("%d ", (nodo->info).valor);
}

int insere_arv(Arvore ** arv, Data novo){
    Arvore *novo_nodo;

    if(ehvazia_arv(arv) == 1){
        novo_nodo = (Arvore *) malloc(sizeof(Arvore));
        if(novo_nodo != NULL){
            novo_nodo->info = novo;
            novo_nodo->pai = NULL;
            novo_nodo->esq = NULL;
            novo_nodo->dir = NULL;
            *arv = novo_nodo;
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if(insereCaminha_arv(*arv, novo) == 1){
            return 1;
        }      
        else{
            return 0;
        }  
    }
}

int insereCaminha_arv(Arvore *nodo, Data novo){
    Arvore *novo_nodo;

    if(novo.valor < nodo->info.valor){
        if(nodo->esq == NULL){
            novo_nodo = (Arvore *) malloc(sizeof(Arvore));
            if(novo_nodo != NULL){
                novo_nodo->info = novo;
                novo_nodo->pai = nodo;
                novo_nodo->esq = NULL;
                novo_nodo->dir = NULL;
                nodo->esq = novo_nodo;
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            insereCaminha_arv(nodo->esq, novo);
        }
    }
    else if(novo.valor > nodo->info.valor){
        if(nodo->dir == NULL){
            novo_nodo = (Arvore *) malloc(sizeof(Arvore));
            if(novo_nodo != NULL){
                novo_nodo->info = novo;
                novo_nodo->pai = nodo;
                novo_nodo->esq = NULL;
                novo_nodo->dir = NULL;
                nodo->dir = novo_nodo;
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            insereCaminha_arv(nodo->dir, novo);
        }
    }
}

int buscar_arv(Arvore *nodo, Data busca){
    lugar ++;
    if((nodo->info).valor < busca.valor){
        buscar_arv(nodo->dir, busca);
    }
    if((nodo->info).valor > busca.valor){
        buscar_arv(nodo->esq, busca);
    }
    if((nodo->info).valor == busca.valor){
        printf("%d", lugar);
        lugar = 0;
        return 1;
    }
    else{
        lugar = 0;
        return 0;
    }
}

void caminhaPosOrdem_arv(Arvore *nodo){
    if(nodo == NULL){
        return;
    }
    caminhaPosOrdem_arv(nodo->esq);
    caminhaPosOrdem_arv(nodo->dir);
    visita_Nodo(nodo);
}

void caminhaPreOrdem_arv(Arvore *nodo){
    if(nodo == NULL){
        return;
    }
    visita_Nodo(nodo);
    caminhaPosOrdem_arv(nodo->esq);
    caminhaPosOrdem_arv(nodo->dir);
}

Arvore* removeno_arv(Arvore *remover){
    Arvore *no1, *no2;
    if(remover->esq == NULL){
        no2 = remover->dir;
        free(remover);
        return no2;
    }
    no1 = remover;
    no2 = remover->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }

    if(no1 != remover){
        no1->dir = no2->esq;
        no2->esq = remover->esq;
    }
    no2->dir = remover->dir;
    free(remover); 
    return no2;
}

int remove_arv(Arvore **aux, Data remover){
    Arvore *ant, *atu;
    if(aux == NULL){
        return 0;
    }
    ant = NULL;
    atu = *aux;
    while(atu != NULL){
        if(remover.valor == (atu->info).valor){
            if(atu == *aux){
                *aux = removeno_arv(atu);
            }
            else{
                if(ant->dir == atu){
                    ant->dir = removeno_arv(atu);
                }
                else{
                    ant->esq = removeno_arv(atu);
                }
            }
            return 1;
        }
        ant = atu;
        if(remover.valor > (atu->info).valor){
            atu = atu->dir;
        }
        else{
            atu = atu->esq;
        }
    }
    return 0;
}
