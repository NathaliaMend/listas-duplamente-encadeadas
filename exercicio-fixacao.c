#include <stdio.h>
#include <stdlib.h>

typedef struct NO
{
    struct NO *previous;
    struct NO *next;
    int key;
} NO;

typedef struct LISTA
{
    struct NO *first;
    struct NO *last;
} LISTA;

void inicializarLista(){

}
void receberLista(LISTA *l)
{
    int tam;
    printf("Qual o tamanho da lista? ");
    scanf("%d", &tam);

    int i = 0;
    while (i < tam)
    {
        int input;
        printf("Escreva um numero: ");
        scanf("%d", &input);
        // adcionar funcao
        i++;
    }
}

int main()
{
    LISTA l1;
    LISTA l2;

    // receberLista(l1);
    // receberLista(l2);
}