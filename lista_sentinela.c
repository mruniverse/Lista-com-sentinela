#include "lista_sentinela.h"

Lista* lista_criar(){
    // Criação da lista
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->qtde = 0;
    // Criação do no sentinela
    No* sentinela = (No*) malloc(sizeof(No));

    sentinela->ant = sentinela;
    sentinela->prox = sentinela;
    lista->sentinela = sentinela;

    return lista;
}
// ========================================================================
void lista_destruir(Lista* l){
    if(l->qtde > 0){
        No* aux = (No*) malloc(sizeof(No));
        aux = l->sentinela->prox->prox;

        for (int i = l->qtde; i > 0; i--) {
            free(aux->ant);
            aux = aux->prox;
        }
    }

    free(l->sentinela); free(l);
}
// ========================================================================
Boolean lista_inserirFim(Lista* l, TipoElemento elemento){
    No* novo_no = (No*) malloc(sizeof(No));
    // Aponta o novo no para os elementos da lista
    novo_no->dado = elemento;
    novo_no->prox = l->sentinela;
    novo_no->ant = l->sentinela->ant;
    // Acopla o ponteiro do ultimo no, no novo no
    l->sentinela->ant->prox = novo_no;
    // Acopla o ultimo ponteiro da sentinela ao novo no
    l->sentinela->ant = novo_no;
    l->qtde++;
}
// ========================================================================
void lista_imprimir(Lista* l){
    No* aux = (No*) malloc(sizeof(No));
    aux = l->sentinela->prox;

    for (int i = 0; i < l->qtde; i++) {
        printf("Node [%d]: |%p|%d|%p|\n", i, aux->ant, aux->dado, aux->prox);
        aux = aux->prox;
    }
}
// ========================================================================
No* getNode(Lista* l, int position){
    No* aux = (No*) malloc(sizeof(No));
    aux = l->sentinela->prox;

    for (int i = 0; i < position; i++) {
        aux = aux->prox;
    }

    return aux;
}
