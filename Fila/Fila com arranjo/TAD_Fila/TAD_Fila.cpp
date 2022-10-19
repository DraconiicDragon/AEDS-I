#include "TAD_Fila.hpp"

void criaFilaVazia(Fila* fila) {
    fila->tamanho = 0;
}

bool verificaFilaVazia(Fila* fila) {
    if(fila->tamanho == 0) {
        return true;
    }
    return false;
}
void enfileira(Fila* fila, Item item) {
    fila->item[fila->tamanho] = item;
    fila->ultimo = fila->tamanho;
    fila->tamanho++;
}
Item desenfileira(Fila* fila) {
    Item item = fila->item[0];
    for(int i = 0; i < fila->tamanho; i++) {
        fila->item[i] = fila->item[i+1];
    }
    return item;
}
void imprimeFila(Fila* fila) {
    for(int i = 0; i < fila->tamanho; i++) {
        cout << fila->item->nome;
    }
}