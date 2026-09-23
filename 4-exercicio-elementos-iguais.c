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

void inicializaLista(LISTA *L)
{
    L->primeiro = NULL;
    L->ultimo = NULL;
}

void insereFim(LISTA *L, int input)
{

    NO *novo = malloc(sizeof(NO));
    novo->chave = input;

    if (L->ultimo == NULL)
    {
        L->primeiro = novo;
        L->ultimo = novo;
    }
    else
    {
        novo->ant = L->ultimo;
        L->ultimo->prox = novo;
        L->ultimo = novo;
    }
}

void mostrarLista(LISTA *L)
{
    NO *atual = L->primeiro;
    while (atual != NULL)
    {
        printf("%d\n", atual->chave);
        atual = atual->prox;
    }
    printf("--\n");
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

void removeElementosComuns(LISTA *L, LISTA *M)
{
    NO *atual = L->primeiro;
    NO *proximo;

    while (atual != NULL)
    {

        proximo = atual->prox;

        if (buscaLista(M, atual->chave) == 1)
        {
            removeLista(L, atual->chave);
        }

        atual = proximo;
    }
}

int main()
{
    LISTA L;
    LISTA M;

    inicializaLista(&L);
    inicializaLista(&M);

    // Preenche L
    insereFim(&L, 10);
    insereFim(&L, 15);
    insereFim(&L, 20);
    insereFim(&L, 25);
    insereFim(&L, 30);

    // Preenche M
    insereFim(&M, 5);
    insereFim(&M, 10);
    insereFim(&M, 12);
    insereFim(&M, 25);
    insereFim(&M, 40);

    mostrarLista(&L);
    mostrarLista(&M);

    removeElementosComuns(&L, &M);
    mostrarLista(&L);
    mostrarLista(&M);

    return 0;
}
