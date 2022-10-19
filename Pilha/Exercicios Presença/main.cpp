#include <iostream>
#include "TAD_PilhaPonteiro.cpp"

using namespace std;

int main() {
    Pilha pilha;
    criaPilhaVazia(&pilha);

    Item item;
    int num = 69;

    while(num != 0) {
        item.id = num % 2;
        num /= 2;
        empilha(&pilha, item);
    }
    imprimePilha(pilha);

    cout << endl;
    item.id = 4;
    item.nome = "Bingus";
    empilha(&pilha, item);
    

    cout << consultaNome(&pilha, "Bingus")->item.id << endl;
    cout << consultaPorID(&pilha, 4)->item.nome << endl;

    return 0;
}