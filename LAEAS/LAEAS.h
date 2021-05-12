#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

#define MAX 5

int bandc = 0;
int bandv = 0;
int cheia = 0;
int vazia = 0;
int band = 0;
int exoubusca =0;
int banelemento = 0;

struct lista 
{
    int fim;
    int elem[MAX];
};
typedef struct lista LAEAS;

void CriaLAEAS(LAEAS *lista);
void LAEASvazia(LAEAS *lista);
void inserefim(LAEAS *lista);
void insereinicio(LAEAS *lista);
void removefinal(LAEAS *lista);
void removeinicio(LAEAS *lista);
void buscar(LAEAS *lista);
void removeelemento(LAEAS *lista);
void Menu(LAEAS *lista);