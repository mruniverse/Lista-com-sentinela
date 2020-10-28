#include "lista_sentinela.h"

int main() {
    TipoElemento aux;

    // lista_criar ============================================================
    Lista* l = lista_criar();

    printf("Lista: %p\n", l);
    printf("Sentinela: %p\n", l->sentinela);
    printf("Ant: %p | Prox: %p\n", l->sentinela->ant, l->sentinela->prox);

    // lista_destruir =========================================================
    // lista_destruir(l);

    // lista_inserirFim =======================================================
    lista_inserirFim(l, 10);
    lista_inserirFim(l, 20);

    // lista_inserir ==========================================================
    lista_inserir(l, 15, 1);
    // lista_imprimir(l);

    // lista_removerPosicao ===================================================
    // lista_removerPosicao(l, 0, &aux);
    // printf("Endereco removido: [%d]\n", aux);

    // lista_removerElemento =========================================================
    // lista_removerElemento(l, 20);

    // lista_substituir =========================================================
    lista_substituir(l, 2, 25);

    // lista_posicao =========================================================
    // printf("lista_posicao: %d\n", lista_posicao(l, 25));

    // lista_buscar ===================================================
    // lista_buscar(l, 0, &aux);
    // printf("lista_buscar: [%d]\n", aux);

    // lista_imprimir =========================================================
    lista_imprimir(l);



    return 0;
}
