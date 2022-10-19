#include "TAD_PilhaPonteiro.hpp"

void criaPilhaVazia(Pilha* pilha) {
    pilha->tamanho = 0;
    pilha->topo = NULL;
}

bool verificaPilhaVazia(Pilha* pilha) {
    if(pilha->tamanho == 0 && pilha->topo == NULL) {
        return true;
    }
    return false;
}

void empilha(Pilha* pilha, Item item) {
    Apontador aux = new Celula;
    aux->item = item;
    aux->prox = pilha->topo;
    pilha->topo = aux;
    pilha->tamanho++;
}

Apontador desempilha(Pilha* pilha) {
    Apontador aux;
    Apontador item;
    
    if(verificaPilhaVazia(pilha)) {
        return NULL;
    }

    item = pilha->topo;
    aux = pilha->topo;
    pilha->topo = pilha->topo->prox;
    delete aux;
    pilha->tamanho--;

    return item;
}

void imprimePilha(Pilha pilha) {
    Apontador aux = pilha.topo;
    while(aux != NULL) {
        cout << aux->item.id << endl;
        aux = aux->prox;
    }
}