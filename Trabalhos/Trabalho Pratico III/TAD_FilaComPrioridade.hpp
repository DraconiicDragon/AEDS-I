#include <iostream>

using namespace std;

namespace FilaPrioridade {

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
    Apontador ultimoPrioridade[5];
};

void criaFilaVazia(Fila* fila); 
bool filaVazia(Fila* fila); 


void insereItemUltimo(Fila* fila, Item item); 
void insereItemPrimeiro(Fila* fila, Item item); 
void insereAposElemento(Apontador anterior, Apontador novo);
void insereItemPrioridade(Fila* fila, Item item); 

Item retiraItem(Fila* fila); 
void esvaziaFila(Fila* fila); 

void imprimeItem(Item item); 
void imprimeFila(Fila* fila); 

}

