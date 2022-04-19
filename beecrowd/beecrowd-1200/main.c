#include <stdio.h>
#include <stdlib.h>

typedef int tp_item;

typedef struct tp_no{
    struct tp_no *esq;
    tp_item info;
    struct tp_no *dir;
}tp_no;

typedef tp_no *tp_arvore;

tp_arvore inicializa_arvore(){
    return NULL;
}

int arvore_vazia(tp_arvore raiz){
    if(raiz == NULL) return 1;
    else return 0;
}

tp_no *aloca_no(){
    tp_no *no;
    no=(tp_no*)malloc(sizeof(tp_no));
    return no;
}

int insere_no(tp_arvore *raiz, tp_item e){
    tp_no *pai=NULL, *novo, *p;
    novo=aloca_no();
    
    if(!novo) return 0;
	
    novo->info=e;
	novo->esq=NULL;
	novo->dir=NULL;
		
	p = *raiz;
	while(p!=NULL) {
	    pai=p;
		if( e < p->info)
			p=p->esq;
		else
			p=p->dir;
	}	
	
	if(pai!=NULL){	
	    if ( e < pai->info){
		   pai->esq=novo;
        } else{ 
		   pai->dir=novo;
        }
	} else { 
		*raiz=novo;
    }
	return 1;
}

tp_no * busca_maior(tp_no *p){
    if(p->dir == NULL) return p;
    return busca_maior(p->dir);
}

void pre_ordem(tp_no *p, tp_no *aux) {
	if(p!=NULL) {
        printf("%d",p->info);
        if(p != aux) printf(" ");
		pre_ordem(p->esq, aux);
		pre_ordem(p->dir, aux);
	} 
}

void em_ordem (tp_no *p, tp_no *aux) { 
  if (p != NULL) {
    	em_ordem (p->esq, aux);
	    printf("%d",p->info);
        if(p != aux) printf(" ");
    	em_ordem (p->dir, aux);
    }
}

void pos_ordem (tp_no *p, tp_no *aux) {
	if (p != NULL) {
        pos_ordem (p->esq, aux);
    	pos_ordem (p->dir, aux);
        printf("%d",p->info);
        if(p != aux) printf(" ");
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

tp_arvore busca_no_rec (tp_arvore p, tp_item e) {
	if (p != NULL) { 
		if (e < p->info) 
			return busca_no_rec(p->esq, e); 
		else 
			if (e > p->info) 
				return busca_no_rec(p->dir, e); 
			else 
				return (p);
	}
	else
 		return (NULL); 
}

int remove_no (tp_arvore *raiz, tp_item e ) {
	tp_no  *p=*raiz,   *ant=NULL,   *sub,   *pai,   *filho;
	while (p!=NULL && p->info!=e) {
		ant=p;
		if (e < p->info){
			p = p->esq;
        } else {
			p = p->dir;
        }
	}
	if (p==NULL) {
		return  0;
    }
	
	if (p->esq==NULL){
		sub=p->dir;
    } else {
		if (p->dir==NULL){
			sub=p->esq;
        } else {
			pai=p; sub=p->dir; filho=sub->esq;
			while (filho!=NULL) {
				pai=sub;  sub=filho;  filho=sub->esq;
			}
			if (pai!=p) {
				pai->esq=sub->dir;
				sub->dir=p->dir;
			}
			sub->esq=p->esq;
		}
		if (ant==NULL)
			*raiz=sub;
		else
			if (p==ant->esq)
				ant->esq=sub;
			else
				ant->dir=sub;
		free(p);
    }
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

int main (int argc, char *argv[]) {
    tp_arvore raiz = inicializa_arvore();
    insere_no(&raiz, 5);
    insere_no(&raiz, 7);
    insere_no(&raiz, 8);
    insere_no(&raiz, 4);
    insere_no(&raiz, 15);
    insere_no(&raiz, 5);
    insere_no(&raiz, 6);
    insere_no(&raiz, 2);
    insere_no(&raiz, 3);
    insere_no(&raiz, 3);
    insere_no(&raiz, 4);
    insere_no(&raiz, 1);
    pre_ordem(raiz, busca_maior(raiz));
    printf("\n"); 
    em_ordem(raiz, busca_maior(raiz));
    printf("\n"); 
    pos_ordem(raiz, raiz);
    printf("\n"); 

    return 0;
}
