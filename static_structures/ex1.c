#include <stdio.h>

#define s 100

struct pilha{
    int topo;
    int pilha[s];
};

void inicializa(struct pilha *p)
{
    p->topo = -1;
}

int pilha_vazia(struct pilha *p)
{
    if(p->topo == -1)
        return 1;
    return 0;
}

int pilha_cheia(struct pilha *p)
{
    if(p->topo == s - 1)
        return 1;
    return 0;
}

int empilha(struct pilha *p, int chave)
{
    if(pilha_cheia(p))
        return 0;
    
    p->topo++;
    p->pilha[p->topo] = chave;
    return 1; 
}

int desempilha(struct pilha *p, int *e)
{
    if(pilha_vazia(p))
        return 0;

    *e = p->pilha[p->topo];
    p->topo--;
    return 1;
}

void invert(struct pilha *p, struct pilha *aux)
{
    int i, n;

    for(i = aux->topo; i > -1; i--)
    {
        desempilha(aux, &aux->pilha[i]);
        printf("%d\t", aux->pilha[i]);
        n = aux->pilha[i];
    }

    for(i = 0; i <= p->topo; i++)
    {
        empilha(p, n);
    }
}

void binary(struct pilha *p, int n)
{
    struct pilha *aux;
    inicializa(aux);

    while(n/2 > 0)
    {
        empilha(aux, n%2);
        n = n/2;
    }
    empilha(aux, n);

    invert(p, aux);
}

void printinscreen(struct pilha *p)
{
    int i;
    for(i = 0; i <= p->topo; i++)
    {
        printf("%d\t", p->pilha[i]);
    }
}

void main()
{
    struct pilha x;
    int n, i;

    inicializa(&x);

    printf("\nenter a number\n");
    scanf("%d", &n);

    binary(&x, n);

    printinscreen(&x)
}