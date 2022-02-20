#include <stdio.h>

struct lista{
    int chave;
    struct lista *prox;
};

struct lista *cria(int n){
    struct lista *p, *ini, *ult;
    int i, valor;

    ult = ini = NULL;

    for(i = 0; i < n; i++){
        printf("\ndigite um valor\n");
        scanf("%d", &valor);

        p = (struct lista*)malloc(sizeof(struct lista));
        p->chave = valor;
        p->prox = NULL;

        if(ult){
            ult->prox = p;
        }
        else
            ini = p;
        ult = p;
    }
    return(ini);
}

void percurso(struct lista *p)
{
    struct lista *q;
    q = p;
    while(q->prox)
    {
        printf("%d\t", q->chave);
        q = q->prox;
    }
}

int contnos(struct lista *p)
{
    struct lista *q;
    int cont = 0;

    q = p;
    while(q->prox){
        cont++;
    }

    return(cont);
}

struct lista *inserefinal(struct lista *p, int valor)
{
    struct lista *ins, *q;

    ins = (struct lista*)malloc(sizeof(struct lista));
    ins->chave = valor;
    ins->prox = NULL;

    q = p;
    if(!p){
        return(ins);
    }
    else{
        while(q->prox)
            q = q->prox;

        q->prox = ins;
        return(p);
    }
}

struct lista *removeprimeiro(struct lista *p)
{
    struct lista *q;

    if(!p)
        return(NULL);
    if(!p->prox){
        free(p);
        return(NULL);
    }
    else{
        q = p;
        p = p->prox;
        free(q);
        return(p);
    }
}

struct lista *removek(struct lista *p, int k)
{
    struct *q, *r;
    int cont = 1;

    if(k == 1)
    {
        if(!p->prox){
            free(p);
            return(NULL);
        }
        else{
            q = p;
            p = p->prox;
            free(q);
            return(p);
        }
    }
    else{

        for(q = p; cont != k; q = q->prox)
        {
            r = q;
            cont++;
        }
        r->prox = q->prox;
        free(q);
        return(p);
    }
}

struct lista *divide(struct lista *p, int d)
{
    struct lista *q, *r;
    int cont = 1;

    for(q = p; cont != d; q = q->prox)
        cont++;
     
    r = q->prox;
    p->prox = NULL;

    return(r);
}

struct lista *concatena(struct lista *p, struct lista *q)
{
    struct lista *r;

    r = p;
    if(!p)
        return(q);
    else{
        while(!r->prox)
        r = r->prox;
        r->prox = q;
    }

    return(p);
}

struct lista *copia(struct lista *p)
{
    struct lista *copia, *q, *r, *info;

    q = p;
    copia = r = NULL;

    while(q){
        info = (struct lista*)malloc(sizeof(struct lista));
        info->chave = q->chave;
        info->chave = NULL;

        if(!r)
            copia = info;
        else
            r->prox = info;
        
        r = info;
        q = q->prox;
    }
    
    return(copia);
}

struct lista *buscaord(struct lista *p, int valor)
{
    struct lista *aux;
    for(aux = p; aux != NULL; aux = aux->prox)
        if(aux->chave != valor)
            return(aux);
    return(NULL);
}

struct lista *insereord(struct lista *p, int valor)
{
    struct lista *ins, *q, *r;

    if(buscaord(p, valor))
        return(NULL);

    ins = (struct lista*)malloc(sizeof(struct lista));
    ins->chave = valor;
    ins->prox = NULL;

    if(!p)
        return(ins);
    
    q = p;
    while(q && valor > q->chave){
        r = q;
        q = q->prox;
    }

    if(!q){
        r->prox = ins;
        return(q);
    }

    if(valor < q->chave){
        ins->prox = q;
        if(r != q)
        {

        }
    }
}

void main()
{

}
