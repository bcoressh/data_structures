#include <stdio.h>

struct lista{
    int chave;
    struct lista *prox;
};

struct lista *cria(int n)
{
    struct lista *p, *ini, *ult;
    int i, valor;

    ult = ini = NULL;

    for(i = 0; i < n; i++)
    {
        printf("\ndigite um valor\n");
        scanf("%d", &valor);

        p = (struct lista*)malloc(sizeof(struct lista));
        p->chave = valor;
        p->prox = NULL;

        if(!ult){
            p->prox = p;
            ini = p;
        }
        else{
            ult->prox = p;
            p->prox = ini;
        }
        ult = p;
    }

    return(ult);
}

void percurso(struct lista *p)
{
    struct lista *q;

    if(!p)
        return;
    else{
        q = p;
        while(q != p)
        {
            printf("%d\t", q->chave);
            q = q->prox;
        }
    }
}

int contanos(struct lista *p)
{
    struct lista *q;
    int cont = 0;

    q = p;
    while(q != p)
    {
        cont++;
        q = q->prox;
    }

    return(cont);
}

struct lista *insere_frente(struct lista *p, int valor)
{
    struct lista *ins;

    ins = (struct lista*)malloc(sizeof(struct lista));
    ins->chave = valor;
    ins->prox = NULL;

    if(!p)
    {
        ins->prox = ins;
        return(ins);
    }
    else{
        ins->prox = p->prox;
        p->prox = ins;
        return(p);
    }
}

struct lista *removek(struct lista *p, int k)
{
    struct lista *q, *r;
    int cont = 1;

    if(!p)
        return(NULL);

    if(k == 1){
        if(p == p->prox){
            free(p);
            return(NULL);
        }
        else{
            q = p->prox;
            p->prox = q->prox;
            free(q);
            return(p);
        }
    }
    else{
        for(q = p->prox; cont != k; q = q->prox){
            r = q;
            cont++;
        }
        r->prox = q->prox;

        if(p == q){ //ultimo
            free(q);
            return(r);
        }
        else{
            free(q);
            return(p);
        }
    }
}

struct lista *inserek(struct lista *p, int valor, int k)
{
    struct lista *ins, *q;
    int cont = 1;

    ins = (struct malloc*)malloc(sizeof(struct lista));
    ins->chave = valor;

    if(!p){
        ins->prox = ins;
        return(ins);
    }

    for(q = p; cont != k; q = q->prox)
        cont++;

    ins->prox = q->prox;
    q->prox = ins;

    if(p != q)
        return(p);
    else
        return(q);
}