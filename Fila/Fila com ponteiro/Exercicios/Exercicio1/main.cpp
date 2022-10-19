#include <iostream>

#include "TAD_FilaComPonteiro.cpp"

using namespace std;
using namespace FilaPonteiro;

int main() {
    Fila fila;
    criaFilaVazia(&fila);

    Item item;
    item.id = 1;
    insereItem(&fila, item);
    item = retiraItem(&fila);
    if(item.id != -1) {
        cout << "Id: " << item.id << endl;
    }

    imprimeFila(&fila);
    return 0;
}