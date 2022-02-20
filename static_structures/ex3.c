#include <stdio.h>

#define s 50

struct fila{
    int f, r;
    int fila[s];
};

struct pilha{
    int topo;
    int pilha[s];
};

void inicializapilha(struct pilha *p)
{
    p->topo = -1;
}

int pilhacheia(struct pilha *p)
{
    if(p->topo == s - 1)
        return 1;
    return 0;
}

int pilhavazia(struct pilha *p)
{
    if(p->topo == -1)
        return 1;
    return 0;
}

int empilha(struct pilha *p, int valor)
{
    if(pilhacheia(p))
        return 0;

    p->pilha[++p->topo] = valor;
    return 1;
}

int desempilha(struct pilha *p, int *elem)
{
    if(pilhavazia(p))
        return 0;

    *elem = p->pilha[p->topo--];
    return 1;
}

void inicializafila(struct fila *fs)
{
    fs->f = 0;
    fs->r = -1;
}

int filavazia(struct fila *fs)
{
    if(fs->f > fs->r)
        return 1;
    return 0;
}

int filacheia(struct fila *fs)
{
    if(fs->r == s - 1)
        return 1;
    return 0;
}

int inserefila(struct fila *fs, int valor)
{
    if(filacheia(fs))
        return 0;
    
    fs->fila[++fs->r] = valor;
    return 1;
}

int removefila(struct fila *fs, int *elem)
{
    if(filavazia(fs))
        return 0;
    
    *elem = fs->fila[fs->f++];
    return 1;
}

void print_fila(struct fila *fs)
{
    int i;
    for(i = 0; i <= fs->r; i++)
    {
        printf("%d\t", fs->fila[i]);
    }
}

void print_pilha(struct pilha *p)
{
    int i;
    for(i = 0; i <= p->topo; i++)
    {
        printf("%d\t", p->pilha[i]);
    }
}

void main()
{
    struct fila par, impar;
    struct pilha p;
    int n, cont = 0, i;

    inicializafila(&par);
    inicializafila(&impar);
    inicializapilha(&p);

    do{
        printf("\ndigite um numero inteiro\n");
        scanf("%d", &n);

        if(n%2 == 0) 
            inserefila(&par, n);
        else
            inserefila(&impar, n);

        cont++;
    }while(n != 0);

    printf("\nfila par:\n");
    print_fila(&par);

    printf("\nfila impar:\n");
    print_fila(&impar);

    for(i = 0; i < cont; i++)
    {
        if(i%2 == 0)
            removefila(&impar, &n);
        else
            removefila(&par, &n);
        
        if(n > 0)
            empilha(&p, n);
        
    }

    printf("\npilha com elementos positivos:\n");
    print_pilha(&p);

}