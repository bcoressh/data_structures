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

    for(i = 0; i < n; i++)
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

struct lista *metade(struct lista *p, int n)
{
    struct lista *aux, *ini, *meio, *ult; 
    int cont = 1;

    aux = p->prox;
    ini = p->prox;
    ult = p;

    while(cont != n/2){
        aux = aux->prox;
        cont++;
    }

    meio = aux->prox;
    aux->prox = ini;
    ult->prox = meio;

    return(aux);
}

void percurso(struct lista *p)
{
    struct lista *q;

    q = p->prox;
    while(q != p){
        printf("%d\t", q->chave);
        q = q->prox;
    }
    if(q == p)
        printf("%d\t", q->chave);
}

void main()
{
    struct lista *x, *y;
    int n;

    printf("\ndigite a quantidade de nós:\n");
    scanf("%d", &n);

    x = cria(n);
    printf("\na lista:\n");
    percurso(x);

    y = metade(x, n);

    printf("\nprimeira metade:\n");
    percurso(y);
    printf("\nsegunda metade\n");
    percurso(x);
}