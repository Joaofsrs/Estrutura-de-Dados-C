#include "pilha.h"
#define SUCESSO 1
#define FALHA 0

int main(){
    PILHA **pilinha;
    Data aux;

    int op;

    do{
        printf("(1) Criar Pilha\n");
        printf("(2) Empilhar novo elemento\n");
        printf("(3) Desempilhar elemento\n");
        printf("(4) Zera Pilha\n");
        printf("(0) SAIR\n");
        printf("Digite sua opcao: ");
        scanf("%d",&op);
        if(op == 1){
            pilinha = criaPilha();

            printf("Lista LADAE inicializada com sucesso\n");
        }

        if(op == 2){
            printf("Digite um elemento: ");
            scanf("%d",&aux.info);

            if(inserePilha(pilinha, aux) == SUCESSO){
                printf("Elemento inserido no topo com sucesso\n");
            }

            printf("\n\n\t\t\tImprime lista\n");
            imprimePilha(pilinha);
            printf("\n\n");
        }

        if(op == 3){
            if(removePilha(pilinha) == SUCESSO){
                printf("Elemento inserido no topo com sucesso\n");
            }

            printf("\n\n\t\t\tImprime lista\n");
            imprimePilha(pilinha);
            printf("\n\n");
        }
        if(op == 4){
            if(ZeraPilha(pilinha) == SUCESSO){
                printf("Pilha Zerada\n\n");
            }
            
            printf("\n\n\t\t\tImprime lista\n");
            imprimePilha(pilinha);
            printf("\n\n");
        }
    }while(op != 0);
    
    LiberaPilha(pilinha);

    return 0;
}