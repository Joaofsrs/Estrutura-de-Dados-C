#include "Parte2.h"

Arvore** Cria(){
    Arvore **nova;

    nova = (Arvore **) malloc(sizeof(Arvore *));

    if(nova != NULL){
        *nova = NULL;
    }
    return nova;
}

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

void caminhaEmOrdem_arv(Arvore *nodo){
    if(nodo == NULL){
        return;
    }
    caminhaEmOrdem_arv(nodo->esq);
    visita_Nodo(nodo);
    caminhaEmOrdem_arv(nodo->dir);
}

void caminhaPosOrdem_arv(Arvore *nodo){
    if(nodo == NULL){
        return;
    }
    caminhaPosOrdem_arv(nodo->esq);
    caminhaPosOrdem_arv(nodo->dir);
    visita_Nodo(nodo);
}

void caminhaPreOrdem_arv(Arvore *nodo){
    if(nodo == NULL){
        return;
    }
    visita_Nodo(nodo);
    caminhaPosOrdem_arv(nodo->esq);
    caminhaPosOrdem_arv(nodo->dir);
}

void visita_Nodo(Arvore *nodo){
    if(nodo->ordem == 1){
        printf("Data de nascimento do Aluno: %s\n", (nodo->informacoes).datadenascimento);
    }
    if(nodo->ordem == 2){
        printf("Identidade do Aluno: %s\n", (nodo->informacoes).iddoaluno);
    }
    if(nodo->ordem == 3){
        printf("Serie do Aluno: %s\n", (nodo->informacoes).serie);
    }
    if(nodo->ordem == 4){
        printf("Orientador do Aluno: %s\n", (nodo->informacoes).professororientador);
    }
    if(nodo->ordem == 5){
        printf("Turma do Aluno: %s\n", (nodo->informacoes).turma);
    }
    if(nodo->ordem == 6){
        printf("Matricula do Aluno: %s\n", (nodo->informacoes).matricula);
    }
    if(nodo->ordem == 7){
        printf("Nome do Aluno: %s\n", (nodo->informacoes).nome);
    }
    if(nodo->ordem == 8){
        printf("Estado do Aluno: %s\n", (nodo->informacoes).Estado);
    }
    if(nodo->ordem == 9){
        printf("Endereco do aluno: %s\n", (nodo->informacoes).endereco);
    }
    if(nodo->ordem == 10){
        printf("Cidade do Aluno: %s\n", (nodo->informacoes).Cidade);
    }
    if(nodo->ordem == 11){
        printf("Responsavel pelo Aluno: %s\n", (nodo->informacoes).umresponsavel);
    }
    if(nodo->ordem == 12){
        printf("Telefone do Aluno: %s\n", (nodo->informacoes).telefone);
    }
    
}