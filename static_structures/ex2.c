#include <stdio.h>

#define s 10

struct fila{
    int fr, r;
    int fila[s];
};

struct pilha{
    int topo;
    int pilha[s];
};

void inicializap(struct pilha *p)
{
    p->topo = -1;
}

int pilha_vazia(struct pilha *p)
{
    if(p->topo == 1)
        return 1;
    return 0;
}

int pilha_cheia(struct pilha *p)
{
    if(p->topo == s - 1)
        return 1;
    return 0;
}

int empilha(struct pilha *p, int valor)
{
    if(pilha_cheia(p))
        return 0;

    p->pilha[++p->topo] = valor;
    return 1;
}

int desempilha(struct pilha *p, int *e)
{
    if(pilha_vazia(p))
        return 0;
    
    *e = p->pilha[p->topo--];
    return 1;
}

void inicializaf(struct fila *f)
{
    f->fr = 0;
    f->r = -1;
}

int fila_vazia(struct fila *f)
{
    if(f->fr > f->r)
        return 1;
    return 0;
}

int fila_cheia(struct fila *f)
{
    if(f->r == s - 1)
        return 1;
    return 0;
}

int insere_fila(struct fila *f, int valor)
{
    if(fila_cheia(f))
        return 0;

    f->fila[++f->r] = valor;
    return 1;
}

int remove_fila(struct fila *f, int *e)
{
    if(fila_vazia(f))
        return 0;

    *e = f->fila[f->fr++];
    return 1;
}

void scan_values(struct fila *f)
{
    int i, n;

    for(i = 0; i < 10; i++)
    {
        printf("\ndigite elemento %d\n", i);
        scanf("%d", &n);

        insere_fila(f, n);
    }

}

void print_values(struct fila *f)
{
    int i;
    for(i = 0; i < s; i++)
    {
        printf("%d\t", f->fila[i]);
    }
}

void invert(struct fila *f, struct pilha *p)
{
    int i, n;

    for(i = 0; i < s; i++)
    {
        remove_fila(f, &n);
        empilha(p, n);
    }

    inicializaf(f);

    for(i = 0; i < s; i++)
    {
        desempilha(p, &n);
        insere_fila(f, n);
    }
}

void main()
{
    struct pilha aux;
    struct fila x;

    inicializaf(&x);
    inicializap(&aux);

    scan_values(&x);
    printf("\nfila inicial:\n");
    print_values(&x);
    printf("\n");


    invert(&x, &aux);
    printf("\nfila invertida:\n");
    print_values(&x);
    printf("\n");
}


