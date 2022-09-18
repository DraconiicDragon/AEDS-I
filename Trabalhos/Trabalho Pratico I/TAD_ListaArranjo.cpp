#define MAX_TAM 5
#include <iostream>

using namespace std;

struct Projeto {
    int id;
    char nome[50];
    float horasSemanais;
};

struct ListaProjetos {
    Projeto projeto[MAX_TAM];
    int tamanho;
};

void criaListaVazia(ListaProjetos *lista) {
    lista->tamanho = 0;
}

bool verificaListaVazia(ListaProjetos *lista) {
    if(lista->tamanho == 0) {
        return true;
    } else {
        return false;
    }
}

bool verificaListaCheia(ListaProjetos *lista) {
    if(lista->tamanho == MAX_TAM) {
        return true;
    } else {
        return false;
    }
}

bool insereItem(ListaProjetos *lista, Projeto projeto) {
    if(!verificaListaCheia(lista)) {
        lista->projeto[lista->tamanho] = projeto;
        lista->tamanho++;
        return true;
    } else {
        return false;
    }
}

// Adaptar "int chave" para cada projeto 
int localizaItem(ListaProjetos *lista, int id) {
    for(int i = 0; i < lista->tamanho; i++) {
        if(lista->projeto[i].id == id) {
            return i;
        } 
    }
    return -1;
}

// Adaptar "int chave" para cada projeto 
void removeItem(ListaProjetos *lista, int id) {
    int posicao = localizaItem(lista, id);
    for(int i = posicao; i < lista->tamanho; i++) {
        lista->projeto[i] = lista->projeto[i+1];
    }
    lista->tamanho--;
}

// Adaptar "cout << chave" para cada projeto 
void imprimeLista(ListaProjetos lista) {
    for(int i = 0; i < lista.tamanho; i++) {
        cout << "ID do Projeto: " << lista.projeto[i].id << endl;
        cout << "Nome do Projeto: " << lista.projeto[i].nome << endl;
        cout << "Horas Semanais: " << lista.projeto[i].horasSemanais << endl;
        cout << endl;
    }
}

void imprimeItem(Projeto projeto) {
    cout << "ID: " << projeto.id << endl;
    cout << "Nome: " << projeto.nome << endl;
    cout << "Horas Semanais: " << projeto.horasSemanais << endl << endl;
}