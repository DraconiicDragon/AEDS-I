#include "TAD_CircularDuplamenteEncadeada.hpp"

void circularDuplamenteEncadeada::criaListaVazia(Lista* lista) {
    lista->primeiro = new Elemento;
    lista->ultimo = lista->primeiro;
    lista->ultimo->prox = lista->ultimo;
    lista->ultimo->ante = lista->ultimo;
    lista->tamanho = 0;
}

bool circularDuplamenteEncadeada::listaVazia(Lista* lista) {
    if(lista->tamanho == 0 && lista->ultimo == lista->primeiro) {
        return true;
    }
    return false;
}

void circularDuplamenteEncadeada::insereItemUltimo(Lista* lista, Item item) {
    lista->ultimo->prox = new Elemento;
    lista->ultimo->prox->ante = lista->ultimo;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->item = item;
    lista->ultimo->prox = lista->primeiro;
    lista->primeiro->ante = lista->ultimo;
    lista->tamanho++;
}

void circularDuplamenteEncadeada::insereItemPrimeiro(Lista* lista, Item item) {
    Apontador inserido = new Elemento;
    inserido->item = item;

    inserido->prox = lista->primeiro->prox;
    inserido->ante = lista->primeiro;
    lista->primeiro->prox->ante = inserido;
    lista->primeiro->prox = inserido;
    lista->tamanho++;
}

void circularDuplamenteEncadeada::insereItemAposElemento(Lista* lista, Item item, int id) {
    Apontador atual = localizaItemPorId(lista, id);

    if(atual == NULL) {
        cout << "Id inexistente!" << endl;
        return;
    }

    Apontador inserido = new Elemento;
    inserido->item = item;

    if(atual == lista->ultimo) {
        insereItemUltimo(lista ,item);
    }
    else {
        inserido->prox = atual->prox;
        inserido->ante = atual;
        inserido->prox->ante = inserido;
    }
    atual->prox = inserido;
    lista->tamanho++;
}

circularDuplamenteEncadeada::Apontador circularDuplamenteEncadeada::localizaItemPorId(Lista* lista ,int id) {
    Apontador aux = lista->primeiro->prox;
    while(aux != lista->primeiro) {
        if(aux->item.id == id) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

circularDuplamenteEncadeada::Item circularDuplamenteEncadeada::retiraItemPorId(Lista* lista, int id) {
    Item retorno;
    retorno.id = -1;

    if(listaVazia(lista)) {
        return retorno;
    }
    Apontador atual = localizaItemPorId(lista, id);
    
    if(atual != lista->primeiro) {
        // Atualiza o proximo do anterior.
        atual->ante->prox = atual->prox;     

        // Caso o item removido seja o ultimo, atualiza o ultimo para o antecessor do removido.
        if(atual == lista->ultimo) {
            lista->ultimo = atual->ante;
            lista->primeiro->ante = lista->ultimo;
        }
        // Caso não, atualiza o anterior do proximo.
        else {
            atual->prox->ante = atual->ante;
        }

        // Guarda o item removido para retorno.
        retorno = atual->item;
        delete atual;
    }
    lista->tamanho--;
    return retorno;
}

void circularDuplamenteEncadeada::imprimeItem(Item item) {
    if(item.id == -1) {
        cout << "Item inexistente!" << endl;
        return;
    }

    cout << item.id;
    cout << endl;
}

void circularDuplamenteEncadeada::imprimeLista(Lista* lista) {
    Apontador aux = lista->primeiro->prox;
    while(aux != lista->primeiro) {
        imprimeItem(aux->item);
        aux = aux->prox;
    }
}

void circularDuplamenteEncadeada::imprimeListaReversa(Lista* lista) {
    Apontador aux = lista->ultimo;
    while(aux != lista->primeiro) {
        imprimeItem(aux->item);
        aux = aux->ante;
    } 
}
