#include <stdio.h>
#include <math.h>

int somacubo(int x)
{
    int soma;
    if(x == 0)
        return 0;
    else{
        soma = pow(x, 3)  + somacubo(x - 1);
    }
    return(soma);
}

void main()
{
    int x, scubo;

    printf("\ndigite um número inteiro\n");
    scanf("%d", &x);

    scubo = somacubo(x);
    printf("\na soma dos primeiros cubos: %d\n", scubo);
}