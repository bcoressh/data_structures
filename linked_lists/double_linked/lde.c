#include <stdio.h>

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
        p->eprox = p->dprox = NULL;

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

struct dupla *inseredois(struct dupla *p, int valor)
{
    struct dupla *ins, *q;

    ins = (struct dupla*)malloc(sizeof(struct dupla));
    ins->chave = valor;
    
    if(!p){
        ins->dprox = ins->eprox = NULL;
        return(ins);
    }
    if(!p->dprox){
        ins->dprox = p->dprox;
        p->dprox = ins;
        ins->eprox = p;
    }
    else{
        q = p->dprox;
        ins->dprox = q;
        q->eprox = ins;
        p->dprox = ins;
        ins->eprox = p;
    }
    return(p);
}

struct dupla *removek(struct dupla *p, int k)
{
    struct dupla *q, *r, *s;
    int cont = 1;

    if(k == 1)
    {
        if(!p->dprox){
            free(p);
            return(NULL;)
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
        for(q = p; cont != k; q = q->prox)
            cont++;

        r = p->eprox;
        s = p->dprox;

        if(s)
            s->eprox = r;

        free(q);
        return(p);
    }
}

void percurso(struct dupla *p)
{
    struct dupla *q;
    
    q = p;
    while(q)
    {
        printf("%d\t", q->chave);
        q = q->dprox;
    }
}

//função para inserir um nó apontado por p, após um nó apontado por x, onde x para algum nó da lde não vazia.
void insereno(struct dupla *x, struct dupla *p)
{
    if(x->dprox == NULL)
        (x->dprox)->eprox = p;

    p->dprox = x->dprox;
    x->dprox = p;
    p->eprox = x;
}

//função para remover um nó apontador por x de uma lde nao vazia, onde l aponta para o ínicio da lista.
//retornar ponteiro para a lista resultante.
struct dupla *removeno(struct dupla *x, struct dupla *p)
{
    if(x == l){
        if(l->dprox == NULL){
            free(x);
            return(NULL);
        }
        else{
            l = l->dprox;
            l->eprox = NULL;
            free(x);
            return(l);
        }
    }
    else{
        if(x->dprox == NULL)
            (x->eprox)->dprox = NULL;
        else{
            (x->eprox)->dprox = x->dprox;
            (x->dprox)->eprox = x->eprox;
        }
        free(x);
        return(l);
    }
}