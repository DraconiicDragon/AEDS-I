#include <iostream>

using namespace std;

namespace listaDuplamenteEncadeada {

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

        void criaListaVazia();

        void insereItemUltimo(Item item);
        void insereItemPrimeiro(Item item);
        void insereItemAposElemento(Item item, int id);

        Apontador localizaItemPorId(int id);

        Item retiraItemPorId(int id);

        void imprimeItem(Item item);
        void imprimeLista();

    };

}
