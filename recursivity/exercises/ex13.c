#include <stdio.h>
#include <string.h>

char reverso(char s[], int i, int size)
{  
    char inv[size], aux;
    if(i != size)
    {
        reverso(s, i + 1, size);
        aux = s[i];
        inv[i] = s[size - i - 1];
        inv[size - i - 1] = aux;
    }

    return(*inv);
}

int palindromo(char s[], char inv[], int ini, int fim)
{
    int cont;

    if(ini == fim)
        cont = 0;
    else{
        cont = palindromo(s, inv, ini + 1, fim - 1);
        if(s[ini] == inv[fim - 1])
            cont++;
        
        printf("%d\n", cont);
        if(cont == ini + 1)
                return 1;
            else 
                return 0;
    }
}

void main()
{
    char s[100], inv[100];
    int size, value;

    printf("\ndigite sua string\n");
    gets(s);

    size = strlen(s);

    *inv = reverso(s, 0, size);
    value = palindromo(s, inv, 0, size);

    if(value == 1)
        printf("\npalíndromo\n");
    else
        printf("\nnão é palíndromo\n");
}