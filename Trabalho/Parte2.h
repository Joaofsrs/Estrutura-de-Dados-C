#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dados
{
    char nome[50];  
    char datadenascimento[15]; 
    char Estado[20];
    char Cidade[20];
    char endereco[50];
    char iddoaluno[20];
    char umresponsavel[50]; 
    char telefone[11];
    char matricula[20];
    char serie[10];
    char turma[10];
    char professororientador[50];

    char hash[10];
    char hashanterior[10];
};

typedef struct Dados Data;

struct Preferencia
{
    int Anome;
    int Adata;
    int Aestado;
    int Acidade;
    int Aendereco;
    int Aidd;
    int Aresponsavel;
    int Atelefone;
    int Amatricula;
    int Aserie;
    int Aturma;
    int Aprofessor;
    int numero;
};
typedef struct Preferencia Pref;

struct node
{
    Data informacoes;
    int ordem;
    struct node *pai;
    struct node *esq;
    struct node *dir;
};

typedef struct node Arvore;

int insereCaminha_arv(Arvore *nodo, Data novo, Pref preferencia);

int insere_arv(Arvore **arv, Data novo, Pref preferencia);

int ehvazia_arv(Arvore **arv);

int existe_arv(Arvore **arv);

Arvore** Cria();

void visita_Nodo(Arvore *nodo);

void caminhaEmOrdem_arv(Arvore *nodo);

void caminhaPreOrdem_arv(Arvore *nodo);

void caminhaPosOrdem_arv(Arvore *nodo);

void caminhaEmOrdem_arv(Arvore *nodo);

void visita_Nodo(Arvore *nodo);