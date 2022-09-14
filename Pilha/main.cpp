#include <iostream>
#include "TAD_PilhaArranjo.hpp";

using namespace std;

int main() {
    Pilha normal, inverso;
    criaPilhaVazia(&normal);
    criaPilhaVazia(&inverso);

    string nome = "stun amogus";

    for(char i : nome) {
        Item item;
        item.letra = i;
        empilha(&normal, item);
    }
    imprimePilha(normal);

    int aux = normal.tamanho;
    for(int i = 0; i < aux; i++) {
        empilha(&inverso, desempilha(&normal));
    }
    imprimePilha(inverso);
    return 0;
}