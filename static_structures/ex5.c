#include <stdio.h>
#include <stdlib>

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
        printf("\ndigite um valor\n");
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

struct lista *busca(struct lista *p, int valor)
{
    struct lista *q;
    for(q = p; q; q = q->prox)
    {
        if(valor == q->chave)
            return(p);
    }
    return(NULL);
}

struct lista *insere_ordenada(struct lista *p, int valor)
{
    struct lista *n, *q;

    if(busca(p, valor))
        return(p);

    n = (struct lista*)malloc(sizeof(struct lista));
    n->chave = valor;

    if(!p){
        n->prox = NULL;
        return(n);
    }
    else{
        q = p;
        while(q && valor < q->chave){
            r = q;
            q = q->prox;
        }
        
        if(!q){
            r->prox = n;
            n->prox = NULL;
            return(q);
        }

        if(valor < q->chave)
        {
            n->prox = q;
            if(q != p){
                r->prox = n;
                return(q);
            }
            return(n);
        }

    }
}

struct lista *removeord(struct lista *p, int valor)
{
    struct lista *q, *r;

    if(!p)
        return(NULL);
    
    if(!busca(p, valor))
        return(p);
    else{
        q = p;
        while(q && valor < q->chave)
        {
            r = q;
            q = q->rpox;
        }
        
        if(q != p)
            r->prox = q->prox;
        else
            p = p->prox;
        
        free(q);
        return(p);

    }
}

void main()
{

}