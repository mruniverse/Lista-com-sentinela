#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definitions ==========================================================
typedef enum boolean{false=0, true=1} Boolean;
typedef int TipoElemento;

// Data Struct definitions ===================================================
typedef struct no{
    TipoElemento dado;
    struct no *ant;
    struct no *prox;
}No;

typedef struct lista{
    No *sentinela;
    int qtde;
}Lista;
// ============================================================================

// Function definitions =======================================================
Lista* lista_criar();
void lista_destruir(Lista* l);
Boolean lista_inserirFim(Lista* l, TipoElemento elemento);
Boolean lista_inserir(Lista* l, TipoElemento elemento, int posicao);
Boolean lista_removerPosicao(Lista* l, int posicao, TipoElemento* endereco);
int lista_removerElemento(Lista* l, TipoElemento elemento);
Boolean lista_substituir(Lista* l, int posicao, TipoElemento novoElemento);
int lista_posicao(Lista* l, TipoElemento elemento);
Boolean lista_buscar(Lista* l, int posicao, TipoElemento* endereco);
Boolean lista_contem(Lista* l, TipoElemento elemento);
int lista_tamanho(Lista* l);
Boolean lista_toString(Lista* l, char* enderecoString);
void lista_imprimir(Lista* l);
No* getNode(Lista* l, int position);
// ============================================================================
