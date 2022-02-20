#include <stdio.h>
#include <stdlib.h>

#define size 6

void merge(int v[], int ini, int meio, int fim)
{
    int i, j, k;
    int l = (meio - ini), r = (fim - meio); 
    int right[r], left[l];

    for(i = 0; i < l; i++)
        left[i] = v[ini + i];
    for(j = 0; j < r; j++)
        right[j] = v[meio + j + 1];

    i = 0;
    j = 0;
    k = ini;

    while(i < l && j < r)
    {
        if(left[i] <= right[j]){
            v[k] = left[i];
            i++;
        }
        else{
            v[k] = right[j];
            j++;
        }
        k++;  
    }

    while(j < r){
        v[k] = right[j];
        j++;
        k++;
    }

    while(i < l){
        v[k] = left[i];
        i++;
        k++;
    }

}

void mergesort(int v[], int ini, int fim)
{
    int meio;
    if(ini < fim){
        meio = (ini + fim)/2;
        mergesort(v, ini, meio);
        mergesort(v, meio + 1, fim);

        merge(v, ini, meio + 1, fim);
    }
}

void main()
{
    int v[size], i, valor;

    for(i = 0; i < size; i++)
    {
        printf("\ndigite valor\n");
        scanf("%d", &valor);

        v[i] = valor;
    }

    printf("\nvetor\n");
    for(i = 0; i < size; i++)
        printf("%d\t", v[i]);

    mergesort(v, 0, size - 1);

    printf("\nmergesort\n");
    for(i = 0; i < size; i++)
        printf("%d\t", v[i]);
}