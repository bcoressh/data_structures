#include <stdio.h>
#include <stdlib.h>

struct dupla{
    int chave;
    struct dupla *eprox;
    struct dupla *dprox;
};

struct dupla *cria(int n)
{
    struct dupla *p, *ini, *ult;
    int i, valor;

    ini = ult = NULL;
    for(i = 0; i < n; i++)
    {
        printf("\ndigite um valor\n");
        scanf("%d", &valor);

        p = (struct dupla*)malloc(sizeof(struct dupla));
        p->chave = valor;
        p->dprox = p->eprox = NULL;

        if(ult){
            ult->dprox = p;
            p->eprox = ult;
        }
        else
            ini = p;
        ult = p;
    }

    return(ini);
}

void percurso(struct dupla *p)
{
    struct dupla *q;
    q = p;
    while(q){
        printf("%d\t", q->chave);
        q = q->dprox;
    }
}

struct dupla *inverte(struct dupla *p)
{
    struct dupla *q, *r, *s;
    s = p;
    q = NULL;
    while(s){
        r = p->dprox;
        s->dprox = q;
        q = s;
        s = r;
    }
    p = r;
    return(p);
}

void main()
{
    struct dupla *x, *y;
    int n;

    printf("\ndigite a quantidade de elementos:\n");
    scanf("%d", &n);

    x = cria(n);

    printf("\nlista:\n");
    percurso(x);

    y = inverte(x);

    printf("\nlista:\n");
    percurso(y);
}