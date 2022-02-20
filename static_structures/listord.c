// sequential ordened list

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 100


struct tno{
	int codigo, idade;
	char nome[60], tipo[60];
};

struct tlista{
	int qtnos;
	struct tno lista[10];
};

void inicializalista(struct tlista *pl)
{
	pl->qtnos = 0;
}

int listavazia(struct tlista *pl)
{
	if(pl->qtnos == 0)
		return 1;
		
	return 0;
}

int listacheia(struct tlista *pl)
{
	if(pl->qtnos == TAM)
		return 1;
		
	return 0;
}

void imprimelista(struct tlista *pl)
{
	int i;
	
	for(i = 0; i < pl->qtnos; i++)
	{	
		printf("\n");
		printf("nome do cliente %d: %s\n", i, pl->lista[i].nome);
		printf("código do cliente: %d\n", pl->lista[i].codigo);
		printf("idade do cliente: %d\n", pl->lista[i].idade);
		printf("tipo de livro favorito: %s\n", pl->lista[i].tipo);
		
	}
}

int buscaseqord(struct tlista *pl, int valor, int *pos)
{
	int i;
	
	for(i = 0; i < pl->qtnos && valor > pl->lista[i].codigo; i++);
	
	*pos = i;
	
	if(i == pl->qtnos || valor != pl->lista[i].codigo)
		return 0;	
	else
		return 1;
	
}

int buscabin(struct tlista *pl, int valor)
{
	int ini, fim, meio;
	ini = 0;
	fim = pl->qtnos - 1;
	
	while(ini <= fim)
	{
		meio = (ini + fim)/2;
		
		if(valor == pl->lista[meio].codigo)
			return(meio);
		if(valor > pl->lista[meio].codigo)
			ini = meio + 1;
		else
			fim = meio - 1;
		
	}
	
	return -1;
	
}

int insereord(struct tlista *pl, int cod, int id, char name[], char type[])
{
	int i, posicao;
	
	if(pl->qtnos == TAM)
		return 0;
	if(buscaseqord(pl, cod, &posicao))
		return -1;
		
	for(i = pl->qtnos; i > posicao; i--)
	{	
		pl->lista[i].codigo = pl->lista[i - 1].codigo;
		pl->lista[i].idade = pl->lista[i - 1].idade;
		strcpy(pl->lista[i].nome, pl->lista[i - 1].nome);
		strcpy(pl->lista[i].tipo, pl->lista[i - 1].tipo);
	}
		
	pl->lista[posicao].codigo = cod;
	pl->lista[posicao].idade = id;
	strcpy(pl->lista[posicao].nome, name);
	strcpy(pl->lista[posicao].tipo, type);
	pl->qtnos++;
	
	return 1;
}

int removeord(struct tlista *pl, int valor)
{
	int i, posicao;
	
	if(pl->qtnos == 0)
		return 0;
	if(!(buscaseqord(pl, valor, &posicao)))
		return -1;
		
	for(i = posicao; i < pl->qtnos - 1; i++)
	{	
		pl->lista[i].codigo = pl->lista[i + 1].codigo;
		pl->lista[i].idade = pl->lista[i + 1].idade;
		strcpy(pl->lista[i].nome, pl->lista[i + 1].nome);
		strcpy(pl->lista[i].tipo, pl->lista[i + 1].tipo);
	}
		
	pl->qtnos--;
	return 1;
}

void main()
{
	struct tlista x;
	int i = 0, op, cod, id, busc, pos;
	char name[TAM], type[TAM];
	
	inicializalista(&x);
	
	do{
		printf("\ndigite uma opção do menu:\n");
		printf("\n1 - inserir\n2 - imprimir\n3 - buscar cliente\n4 - remover cliente\n5 - sair!\n");
		scanf("%d", &op);
		
		fgetc(stdin);
		
		switch(op)
		{
			case 1:
				if(listacheia(&x))
				{
					printf("\nlista cheia, impossível inserir\n");
				}
				else
				{
					printf("\ndigite o nome do cliente %d:\n", i);
					gets(name);
					
					printf("\ndigite o código de identificação:\n");
					scanf("%d", &cod);
					
					printf("\ndigite a idade do cliente:\n");
					scanf("%d", &id);
					
					fgetc(stdin);
					
					printf("\ndigite o tipo favorito de livro:\n");
					gets(type);
					
					insereord(&x, cod, id, name, type);
				
					i++;
				}
				break;
				
			case 2:
				if(listavazia(&x))
				{
					printf("\nlista vazia\n");
				}
				else
				{
					imprimelista(&x);
				}
				break;
				
			case 3:
				printf("\n1 - busca sequencial\n2 - busca binária\n");
				scanf("%d", &op);
				
				if(op == 1)
				{	
					printf("\ndigite um código:\n");
					scanf("%d", &cod);
					
					busc = buscaseqord(&x, cod, &pos);
					
					if(busc == 1)
					{
						printf("\n");
						printf("nome do cliente %d: %s\n", pos, x.lista[pos].nome);
						printf("código do cliente: %d\n", x.lista[pos].codigo);
						printf("idade do cliente: %d\n", x.lista[pos].idade);
						printf("tipo de livro favorito: %s\n", x.lista[pos].tipo);
					}
					else
					{
						printf("\ncódigo não existente\n");
					}
					
					
				}
				else if(op == 2)
				{
					printf("\ndigite um código:\n");
					scanf("%d", &cod);
					
					busc = buscabin(&x, cod);
					
					if(busc == -1)
					{
						printf("\ncódigo não existente\n");
					}
					else
					{
						printf("\n");
						printf("nome do cliente %d: %s\n", busc, x.lista[busc].nome);
						printf("código do cliente: %d\n", x.lista[busc].codigo);
						printf("idade do cliente: %d\n", x.lista[busc].idade);
						printf("tipo de livro favorito: %s\n", x.lista[busc].tipo);
					}
					
				}
				else
				{
					printf("\ndigite uma opção válida\n");
				}
		
				break;
				
			case 4:
				printf("\ndigite um código:\n");
				scanf("%d", &cod);
				
				if(removeord(&x, cod) == -1)
				{
					printf("\ncódigo não existente\n");
				}
				break;
				
			case 5:
				break;
				
			default:
				printf("\ndigite uma opção do menu\n");
		}	
		
	}while(op != 5);
	
}


