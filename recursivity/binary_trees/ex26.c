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
    n->dir = n->esq = NULL;
    
    if(!p)
        p = n;
    else{
        q = p;
        value = 0;
        while(!value)
        {
            if(valor < q->chave){
                if(q->esq == NULL){
                    q->esq = n;
                    value = 1;
                }
                else
                    q = q->esq;
            }
            else{
                if(q->dir == NULL){
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

int equal(struct tree *p, struct tree *q)
{
    if(p && q){
        equal(p->dir, q->dir);
        equal(p->esq, q->esq);
        if(q->chave == p->chave){
            return 1;
        }
        else{
            return 0;
        }
    }
}

void preorder(struct tree *p)
{
    if(p){
        printf("%d\t", p->chave);
        preorder(p->esq);
        preorder(p->dir);
    }
}

void main()
{
    struct tree *x, *y;
    int i, n;

    x = y = NULL;

    printf("\npreencha a primeira árvore:\n");
    for(i = 0; i < 6; i++)
    {
        printf("\ndigite valor:\n");
        scanf("%d", &n);

        x = insere(x, n);
    }

    preorder(x);

    printf("\npreencha a segunda árvore:\n");
    for(i = 0; i < 6; i++)
    {
        printf("\ndigite valor:\n");
        scanf("%d", &n);

        y = insere(y, n);
    }
    preorder(y);

    if(equal(x, y) == 1)
        printf("\nsão iguais\n");
    else
        printf("\nnão são iguais\n");

    free(x);
    free(y);
}