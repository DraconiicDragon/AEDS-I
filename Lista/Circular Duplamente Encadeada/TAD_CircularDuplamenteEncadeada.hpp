#include <iostream>

using namespace std;

namespace circularDuplamenteEncadeada {

    struct Item {
        int id;
    };

    typedef struct Elemento* Apontador;

    struct Elemento {
        Apontador ante;
        Item item;
        Apontador prox;
    };

    struct Lista {
        Apontador primeiro;
        Apontador ultimo;
        int tamanho;
    };

    void criaListaVazia(Lista* lista);
    bool listaVazia(Lista* lista);

    void insereItemUltimo(Lista* lista, Item item);
    void insereItemPrimeiro(Lista* lista, Item item);
    void insereItemAposElemento(Lista* lista, Item item, int id);

    Apontador localizaItemPorId(Lista* lista, int id);

    Item retiraItemPorId(Lista* lista, int id);

    void imprimeItem(Item item);
    void imprimeLista(Lista* lista);
    void imprimeListaReversa(Lista* lista);

}
