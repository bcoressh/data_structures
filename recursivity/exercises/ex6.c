#include <stdio.h>

#define s 3

void troca(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void inverso(int v[], int size)
{
    if(size - 1 >= 0){
        printf("%d\t", v[size - 1]);
        inverso(v, size - 1);
    }
    printf("\n");
}

void percurso(int v[], int i, int size)
{
    if(i < size){
        printf("%d: %d\t", i, v[i]);
        percurso(v, i + 1, size);
    }
    printf("\n");
}

void ordenada(int v[], int i, int size)
{
    int valor, j;
    if(i <= size - 1)
    {
        ordenada(v, i + 1, size);

        printf("\ndigite um valor:\n");
        scanf("%d", &valor);

        
    }
}

void main()
{
    int v[s], i, valor;

    ordenada(v, 0, s);
    percurso(v, 0, s);
    inverso(v, s);
}