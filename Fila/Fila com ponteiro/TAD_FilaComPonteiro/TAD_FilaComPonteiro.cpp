#include "TAD_FilaComPonteiro.hpp"

void FilaPonteiro::criaFilaVazia(Fila* fila) {
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tamanho = 0;
}

bool FilaPonteiro::verificaFilaVazia(Fila* fila) {
    if(fila->primeiro == NULL) {
        return true;   
    }
    return false;
}

void FilaPonteiro::insereItem(Fila* fila, Item item) {
    Apontador aux = new Elemento;
    aux->item = item;
    aux->prox = NULL;

    if(verificaFilaVazia(fila)) {
        fila->primeiro = aux;
    } else {
        fila->ultimo->prox = aux;
    }

    fila->ultimo = aux;
    fila->tamanho++;
}

FilaPonteiro::Item FilaPonteiro::retiraItem(Fila* fila) {
    Item aux;
    aux.id = -1;

    if(verificaFilaVazia(fila)) {
        return aux;
    }

    aux = fila->primeiro->item;
    Apontador deletado = fila->primeiro;

    fila->primeiro = fila->primeiro->prox;
    fila->tamanho--;

    delete deletado;
    return aux;
}

void FilaPonteiro::esvaziaFila(Fila* fila) {
    Apontador aux = fila->primeiro;
    Apontador deletado;

    while(aux != NULL) {
        deletado = aux;
        aux = aux->prox;
        delete deletado;
    }

    fila->primeiro = NULL;
    fila->ultimo = fila->primeiro;
}

void FilaPonteiro::imprimeItem(Item item) {
    cout << item.id << endl;

    cout << endl;
}

void FilaPonteiro::imprimeFila(Fila* fila) {
    Apontador aux = fila->primeiro;
    while(aux != NULL) {
        imprimeItem(aux->item);
        aux = aux->prox;
    }
}