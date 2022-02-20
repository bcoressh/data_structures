#include <stdio.h>
#include <stdlib.h>

struct tree{
    int chave;
    struct tree *esq;
    struct tree *dir;
};

struct tree *insere(struct tree *p, int valor)
{
    struct tree *n, *q;

    n = (struct tree*)malloc(sizeof(struct tree));
    n->chave = valor;
    n->esq = n->dir = NULL;

    if(!p)
        p = n;
    q = p;
    if(valor < q->chave){
        if(!q->esq)
            q->esq = n;
        else
            insere(q->esq, valor);
    }
    else{
        if(!q->dir)
            q->dir = n;
        else
            insere(q->dir, valor);
    }
    return(p);

}

struct tree *busca(struct tree *p, int valor)
{
    if(p){
        if(valor == p->chave)
            return(p);
        if(valor < p->chave)
            return(busca(p->esq, valor));
        else
            return(busca(p->dir, valor));
    }
    return(NULL);
}

void inorder(struct tree *p)
{
    if(p){
        inorder(p->esq);
        printf("%d\t", p->chave);
        inorder(p->dir);
    }
}

void main()
{
    struct tree *x;
    int i, n;

    x = NULL;

    for(i = 0; i < 6; i++)
    {
        printf("\ndigite um valor\n");
        scanf("%d", &n);

        x = insere(x, n);
    }

    printf("\na árvore:\n");
    inorder(x);

}