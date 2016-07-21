/*
*
*   Desenvolvido por Victor Hugo Braguim Canto
*
*/
#include <stdio.h>
#include <stdlib.h>
int count=0;
typedef struct nodo{
    int chave;
    struct nodo *dir;
    struct nodo *esq;
}nodo;
void insereNo(nodo **raiz, int no){
    if((*raiz)==NULL){
        (*raiz) = (nodo *)(malloc(sizeof(nodo)));
        if((*raiz)!=NULL){
            ((*raiz)->chave) = no;
            ((*raiz)->dir) = NULL;
            ((*raiz)->esq) = NULL;
        }
        else
            return;
    }
    else{
        if(no>((*raiz)->chave))
            return insereNo(&(*raiz)->dir,no);
        else
            return insereNo(&(*raiz)->esq,no);
    }
}
void preOrdem(nodo **raiz, int h){
    printf("%d", ((*raiz)->chave));
    if(count==(h-1))
        printf("\n");
    else
        printf(" ");
    count++;
    if(((*raiz)->esq)!=NULL)
        preOrdem(&((*raiz)->esq),h); 
    if(((*raiz)->dir)!=NULL)
        preOrdem(&((*raiz)->dir),h);
}
void inOrdem(nodo **raiz, int h){
    if(((*raiz)->esq)!=NULL)
        inOrdem(&((*raiz)->esq),h);
    printf("%d", ((*raiz)->chave));
    if(count==(h-1))
        printf("\n");
    else
        printf(" ");
    count++;
    if(((*raiz)->dir)!=NULL)
        inOrdem(&((*raiz)->dir),h);
}
void posOrdem(nodo **raiz, int h){
    if(((*raiz)->esq)!=NULL)
        posOrdem(&((*raiz)->esq),h); 
    if(((*raiz)->dir)!=NULL)
        posOrdem(&((*raiz)->dir),h);
    printf("%d", ((*raiz)->chave));
    if(count==(h-1))
        printf("\n");
    else
        printf(" ");
    count++;
}
 
int main(void)
{
    int C, N, i=0, j=0, no;
    nodo *raiz;
    raiz = NULL;
    scanf("%d", &C);
    while(i<C){
        scanf("%d", &N);
        while(j<N){
            scanf("%d", &no);
            insereNo(&raiz,no);
            j++;
        }
        printf("Case %d:\n", i+1);
        printf("Pre.: ");
        preOrdem(&raiz,N);
        count=0;
        printf("In..: ");
        inOrdem(&raiz,N);
        count = 0;
        printf("Post: ");
        posOrdem(&raiz,N);
        count = 0;
        if(i!=(C-1))
           printf("\n");
        raiz = NULL;
        j=0;
        i++;
    }
    printf("\n");
    return 0;
}
