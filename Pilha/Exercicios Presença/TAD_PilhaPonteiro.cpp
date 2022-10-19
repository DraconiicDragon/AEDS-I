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
        cout << aux->item.id;
        aux = aux->prox;
    }
}

Apontador consultaPorID(Pilha* pilha, int id) {
    Apontador aux = pilha->topo;
    while(aux != NULL) {
        if(aux->item.id == id) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}
Apontador consultaNome(Pilha* pilha, string nome) {
    Apontador aux = pilha->topo;
    while(aux != NULL) {
        if(aux->item.nome == nome) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}