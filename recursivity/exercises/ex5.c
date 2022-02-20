#include <stdio.h>

#define s 3

int somatorio(int v[], int size)
{
    int soma = 0;
    if(size - 1 == 0)
        return v[size - 1];
    else
        soma = v[size - 1] + somatorio(v, size - 1);
    return(soma);
}

int maximo(int v[], int size)
{
    int maior;

    if(size - 1 == 0)
        maior = v[size -1];
    else{
        maior = maximo(v, size - 1);
        if(maior < v[size - 1])
            maior = v[size - 1];
    }
    return(maior);
}

int minimo(int v[], int size)
{
    int menor;

    if(size - 1 == 0)
        menor = v[size - 1];
    else{
        menor = minimo(v, size - 1);
        if(menor > v[size - 1])
            menor = v[size - 1];
    }
    return(menor); 
}

float media(int v[], int i, int size)
{
    float md = 0;

    if(i == 0)
        return(v[i]);
    if(i == size - 1)
        return(md/size);
    else{
        md = v[i]/size + media(v, i + 1, size);
    }
}

void inverso(int v[], int size)
{
    if(size - 1 >= 0)
    {
        printf("%d\t", v[size - 1]);
        inverso(v, size - 1);
    }

}

void main()
{
    int v[s], i, valor;

    printf("\npreencha o vetor:\n");
    for(i = 0; i < s; i++)
    {
        printf("\ndigite o valor:\n");
        scanf("%d", &valor);

        v[i] = valor;
    }

    printf("\no somatorio: %d\n", somatorio(v, s));
    printf("\nvalor máximo: %d\n", maximo(v, s));
    printf("\nvalor mínimo: %d\n", minimo(v, s));
    printf("\na média: %.2f\n", media(v, 0, s));

    printf("\nordem inversa:\n");
    inverso(v, s);
}
