#define MAX_TAM 30
#include <iostream>

using namespace std;

struct Item {
    char letra;
};

struct Pilha {
    Item item[MAX_TAM];
    int tamanho;
};

bool criaPilhaVazia(Pilha* pilha) {
    if(pilha->tamanho == 0) {
        return false;
    }
    pilha->tamanho = 0;
    return true;
}

bool verificaPilhaVazia(Pilha* pilha) {
    if(pilha->tamanho == 0) {
        return true;
    }
    return false;
}

bool verificaPilhaCheia(Pilha* pilha) {
    if(pilha->tamanho == MAX_TAM) {
        return true;
    }
    return false;
}

bool empilha(Pilha* pilha, Item item) {
    if(verificaPilhaCheia(pilha)) {
        return false;
    }
    pilha->item[pilha->tamanho] = item;
    pilha->tamanho++;
    return true;
}

Item desempilha(Pilha* pilha) {
    Item item;
    item = pilha->item[pilha->tamanho - 1];
    pilha->item[pilha->tamanho - 1] = pilha->item[pilha->tamanho];
    pilha->tamanho--;
    return item;
}

void imprimePilha(Pilha pilha) {
    for(int i = 0; i < pilha.tamanho; i++) {
        cout << pilha.item[i].letra;
    }
    cout << endl;
}

int getTamanho(Pilha* pilha) {
    return pilha->tamanho;
}