#include <stdio.h>

#define size 10

void dobro(int v[], int i, int s){
    if(i == s)
        return;
    v[i] = 2*v[i];
    dobro(v, i + 1, s);
}

void percurso(int v[])
{
    int i;
    for(i = 0; i < size; i++)
        printf("%d\t", v[i]);
}

void main()
{
    int v[size], i, valor;

    for(i = 0; i < size; i++)
    {
        printf("\ndigite um valor:\n");
        scanf("%d", &valor);

        v[i] = valor;
    }

    printf("\no vetor:\n");
    percurso(v);

    dobro(v, 0, size);

    printf("\no dobro do vetor:\n");
    percurso(v);
}