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

    ini = NULL;

    for(i = 1; i <= n; i++)
    {
        printf("\ndigite um valor:\n");
        scanf("%d", &valor);

        p = (struct lista*)malloc(sizeof(struct lista));
        p->chave = valor;

        if(ini){
            p->prox = ini;
            ult->prox = p;
        }
        else{
            p->prox = p;
            ini = p;
        }
        ult = p;
    }

    return(p);
}

void percurso(struct lista *p)
{
    struct lista *q;
    q = p->prox;

    if(!p)
        printf("\nlista vazia\n");
    else{
        while(q != p)
        {
            printf("%d\t", q->chave);
            q = q->prox;
        }
        if(q == p)
            printf("%d\t", q->chave);
    }
}

int cont(struct lista *p)
{
    struct lista *q;
    int cont = 1;

    if(!p)
        return 0;
    else{
        q = p->prox;
        while(q->prox != p){
            cont++;
        }
    }
    return(cont);
}

struct lista *removek(struct lista *p, int k)
{
    struct lista *q, *r;
    int cont = 1;

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
        q = p->prox;
        while(cont != k){
            r = q;
            q = q->prox;
            cont++;
        }
        r->prox = q->prox;
        
        if(p == q){
            free(q);
            return(r);
        }
        else{
            free(q);
            return(p);
        }
    }
}

struct lista *copialista(struct lista *p)
{
    struct lista *copia, *ini, *ult, *aux;
    
    ini = NULL;
    aux = p->prox;
    while(aux != p){
        copia = (struct lista*)malloc(sizeof(struct lista));
        copia->chave = aux->chave;

        if(ini){
            ult->prox = copia;
            copia->prox = ini;
        }
        else{
            copia->prox = copia;
             ini = copia;
        }
        ult = copia;

        aux = aux->prox;
    }
    if(aux == p){
        copia = (struct lista*)malloc(sizeof(struct lista));
        copia->chave = aux->chave;
        ult->prox = copia;
        copia->prox = ini;
    }
    return(copia);
}


void main()
{
    struct lista *x, *y;
    int n, c, k;

    printf("\ndigite a quantidade de nós:\n");
    scanf("%d", &n);

    x = cria(n);
    printf("\nlista:\n");
    percurso(x);

    printf("\ndigite um nó para remover:\n");
    scanf("%d", &k);

    x = removek(x, k);
    printf("\nlista:\n");
    percurso(x);

    y = copialista(x);
    printf("\ncopia:\n");
    percurso(y);
}