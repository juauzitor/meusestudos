#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Metodo para inserir na arvore os valores
void inserir_arvore(char str1[], char str2[], char lado){
    if (str1 == NULL || strcmp(str1, "") == 0 || strcmp(str1, "\0") == 0 || str2 == NULL || strcmp(str2, "") == 0 || strcmp(str2, "\0") == 0) {
        return;
    }

    int i = 0;
    // [2] mudar o nome das variaveis para ficar mais amigavel para ler
    char str1cpy[27] = "\0";
    char str2cpy[27] = "\0";
    char str1cpyd[27] = "\0";
    char str2cpyd[27] = "\0";
    strcpy(str1cpy, str1);
    strcpy(str2cpy, str2);
    // Selecionando qual caracter que devo quebrar a string e transformando em uma string para o strtok aceitar 
    char cort1[2] = "\0"; 
    char cort2[2] = "\0";
    // [1] Retirar esses ponteiros e usar o proprio vetor da string
    char *str1pe, *str2pe;

    // While para identificar onde fica a raiz do nó
    while (str2[i] != str1[0])
        i++;

    // Recebe o lado que esta o o char e insere no lugar
    if(lado == 'e')
        printf("Insert %c no lado esquerdo\n", str2[i]);
    else
        printf("Insert %c no lado direto\n", str2[i]);

    // str1cpy[i+1] para pegar o elemento apos o ultimo da esquerda e quebrar a string lá
    cort1[0] = str1cpy[i+1];
    cort2[0] = str2cpy[i];
    str1pe = strtok(str1cpy, cort1);
    // [1] Retirar os ponteiros e usar o proprio vetor da string 
    // Recebe o valor da string nº 1 que esta à esquerda 
    for (int j = 0; j < strlen(str1pe); j++) {
        str1pe[j] = str1pe[j+1]; 
    }
    // Recebe o valor da string nº 2 que esta à esquerda 
    str2pe = strtok(str2cpy, cort2);
    // Recebe o valor da string nº 1 que esta à direita 
    for (int j = 0; j < (strlen(str1) - i); j++) {
        str1cpyd[j] = str1[i+1+j];
    }
    // Recebe o valor da string nº 2 que esta à direita 
    for (int j = 0; j < (strlen(str2) - i); j++) {
        str2cpyd[j] = str2[i+1+j];
    }
    // Chamada recursiva da função
    inserir_arvore(str1pe, str2pe, 'e');
    inserir_arvore(str1cpyd, str2cpyd, 'd');
}

int main (int argc, char *argv[]){
   // Recebe as 2 strings
    char str1[27] = "DBACEGF";
    char str2[27] = "ABCDEFG";
  
    inserir_arvore(str1, str2, 'e');

    return 0;
}
