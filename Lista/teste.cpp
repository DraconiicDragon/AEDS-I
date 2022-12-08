#include <iostream>
#include "./Circular Duplamente Encadeada/TAD_CircularDuplamenteEncadeada.cpp"


using namespace std;
using namespace circularDuplamenteEncadeada;

int main() {
    Lista lista;
    criaListaVazia(&lista);
    Item item;
    item.id = 2;
    insereItemUltimo(&lista, item);

    item.id = 4;
    insereItemUltimo(&lista, item);

    item.id = 3;
    insereItemAposElemento(&lista, item, 2);

    item.id = 1;
    insereItemPrimeiro(&lista, item);

    retiraItemPorId(&lista, 4);
    
    cout << endl << "Normal" << endl;
    imprimeLista(&lista);

    cout << endl << "Reverso" << endl;
    imprimeListaReversa(&lista);

    cout << endl << "Anterior do primeiro" << endl;
    imprimeItem(lista.primeiro->ante->item);

    return 0;
}