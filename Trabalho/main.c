#include "trabalho.h"

int contador = 0;

int main(){
    Arvore **arv;
    Bloco **cadeia;
    cadeia = Cria_Bloco();
    
    Data aux;

    int opcao, op1;
    int i, j;

    /*Hash*/

    unsigned char *hashauxiliar, *Hregistros, *Hpai;
    Hpai = (unsigned char *) malloc(sizeof(unsigned char)*64); 
    hashauxiliar = (unsigned char *) malloc(sizeof(unsigned char)*64);


    /*Menu interativo*/
    do{
        printf("\n\t\t\tMENU\n\n");

        printf("(1) - Cadastrar um novo Aluno.\n");
        printf("(2) - Imprime os blocos.\n");
        printf("(0) - Sair.\n\n");

        printf("Digite a operacao desejada: ");
        scanf("%d", &opcao);
        system("clear");
        
        if(opcao == 1){
            arv = Cria();
            printf("Digite o Nome do aluno:\n");
            getchar();
            scanf("%[^\n]", aux.nome);
            getchar();
            printf("\nDigite a Data de Nascimento do aluno:\n");
            scanf("%s", aux.datadenascimento);
            getchar();
            printf("\nDigite as informacoes referentes ao endereco residencial do aluno.");
            printf("\nCidade: ");
            scanf("%[^\n]", aux.Cidade);
            getchar();
            printf("Estado: ");
            scanf("%[^\n]", aux.Estado);
            getchar();
            printf("Endereco Completo: ");
            scanf("%[^\n]", aux.endereco);
            getchar();
            printf("\nDigite o Numero da indentidade do aluno (somente numeros):\n");
            scanf("%s", aux.iddoaluno);
            getchar();
            printf("\nDigite o nome de um responsavel: \n");
            scanf("%[^\n]", aux.umresponsavel);
            getchar();
            printf("\nDigite um telefone para contato: \n");
            scanf("%[^\n]", aux.telefone);
            getchar();
            printf("\nDigite a Serie e Turma do aluno.\n");
            printf("Serie: ");
            scanf("%[^\n]", aux.serie);
            getchar();
            printf("Turma: ");
            scanf("%[^\n]", aux.turma);
            getchar();
            printf("\nDigite o Nome do Professor Orientador desse aluno:\n");
            scanf("%[^\n]", aux.professororientador);
            getchar();
            printf("\nNumero da matricula do aluno: \n");
            scanf("%s", aux.matricula); 

            insereordenado(arv, aux);

            printf("\t\tBUFFER\n\n");
            caminhaPreOrdem_arv(*arv);
            printf("\n");

            if(contador == 0){
                Hregistros = (unsigned char *) malloc(sizeof(unsigned char)*32);
                Hregistros = hash(*arv, Hregistros);
                hashauxiliar = blockhash(Hpai, Hregistros);
                insere_bloco(cadeia, hashauxiliar, Hpai, Hregistros, aux);
                contador++;
                
            }else{
                Hregistros = (unsigned char *) malloc(sizeof(unsigned char)*32);
                Hregistros = hash(*arv, Hregistros);
                Hpai = hashauxiliar;
                hashauxiliar = blockhash(Hpai, Hregistros);
                insere_bloco(cadeia, hashauxiliar, Hpai, Hregistros, aux);          
            }
            libera(arv);
            arv = NULL;

        }
        else if(opcao == 2){
            printf("\n");
            if(ehVaziabloco(cadeia) == 1){
                printf("Sem blocos\n");
            }else{
                printf("\n");
                Imprimecadeia(cadeia);
            }
        }
    }while(opcao != 0);

    free(Hregistros);
    Hregistros = NULL;

    free(hashauxiliar);
    hashauxiliar = NULL;

    free(Hpai);
    Hpai = NULL;

    liberabloco(cadeia);
    cadeia = NULL;

    return 0;
}
