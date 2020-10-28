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

        free(aux);
    }

    free(l->sentinela); free(l);
}
// ========================================================================
Boolean lista_inserirFim(Lista* l, TipoElemento elemento){
    if(l){
        No* novo_no = (No*) malloc(sizeof(No));
        // Aponta o novo no para os elementos da lista
        novo_no->dado = elemento;
        novo_no->prox = l->sentinela;
        novo_no->ant = l->sentinela->ant;
        // Acopla o ponteiro do ultimo node, no novo node
        l->sentinela->ant->prox = novo_no;
        // Acopla o ultimo ponteiro da sentinela ao novo node
        l->sentinela->ant = novo_no;
        l->qtde++;

        return true;
    }else{
        return false;
    }
}
// ========================================================================
Boolean lista_inserir(Lista* l, TipoElemento elemento, int posicao){
    No* novo_no = (No*) malloc(sizeof(No));
    No* aux = getNode(l, posicao-1);

    novo_no->dado = elemento;
    novo_no->prox = aux->prox;
    novo_no->ant = aux;

    aux->prox = novo_no;
    novo_no->prox->ant = novo_no;

    l->qtde++;
}
// ========================================================================
Boolean lista_removerPosicao(Lista* l, int posicao, TipoElemento* endereco){
    if(posicao > l->qtde || posicao < 0){
        return 0;
    }else{
        No* aux = getNode(l, posicao);
        *endereco = aux->dado;

        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        l->qtde--;
        free(aux);

        return 1;
    }
}
// ========================================================================
int lista_removerElemento(Lista* l, TipoElemento elemento){
    No* aux = (No*) malloc(sizeof(No));
    aux = l->sentinela->prox;

    while(elemento != aux->dado){
        if(aux->prox == l->sentinela) return 0;
        aux = aux->prox;
    }

    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    l->qtde--;
    free(aux);

    return 1;
}
// ========================================================================
Boolean lista_substituir(Lista* l, int posicao, TipoElemento novoElemento){
    No* aux = getNode(l, posicao);
    if(aux){
        aux->dado = novoElemento;
        return true;
    }else{
        return false;
    }
}
// ========================================================================
int lista_posicao(Lista* l, TipoElemento elemento){
    int pos = 0;
    No* aux = (No*) malloc(sizeof(No));
    aux = l->sentinela->prox;

    while(elemento != aux->dado){
        if(aux->prox == l->sentinela) return -1;
        aux = aux->prox;
        pos++;
    }

    free(aux);
    return pos;
}
// ========================================================================
Boolean lista_buscar(Lista* l, int posicao, TipoElemento* endereco){
    if(posicao > l->qtde || posicao < 0){
        return false;
    }else{
        No* aux = getNode(l, posicao);
        *endereco = aux->dado;

        return true;
    }
}
// ========================================================================
void lista_imprimir(Lista* l){
    No* aux = (No*) malloc(sizeof(No));
    aux = l->sentinela->prox;

    for (int i = 0; i < l->qtde; i++) {
        printf("Node [%p]: |%p|%d|%p|\n", aux, aux->ant, aux->dado, aux->prox);
        aux = aux->prox;
    }
}
// ========================================================================
No* getNode(Lista* l, int position){
    if(position > l->qtde){
        return NULL;
    }else{
        No* aux = (No*) malloc(sizeof(No));
        aux = l->sentinela->prox;

        for (int i = 0; i < position; i++) {
            aux = aux->prox;
        }

        return aux;
    }
}
