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
        printf("\ndigite um valor\n");
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

void percurso(struct lista *p)
{
    struct lista *q;
    q = p;
    while(q)
    {
        printf("%d\t", q->chave);
        q = q->prox;
    }
}

int conta(struct lista *p)
{
    struct lista *q;
    int cont = 0;

    q = p;
    while(q)
    {
        cont++;
        q = q->prox;
    }

    return(cont);
}

struct lista *removek(struct lista *p, int k)
{
    struct lista *q, *r;
    int cont = 1;

    if(!p)
        return(NULL);

    if(k == 1)
    {
        if(!p->prox){
            free(p);
            return(NULL);
        }
        else{
            q = p;
            p = p->prox;
            free(q);
            return(p);
        }
    }
    else{
        for(q = p; cont != k; q = q->prox){
            r = q;
            cont++;
        }
        r->prox = q->prox;

        free(q);
        return(p);
    }
}

struct lista *copia(struct lista *p)
{
    struct lista *info, *copia, *q, *r;

    copia = r = NULL;

    q = p;
    while(q)
    {
        info = (struct lista*)malloc(sizeof(struct lista));
        info->chave = q->chave;
        info->prox = NULL;

        if(r)
            r->prox = info;
        else
            copia = info;
        r = info;

        q = q->prox;
    }

    return(copia);
}

struct lista *inverte(struct lista *p)
{
    struct lista *inv, *q, *r;

    inv = NULL;

    q = p;
    while(q){
        r = q->prox;
        q->prox = inv;
        inv = q;
        q = r;
    }

    return(inv);

}

struct lista *inserepar(struct lista *p)
{
    struct lista *par, *q, *ini, *ult;

    ini = ult = NULL;

    q = p;
    while(q)
    {
        if((q->chave)%2 == 0)
        {
            par = (struct lista*)malloc(sizeof(struct lista));
            par->chave = q->chave;
            par->prox = NULL;

            if(ult)
                ult->prox = par;
            else
                ini = par;
            ult = par;
        }
        q = q->prox;
    }

    return(ini);
}

struct lista *insereimpar(struct lista *p)
{
    struct lista *impar, *q, *ini, *ult;

    ini = ult = NULL;

    q = p;
    while(q)
    {
        if((q->chave)%2 != 0)
        {
            impar = (struct lista*)malloc(sizeof(struct lista));
            impar->chave = q->chave;
            impar->prox = NULL;

            if(ult)
                ult->prox = impar;
            else
                ini = impar;
            ult = impar;
        }
        q = q->prox;
    }

    return(ini);
}

void main()
{
    struct lista *x, *y, *par, *impar;
    int op, k;

    do{

        printf("\n1 cria lista\n2 percurso\n3 conta nós\n4 remover k\n5 copia\n6 inverter\n7 par\n8 impar\n9 sair\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("\ndigite a quantidade de nós para serem criados:\n");
                scanf("%d", &k);

                x = cria(k);
                break;

            case 2:
                percurso(x);
                break;

            case 3:
                printf("\nquantidade de nós: %d\n", conta(x));
                break;

            case 4:
                printf("\ndigite a posição para remover:\n");
                scanf("%d", &k);

                x = removek(x, k);
                break;

            case 5:
                y = copia(x);
                printf("\na copia:\n");
                percurso(y);
                break;

            case 6:
                x = inverte(x);
                break;

            case 7:
                par = inserepar(x);

                printf("\na lista par:\n");
                percurso(par);                
                break;

            case 8:
                impar = insereimpar(x);

                printf("\na lista impar:\n");
                percurso(impar);
                break;

            case 9:
                break;

            default:
                printf("\ndigite opção válida\n");
        }
    }while(op != 9);
}