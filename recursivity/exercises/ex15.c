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

struct lista *copialista(struct lista *p)
{
    struct lista *copia, *info, *aux, *ult;

    copia = ult = NULL;
    aux = p;
    
    if(aux){
        if(ult)
            ult->prox = aux->prox;
        else
            copia = info;
        ult = info;

        info = (struct lista*)malloc(sizeof(struct lista));
        info->chave = aux->chave;
        info->prox = NULL;
        info = copialista(aux->prox);
    }
        
    return(copia);
}

void percurso(struct lista *p)
{
    struct lista *q;
    q = p;
    if(q)
    {
        printf("%d\t", q->chave);
        percurso(q->prox);
    }
}

void main()
{
    struct lista *x, *cp;
    int n;

    printf("\ndigite a quantidade de nós:\n");
    scanf("%d", &n);

    x = cria(n);

    printf("\na lista:\n");
    percurso(x);

    cp = copialista(x);

    printf("\na copia:\n");
    percurso(cp);

}