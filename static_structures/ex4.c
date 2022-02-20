#include <stdio.h>

#define size 10

struct pilha{
    int topo;
    int pilha[size];
};

struct cont{
    int ini, fim, cont;
    int fila[size];
};

void inicializapilha(struct pilha *p)
{
    p->topo = -1;
}

int pilhacheia(struct pilha *p)
{
    if(p->topo == size - 1)
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

void inicializacont(struct cont *f)
{
    f->ini = 0;
    f->fim = -1;
    f->cont = 0;
}

int contvazia(struct cont *f)
{
    if(f->cont == 0)
        return 1;
    return 0;
}

int contcheia(struct cont *f)
{
    if(f->cont == size - 1)
        return 1;
    return 0;
}

int inserecont(struct cont *f, int valor)
{
    if(contcheia(f))
        return 0;

    f->cont++;
    f->fim = (f->fim == size - 1) ? 0: f->fim + 1;
    f->fila[f->fim] = valor;
    return 1;
}

int removecont(struct cont *f, int *elem)
{
    if(contvazia(f))
        return 0;

    f->cont--;
    *elem = f->fila[f->ini];
    f->ini = (f->ini == size - 1) ? 0: f->ini + 1;
    return 1;
}

void scanvaluescont(struct cont *f)
{
    int valor;

    do{
        printf("\ndigite um valor:\n");
        scanf("%d", &valor);

        inserecont(f, valor);
    }while(valor != 0);
}

void scanvaluespilha(struct pilha *p)
{
    int valor;

    do{
        printf("\ndigite um valor:\n");
        scanf("%d", &valor);

        empilha(p, valor);
    }while(valor != 0);
}

void printpilha(struct pilha *p)
{
    int i;

    for(i = 0; i <= p->topo; i++)
    {
        printf("%d\t", p->pilha[i]);
    }
}

void printcont(struct cont *f)
{
    int i;

    for(i = 0; i < f->cont; i++)
    {
        printf("%d\t", f->fila[i]);
    }
}

void infocont(struct cont *f)
{
    int i, maior = 0, menor = 0, media = 0;

    for(i = 0; i < f->cont; i++)
    {
        if(maior < f->fila[i])
            maior = f->fila[i];
        if(menor > f->fila[i])
            menor = f->fila[i];
        media = (media + f->fila[i]);
    }

    printf("\n%d\n", f->cont);
    media = media/(f->cont - 1);

    printf("\nmaior elemento da fila: %d\n", maior);
    printf("\nmenor elemento da fila: %d\n", menor);
    printf("\nmedia  da fila: %.2f\n", (float)media);
}

void infopilha(struct pilha *p)
{
    int i, maior = 0, menor = 0, media = 0;

    for(i = 0; i <= p->topo; i++)
    {
        if(maior < p->pilha[i])
            maior = p->pilha[i];
        if(menor > p->pilha[i])
            menor = p->pilha[i];
        media = (media + p->pilha[i]);
    }

    media = media/p->topo;

    printf("\nmaior elemento da pilha: %d\n", maior);
    printf("\nmenor elemento da pilha: %d\n", menor);
    printf("\nmedia da pilha: %.2f\n", (float)media);
}


void main()
{
    struct pilha x;
    struct cont y;

    inicializapilha(&x);
    inicializacont(&y);

    printf("\npreencha a pilha:\n");
    scanvaluespilha(&x);
    printf("\na pilha:\n");
    printpilha(&x);


    printf("\npreencha a fila:\n");
    scanvaluescont(&y);
    printf("\na fila:\n");
    printcont(&y);

    infopilha(&x);
    infocont(&y);
}