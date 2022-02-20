#include <stdio.h>

#define size 100

struct bobo{
    int f, r;
    int fila[size];
};

void inicializab(struct bobo *p)
{
    p->f = 0;
    p->r = 0;
}

int bobocheia(struct bobo *p)
{
    if((p->r + 1)%size == p->f)
        return 1;
    return 0;
}

int bobovazia(struct bobo *p)
{
    if(p->r == p->f)
        return 1;
    return 0;
}

int inserebobo(struct bobo *p, int valor)
{
    if(bobocheia(p))
        return 0;
    
    p->r = (p->r + 1)%size;
    p->fila[p->r] = valor;
    return 1;
}

int removebobo(struct bobo *p, int *elem)
{
    if(bobovazia(p))
        return 0;
    
    p->f = (p->f + 1)%size;
    *elem = p->fila[p->f];
    return 1;
}

