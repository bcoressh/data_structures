#include <stdio.h>

#define s 3

int prodint(int x[], int y[], int size)
{
    int prod;

    if(size == 0)
        return(prod);
    else{
        prod = x[size - 1]*y[size - 1] + prodint(x, y, size - 1);
    }
}

void main()
{
    int x[s] = {1, 2, 3}, y[s] = {4, 5, 6};

    printf("\nproduto interno: %d\n", prodint(x, y, s));
}