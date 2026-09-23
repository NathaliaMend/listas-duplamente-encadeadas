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

void mostrarLista(LISTA *l1)
{
    NO *atual = l1->primeiro;
    while (atual != NULL)
    {
        printf("%d\n", atual->chave);
        atual = atual->prox;
    }
     printf("--\n");
}

int contaOcorrencias(LISTA *l1, int var) {
    NO *atual = l1->primeiro;
    int i = 0;

    while (atual != NULL) {
        if (atual->chave == var) {
            i++;
        }

        atual = atual->prox;
    }

    return i;
}

void removeLista(LISTA *l1, int x) {

    // Verifica quantas vezes o elemento aparece
    int quantidade = contaOcorrencias(l1, x);

    // Se tiver 0 ou apenas 1 ocorrência,
    // não pode remover
    if (quantidade <= 1) {
        return;
    }

    NO *atual = l1->primeiro;

    // Procura o elemento
    while (atual != NULL && atual->chave != x) {
        atual = atual->prox;
    }

    // Não encontrou
    if (atual == NULL) {
        return;
    }

    // Se não for o primeiro
    if (atual->ant != NULL) {
        atual->ant->prox = atual->prox;
    } 
    else {
        l1->primeiro = atual->prox;
    }

    // Se não for o último
    if (atual->prox != NULL) {
        atual->prox->ant = atual->ant;
    } 
    else {
        l1->ultimo = atual->ant;
    }

    free(atual);
}

int main()
{
      LISTA l1;

    inicializaLista(&l1);

    // Preenche l1
    insereFim(&l1, 10);
    insereFim(&l1, 15);
    insereFim(&l1, 20);
    insereFim(&l1, 25);
    insereFim(&l1, 20);


    mostrarLista(&l1);
    removeLista(&l1, 20);
    mostrarLista(&l1);
     return 0;
}