#include <stdio.h>
#include <stdlib.h>
typedef struct NO
{
    int chave;
    struct NO *ant;
    struct NO *prox;
} NO;

typedef struct LISTA
{
    NO *primeiro;
    NO *ultimo;
} LISTA;

void inicializaLista(LISTA *l1)
{
    l1->primeiro = NULL;
    l1->ultimo = NULL;
}

int buscaLista(LISTA *l1, int input)
{
    NO *atual = l1->primeiro;

    while (atual != NULL)
    {
        if (atual->chave == input)
        {
            // printf("O numero %d, FOI encontrado", atual->chave);
            return 1;
        }
        atual = atual->prox;
    }
    // printf("\n O numero %d, NÃO foi encontrado.\n", input);
    return 0;
}

void insereFim(LISTA *l1, int input)
{

    NO *novo = malloc(sizeof(NO));
    novo->chave = input;

    if (l1->ultimo == NULL)
    {
        l1->primeiro = novo;
        l1->ultimo = novo;
    }
    else
    {
        novo->ant = l1->ultimo;
        l1->ultimo->prox = novo;
        l1->ultimo = novo;
    }
}

void removeLista(LISTA *l1, int input)
{
    NO *anterior = l1->primeiro;
    NO *aux = l1->primeiro;

    if (anterior->chave == input && anterior->prox != NULL)
    {
        l1->primeiro = anterior->prox;
        return;
    }

    while (anterior->prox != NULL)
    {

        if (anterior->prox->chave == input)
        {
            if (anterior->prox->prox == NULL)
            {
                anterior->prox = NULL;
                l1->ultimo = anterior;
                return;
            }
            else
            {
                aux = anterior->prox->prox;
                anterior->prox = aux;
            }
        }

        anterior = anterior->prox;
    }
}

void mostrarLista(LISTA *l1)
{
    NO *atual = l1->primeiro;
    while (atual != NULL)
    {
        printf("%d\n", atual->chave);
        atual = atual->prox;
    }
}

void removerParesComuns(LISTA *l1, LISTA *l2)
{
    NO *atual = l2->primeiro;
    NO *proximo;

    while (atual != NULL)
    {
        proximo = atual->prox;

        if (atual->chave % 2 == 0 && buscaLista(l1, atual->chave) == 1)
        {

            removeLista(l2, atual->chave);
        }
        atual = proximo;
    }
}

void inserirImparesNaoRepetidos(LISTA *l1, LISTA *l2)
{
    NO *atual = l1->primeiro;

    while (atual != NULL)
    {
        if (atual->chave % 2 != 0 &&
            buscaLista(l2, atual->chave) == 0)
        {

            insereFim(l2, atual->chave);
        }
        atual = atual->prox;
    }
}

int todosPresentes(LISTA *l1, LISTA *l2)
{
    NO *atual = l1->primeiro;
 
    while (atual != NULL)
    {
        if (buscaLista(l2, atual->chave) == 0)
        {
            printf("\nHa difentes elementos nas listas e nem todos estao presentes.\n");
            return 0; // Falso
        }
        atual = atual->prox;
    }
    printf("\nTodos os elementos ESTAO presentes.\n");
    return 1; // Verdadeiro
}

int main()
{
    LISTA l1;
    LISTA l2;

    inicializaLista(&l1);
    inicializaLista(&l2);

    // Preenche l1
    insereFim(&l1, 10);
    insereFim(&l1, 15);
    insereFim(&l1, 20);
    insereFim(&l1, 25);
    insereFim(&l1, 30);

    // Preenche l2
    insereFim(&l2, 5);
    insereFim(&l2, 10);
    insereFim(&l2, 12);
    insereFim(&l2, 25);
    insereFim(&l2, 40);

    mostrarLista(&l1);
    mostrarLista(&l2);
    // inserirImparesNaoRepetidos(&l1, &l2);
    // removerParesComuns(&l1, &l2);
    // mostrarLista(&l1);
    // mostrarLista(&l2);
    todosPresentes(&l1, &l2);
    return 0;
}
