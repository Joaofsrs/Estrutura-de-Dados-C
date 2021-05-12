#include <stdio.h>
#include <stdlib.h>

struct dados
{
    int valor;
};
typedef struct dados Data;

struct node 
{
    Data info;
    struct node *esq;
    struct node *dir;
    struct node *pai;
};
typedef struct node Arvore;

int insereCaminha_arv(Arvore *nodo, Data novo);

int insere_arv(Arvore ** arv, Data novo);

void visita_Nodo(Arvore *nodo);

void caminhaEmOrdem_arv(Arvore *nodo);

void caminhaProfund_arv(Arvore **arv, int opcao);

int ehvazia_arv(Arvore **arv);

int existe_arv(Arvore **arv);

Arvore** Cria();

int buscar_arv(Arvore *nodo, Data busca);

void caminhaPosOrdem_arv(Arvore *nodo);

void caminhaPreOrdem_arv(Arvore *nodo);

Arvore* removeno_arv(Arvore *remover);

int remove_arv(Arvore **aux, Data remover);

void removeEmOrdem_arv(Arvore *nodo);

void removelem_arv(Arvore *nodo);