#include <iostream>
#include "./Fila com Prioridade/TAD_FilaComPrioridade.cpp"

using namespace std;
using namespace FilaPrioridade;

int main() {
    Fila fila;
    criaFilaVazia(&fila);

    Item item;
    item.id = 1;
    item.prioridade = 1;
    insereItemPrioridade(&fila, item);

    item.id = 2;
    item.prioridade = 2;
    insereItemPrioridade(&fila, item);

    item.id = 3;
    item.prioridade = 2;
    insereItemPrioridade(&fila, item);

    imprimeFila(&fila);
    return 0;
}