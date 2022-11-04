#include <iostream>
#include "./Duplamente Encadeada/TAD_ListaDuplamenteEncadeada.cpp"


using namespace std;
using namespace listaDuplamenteEncadeada;

int main() {
    Lista lista;
    lista.criaListaVazia();
    Item item;
    item.id = 2;
    lista.insereItemUltimo(item);

    item.id = 4;
    lista.insereItemUltimo(item);

    item.id = 3;
    lista.insereItemAposElemento(item, 2);

    item.id = 1;
    lista.insereItemPrimeiro(item);

    lista.retiraItemPorId(2);
    
    cout << endl << "Normal" << endl;
    lista.imprimeLista();

    cout << endl << "Reverso" << endl;
    lista.imprimeListaReversa();

    return 0;
}