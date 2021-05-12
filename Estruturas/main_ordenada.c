#include"ordenada.h"
#define SUCESSO 1
#define FALHA 0

int main()
{
    LADAE **lista;
    LADAE *node;
    Data aux;
    int r;
    
    int elem,op=-1,elemento = 0, retorno;
    
    do
    {          
        printf("\n\t\tMenu interativo\n\n");
        printf("(1) Criar e Inicializar LADAE\n");
        printf("(2) Inserir elemento ordenado\n");
        printf("(3) Remover elemento\n");
        printf("(4) Buscar um elemento na LADAE\n");
        printf("(5) Zerar LADAE\n");
        printf("(0) SAIR\n");
        printf("Digite sua opcao: ");
        scanf("%d",&op);
        
        if(op == 1){
            lista = criaLADAE();

            printf("Endereço do primeiro no da lista: %p\n",*lista);
            printf("Endereço da lista: %p\n",lista);
            
            printf("Lista LADAE inicializada com sucesso\n");
        }
        if(op == 2){
            printf("Digite um elemento: ");
            scanf("%d",&aux.info);
            
            if(InsereOrdenada(lista,aux) == SUCESSO)
            {
                printf("Elemento inserido %d com sucesso\n",elem);
            }
            
            printf("\n\n\t\t\tImprime lista\n");
            imprimeLADAE(lista);
            printf("\n\n");
        }
        if(op == 3){
            printf("Digite um elemento: ");
            scanf("%d",&elemento);

            if(RemoveOrdenada(lista,elemento) == SUCESSO)
            {
                printf("Elemento Removido com sucesso\n");
            }
            else{
                printf("Nao foi possivel remover o elemento\n");
            }

            printf("\n\n\t\t\tImprime lista\n");
            imprimeLADAE(lista);
            printf("\n\n");
        }

        if(op == 4){
            printf("Digite um elemento: ");
            scanf("%d",&elemento);

            retorno = BuscarLADAE(lista,elem);
            if(retorno != -1){
                printf("Seu elemento esta no lugar %d da lista\n", retorno);
            }
            else{
                printf("elemento não encontrado\n");
            }
        }
        if(op == 5){
            if(ZeraLADAE(lista) == SUCESSO)
            {  
                printf("Lista zerada com sucesso\n");
            }

            printf("\n\n\t\t\tImprime lista\n");
            imprimeLADAE(lista);
            printf("\n\n");
        }

    }while(op != 0);
    
    printf("Encerrando as operações...\n");
    
    liberaLADAE(lista);
    
    return 0;
}
