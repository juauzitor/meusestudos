#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Author: João VItor Mendes Pinto dos Santos
//github: https://github.com/juauzitor

typedef char tp_item;	
	
typedef struct tp_no{
	struct tp_no *esq;
	tp_item info;
	struct tp_no *dir;
} tp_no; 

typedef tp_no * tp_arvore;

tp_arvore inicializa_arvore()
{
 return NULL;
}


int arvore_vazia(tp_arvore raiz)
{
	if(raiz==NULL) return 1;
	else return 0;
}

tp_no *aloca_no() //aloca e retorna o endereço
{
	tp_no *no;
	no=(tp_no*)malloc(sizeof(tp_no));
	return no;
}

int insere_no(tp_arvore *raiz, tp_item e){	
    tp_no *pai=NULL, *novo, *p;  //*p=ponteiro auxiliar
	novo=aloca_no();//cria um novo elemento e coloca o endereço dele no novo
	if(!novo) return 0; //não deu para alocar (novo==null)
    pai = *raiz;
	novo->info=e;
	novo->esq=NULL;
	novo->dir=NULL;

    *raiz = novo;
	
	return 1;	
}

void pos_ordem (tp_no *p) { //imprime os elementos em pós-ordem 
	if (p != NULL) {
	pos_ordem (p->esq);
    pos_ordem (p->dir);
    printf("%c",p->info);
    }
}

int altura_arvore(tp_arvore raiz){
	if(raiz == NULL) return 0;
	int alt_esq = altura_arvore(raiz->esq);
	int alt_dir = altura_arvore(raiz->dir);
	if(alt_esq > alt_dir){
		return alt_esq + 1;
	}else{
		return alt_dir + 1;
	}
}

void destroi_no(tp_no *no){
   if(no==NULL) return;
   destroi_no(no->esq);
   destroi_no(no->dir);
 //  printf("\n %d ", no->info);
   free(no);
   no = NULL;
   return;
}

void destroi_arvore(tp_arvore *raiz){
   if(*raiz==NULL) return;
   destroi_no(*raiz);
  // free(*raiz);
   *raiz=NULL;
}

// Metodo para inserir na arvore os valores
void inserir_arvore(tp_arvore *raiz,char prefixa[], char infixa[]){
    // Evita um loop infinito na recursão
    if (prefixa == NULL || strcmp(prefixa, "") == 0 || strcmp(prefixa, "\0") == 0 || infixa == NULL || strcmp(infixa, "") == 0 || strcmp(infixa, "\0") == 0) {
        return;
    }
    int i = 0, j = 0;
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

    // Insere os valores no nó
    insere_no(raiz, infixa[i]);

    // strprefixesq[i+1] para pegar o elemento apos o ultimo da esquerda e quebrar a string lá
    cort1[0] = strprefixesq[i+1];
    cort2[0] = strinfixesq[i];
    strtok(strprefixesq, cort1);
    // Recebe o valor da string nº 1 que esta à esquerda, passando sempre o elemento do lado para eliminar a raiz 
    for (j = 0; j < strlen(strprefixesq); j++) {
        strprefixesq[j] = strprefixesq[j+1]; 
    }
    // Recebe o valor da string nº 2 que esta à esquerda 
    strtok(strinfixesq, cort2);
    // Recebe o valor da string nº 1 que esta à direita 
    for (j = 0; j < (strlen(prefixa) - i); j++) {
        strprefixdir[j] = prefixa[i+1+j];
    }
    // Recebe o valor da string nº 2 que esta à direita 
    for (j = 0; j < (strlen(infixa) - i); j++) {
        strinfixdir[j] = infixa[i+1+j];
    }
    // Chamada recursiva da função
    inserir_arvore(&(*raiz)->esq ,strprefixesq, strinfixesq);
    inserir_arvore(&(*raiz)->dir ,strprefixdir, strinfixdir);
}

int main (int argc, char *argv[]){
    char prefixa[27];
    char infixa[27];
    while(scanf(" %s", prefixa) != EOF && scanf(" %s", infixa) != EOF){
        tp_arvore raiz = inicializa_arvore();
		inserir_arvore(&raiz, prefixa, infixa);
		pos_ordem(raiz);
		printf("\n");
        destroi_arvore(&raiz);
    }
    return 0;
}
