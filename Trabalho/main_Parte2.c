#include "Parte2.h"

int main(){
    /*declaracao das listas*/
    Arvore **arv;

    arv = Cria();

    /*Variaveis para pegar informacoes*/
    Data aux;
    Pref preferencia;

    /*Variaveis */
    int opcao, op1;
    int i;

    /*Menu interativo*/
    do{
        printf("\t\t\tMENU\n\n");

        printf("(1) - Cadastrar um novo Aluno.\n");
        printf("(2) - Caminha Pre Ordem.\n");
        printf("(3) - Caminha Em Ordem.\n");
        printf("(4) - Caminha Pos Ordem.\n");
        printf("(0) - Sair.\n\n");

        printf("Digite a operacao desejada: ");
        scanf("%d", &opcao);
        system("clear");
        
        if(opcao == 1){
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
             
            preferencia.Anome = 7;
            preferencia.Adata = 1;
            preferencia.Acidade = 10;
            preferencia.Aestado = 8;
            preferencia.Aendereco = 9;
            preferencia.Aidd = 2;
            preferencia.Aresponsavel = 11;
            preferencia.Atelefone = 12;
            preferencia.Aserie = 3;
            preferencia.Aturma = 5;
            preferencia.Aprofessor = 4;
            preferencia.Amatricula = 6; 

            preferencia.numero = preferencia.Anome;
            insere_arv(arv,aux,preferencia);
            preferencia.numero = preferencia.Aidd;
            insere_arv(arv,aux,preferencia);
            preferencia.numero = preferencia.Adata;
            insere_arv(arv,aux,preferencia);
            preferencia.numero = preferencia.Amatricula;
            insere_arv(arv,aux,preferencia);
            preferencia.numero = preferencia.Aprofessor;
            insere_arv(arv,aux,preferencia);
            preferencia.numero = preferencia.Aserie;
            insere_arv(arv,aux,preferencia);
            preferencia.numero = preferencia.Aturma;
            insere_arv(arv,aux,preferencia);
            preferencia.numero = preferencia.Aresponsavel;
            insere_arv(arv,aux,preferencia);
            preferencia.numero = preferencia.Aendereco;
            insere_arv(arv,aux,preferencia);
            preferencia.numero = preferencia.Atelefone;
            insere_arv(arv,aux,preferencia);
            preferencia.numero = preferencia.Aestado;
            insere_arv(arv,aux,preferencia);
            preferencia.numero = preferencia.Acidade;
            insere_arv(arv,aux,preferencia);
        }
        if(opcao == 2){
            printf("\n");
            caminhaPreOrdem_arv(*arv);
            printf("\n");
        }
        if(opcao == 3){
            printf("\n");
            caminhaEmOrdem_arv(*arv);
            printf("\n");
        }
        if(opcao ==4){
            printf("\n");
            caminhaPosOrdem_arv(*arv);
            printf("\n");
        }

    }while(opcao != 0);

    return 0;
}