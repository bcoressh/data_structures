#include <stdio.h>

/*
    escreva um programa que leia o tamanho de um vetor de inteiros.
    aloque memória, leia os valores e preencha o vetor. imprima o vetor.
    em seguida, ordene o vetor mostrando para o usuário o seuginte menu abaixo:
        1 bubblesort
        2 selectionsort
        3 insertionsort
        4 sair
    após a ordenação do vetor, leia um valor qualquer e faça a busca do mesmo.
    mostre para o usuário:
        1 busca sequencial
        2 busca binária
        3 sair
    se o valor não for encontrado mostre uma mensagem de erro.
*/

#define s 10

void troca(int *a, int *b)
{
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

void bubblesort(int v[], int size)
{
    int i, value = 1;

    while(value){
        value = 0;
        for(i = 0; i < size; i++){
            if(v[i + 1] < v[i]){
                troca(&v[i], &v[i + 1]);
                value = 1;
            }
        }
    }
}

void selectionsort(int v[], int size)
{
    int i, j, menor;
    
    for(i = 0; i < size - 1; i++){
        menor = i;
        for(j = i + 1; j < size; j++){
            if(v[j] < v[menor])
                menor = j;
        }
        troca(&v[menor], &v[j]);
    }
}

void percurso(int v[], int size)
{
    int i;
    for(i = 0; i < size; i++){
        printf("%d\t", v[i]);
    }
}

void insertionsort(int v[], int size)
{
    int i, j;
    for(j = 1; j < size; j++)
    {
        for(i = j; i > 0 && v[i - 1] > v[i]; i--){
            troca(&v[i], &v[i - 1]);
        }
    }
}

int busca_sequencial(int v[], int valor, int size) //ordenada
{
    int i;
    
    for(i = 0; i < size && valor > v[i]; i++);
    if(i == size || valor != v[i])
        return -1;
    else
        return i; 
}

int busca_binaria(int v[], int valor, int size)
{
    int ini = 0, fim = size - 1, meio;

    while(ini <= fim)
    {
        meio = (ini + fim)/2;
        if(valor == v[meio])
            return meio;
        if(valor < v[meio])
            fim = meio - 1;
        else
            ini = meio + 1;
    }
    return 0;
}

void main()
{
    int v[s], i, op, valor, pos;

    printf("\npreencha o vetor v:\n");
    for(i = 0; i < s; i++){
        printf("\ndigite elemento %d\n", i);
        scanf("%d", &valor);

        v[i] = valor;
    }

    percurso(v, s);

    do{
        printf("\n1 bubblesort\n2 selectionsort\n3 insertionsort\n4 sair\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                bubblesort(v, s);
                percurso(v, s);
                break;

            case 2:
                selectionsort(v, s);
                percurso(v, s);
                break;

            case 3:
                insertionsort(v, s);
                percurso(v, s);
                break;

            case 4:
                break;

            default:
                printf("\ndigite uma opção válida\n");
        }
    }while(op != 4);

    do{
        printf("\n1 sequencial\n2 binaria\n3 sair\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("\ndigite um valor para buscar\n");
                scanf("%d", &valor);

                pos = busca_sequencial(v, valor, s);
                if(pos > -1)
                    printf("\nposição do valor: %d\n", pos);
                break;

            case 2:
                printf("\ndigite um valor para buscar\n");
                scanf("%d", &valor);

                pos = busca_binaria(v, valor, s);
                if(pos >= 0)
                    printf("\nposição do valor: %d\n", pos);
                break;

            case 3:
                break;

            default:
                printf("\ndigite uma opção válida\n");
        }
    }while(op != 3);
}