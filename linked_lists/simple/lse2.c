#include <stdio.h>
#include <stdlib.h>

struct lista{
    int chave;
    struct lista *prox;
};

struct lista *cria(int n)
{
    struct lista *p, *ini, *ult;
    int i, valor;

    ini = ult = NULL;

    for(i = 0; i < n; i++)
    {
        printf("\ndigite o valor:\n");
        scanf("%d", &valor);

        p = (struct lista*)malloc(sizeof(struct lista));
        p->chave = valor;
        p->prox = NULL;

        if(ult)
            ult->prox = p;
        else
            ini = p;
        ult = p;
    }
    return(ini);
}

struct lista *intercala(struct lista *p, struct lista *q)
{
    struct lista *r, *s, *i, *ini, *ult;

    ini = ult = NULL;

    r = p;
    s = q;
    while(r && s){
        i = (struct lista*)malloc(sizeof(struct lista));
        if(r->chave <= s->chave){
            i->chave = r->chave;
            r = r->prox;
        }
        else{
            i->chave = s->chave;
            s = s->prox;
        }

        if(ult)
            ult->prox = i;
        else
            ini = i;
        ult = i;
    }

    while(r){
        i = (struct lista*)malloc(sizeof(struct lista));
        i->chave = r->chave;
        i->prox = NULL;

        ult->prox = i;
        ult = i;

        r = r->prox;
    }

    while(s){
        i = (struct lista*)malloc(sizeof(struct lista));
        i->chave = s->chave;
        i->prox = NULL;

        ult->prox = i;
        ult = i;

        s = s->prox;
    }

    return(ini);
}

void percurso(struct lista *p)
{
    struct lista *q;
    q = p;
    while(q){
        printf("%d\t", q->chave);
        q = q->prox;
    }
    printf("\n");
}

void main()
{
    struct lista *x, *y, *z;
    int n;

    printf("\ndigite a quantidade de nós de x:\n");
    scanf("%d", &n);
    x = cria(n);

    printf("\na lse x:\n");
    percurso(x);

    printf("\ndigite a quantidade de nós de y:\n");
    scanf("%d", &n);
    y = cria(n);

    printf("\na lse y:\n");
    percurso(y);

    z = intercala(x, y);
    printf("\na intercalação:\n");
    percurso(z);

}