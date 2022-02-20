// circular queue

#include <stdio.h>

#define TAM 100
#define S 2

struct tfila_bobo{
	
	int F, R;
	int fila[TAM];
};

struct tfila_cont{
	
	int ini, fim, cont;
	int filacirc[S];
};

void inicializa_bobo(struct tfila_bobo *pf)
{
	pf->R = 0;
	pf->F = 0;
}

int filavazia_bobo(struct tfila_bobo *pf)
{
	if(pf->F == pf->R)
		return 1;
	
	return 0;
	
}

int filacheia_bobo(struct tfila_bobo *pf)
{
	if((pf-> R + 1)%TAM == pf->F)
		return 1;
	return 0;
}

int inserefila_bobo(struct tfila_bobo *pf, int valor)
{
	if(filacheia_bobo(pf))
		return 0;
	pf->R = (pf->R + 1)%TAM;
	pf->fila[pf->R] = valor;
	return 1;
	
}

int removefila_bobo(struct tfila_bobo *pf, int *elem)
{
	if(filavazia_bobo(pf))
		return 0;
	pf->F = (pf->F + 1)%TAM;
	*elem = pf->fila[pf->F];
	return 1;
	
}

void inicializa_cont(struct tfila_cont *pf)
{
	pf->cont = 0;
	pf->ini = 0;
	pf->fim = -1;
}

int filavazia_cont(struct tfila_cont *pf)
{
	if(pf->cont == 0)
		return 1;
	return 0;
}

int filacheia_cont(struct tfila_cont *pf)
{
	if(pf->cont == TAM - 1)
		return 1;
	return 0;
}

int inserefila_cont(struct tfila_cont *pf, int valor)
{
	if(filacheia_cont(pf))
		return 0;
	pf->cont++;
	pf->fim = (pf->fim == TAM - 1) ? 0: pf->fim + 1;
	pf->filacirc[pf->fim] = valor;
	return 1;
}

int removefila_cont(struct tfila_cont *pf, int *elem)
{
	if(filavazia_cont(pf))
		return 0;
	pf->cont--;
	*elem = pf->filacirc[pf->ini];
	pf->ini = (pf->ini == TAM -1) ? 0: pf->ini + 1;
	return 1;
	
}

void main()
{
	struct tfila_cont x;
	struct tfila_bobo y;
	int i, op, v, cnt = 0, true;
	
	inicializa_bobo(&y);
	inicializa_cont(&x);
	
	do{
		printf("\n1 - inserção\n2 - remoção\n3 - impressão\n4 - sair\n");
		scanf("%d", &op);
		
		switch(op)
		{
			case 1:
				
				printf("\ndigite um numero inteiro:\n");
				scanf("%d", &v);

				true = filacheia_cont(&x);

				if(true == 1)
				{
					if(filacheia_bobo(&y))
						printf("\nERROR\n");
					inserefila_bobo(&y, v);
				}
				else
					inserefila_cont(&x, v);
				
				break;
				
			case 2:
				if(filavazia_cont(&x))
				{	
					if(!filavazia_bobo(&y))
					{
						removefila_bobo(&y, &v);
					}
	
				}
				else
				{
					removefila_cont(&x, &v);
				}
				
				break;
				
			case 3:
				printf("\nsua fila é:\n");
				
				printf("\nfila contador:\n");
				for(i = 0; i < x.cont; i++)
				{
					printf("%d ", x.filacirc[i]);
				}

				break;
				
			case 4:
				break;
				
			default:
				printf("\ndigite uma op valida\n");
				
		}
	
	}while(op != 4);
}