#include <stdio.h>

int binario(int x, int bin, int i)
{
    if(x > 0){
        bin += (x%2)*i;
        i *= 10;
        binario(x/2, bin, i);
    }
    else
        return(bin);
}

void main(){
    int x, b;

    printf("\ndigite um número para converter\n");
    scanf("%d", &x);

    b = binario(x, 0, 1);
    printf("%d\n", b);
}