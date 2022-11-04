#include "TAD_ListaDuplamenteEncadeada.hpp"

void listaDuplamenteEncadeada::Lista::criaListaVazia() {
    primeiro = new Elemento;
    ultimo = primeiro;
    ultimo->prox = NULL;
    ultimo->ante = NULL;
    tamanho = 0;
}

bool listaDuplamenteEncadeada::Lista::listaVazia() {
    if(tamanho == 0 && ultimo == primeiro) {
        return true;
    }
    return false;
}

void listaDuplamenteEncadeada::Lista::insereItemUltimo(Item item) {
    ultimo->prox = new Elemento;
    ultimo->prox->ante = ultimo;
    ultimo = ultimo->prox;
    ultimo->item = item;
    ultimo->prox = NULL;
    tamanho++;
}

void listaDuplamenteEncadeada::Lista::insereItemPrimeiro(Item item) {
    Apontador inserido = new Elemento;
    inserido->item = item;

    inserido->prox = primeiro->prox;
    inserido->ante = primeiro;
    primeiro->prox->ante = inserido;
    primeiro->prox = inserido;
    tamanho++;
}

void listaDuplamenteEncadeada::Lista::insereItemAposElemento(Item item, int id) {
    Apontador atual = localizaItemPorId(id);

    if(atual == NULL) {
        cout << "Id inexistente!";
        return;
    }

    Apontador inserido = new Elemento;
    inserido->item = item;

    if(atual == ultimo) {
        insereItemUltimo(item);
    }
    else {
        inserido->prox = atual->prox;
        inserido->ante = atual;
        inserido->prox->ante = inserido;
    }
    atual->prox = inserido;
    tamanho++;
}

listaDuplamenteEncadeada::Apontador listaDuplamenteEncadeada::Lista::localizaItemPorId(int id) {
    Apontador aux = primeiro->prox;
    while(aux != NULL) {
        if(aux->item.id == id) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

listaDuplamenteEncadeada::Item listaDuplamenteEncadeada::Lista::retiraItemPorId(int id) {
    Item retorno;
    retorno.id = -1;

    if(listaVazia()) {
        return retorno;
    }
    Apontador atual = localizaItemPorId(id);
    
    if(atual != NULL) {
        // Atualiza o proximo do anterior.
        atual->ante->prox = atual->prox;     

        // Caso o item removido seja o ultimo, atualiza o ultimo para o antecessor do removido.
        if(atual == ultimo) {
            ultimo = atual->ante;
        }
        // Caso não, atualiza o anterior do proximo.
        else {
            atual->prox->ante = atual->ante;
        }

        // Guarda o item removido para retorno.
        retorno = atual->item;
        delete atual;
    }
    tamanho--;
    return retorno;
}

void listaDuplamenteEncadeada::Lista::imprimeItem(Item item) {
    if(item.id == -1) {
        cout << "Item inexistente!" << endl;
        return;
    }

    cout << item.id;
    cout << endl;
}

void listaDuplamenteEncadeada::Lista::imprimeLista() {
    Apontador aux = primeiro->prox;
    while(aux != NULL) {
        imprimeItem(aux->item);
        aux = aux->prox;
    }
}

void listaDuplamenteEncadeada::Lista::imprimeListaReversa() {
    Apontador aux = ultimo;
    while(aux != primeiro) {
        imprimeItem(aux->item);
        aux = aux->ante;
    } 
}
