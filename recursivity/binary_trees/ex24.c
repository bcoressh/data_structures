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
    int value;

    n = (struct tree*)malloc(sizeof(struct tree));
    n->chave = valor;
    n->esq = n->dir = NULL;

    if(!p)
        p = n;
    else{
        q = p;
        value = 0;
        while(!value)
        {
            if(valor < q->chave){
                if(!q->esq){
                    q->esq = n;
                    value = 1;
                }
                else
                    q = q->esq;
            }
            else{
                if(!q->dir){
                    q->dir = n;
                    value = 1;
                }
                else
                    q = q->dir;
            }
        }
    }
    return(p);
}

void preorder(struct tree *p)
{
    if(p){
        printf("%d\t", p->chave);
        preorder(p->esq);
        preorder(p->dir);
    }
}

int maiorquezero(struct tree *p)
{
    int cont = 0;

    if(!p)
        return 0;
    else{
        cont = maiorquezero(p->dir);
        if(p->chave > 0)
            cont++;
        return(cont);
    }
}

int altura(struct tree *p)
{
    int x, y;

    if(!p)
        return 0;

    x = (1 + altura(p->dir));
    y = (1 + altura(p->dir));

    if(x > y)
        return(x);
    else
        return(y);
}

int paideum(struct tree *p)
{
    if(!p)
        return 0;
    if((p->dir == NULL && p->esq == NULL))
        return 0;
    if((p->dir != NULL && p->esq != NULL))
        return(paideum(p->dir) + paideum(p->esq));
    return(1 + paideum(p->dir) + paideum(p->esq));
}

struct tree *abb(struct tree *p)
{
    struct tree *x, *y;

    x = abb(p->dir);
    y = abb(p->esq);
    if(p){
        if(x->chave < p->chave)
            return(NULL);
        if(y->chave > p->chave)
            return(NULL);
    }
}

void main()
{
    struct tree *x;
    int n, i, cont, h, pai;

    x = NULL;

    for(i = 0; i < 5; i++)
    {
        printf("\ndigite um valor\n");
        scanf("%d", &n);

        x = insere(x, n);
    }

    preorder(x);

    h = altura(x);
    cont = maiorquezero(x);
    pai = paideum(x);
    printf("\na altura da árvore: %d\n", h);
    printf("\nquantidade de elementos maiores que zero: %d\n", cont);
    printf("\nquantidade de nós pais de um único filho: %d\n", pai);

    free(x);
}