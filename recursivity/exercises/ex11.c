#include <stdio.h>
#include <string.h>

void reverso(char inv[], char s[], int i, int size)
{  
    char aux;
    if(i != size)
    {
        reverso(inv, s, i + 1, size);
        aux = s[i];
        inv[i] = s[size - i - 1];
        inv[size - i - 1] = aux;
    }
}

void main()
{
    char string[100], inv[100];
    int size;

    printf("\ndigite a string:\n");
    gets(string);

    size = strlen(string);

    reverso(inv, string, 0, size);
    printf("\nstring inversa: %s\n", inv);
}