#include <iostream>

using namespace std;

struct Item {
    int id;
    string nome;
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
Apontador consultaPorID(Pilha* pilha, int id);
Apontador consultaNome(Pilha* pilha, string nome);
