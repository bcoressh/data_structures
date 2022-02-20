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
        printf("\ndigite um valor:\n");
        scanf("%d", &valor);

        p = (struct dupla*)malloc(sizeof(struct dupla*));
        p->chave = valor;
        p->dprox = p->eprox = NULL;

        if(ult){
            ult->dprox = p;
            p->eprox = ult;
        }
        else{
            ini = p;
        }
        ult = p;
    }
    return(ini);
}

struct dupla *busca(struct dupla *p, int valor)
{
    struct dupla *q;
    for(q = p; q; q = q->dprox){
        if(valor == q->chave)
            return(q);
    }
    return(NULL);
}

struct dupla *insereord(struct dupla *p, int valor)
{
    struct dupla *n, *aux, *aux2;

    if(busca(p, valor))
        return(NULL);

    n = (struct dupla*)malloc(sizeof(struct dupla));
    n->chave = valor;
    n->dprox = n->eprox = NULL;

    if(!p){
        return(n);
    }

    aux = p;
    while(p && valor > p->chave){
        aux2 = p;
        p = p->dprox;
    }

    if(!p){
        aux2->dprox = n;
        n->eprox = aux2;
        return(p);
    }

    if(valor < p->chave)
    {
        n->dprox = p;
        p->eprox = n;
        if(p != aux){
            aux2->dprox = n;
            n->eprox = aux2;
            return(aux2);
        }
        return(p);
    }
}

struct dupla *removeord(struct dupla *p, int valor)
{
    struct dupla *q, *r;

    if(!p)
        return(NULL);

    if(!busca(p, valor))
        return(NULL);
    else{
        q = p;
        while(valor > q->chave){   
            r = q;
            q = q->dprox;
        }

        if(q == p){
            p = p->dprox;
            p->eprox = NULL;
        }
        else{
            r->dprox = q->dprox;
            (q->dprox)->eprox = r;
        }
        free(q);
        return(p);
    }
}

struct dupla *intercala(struct dupla *p, struct dupla *q)
{
    struct dupla *x, *y, *ult, *out;

    if(!p)
        out = q;
    else{
        if(!q)
            out = p;
        else{
            x = p;
            y = q;
            if(x->chave == y->chave){
                out = x;
                x = x->dprox;
                y = y->dprox;
            }
            else if(x->chave > y->chave){
                out = y;
                y = y->dprox;
            }
            else{
                out = x;
                x = x->dprox;
            }
            
            ult = out;
            ult->eprox = NULL;
            while(x && y){
                if(x->chave < y->chave){
                    ult->dprox = x;
                    ult = x;
                    x = x->dprox;
                }
                else if(x->chave > y->chave){
                    ult->dprox = y;
                    ult = y;
                    y = y->dprox;
                }
                else{
                    ult->dprox = y;
                    ult = y;
                    x = x->dprox;
                    y = y->dprox;
                }
            }

            if(!x)
                ult->dprox = y;
            else
                ult->dprox = x;

            return(out);
        }
    }
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

void main()
{
    struct dupla *x, *y, *z;
    int n;

    printf("\ndigite a quantidade de nós:\n");
    scanf("%d", &n);
    x = cria(n);

    printf("\na lista x:\n");
    percurso(x);

    printf("\ndigite a quantidade de nós:\n");
    scanf("%d", &n);
    y = cria(n);

    printf("\na lista y:\n");
    percurso(y);

    z = intercala(x, y);

    printf("\nlista intercalada\n");
    percurso(z);
}