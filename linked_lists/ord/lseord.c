#include <stdio.h>
#include <stdlib.h>

#define S 100

struct lista{
 	int chave;
 	struct lista *prox;
};
 
struct lista *cria(int n)
{
	struct lista *p, *ini, *ult;
	int i, valor;
	
	ini = ult = NULL;
	
	for(i = 1; i <= n; i++)
	{
		printf("\nvalor\n");
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
 
void imprime(struct lista *p)
{
	while(p)
	{
		printf("%d\t", p->chave);
		p = p->prox;
	}	
}
 
int cont(struct lista *p)
{
 	int cont = 0;
 	
 	while(p){
 		p = p->prox;
 		cont++;
 	}
 	return(cont);
}
 
struct lista *buscaOrd(struct lista *p, int valor){
 	struct lista *q;
 	
 	for(q=p; q; q=q->prox){
 		if(q->chave==valor)
 			return(q);
 	}
 	return(NULL);
}
 
struct lista *insereOrd(struct lista *p, int valor){
 	struct lista *q, *t, *r;
 	
 	if(buscaOrd(p, valor)){
 		printf("elemento ja existe");
 		return(NULL);
 	}

 	q = (struct lista*)malloc(sizeof(struct lista));
 	q->chave = valor;
 	
 	if(!p){
 		q->prox = NULL;
 		return(q);
 	}

 	r=p;
 	while(p && valor > p->chave){
 		t = p;
 		p = p->prox;
 	}

 	if(!p){
 		t->prox = q;
 		q->prox = NULL;
 		return(r);
 	}

 	if(valor < p->chave){
 		q->prox = p;
 		if(r != p){
 			t->prox = q;
 			return(r);
 		}
 		return(q);
 	}
}
 
struct lista *removeord(struct lista *p, int valor)
{
	struct lista *q, *r, *t;
	
	if(!p)
	{
		printf("\nlista vazia\n");
		return(p);
	}
	
	if(buscaOrd(p, valor) == NULL)
	{
		printf("\nelemento n existe\n");
		return(p);
	}
	else{
		q = p;
		while(q->chave < valor)
		{
			t = q;
			q = q->prox;
		}
		if(p != q)
			t->prox = q->prox;
		else
			p = p->prox;
		
		free(q);
		return(p);
	}
}

struct lista *intercala(struct lista *p, struct lista *q)
{
	struct lista *p1, *p2, *ult, *out;
	
	if(!p)
		out = q;
	else{
		if(!q)
			out = p;
		else{
			p1 = p;
			p2 = q;
			
			if(p1->chave == p2->chave)
			{
				out = p;
				
				p1 = p1->prox;
				p2 = p2->prox;
			}
			else if(p1->chave < p2->chave)
			{
				out = p;
				p1 = p1->prox;
			}
			else
			{
				out = q;
				p2 = p2->prox;
			}
			
			ult = out;
			
			while(p1 && p2)
			{
				if(p1->chave < p2->chave)
				{
					ult->prox = p1;
					ult = p1;
					p1 = p1->prox;	
				}
				else if(p1->chave > p2->chave)
				{
					ult->prox = p2;
					ult = p2;
					p2 = p2->prox;
				}
				else
				{
					ult->prox = p2;
					ult = p2;
					p1 = p1->prox;
					p2 = p2->prox;
				}
			} 
			
			if(!p1)
				ult->prox = p2;
			else
				ult->prox = p1;
		
		}
	}
	
	return(out);
}

void main()
{
	struct lista *x, *y, *z;
	int m, n;
	
	//lista 1
	x = (struct lista*)malloc(sizeof(struct lista));

	printf("\ndigite a quantidade de elementos da lista 1:\n");
	scanf("%d", &n);
	
	x = cria(n);
	
	printf("\nlista 1:\n");
	imprime(x);
	printf("\n\n");
	
	//lista 2
	y = (struct lista*)malloc(sizeof(struct lista));
	
	printf("\ndigite a quantidade de elementos da lista 2:\n");
	scanf("%d", &m);
	
	y = cria(m);
	
	printf("\nlista 2:\n");
	imprime(y);
	printf("\n\n");
	
    printf("\ndigite um valor para inserir\n");
    scanf("%d", &n);
    x = insereOrd(x, n);

    printf("\nlista x após inserção:\n");
    imprime(x);

    printf("\ndigite um valor para remover:\n");
    scanf("%d", &n);
    x = removeord(x, n);

    printf("\nlista x após remoção:\n");
    imprime(x);

	//intercalada
	z = intercala(x, y);
	
	printf("\nintercaladas:\n");
	imprime(z);
	printf("\n\n");
	
	free(x);
	free(y);
}