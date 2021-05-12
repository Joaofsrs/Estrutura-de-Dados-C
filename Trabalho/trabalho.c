#include "trabalho.h"

unsigned char string[64];

Bloco** Cria_Bloco(){
    Bloco **novo;
    novo = (Bloco **) malloc(sizeof(Bloco *));
    
    
    if(novo != NULL){
        *novo = NULL;
    }
    return novo;

}

Arvore** Cria(){
    Arvore **nova;

    nova = (Arvore **) malloc(sizeof(Arvore *));

    if(nova != NULL){
        *nova = NULL;
    }
    return nova;
}

/*Blocos*/

unsigned char *criar_hash(unsigned char *string, unsigned char *aux){
    unsigned char Hash[64];
    
    SHA256(string, sizeof(unsigned char)*32, Hash);
    
    strcpy(aux, Hash);

    return (aux);
}

unsigned char *blockhash(unsigned char *pai, unsigned char *registros){
    int i, j;
    
    unsigned char *Hash_bloco;
    unsigned char *str;

    str = (unsigned char*) malloc(sizeof(unsigned char) * 64);
    Hash_bloco = (unsigned char *) malloc(sizeof(unsigned char) * 64);

    strcat(str, pai);

    for(i = 32, j = 0; i < 64; i++){
        str[i] = registros[j];
        j++;
    }

    Hash_bloco = criar_hash(str, Hash_bloco);

    free(str);
    str = NULL;

    return (Hash_bloco);
}

int insere_bloco(Bloco **bloco, unsigned char hash[], unsigned char pai[], unsigned char hasharvore[], Data infos){
    Bloco *nodo;

    nodo = (Bloco *) malloc(sizeof(Bloco));
    nodo -> infoblocks.hashpai = pai;
    nodo -> infoblocks.registros = hasharvore;
    nodo -> infoblocks.hashdobloco = hash;
    nodo -> informacoes = infos;
    nodo -> prox = NULL;
    
    if(ehVaziabloco(bloco) == 1){
       *bloco = nodo;
        
    }else{
        nodo->prox = *bloco;
        *bloco = nodo;
    }
    return 1;
}

void Imprimecadeia(Bloco **inicio){
    Bloco *aux;
    aux = *inicio;
    int i;
    
    printf("\n--------------Encadeamento de blocos------------------\n");

        if(aux == NULL){
            printf("Sem blocos\n");

        }else{

            while(aux != NULL){
                if(aux->prox != NULL){
                    printf("\n\nProximo Bloco: \n");
                }
                if(aux->prox == NULL){
                    printf("\n\nBloco Pai: \n");
                }
                printf("\nHash pai -> ");
                for(i=0; i<32; i++){
                    printf("%x", (aux->infoblocks).hashpai[i]);
                }
                printf("\nHash dos Registros -> ");
                for(i=0; i<32; i++){
                    printf("%x", (aux->infoblocks).registros[i]);
                }

                printf("\nHash do bloco -> ");
                for(i=0; i<32; i++){
                    printf("%x", (aux->infoblocks).hashdobloco[i]);
                }
                aux = aux->prox;
            }
        }
    printf("\n");
}

int ehVaziabloco(Bloco **inicio){
    if(*inicio == NULL){
        return 1;
    }else{
        return 0;
    }
}

int liberabloco(Bloco **inicio){
    Bloco *aux, *liberar;
    aux = *inicio;

    while(aux != NULL){
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    *inicio = NULL;
    return 1;
}

/*ARVORE*/ 

int existe_arv(Arvore **arv){
    if(arv == NULL)
        return 0;
    return 1;
}

int ehvazia_arv(Arvore **arv){
    if(existe_arv(arv) == 0)
        return -1;
    if(*arv == NULL)
        return 1;
    return 0;
}

int insere_arv(Arvore **arv, Data novo, Pref preferencia){
    Arvore *novo_nodo;

    if(ehvazia_arv(arv) == 1){
        novo_nodo = (Arvore *) malloc(sizeof(Arvore));
        if(novo_nodo != NULL){
            strcpy((novo_nodo->informacoes).nome, novo.nome);
            novo_nodo->ordem = preferencia.numero;
            novo_nodo->pai = NULL;
            novo_nodo->esq = NULL;
            novo_nodo->dir = NULL;
            *arv = novo_nodo;
            return 1;
        }
        else{
            return 0;
        }  
    }
    else{
        if(insereCaminha_arv(*arv, novo, preferencia) == 1){
            return 1;
        }      
        else{
            return 0;
        }  
    }
} 

int insereordenado(Arvore **arv, Data aux){
    Pref preferencia;

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

int insereCaminha_arv(Arvore *nodo, Data novo, Pref preferencia){
    Arvore *novo_nodo;

    if(preferencia.numero < nodo->ordem){
        if(nodo->esq == NULL){
            novo_nodo = (Arvore *) malloc(sizeof(Arvore));
            if(novo_nodo != NULL){
                if(preferencia.numero == 1){
                    strcpy((novo_nodo->informacoes).datadenascimento, novo.datadenascimento);
                }
                else if(preferencia.numero == 2){
                    strcpy((novo_nodo->informacoes).iddoaluno, novo.iddoaluno);
                }
                else if(preferencia.numero == 3){
                    strcpy((novo_nodo->informacoes).serie, novo.serie);
                }
                else if(preferencia.numero == 4){
                    strcpy((novo_nodo->informacoes).professororientador, novo.professororientador);
                }
                else if(preferencia.numero == 5){
                    strcpy((novo_nodo->informacoes).turma, novo.turma);
                }
                else if(preferencia.numero == 6){
                    strcpy((novo_nodo->informacoes).matricula, novo.matricula);
                }
                else if(preferencia.numero == 8){
                    strcpy((novo_nodo->informacoes).Estado, novo.Estado);
                }
                else if(preferencia.numero == 9){
                    strcpy((novo_nodo->informacoes).endereco, novo.endereco);
                }
                novo_nodo->ordem = preferencia.numero;
                novo_nodo->pai = nodo;
                novo_nodo->esq = NULL;
                novo_nodo->dir = NULL;
                nodo->esq = novo_nodo;
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            insereCaminha_arv(nodo->esq, novo, preferencia);
        }
    }
    else {
        if(nodo->dir == NULL){
            novo_nodo = (Arvore *) malloc(sizeof(Arvore));
            if(novo_nodo != NULL){
                if(preferencia.numero == 8){
                    strcpy((novo_nodo->informacoes).Estado, novo.Estado);
                }
                else if(preferencia.numero == 9){
                    strcpy((novo_nodo->informacoes).endereco, novo.endereco);
                }
                else if(preferencia.numero == 10){
                    strcpy((novo_nodo->informacoes).Cidade, novo.Cidade);
                }
                else if(preferencia.numero == 11){
                    strcpy((novo_nodo->informacoes).umresponsavel, novo.umresponsavel);
                }
                else if(preferencia.numero == 12){
                    strcpy((novo_nodo->informacoes).telefone, novo.telefone);
                }
                else if(preferencia.numero == 6){
                    strcpy((novo_nodo->informacoes).matricula, novo.matricula);
                }
                else if(preferencia.numero == 5){
                    strcpy((novo_nodo->informacoes).turma, novo.turma);
                }
                novo_nodo->ordem = preferencia.numero;
                novo_nodo->pai = nodo;
                novo_nodo->esq = NULL;
                novo_nodo->dir = NULL;
                nodo->dir = novo_nodo;
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            insereCaminha_arv(nodo->dir, novo, preferencia);
        }
    }
}

void caminhaPreOrdem_arv(Arvore *nodo){
    if(nodo == NULL){
        return;
    }
    visita_Nodo(nodo);
    caminhaPreOrdem_arv(nodo->esq);
    caminhaPreOrdem_arv(nodo->dir);
}

void visita_Nodo(Arvore *nodo){
    if(nodo->ordem == 1){
        printf("Data de nascimento do Aluno: %s\n", (nodo->informacoes).datadenascimento);
    }
    else if(nodo->ordem == 2){
        printf("Identidade do Aluno: %s\n", (nodo->informacoes).iddoaluno);
    }
    else if(nodo->ordem == 3){
        printf("Serie do Aluno: %s\n", (nodo->informacoes).serie);
    }
    else if(nodo->ordem == 4){
        printf("Orientador do Aluno: %s\n", (nodo->informacoes).professororientador);
    }
    else if(nodo->ordem == 5){
        printf("Turma do Aluno: %s\n", (nodo->informacoes).turma);
    }
    else if(nodo->ordem == 6){
        printf("Matricula do Aluno: %s\n", (nodo->informacoes).matricula);
    }
    else if(nodo->ordem == 7){
        printf("Nome do Aluno: %s\n", (nodo->informacoes).nome);
    }
    else if(nodo->ordem == 8){
        printf("Estado do Aluno: %s\n", (nodo->informacoes).Estado);
    }
    else if(nodo->ordem == 9){
        printf("Endereco do aluno: %s\n", (nodo->informacoes).endereco);
    }
    else if(nodo->ordem == 10){
        printf("Cidade do Aluno: %s\n", (nodo->informacoes).Cidade);
    }
    else if(nodo->ordem == 11){
        printf("Responsavel pelo Aluno: %s\n", (nodo->informacoes).umresponsavel);
    }
    else if(nodo->ordem == 12){
        printf("Telefone do Aluno: %s\n", (nodo->informacoes).telefone);
    }
    
}

int buscar_arv(Arvore *nodo, int busca){
    if(nodo->ordem < busca){
        buscar_arv(nodo->dir, busca);
    }
    else if(nodo->ordem > busca){
        buscar_arv(nodo->esq, busca);
    }
    else if(nodo->ordem == busca){
        if(busca == 1){
            strcpy(string, (nodo->informacoes).datadenascimento);
            return 1;
        }
        else if(busca == 2){
            strcpy(string, (nodo->informacoes).iddoaluno);
            return 1;
        }
        else if(busca == 3){
            strcpy(string, (nodo->informacoes).serie);
            return 1;
        }
        else if(busca == 4){
            strcpy(string, (nodo->informacoes).professororientador);
            return 1;
        }
        else if(busca == 5){
            strcpy(string, (nodo->informacoes).turma);
            return 1;
        }
        else if(busca == 6){
            strcpy(string, (nodo->informacoes).matricula);
            return 1;
        }
        else if(busca == 7){
            strcpy(string, (nodo->informacoes).nome);
            return 1;
        } 
        else if(busca == 8){
            strcpy(string, (nodo->informacoes).Estado);
            return 1;
        }
        else if(busca == 9){
            strcpy(string, (nodo->informacoes).endereco);
            return 1;
        }
        else if(busca == 10){
            strcpy(string, (nodo->informacoes).Cidade);
            return 1;
        }
        else if(busca == 11){
            strcpy(string, (nodo->informacoes).umresponsavel);
            return 1;
        }
        else if(busca == 12){
            strcpy(string, (nodo->informacoes).telefone);
            return 1;   
        }
    }
}

void liberano(Arvore *no){
    if(no == NULL){
        return;
    }
    liberano(no -> esq);
    liberano(no -> dir);
    free(no);
    no = NULL;
}

void libera(Arvore **arvore){
    if(arvore == NULL){
        return;
    }
    liberano(*arvore);
    free(arvore);
}

/*HASHES*/
unsigned char *hash(Arvore *ficha, unsigned char *destino){
    int i,j;
    Vtor *hashes;
    unsigned char *str1, *str2, *pai;
    
    str2 = (unsigned char *) malloc(sizeof(unsigned char) * 64);
    str1 = (unsigned char *) malloc(sizeof(unsigned char) * 64);
    pai = (unsigned char *) malloc(sizeof(unsigned char) * 64);

    hashes = (Vtor *)malloc(sizeof(Vtor) *12);
    for(i = 0; i < 12; i++){
        hashes[i].strings = (unsigned char *) malloc(sizeof(unsigned char)* 64);
        buscar_arv(ficha, i+1);
        hashes[i].strings = criar_hash(string, hashes[i].strings);
    }
    strcpy(str1, hashes[2].strings);

    for(i = 32, j = 0; i < 64; i++){
        str1[i] = hashes[4].strings[j];
        j++;
    }

    str1 = criar_hash(str1, str1);

    for(i = 32, j = 0; i < 64; i++){
        str1[i] = hashes[3].strings[j];
        j++;
    }

    str1 = criar_hash(str1, str1);

    for(i = 32, j = 0; i < 64; i++){
        str1[i] = hashes[5].strings[j];
        j++;
    }

    str1 = criar_hash(str1, str1);

    for(i = 32, j = 0; i < 64; i++){
        str1[i] = hashes[0].strings[j];
        j++;
    }

    str1 = criar_hash(str1, str1);

    for(i = 32, j = 0; i < 64; i++){
        str1[i] = hashes[1].strings[j];
        j++;
    }

    str1 = criar_hash(str1, str1);

    strcpy(str2, hashes[7].strings);

    for(i = 32, j = 0; i < 64; i++){
        str2[i] = hashes[9].strings[j];
        j++;
    }

    str2 = criar_hash(str2, str2);

    for(i = 32, j = 0; i < 64; i++){
        str2[i] = hashes[8].strings[j];
        j++;
    }

    str2 = criar_hash(str2, str2);
    
    for(i = 32, j = 0; i < 64; i++){
        str2[i] = hashes[11].strings[j];
        j++;
    }

    str2 = criar_hash(str2, str2);

    for(i = 32, j = 0; i < 64; i++){
        str2[i] = hashes[10].strings[j];
        j++;
    }

    str2 = criar_hash(str2, str2);
    
    strcat(pai, str1);
    
    for(i = 32, j = 0; i < 64; i++){
        pai[i] = str2[j];
        j++;
    }

    pai = criar_hash(pai, pai);

    for(i = 32, j = 0; i < 64; i++){
        pai[i] = hashes[6].strings[j];
        j++;
    }

    pai = criar_hash(pai, pai);

    memcpy(destino, pai, sizeof(unsigned char)*32);

    liberavetor(hashes);
    hashes = NULL;

    free(pai);
    pai = NULL;

    free(str2);
    str2 = NULL;

    free(str1);
    str1 = NULL;

    return (destino);
}

void liberavetor(Vtor *hashes){ 
    int i;
        for(i=0; i < 12; i++){
            free(hashes[i].strings);
            hashes[i].strings = NULL;
        }   
    free(hashes);
    hashes = NULL;
}

void caminhaLimpa_ABB(Arvore *node){
    if(node == NULL)
    {
        return ;
    }
    caminhaLimpa_ABB(node->esq);
    caminhaLimpa_ABB(node->dir);
    free(node);
    node=NULL;
}
