#include <iostream>
#include "TAD_PilhaPonteiro.cpp"

using namespace std;

int main() {
    Pilha pilha;
    criaPilhaVazia(&pilha);
    Item item;
    item.id = 1;
    empilha(&pilha, item);
    desempilha(&pilha);
    empilha(&pilha, item);
    empilha(&pilha, item);
    imprimePilha(pilha);

    cout << endl;
    desempilha(&pilha);
    empilha(&pilha, item);
    imprimePilha(pilha);

    return 0;
}