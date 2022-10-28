#include <iostream>

using namespace std;

namespace FilaPonteiro {

struct Item {
    int id;
    int prioridade;
};

typedef struct Elemento* Apontador;

struct Elemento {
    Item item;
    Apontador prox;
};

struct Fila {
    Apontador primeiro;
    Apontador ultimo;
    int tamanho;
};

void criaFilaVazia(Fila* fila);
bool verificaFilaVazia(Fila* fila);

void insereItem(Fila* fila, Item item);

Item retiraItem(Fila* fila);
void esvaziaFila(Fila* fila);

void imprimeItem(Item item);
void imprimeFila(Fila* fila);

}

