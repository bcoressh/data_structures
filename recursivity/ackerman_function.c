#include <stdio.h>

int ackerman(int m, int n)

{   int a;

    if(m == 0)
        return(n + 1);
    if(m != 0 && n != 0)
        ackerman(m - 1, ackerman(m, n - 1));
    if(m != 0 && n == 0)
        ackerman(m - 1, 1);
}

void main()
{
    int m = 2, n = 2;

    printf("\nackerman: %d\n", ackerman(m, n));
} 