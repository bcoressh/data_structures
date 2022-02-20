#include <stdio.h>
#include <string.h>

int contchar(char s[], char a, int tam)
{
    int cont;
    
    if(tam == 0)
        cont = 0;
    else{
        cont = contchar(s, a, tam - 1);
        if(a == s[tam - 1])
            cont++;
    }
    return(cont);
}

void main()
{
    char string[60], a;
    int i, tam, cont;

    printf("\ndigite uma string\n");
    gets(string);

    tam = strlen(string);
    printf("\ndigite o caracter para buscar\n");
    scanf("%c", &a);

    cont = contchar(string, a, tam);
    printf("\nnumero de ocorrências de %c: %d\n", a, cont);
}