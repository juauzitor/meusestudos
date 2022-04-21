#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int tp_item;	
	
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

int insere_no(tp_arvore *raiz, tp_item e)
{	tp_no *pai=NULL, *novo, *p;  //*p=ponteiro auxiliar
	novo=aloca_no();//cria um novo elemento e coloca o endereço dele no novo
	if(!novo) return 0; //não deu para alocar (novo==null)

	novo->info=e;
	novo->esq=NULL;
	novo->dir=NULL;
		
	p = *raiz;
	while(p!=NULL) 
	{//busca a posição onde será inserido o novo nó
		pai=p;
		if( e < p->info)
			p=p->esq;
		else
			p=p->dir;
	}	
	
	if(pai!=NULL) //Qual ponteiro do pai (esq ou dir) irá apontar para o novo nó
	{	
		if ( e < pai->info)
		   pai->esq=novo;
		else 
		   pai->dir=novo;
	}
	else 
		*raiz=novo;

	return 1;	
}

void pos_ordem (tp_no *p) { //imprime os elementos em pós-ordem 
	 if (p != NULL) {
	 pos_ordem (p->esq);
	 pos_ordem (p->dir);
	printf("\n%d\n",p->info);
}
}

tp_no* busca_no (tp_no *p, tp_item e) {
	while (p != NULL) { 
		if (e < p->info) 
			p = p->esq; 
		else 
			if (e > p->info) 
				p = p->dir; 
			else 
				return (p);
	};
 	return (NULL); 
}

int remove_no (tp_arvore *raiz, tp_item e ) {
	tp_no  *p=*raiz,   *ant=NULL,   *sub,   *pai,   *filho;
	while (p!=NULL && p->info!=e) {
		ant=p;
		if (e < p->info)
			p = p->esq;
		else
			p = p->dir;
	}
	if (p==NULL) /* não encontrou */
		return  0;
	/* nó tem no máximo um filho */
	if (p->esq==NULL)
		sub=p->dir;
	else
		if (p->dir==NULL)
			sub=p->esq;
		else {
		/* nó tem dois filhos */
			pai=p; sub=p->dir; filho=sub->esq;
			while (filho!=NULL) {
				pai=sub;  sub=filho;  filho=sub->esq;
			}
/* neste ponto, sub é o sucessor em ordem de p */
			if (pai!=p) {
				/*p não é o pai de sub e sub==pai->esq */
				pai->esq=sub->dir;
				/* remove o nó apontado por sub de sua atual 
				 posição e substitui pelo filho direito de rp */
				/* sub ocupa o lugar de p */
				sub->dir=p->dir;
			}
		/*define filho esq de sub para que sub ocupe o lugar de p */
			sub->esq=p->esq;
		}
		/* insere sub na posição ocupada por p */
		if (ant==NULL)
			*raiz=sub; /* p era raiz */
		else
			if (p==ant->esq)
				ant->esq=sub;
			else
				ant->dir=sub;
		free(p);
	return 1;
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

int main (int argc, char *argv[]){
    tp_arvore raiz = inicializa_arvore();
    char str1[27];
    char str2[27];
    while(scanf(" %s", str1) != EOF && scanf(" %s", str2) != EOF){
        printf("pre: %s | in: %s\n", str1, str2);
        
    }
    printf("EOF\n");
    return 0;
}
