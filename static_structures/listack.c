#include <stdio.h>

#define size 5

struct tno{
    int chave;
};

struct lista{
    int qtnos;
    struct tno lista[size];
};

struct pilha{
    int topo;
    int pilha[size];
};

void inicializa_pilha(struct pilha *p)
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
    if(p->topo == size -1)
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

int desempilha(struct pilha *p, int *elem)
{
    if(pilha_vazia(p))
        return 0;

    *elem = p->pilha[p->topo--];
    return 1;
}

void inicializa_lista(struct lista *p)
{
    p->qtnos = 0;
}

int lista_cheia(struct lista *p)
{
    if(p->qtnos == size)
        return 1;
    return 0;
}

int lista_vazia(struct lista *p)
{
    if(p->qtnos == 0)
        return 1;
    return 0;
}

int busca_sequencial_ord(struct lista *p, int valor, int *pos)
{
    int i;

    for(i = 0; i < p->qtnos && valor > p->lista[i].chave; i++);
    *pos = i;

    if(i == p->qtnos || valor != p->lista[i].chave)
        return 0;
    return 1; 
}

int busca_binaria(struct lista *p, int valor)
{
    int ini = 0, fim = p->qtnos - 1, meio;

    while(ini <= fim){
        meio = (ini + fim)/2;
        if(valor == p->lista[meio].chave)
            return meio;
        if(valor > p->lista[meio].chave)
            ini = meio + 1;
        else   
            fim = meio - 1;
    }
}

int insere_ordenada(struct lista *p, int valor)
{
    int i, pos;

    if(lista_cheia(p))
        return 0;
    
    if(busca_sequencial_ord(p, valor, &pos))
        return -1;

    for(i = p->qtnos; i > pos; i--)
        p->lista[i].chave = p->lista[i - 1].chave;

    p->lista[pos].chave = valor;
    p->qtnos++;

    return 1;
}

int insere(struct lista *p, int valor)
{
    if(lista_cheia(p))
        return 0;

    p->lista[p->qtnos].chave = valor;
    p->qtnos++;
    return 1;
}

int remove_lista(struct lista *p, int valor)
{
    int i, pos;
    
    if(lista_vazia(p))
        return 0;

    if(!busca_sequencial_ord(p, valor, &pos))
        return -1;

    for(i = pos; i < p->qtnos - 1; i++)
        p->lista[i].chave = p->lista[i + 1].chave;

    p->qtnos--;
    return 1;
}

void percurso_lista(struct lista *p)
{
    int i;
    for(i = 0; i < p->qtnos; i++)
    {
        printf("%d\t", p->lista[i].chave);
    }
}

void percurso_pilha(struct pilha*p)
{
    int i;
    for(i = 0; i <= p->topo; i++)
    {
        printf("%d\t", p->pilha[i]);
    }
}

void inverter(struct lista *pl, struct pilha *p)
{
    int i, cont;

    for(i = 0; i < pl->qtnos; i++){
        empilha(p, pl->lista[i].chave);
    }

    i = 0;
    while(pl->qtnos){
        remove_lista(pl, pl->lista[i].chave);
        i++;
    }

    cont = p->topo;
    for(i = 0; i <= cont; i++){
        desempilha(p, &pl->lista[i].chave);
        insere(pl, pl->lista[i].chave);
    }

}

void ler_valores(struct lista *p)
{
    int i, valor;
    for(i = 0; i < size; i++)
    {
        printf("\ndigite um valor:\n");
        scanf("%d", &valor);

        insere_ordenada(p, valor);
    }
}

void main()
{
    struct lista x;
    struct pilha aux;
    int i, n;

    inicializa_lista(&x);
    inicializa_pilha(&aux);

    ler_valores(&x);

    printf("\na lista:\n");
    percurso_lista(&x);
    printf("\n");

    inverter(&x, &aux);

    printf("\na lista invertida:\n");
    percurso_lista(&x);
    printf("\n");

}