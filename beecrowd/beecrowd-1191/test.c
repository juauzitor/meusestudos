#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inserir_arvore(char str1[], char str2[], char lado){
    if (str1 == NULL || strcmp(str1, "") == 0 || str2 == NULL || strcmp(str2, "") == 0) {
        return;
    }

    int i = 0;
    char str1cpy[27] = "\0";
    char str2cpy[27] = "\0";
    char str1cpyd[27] = "\0";
    char str2cpyd[27] = "\0";
    strcpy(str1cpy, str1);
    strcpy(str2cpy, str2);
    char cort1[2] = "\0"; 
    char cort2[2] = "\0"; 
    char *str1pe, *str2pe, *str1pd, *str2pd;

    while (str2[i] != str1[0])
        i++;
    if(lado == 'e')
        printf("Insert %c no lado esquerdo\n", str2[i]);
    else
        printf("Insert %c no lado direto\n", str2[i]);

    // str1cpy[i+1] para pegar o elemento apos o ultimo da esquerda e quebrar a string lá
    cort1[0] = str1cpy[i+1];
    cort2[0] = str2cpy[i];
    str1pe = strtok(str1cpy, cort1);
    for (int j = 0; j < strlen(str1pe); j++) {
        str1pe[j] = str1pe[j+1]; 
    }
    str2pe = strtok(str2cpy, cort2);
    for (int j = 0; j < (strlen(str1) - i); j++) {
        str1cpyd[j] = str1[i+1];
    }
    for (int j = 0; j < (strlen(str2) - i); j++) {
        str2cpyd[j] = str2[i+1];
    }

        inserir_arvore(str1pe, str2pe, 'e');
        inserir_arvore(str1pd, str2pd, 'd');
}
/*
    void inserir_arvore(char str1[], char str2[], char lado){
    int i = 0;
    char str1cpy[27] = "\0";
    char str2cpy[27] = "\0";
    strcpy(str1cpy, str1);
    strcpy(str2cpy, str2);
    char cort1[2] = "\0"; 
    char cort2[2] = "\0"; 
    char *str1p;
    char *str2p;

    while (str2[i] != str1[0])
        i++;
    if(lado == 'e')
        printf("Insert %c no lado esquerdo\n", str2[i]);
    else
        printf("Insert %c no lado direto\n", str2[i]);

    cort1[0] = str1cpy[i+1];
    cort2[0] = str2cpy[i];
    str1p = strtok(str1cpy, cort1);
    for (int i = 0; i < strlen(str1p); i++) {
        str1p[i] = str1p[i+1]; 
    }
    str2p = strtok(str2cpy, cort2);

    if ( i == 0)
        inserir_arvore(str1p, str2p, 'd');
    else
        inserir_arvore(str1p, str2p, 'e');
}
*/
int main (int argc, char *argv[]){
    char str1[27] = "DBACEGF";
    char str2[27] = "ABCDEFG";
    char str1cpy[27] = "\0";
    char str2cpy[27] = "\0";
    int i = 0;
    char *t;

    while (str2[i] != str1[0])
        i++;
    char sla[2] = "\0";
    sla[0] = str1[i+1];
    strcpy(str1cpy, str1);
    inserir_arvore(str1, str2, 'e');
/*    printf("Raiz: %c\n", str2[i]);
    t = strtok(str1cpy, sla);
    printf("String cortada: %s\n", t);
    printf("Indice: %d\n", i);
    printf("Str1: %s\n", str1);
    printf("Str2: %s\n", str2);
    printf("Insert %c\n", str2[i]);
    printf("Str1 cortada: %s\n", str1cpy);
    for (int i = 0; i < strlen(t); i++) {
        t[i] = t[i+1];
    }
    printf("Str1 cortada: %s\n", str1cpy);
    printf("String cortada editada: %s\n", t);
*/
    return 0;
}
