#include <iostream>

#include "TAD_Fila.cpp"

using namespace std;

int main() {
    Fila fila;
    criaFilaVazia(&fila);
    for(int i = 0; i < MAXTAM; i++) {
        Item item;
        string s;
        s = to_string(i+1);
        item.nome = s;
        item.telefone = s;
        item.solicitacao = s;
        enfileira(&fila, item);
    }
    imprimeFila(&fila);

    return 0;
}