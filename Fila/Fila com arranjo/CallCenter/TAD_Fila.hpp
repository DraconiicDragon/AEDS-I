#ifndef FILA_H
#define FILA_H

#include <iostream>
using namespace std;

#define MAXTAM 10

typedef struct Item {
    string nome;
    string telefone;
    string solicitacao;
};
typedef struct Fila {
    Item item[MAXTAM];
    int ultimo;
    int tamanho;
};

#endif FILA_H