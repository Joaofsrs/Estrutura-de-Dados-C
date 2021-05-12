#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

unsigned char *criar_hash(unsigned char *string){
    int i;
    unsigned char Hash[32];
    unsigned char *aux;

    aux = (char *) malloc(sizeof(char) * 32);

    SHA256(string, sizeof(string), Hash);

    strcpy(aux, Hash);

    return (aux);
}


int main(void){
    int i;
    unsigned char string[32];
    unsigned char string2[32];
    unsigned char *str;
    unsigned char *str1;
    
    str = (unsigned char *) malloc(sizeof(unsigned char) * 32);
    str1 = (unsigned char *) malloc(sizeof(unsigned char) * 32);

    printf("Primeira String:\n");
    scanf("%s", string);
    printf("HASH DA PRIMEIRA STRING:\n");

    str = criar_hash(string);

    for(i=0; i < 32; i++){
        printf("%x", str[i]);
    }

    printf("\n\n");

    printf("Segunda String:\n");
    scanf("%s", string2);
    printf("HASH DA SEGUNDA STRING:\n");

    str1 = criar_hash(string2);

    for(i=0; i < 32; i++){
        printf("%x", str1[i]);
    }

    printf("\n\n");


    printf("CONCATENAÇAO DOS HASHES:\n");
    
    strcat(str1, str);

    for(i=0; i < 64; i++){
        printf("%x", str1[i]);
    }

    return 0;
}