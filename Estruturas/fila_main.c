#include "fila.h"
#define SUCESSO 1
#define FALHA 0

int main(){
    FILA **filinha;
    Data aux;

    int op;

    do{
        printf("\n\n\n\n");
        printf("(1) Criar Fila\n");
        printf("(2) Enfileirar novo elemento\n");
        printf("(3) Desenfileirar elemento\n");
        printf("(4) Zera Fila\n");
        printf("(0) SAIR\n");
        printf("Digite sua opcao: ");
        scanf("%d",&op);
        if(op == 1){
            filinha = criaFila();

            printf("Fila criada com sucesso\n");
        }

        if(op == 2){
            printf("Digite um elemento: ");
            scanf("%d",&aux.info);

            if(insereFinalFila(filinha, aux) == SUCESSO){
                printf("Elemento inserido no topo com sucesso\n");
            }

            printf("\n\n\t\t\tImprime lista\n");
            imprimeFila(filinha);
            printf("\n\n");
        }
        if(op == 3){
            if(RemoveInicioFila(filinha) == SUCESSO){
                printf("Elemento removido com sucesso");
            }
            printf("\n\n\t\t\tImprime lista\n");
            imprimeFila(filinha);
            printf("\n\n");
        }
        if(op == 4){
            if(ZeraFila(filinha)==SUCESSO){
                printf("Fila Zerada\n");
            }
        }
    }while(op != 0);

    LiberaFila(filinha);

    return 0;
}