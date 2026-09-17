#include <stdio.h>
#include <stdlib.h>

typedef struct NO
{
    struct NO *previous;
    int key;
    struct NO *next;
} NO;

typedef struct LISTA
{
    struct NO *first;
    struct NO *last;
} LISTA;

void inicializaLista(LISTA *l1)
{
    l1->first = NULL;
    l1->last = NULL;
}

int listaVazia(LISTA *l1)
{
    if (l1->first == NULL && l1->last == NULL)
    {
        return 1;
    }
    return 0;
}

void buscaLista(LISTA *l1, int input)
{
    NO *atual = l1->first;

    while (atual != NULL)
    {
        if (atual->key == input)
        {
            printf("O numero %d, FOI encontrado", atual->key);
            return;
        }
        atual = atual->next;
    }
    printf("\n O numero %d, NÃO foi encontrado.", input);
}

void insereInicio(LISTA *l1, int input)
{
    NO *novo = malloc(sizeof(NO));
    novo->key = input;

    if (l1->first == NULL)
    {
        l1->first = novo;
        l1->last = novo;
    }
    else
    {
        novo->next = l1->first;
        l1->first->previous = novo;
        l1->first = novo;
    }
}

void insereFim(LISTA *l1, int input)
{

    NO *novo = malloc(sizeof(NO));
    novo->key = input;

    if (l1->last == NULL)
    {
        l1->first = novo;
        l1->last = novo;
    }
    else
    {
        novo->previous = l1->last;
        l1->last->next = novo;
        l1->last = novo;
    }
}

void insereOrdenado(LISTA *l1, int input){
     NO *novo = malloc(sizeof(NO));
    novo->key = input;
    novo->next = NULL;

    NO *primeiro = l1->first;

    if (primeiro == NULL)
    {
        l1->first = novo;
        l1->last = novo;
        return;
    }

    if (input < l1->first->key)
    {
        primeiro->previous = novo;
        novo->next = l1->first;

        l1->first = novo;

        novo->previous = NULL;

        return;
    }

    NO *anterior = l1->first;
    while (anterior->next != NULL && anterior->next->key < input)
    {
        anterior = anterior->next;
    }

    novo->next = anterior->next;
    anterior->next = novo;
    novo->previous = anterior;

    if (novo->next == NULL)
    {
        l1->last = novo;
    }

}

void removeLista(LISTA *l1, int input){

    NO *anterior = l1->first;
    NO *aux = l1->first;

    if (anterior->key == input && anterior->next != NULL)
    {
        l1->first = anterior->next;
        return;
    }

    while (anterior->next != NULL)
    {

        if (anterior->next->key == input)
        {
            if (anterior->next->next == NULL)
            {
                anterior->next = NULL;
                l1->last = anterior;
                return;
            }
            else
            {
                aux = anterior->next->next;
                anterior->next = aux;
            }
        }

        anterior = anterior->next;
    }
   
}


void mostrarLista(LISTA *l1)
{
    NO *atual = l1->first;
    while (atual != NULL)
    {
        printf("%d\n", atual->key);
        atual = atual->next;
    }
}
void mostraListaReverse(LISTA *l1){
     NO *atual = l1->last;
     printf("Reversa:\n");
    while (atual != NULL)
    {
        printf("%d\n", atual->key);
        atual = atual->previous;
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
        int var;
        printf("Digite um numero: ");
        scanf("%d", &var);
        // insereInicio(&l1, var);
        //insereFim(&l1, var);
        insereOrdenado(&l1, var);
        i++;
    }
    listaVazia(&l1);
    mostrarLista(&l1);
    mostraListaReverse(&l1);

    while (1)
    {
        int input;
       //printf("\nBuscar por numero: ");
        printf("\nQual numero deseja remover? ");
        scanf("%d", &input);
       // buscaLista(&l1, input);
        removeLista(&l1, input);
        mostrarLista(&l1);
    }
}