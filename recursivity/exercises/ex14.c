#include <stdio.h>
#include <stdlib.h>

struct lista{
    int chave;
    struct lista *prox;
};

int minimo(struct lista *p)
{
    struct lista *q;
    int menor;
    
    q = p;
    if(!q->prox)
        menor = q->chave;
    else
    {
        menor = minimo(q->prox);
        if(menor > (q->prox)->chave)
            menor = (q->prox)->chave;
    }

    return(menor);
    
}

struct lista *cria(int n)
{
    struct lista *p, *ini, *ult;
    int i, valor;

    ini = ult = NULL;
    for(i = 0; i < n; i++)
    {
        printf("\ndigite um valor para inserir\n");
        scanf("%d", &valor);

        p = (struct lista*)malloc(sizeof(struct lista));
        p->chave = valor;
        p->prox = NULL;

        if(ult)
            ult->prox = p;
        else
            ini = p;
        ult = p;
    }

    return(ini);
}

void main()
{
    struct lista *x;
    int n;

    printf("\ndigite a quantidade de nós:\n");
    scanf("%d", &n);

    x = cria(n);

    printf("\nmenor elemento: %d\n", minimo(x));
}