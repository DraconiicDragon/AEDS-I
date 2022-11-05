#include <iostream>
#include "FuncoesMain.cpp"

using namespace std;

int main() {
    Fila fila;
    criaFilaVazia(&fila);

    Paciente item;
    item.id = 1;
    item.prioridade = 2;
    inserePacientePrioridade(&fila, item);

    item.id = 2;
    item.prioridade = 1;
    inserePacientePrioridade(&fila, item);

    item.id = 3;
    item.prioridade = 2;
    inserePacientePrioridade(&fila, item);

    item.id = 4;
    item.prioridade = 3;
    inserePacientePrioridade(&fila, item);

    item.id = 5;
    item.prioridade = 4;
    inserePacientePrioridade(&fila, item);

    imprimeFila(&fila);

    return 0;
}