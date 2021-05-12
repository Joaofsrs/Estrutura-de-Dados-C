#include "LAEAS.h"

void CriaLAEAS(LAEAS *lista){
    lista -> fim = -1;
}   

void LAEAScheia(LAEAS *lista){
    if(lista -> fim < MAX-1) {
        cheia = 0;
    }
    else if(lista -> fim == MAX-1){
        cheia = 1;
    }
}

void LAEASvazia(LAEAS *lista){
    if(lista -> fim == -1){
        vazia = 0;
    }
    else if (lista -> fim > -1){
        vazia = 1;
    }
}

void inserefim(LAEAS *lista){
    LAEAScheia(lista);
    
    int x;
    
    printf("Digite o numero que deseja inserir");
    scanf("%d",&x);
    
    if(cheia == 1){
        printf("Nao foi possivel inserir pois a lista esta cheia");
    }
    else if(cheia == 0){
        lista -> fim++;
        lista -> elem[lista -> fim] = x;
        printf("Deu tudo certo!!");
    }
}

void insereinicio(LAEAS *lista){
    int i,x;

    LAEAScheia(lista);

    printf("Digite o numero que deseja inserir");
    scanf("%d",&x);
    
    if(cheia == 1){
        printf("Nao foi possivel inserir pois a lista esta cheia");
    }
    else if(cheia == 0){
        for(i = lista -> fim; i >= 0; i--){
            lista -> elem[i+1] == lista -> elem[i]; 
        }
        lista -> elem[0] = x;
        lista -> fim++;
        printf("Deu tudo certo!!");
    }
}

void removefinal(LAEAS *lista){
    if(vazia == 1){
        lista -> elem[lista -> fim] = NULL;
        lista -> fim--;
        printf("Deu tudo certo!!");
    }
    else if(vazia == 0){
        printf("Nao foi possivel remover pois a lista esta vazia");
    }
}

void removeinicio(LAEAS *lista){
    int i;
    LAEASvazia(lista);
    if(vazia == 1){
        if(lista -> fim == 0){
            lista -> elem[0] = NULL;
            lista -> fim--;
        }
        else{
            for(i = 0; i < lista -> fim; i++){
                lista -> elem[i] = lista -> elem[i+1];
            }
            lista -> elem[lista -> fim] = NULL;
            lista ->fim--;
        }
        printf("Deu tudo certo!!");
    }
    else if(vazia == 0){
        printf("Nao foi possivel remover pois a lista esta vazia");
    }
}

void buscar(LAEAS *lista){
    int i, elemento;
    if(exoubusca == 0){
        printf("Digite o numero que deseja buscar:");
    }
    else if(exoubusca == 1){
        printf("Digite o numero que deseja excluir:");
    }
    scanf("%d",&elemento);
    for(i = 0; lista -> elem[i] != elemento && i <= lista -> fim; i++){
        if(lista -> elem[i] == elemento){
            band = 1;
        }
        else if(lista -> elem[i] != elemento){
            band = 0;
        }
    }
    if(exoubusca == 0){
        if(band == 1){
            printf("seu numero esta no lugar %d do vetor", i);
        }
        else if(band == 0){
            printf("Nao foi possivel achar esse numero");
        }
    }
    if(exoubusca == 1){
        if(band == 1){
            banelemento = i;
        }
        else if(band == 0){
            printf("Nao foi possivel achar esse numero");
        }
    }
}

void removeelemento(LAEAS *lista){
    int i;
    LAEASvazia(lista);
    exoubusca = 1;
    buscar(LEAR lista);
    lista -> elem[banelemento] = NULL;
    if(vazia == 1 && band == 1){
        if(lista -> fim == 0){
            lista -> elem[0] = NULL;
            lista -> fim--;
        }
        else{
            for(i = banelemento; i < lista -> fim; i++){
                lista -> elem[i] = lista -> elem[i+1];
            }
            lista -> elem[lista -> fim] = NULL;
            lista ->fim--;
        }
        printf("Deu tudo certo!!");
    }
    else if(vazia == 0 || band == 0){
        printf("Infelizmente não foi possivel remover esse numero");
    }
}

void Menu(LAEAS *lista){
    CriaLAEAS(lista); 
    int menu, ban = 0; 
    printf("1 - Inserir um numero no fim da lista\n");
    printf("2 - Inserir um nuemro no inicio da lista");
    printf("3 - Remoover um numero no fim da lista");
    printf("4 - Remover um numero no inicio da lista");
    printf("5 - Remover um numero que deseja");
    printf("6 - Buscar um elemento da lista");
    printf("7 - Fechar programa");
    scanf("%d",&menu);
    switch(menu){
        case 1:
            inserefim(lista);
        break;

        case 2:
            insereinicio(lista);
        break;
        
        case 3:
            removefim(lista);
        break;

        case 4:
            removeinicio(lista);
        break;

        case 5:
            removeelemento(lista);
        break;

        case 6:
            buscar(lista);
        break;

        case 7:
            ban = 1;
        break;
    }

    if(ban == 0){
        Menu(lista);
    }
}