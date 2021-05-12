#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

/*STRUCTS*/

struct block1{
    unsigned char *hashdobloco;
    unsigned char *hashpai;
    unsigned char *registros;
};
typedef struct block1 DataBloco;

struct Preferencia{
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

struct dados{
    char nome[50];  
    char datadenascimento[15]; 
    char Estado[20];
    char Cidade[20];
    char endereco[50];
    char iddoaluno[10];
    char umresponsavel[50]; 
    char telefone[11];
    char matricula[10];
    char serie[10];
    char turma[10];
    char professororientador[50];
};
typedef struct dados Data;

struct node{
    Data informacoes;
    int ordem;
    struct node *pai;
    struct node *esq;
    struct node *dir;
};
typedef struct node Arvore;

struct block{
    DataBloco infoblocks;
    Data informacoes;
    struct block *prox;
};
typedef struct block Bloco;

struct vetor{
    unsigned char *strings;
};
typedef struct vetor Vtor;

/*BLOCOS*/

Bloco** Cria_Bloco();

int insere_bloco(Bloco **cadeia, unsigned char hash[], unsigned char pai[], unsigned char hasharvore[], Data infos);

unsigned char *criar_hash(unsigned char string[], unsigned char aux[]);

unsigned char *blockhash(unsigned char *pai, unsigned char *registros);

int imprimecadeia(Bloco **inicio);

int liberabloco(Bloco **inicio);

int ehVaziabloco(Bloco **inicio);


/* ARVORE */

Arvore** Cria();

int insereCaminha_arv(Arvore *nodo, Data novo, Pref preferencia);

int insere_arv(Arvore **arv, Data novo, Pref preferencia);

int ehvazia_arv(Arvore **arv);

int existe_arv(Arvore **arv);

void visita_Nodo(Arvore *nodo);

void caminhaEmOrdem_arv(Arvore *nodo);

void caminhaPreOrdem_arv(Arvore *nodo);

void visita_Nodo(Arvore *nodo);

void liberano(Arvore *no);

void libera(Arvore **arvore);

int buscar_arv(Arvore *nodo, int busca);

int insereordenado(Arvore **arv, Data novo);

/*Hashes*/

unsigned char *hash(Arvore *ficha, unsigned char *registros);

void liberavetor(Vtor *hashes);

void Imprimecadeia(Bloco **inicio);