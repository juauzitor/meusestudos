#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char tp_item;

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

tp_no * busca_filhos_do_maior(tp_no *p){
	if(p->dir != NULL){
		busca_filhos_do_maior(p->dir);
	} else if(p->esq != NULL){
		busca_filhos_do_maior(p->esq);
	} else return p;
}

void pre_ordem(tp_no *p, tp_no *aux) {
	if(p!=NULL) {
        printf("%c",p->info);
        if(p != aux) printf(" ");
		pre_ordem(p->esq, aux);
		pre_ordem(p->dir, aux);
	} 
}

void em_ordem (tp_no *p, tp_no *aux) { 
  if (p != NULL) {
    	em_ordem (p->esq, aux);
	    printf("%c",p->info);
        if(p != aux) printf(" ");
    	em_ordem (p->dir, aux);
    }
}

void pos_ordem (tp_no *p, tp_no *aux) {
	if (p != NULL) {
        pos_ordem (p->esq, aux);
    	pos_ordem (p->dir, aux);
        printf("%c",p->info);
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
    char op[8];
	tp_item t;
    while(scanf("%s", op) != EOF){
		if(strcmp(op, "I") == 0){
			scanf(" %c", &t);
			insere_no(&raiz, t);
		} 
		else if(strcmp(op, "P") == 0){
			scanf(" %c", &t);
			if(busca_no(raiz, t) != NULL) printf("%c existe\n", t);
			else printf("%c nao existe\n", t);
		}
		else if(strcmp(op, "PREFIXA") == 0){
			pre_ordem(raiz, busca_filhos_do_maior(busca_maior(raiz)));
			printf("\n");
		}
		else if(strcmp(op, "INFIXA") == 0){
			em_ordem(raiz, busca_maior(raiz));
			printf("\n");
		}
		else if(strcmp(op, "POSFIXA") == 0){
			pos_ordem(raiz, raiz);
			printf("\n"); 
		}
	}
	   	
    return 0;
}
