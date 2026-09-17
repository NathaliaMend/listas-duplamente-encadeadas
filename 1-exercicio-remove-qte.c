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
void insereInicio(LISTA *l1, int input)
{
    NO *novo = malloc(sizeof(NO));
    novo->chave = input;

    if (l1->primeiro == NULL)
    {
        l1->primeiro = novo;
        l1->ultimo = novo;
    }
    else
    {
        novo->prox = l1->primeiro;
        l1->primeiro->ant = novo;
        l1->primeiro = novo;
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

void removeQtd(LISTA *L, int Pos, int Qte)
{
    NO *atual;
    NO *anterior;
    NO *proximo;
    int i;

    // Verifica se a quantidade é válida
    if (Qte <= 0 || Pos <= 0)
    {
        return;
    }

    atual = L->primeiro;

    // Percorre até a posição inicial
    i = 1;
    while (i < Pos && atual != NULL)
    {
        atual = atual->prox;
        i++;
    }

    // Posição não encontrada
    if (atual == NULL)
    {
        return;
    }

    // Remove Qte elementos a partir da posição encontrada
    i = 0;
    while (i < Qte && atual != NULL)
    {
        proximo = atual->prox;

        // Ajusta o nó anterior
        if (atual->ant != NULL)
        {
            atual->ant->prox = atual->prox;
        }
        else
        {
            // Atual era o primeiro nó
            L->primeiro = atual->prox;
        }

        // Ajusta o nó posterior
        if (atual->prox != NULL)
        {
            atual->prox->ant = atual->ant;
        }
        else
        {
            // Atual era o último nó
            L->ultimo = atual->ant;
        }

        free(atual); // Garbage Collector

        atual = proximo;
        i++;
    }
}

int main()
{
    LISTA l1;

    int tam;
    printf("Qual o tamanha da lista? ");
    scanf("%d", &tam);
    inicializaLista(&l1);

    int i = 0;
    while (i < tam)
    {
        int input;
        printf("Digite um numero: ");
        scanf("%d", &input);
        insereInicio(&l1, input);
        i++;
    }

    mostrarLista(&l1);
    removeQtd(&l1, 1, 2);
    printf("\n");
    mostrarLista(&l1);
}