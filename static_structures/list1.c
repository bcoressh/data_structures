#include <stdio.h>
#include <string.h>

#define size 100

struct tno{
    char cliente[70];
};

struct lista{
    int qtnos;
    struct tno lista[size];
};

void inicializa(struct lista *p)
{
    p->qtnos = 0;
}

int listavazia(struct lista *p)
{
    if(p->qtnos == 0)
        return 1;
    return 0;
}

int listacheia(struct lista *p)
{
    if(p->qtnos == size - 1)
        return 1;
    return 0;
}

void percurso(struct lista *p)
{
    int i;
    printf("\n");
    for(i = 0; i < p->qtnos; i++)
    {
        printf("%s\t", p->lista[i].cliente);
    }
    printf("\n");
}

int busca_sequecial_ordenada(struct lista *p, char nome[], int *pos)
{
    int i;
    for(i = 0; i < p->qtnos && strcmp(nome, p->lista[i].cliente) > 0; i++);
    *pos = i;

    if(i == p->qtnos || strcmp(nome, p->lista[i].cliente) != 0)
        return 0;
    else
        return 1;
}

int buscabinaria(struct lista *p, char nome[])
{
    int ini = 0, fim = p->qtnos, meio;

    while(ini <= fim){
        meio = (ini + fim)/2;
        if(strcmp(nome, p->lista[meio].cliente) == 0)
            return(meio);
        if(strcmp(nome, p->lista[meio].cliente) > 0)
            ini = meio + 1;
        else
            fim = meio - 1;
    }
    return(-1);
}

int insere_ordenada(struct lista *p, char nome[])
{
    int i, pos;

    if(listacheia(p))
        return 0;

    i = busca_sequecial_ordenada(p, nome, &pos);
    if(i > 0)
        return -1;
    
    for(i = p->qtnos; i > pos; i--)
        strcpy(p->lista[i].cliente, p->lista[i - 1].cliente);
    
    strcpy(p->lista[pos].cliente, nome);
    p->qtnos++;
    return 1;
}        

int remove_ordenada(struct lista *p, char nome[])
{
    int i, pos;

    if(listavazia(p))
        return 0;

    i = busca_sequecial_ordenada(p, nome, &pos);
    if(i <= 0)
        return -1;

    for(i = pos; i < p->qtnos - 1; i++)
        strcpy(p->lista[i].cliente, p->lista[i + 1].cliente);

    strcpy(p->lista[p->qtnos].cliente, nome);
    p->qtnos--;
    return 1;
}

void main()
{
    struct lista x;
    int op;
    char nome[size];

    inicializa(&x);

    do{
        printf("\ndigite uma opção:");
        printf("\n1 inserir cliente\n2 imprimir\n3 buscar cliente\n4 remover\n5 sair\n");
        scanf("%d", &op);
        fgetc(stdin);

        switch(op){
            case 1:
                printf("\ninsere cliente:\n");
                gets(nome);

                insere_ordenada(&x, nome);
                break;

            case 2:
                percurso(&x);
                break;

            case 3:
                printf("\nbuscar por cliente:\n");
                gets(nome);

                if(buscabinaria(&x, nome) != -1)
                    printf("\nachou\n");
                else
                    printf("\nnão existe\n");
                break;

            case 4:
                printf("\ndigite cliente para remover:\n");
                gets(nome);
                
                remove_ordenada(&x, nome);
                break;

            case 5:
                break;

            default:
                printf("\ndigite opção válida\n");
        }
    }while(op != 5);
}