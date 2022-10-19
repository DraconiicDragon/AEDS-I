#include <iostream>
#include "./TAD_FilaComPonteiro/TAD_FilaComPonteiro.cpp"

using namespace std;
using namespace FilaPonteiro;

int main() {
    Fila fila;
    criaFilaVazia(&fila);
    Item item;

    Item aux = retiraItem(&fila);
    if(aux.id != -1) {
        imprimeItem(aux);
    }

    imprimeFila(&fila);

    item.id = 1;
    insereItem(&fila, item);

    item.id = 2;
    insereItem(&fila, item);

    return 0;
}