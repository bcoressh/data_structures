#include <stdio.h>

int calcula_mdc(int x, int y)
{
    int mdc;

    if(y <= x && x%y == 0)
        mdc = y;
    else
        mdc = calcula_mdc(y, x%y);
    return(mdc);
}

void main()
{
    int x = 15, y = 20, mdc;

    mdc = calcula_mdc(x, y);
    printf("\no mdc: %d\n", mdc);
}