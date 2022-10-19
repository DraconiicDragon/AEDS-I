#include <iostream>

using namespace std;

struct Item {
    int id;
};

typedef struct Celula* Apontador;

struct Celula {
    Item item;
    Apontador prox;
};

struct Pilha {
    Apontador topo;
    int tamanho;
};

void criaPilhaVazia(Pilha* pilha);
bool verificaPilhaVazia(Pilha* pilha);
void empilha(Pilha* pilha, Item item);
Apontador desempilha(Pilha* pilha);
void imprimePilha(Pilha pilha);

