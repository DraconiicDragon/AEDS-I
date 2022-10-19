#include <iostream>

using namespace std;

#include "TAD_PilhaArranjo.hpp"

bool criaPilhaVazia(PilhaPedido* pilha) {
    if(pilha->tamanho == 0) {
        return false;
    }
    pilha->tamanho = 0;
    return true;
}

bool verificaPilhaVazia(PilhaPedido* pilha) {
    if(pilha->tamanho == 0) {
        return true;
    }
    return false;
}

bool verificaPilhaCheia(PilhaPedido* pilha) {
    if(pilha->tamanho == MAX_TAM) {
        return true;
    }
    return false;
}

bool empilha(PilhaPedido* pilha, Pedido item) {
    if(verificaPilhaCheia(pilha)) {
        return false;
    }
    pilha->pedido[pilha->tamanho] = item;
    pilha->tamanho++;
    return true;
}

Pedido desempilha(PilhaPedido* pilha) {
    Pedido item;
    item = pilha->pedido[pilha->tamanho - 1];
    pilha->pedido[pilha->tamanho - 1] = pilha->pedido[pilha->tamanho];
    pilha->tamanho--;
    return item;
}

void imprimePilha(PilhaPedido pilha) {
    for(int i = 0; i < pilha.tamanho; i++) {
        cout << pilha.pedido[i].id;
    }
    cout << endl;
}

int getTamanho(PilhaPedido* pilha) {
    return pilha->tamanho;
}