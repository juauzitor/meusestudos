#include<stdlib.h>
#include<stdio.h>
	
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

int insere_no(tp_arvore *raiz, tp_item e, char lado){	
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

void pre_ordem(tp_no *p) //imprime os elementos em pre-ordem
{
	if(p!=NULL)
	{	printf("%c",p->info);
		pre_ordem(p->esq);
		pre_ordem(p->dir);
    	}
}	
void em_ordem (tp_no *p) {  //imprime os elementos em ordem
  if (p != NULL) {
	em_ordem (p->esq);
	printf("%c",p->info);
	em_ordem (p->dir);
    }
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