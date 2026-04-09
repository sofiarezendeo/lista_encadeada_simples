#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void FLVazia(TipoLista *Lista) {
    Lista->Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista->Ultimo   = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista) {
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista) {
    Lista->Ultimo->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista->Ultimo       = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item) {
    TipoApontador q;
    if (Vazia(*Lista) || p == NULL || p->Prox == NULL) {
        printf("Erro: lista vazia ou posicao invalida\n");
        return;
    }
    q        = p->Prox;
    *Item    = q->Item;
    p->Prox  = q->Prox;
    if (p->Prox == NULL) Lista->Ultimo = p;
    free(q);
}

void Imprime(TipoLista Lista) {
    TipoApontador Aux = Lista.Primeiro->Prox;
    while (Aux != NULL) {
        printf("%d\n", Aux->Item.Chave);
        Aux = Aux->Prox;
    }
}

void RetiraUltimo(TipoLista *Lista, TipoItem *Item) {
    if (Vazia(*Lista)) {
        printf("Erro: lista vazia\n");
        return;
    }

    TipoApontador ant = Lista->Primeiro;
    TipoApontador atual = Lista->Primeiro->Prox;
    while (atual->Prox != NULL) {
        ant = atual;
        atual = atual->Prox;
    }

    *Item = atual->Item;
    ant->Prox = NULL;
    Lista->Ultimo = ant;

    free(atual);

    /* IMPLEMENTAR */
}

void InsereInicio(TipoItem x, TipoLista *Lista) {
    TipoApontador nova = (TipoApontador) malloc(sizeof(TipoCelula));

    nova->Item = x;
    nova->Prox = Lista->Primeiro->Prox;
    Lista->Primeiro->Prox = nova;
    if (Lista->Ultimo == Lista->Primeiro) {
        Lista->Ultimo = nova;
    }
    /* IMPLEMENTAR */
}

void Inverte(TipoLista *Lista) {
    if (Vazia(*Lista)) return;

    TipoApontador prev = NULL;
    TipoApontador current = Lista->Primeiro->Prox;
    TipoApontador next;

    Lista->Ultimo = current;

    while (current != NULL) {
        next = current->Prox;
        current->Prox = prev;
        prev = current;
        current = next;
    }

    Lista->Primeiro->Prox = prev;

    /* IMPLEMENTAR */
}

int Tamanho(TipoLista *Lista) {
    int count = 0;
    TipoApontador aux = Lista->Primeiro->Prox;

    while (aux != NULL) {
        count++;
        aux = aux->Prox;
    }
    /* IMPLEMENTAR */
    return count;
}
