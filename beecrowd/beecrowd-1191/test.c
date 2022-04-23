#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bbteste.h"

// Metodo para inserir na arvore os valores
void inserir_arvore(char prefixa[], char infixa[], char lado){
    if (prefixa == NULL || strcmp(prefixa, "") == 0 || strcmp(prefixa, "\0") == 0 || infixa == NULL || strcmp(infixa, "") == 0 || strcmp(infixa, "\0") == 0) {
        return;
    }

    int i = 0;
    char strprefixesq[27] = "\0";
    char strinfixesq[27] = "\0";
    char strprefixdir[27] = "\0";
    char strinfixdir[27] = "\0";
    strcpy(strprefixesq, prefixa);
    strcpy(strinfixesq, infixa);
    // Selecionando qual caracter que devo quebrar a string e transformando em uma string para o strtok aceitar 
    char cort1[2] = "\0"; 
    char cort2[2] = "\0";

    // While para identificar onde fica a raiz do nó
    while (infixa[i] != prefixa[0])
        i++;

    // Recebe o lado que esta o o char e insere no lugar
    if(lado == 'e')
        printf("Insert %c no lado esquerdo\n", infixa[i]);
    else
        printf("Insert %c no lado direto\n", infixa[i]);

    // strprefixesq[i+1] para pegar o elemento apos o ultimo da esquerda e quebrar a string lá
    cort1[0] = strprefixesq[i+1];
    cort2[0] = strinfixesq[i];
    strtok(strprefixesq, cort1);
    // Recebe o valor da string nº 1 que esta à esquerda 
    for (int j = 0; j < strlen(strprefixesq); j++) {
        strprefixesq[j] = strprefixesq[j+1]; 
    }
    // Recebe o valor da string nº 2 que esta à esquerda 
    strtok(strinfixesq, cort2);
    // Recebe o valor da string nº 1 que esta à direita 
    for (int j = 0; j < (strlen(prefixa) - i); j++) {
        strprefixdir[j] = prefixa[i+1+j];
    }
    // Recebe o valor da string nº 2 que esta à direita 
    for (int j = 0; j < (strlen(infixa) - i); j++) {
        strinfixdir[j] = infixa[i+1+j];
    }
    // Chamada recursiva da função
    inserir_arvore(strprefixesq, strinfixesq, 'e');
    inserir_arvore(strprefixdir, strinfixdir, 'd');
}

int main (int argc, char *argv[]){
   // Recebe as 2 strings
    char prefixa[27] = "DBACEGF";
    char infixa[27] = "ABCDEFG";
  
    inserir_arvore(prefixa, infixa, 'e');

    return 0;
}
