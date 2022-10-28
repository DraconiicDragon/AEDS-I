#include <iostream>
#include "./Duplamente Encadeada/TAD_ListaDuplamenteEncadeada.cpp"


using namespace std;
using namespace listaDuplamenteEncadeada;

int main() {
    Lista lista;
    lista.criaListaVazia();
    Item item;
    item.id = 1;
    lista.insereItemUltimo(item);

    item.id = 3;
    lista.insereItemUltimo(item);

    item.id = 2;
    lista.insereItemAposElemento(item, 1);

    item.id = 4;
    lista.insereItemPrimeiro(item);
        
    lista.retiraItemPorId(2);
    lista.imprimeLista();

    return 0;
}