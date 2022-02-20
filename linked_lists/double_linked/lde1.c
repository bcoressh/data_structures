#include <stdio.h>
#include <stdlib.h>

struct dupla{
    int chave;
    struct dupla *dprox;
    struct dupla *eprox;
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

int contanos(struct dupla *p)
{
    struct dupla *q;
    int cont = 1;

    if(!p)
        return 0;
    else{
        q = p;
        while(q){
            cont++;
            q = q->dprox;
        }
    }
    return(cont);
}

struct dupla *removek(struct dupla *p, int k)
{
    struct dupla *q, *r;
    int cont = 1;

    if(k == 1){
        if(!p->dprox){
            free(p);
            return(NULL);
        }
        else{
            q = p;
            p = p->dprox;
            p->eprox = NULL;
            free(q);
            return(p);
        }
    }
    else{
        q = p;
        while(cont != k){
            cont++;
            r = q;
            q = q->dprox;
        }
        r->dprox = q->dprox;

        if(q->dprox)
            (q->dprox)->eprox = r;
            
        free(q);
        return(p);
    }
}

struct dupla *copialista(struct dupla *p)
{
    struct dupla *copia, *ini, *ult, *aux;

    ini = ult = NULL;
    aux = p;
    while(aux){
        copia = (struct dupla*)malloc(sizeof(struct dupla));
        copia->chave = aux->chave;
        copia->dprox = copia->eprox = NULL;

        if(ult){
            ult->dprox = copia;
            copia->eprox = ult;
        }
        else
            ini = copia;
        ult = copia;

        aux = aux->dprox;
    }
    return(ini);
}

struct dupla *inserek(struct dupla *p, int k)
{
    struct dupla *n, *q, *r;
    int valor, cont = 1;

    printf("\ndigite o valor a ser inserido:\n");
    scanf("%d", &valor);
    n = (struct dupla*)malloc(sizeof(struct dupla));
    n->chave = valor;
    
    if(!p->dprox){
        n->dprox = p;
        p->eprox = n;
        n->eprox = NULL;
    }
    else{
        q = p;
        while(cont != k){
            q = q->dprox;
            cont++;
        }
        r = q->eprox;
        r->dprox = n;
        n->eprox = r;
        q->eprox = n;
        n->dprox = q;
        
    }
    return(p);
}

void main()
{
    struct dupla *x, *y;
    int n, k;

    printf("\ndigite a quantiadae de nós\n");
    scanf("%d", &n);

    x = cria(n);
    printf("\na lista:\n");
    percurso(x);

    printf("\ndigite um nó para remover:\n");
    scanf("%d", &k);

    x = removek(x, k);
    printf("\na lista:\n");
    percurso(x);

    y = copialista(x);
    printf("\na copia:\n");
    percurso(y);

    printf("\ndigite um nó para inserir:\n");
    scanf("%d", &k);

    y = inserek(y, k);
    printf("\na copia:\n");
    percurso(y);
}
