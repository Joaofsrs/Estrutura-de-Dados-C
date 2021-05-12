#include "arvore.h"

int main(){
    Arvore **arv;

    int op = 0;

    int flag = 0;
    
    Data elem;

    arv = Cria();

    if(arv == NULL){
        printf("\nNao foi possivel criar arvore\n");

        exit(1);
    }

    do{
        printf("\n1 - Insere elemento\n");
        printf("2 - Remove elemento\n");
        printf("3 - Caminha Em-Ordem\n");
        printf("4 - Caminha Pos-Ordem\n");
        printf("5 - Caminha Pre-Ordem\n");
        printf("6 - Buscar elemento\n");
        printf("0 - Sair\n");
        scanf("%d", &op);
        if(op == 1){
            printf("\nDigite o elemento que deseja inserir:\n");
            scanf("%d", &elem.valor);

            if(insere_arv(arv, elem)){
                printf("\nElemento %d inserido com sucesso\n", elem.valor);
            }
            else{
                printf("\nErro ao inserir elemento\n");
            }
        }
        if(op == 2){
            printf("\nDigite o elemento que deseja remover:\n");
            scanf("%d", &elem.valor);

            if(remove_arv(arv, elem)){
                printf("\nElemento removido com sucesso\n");
            }
            else{
                printf("\nErro ao remover elemento\n");
            }
        }
        if(op == 3){
            caminhaEmOrdem_arv(*arv);
        }
        if(op == 4){
            caminhaPosOrdem_arv(*arv);
        }
        if(op == 5){
            caminhaPreOrdem_arv(*arv);
        }
        if(op == 6){
            printf("\nDigite numero que deseja buscar:\n");
            scanf("%d", &elem.valor);
            flag = buscar_arv(*arv, elem);
            if(flag == 1){
                printf("\nElemento encontrado\n");
            }
            if(flag == 0){
                printf("\nElemento nao encontrado\n");
            }
            flag = 0;
        }
    }while(op != 0);
    removeEmOrdem_arv(*arv);
    printf("\n..\n");
    free(arv);
    arv = NULL;
    return 0;
}