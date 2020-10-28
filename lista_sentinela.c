#include "lista_sentinela.h"

Lista* lista_criar(){
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    No* sentinela = (No*) malloc(sizeof(No));
    lista->sentinela = sentinela;

    return lista;
}
