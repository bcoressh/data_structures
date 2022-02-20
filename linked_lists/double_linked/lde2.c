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
    int valor, i;

    ini = ult = NULL;

    for(i = 0; i < n; i++)
    {
        printf("\ndigite o valor\n");
        scanf("%d", &valor);

        p = (struct dupla*)malloc(sizeof(struct dupla));
        p->chave = valor;

        if(ini){
            ult->dprox = p;
            ini->eprox = p;
            p->eprox = ult;
            p->dprox = ini;
        }
        else{
            ini = p;
            p->dprox = ini;
            p->eprox = ini;
        }
        ult = p;
    }

    return(p);
}

void percurso(struct dupla *p)
{
    struct dupla *q;
    q = p->dprox;

    if(!p)
        printf("\nvazio\n");
    else{
        while(q != p){
            printf("%d\t", q->chave);
            q = q->dprox;
        }
        if(q == p){
            printf("%d\t", q->chave);
            q = q->dprox;
        }
    }
}  

int contanos(struct dupla *p)
{
    struct dupla *q;
    int cont = 1;

    q = p->dprox;
    while(q != p){
        cont++;
    }
    return(cont);
}

struct dupla *removex(struct dupla *p, int x)
{
    struct dupla *q, *r;
    int cont = 1;


    if(!p)
        return(NULL);

    if(x == 1){
        if(!p->dprox){
            free(p);
            return(NULL);
        }
        else{
            q = p->dprox;
            (q->dprox)->eprox = p;
            p->dprox = q->dprox;
            free(q);
            return(p);
        }
    }
    else{
        for(q = p->dprox; cont != x; q = q->dprox){
            r = q;
            cont++;
        }
        r->dprox = q->dprox;
        (q->dprox)->eprox = r;

        free(q);
        return(p);
    }
}

struct dupla *insereinicio(struct dupla *p, int valor)
{
    struct dupla *n;

    n = (struct dupla*)malloc(sizeof(struct dupla));
    n->chave = valor;

    if(!p){
        n->dprox = n->eprox = n;
        return(n);
    }
    else{
        (p->dprox)->eprox = n;
        n->dprox = p->dprox;
        p->dprox = n;
        n->eprox = p;

        return(p);
    }
}

struct dupla *inserefinal(struct dupla *p, int valor)
{
    struct dupla *n;

    n = (struct dupla*)malloc(sizeof(struct dupla));
    n->chave = valor;

    if(!p){
        n->dprox = n->eprox = n;
        return(n);
    }
    else{
        (p->dprox)->eprox = n;
        n->dprox = p->dprox;
        p->dprox = n;
        n->eprox = p;
        p = p->dprox;

        return(p);
    }
}

void main()
{
    struct dupla *x;
    int n;

    printf("\ndigite a quantidade de nós:\n");
    scanf("%d", &n);

    x = cria(n);

    printf("\na lista:\n");
    percurso(x);

    printf("\ndigite elemento para retirar:\n");
    scanf("%d", &n);

    x = removex(x, n);

    printf("\na lista:\n");
    percurso(x);

    printf("\ndigite um valor para inserir no inicio:\n");
    scanf("%d", &n);

    x = insereinicio(x, n);

    printf("\na lista:\n");
    percurso(x);

    printf("\ndigite um valor para inserir no final:\n");
    scanf("%d", &n);

    x = inserefinal(x, n);

    printf("\na lista:\n");
    percurso(x);
}