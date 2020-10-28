#include "lista_sentinela.h"

int main() {

    // lista_criar ============================================================
    Lista* l = lista_criar();

    printf("Lista: %p\n", l);
    printf("Sentinela: %p\n", l->sentinela);
    printf("Ant: %p | Prox: %p\n", l->sentinela->ant, l->sentinela->prox);

    // lista_destruir =========================================================
    // lista_destruir(l);

    // lista_inserirFim =========================================================
    lista_inserirFim(l, 10);
    lista_inserirFim(l, 20);

    // lista_imprimir =========================================================
    lista_imprimir(l);



    return 0;
}
