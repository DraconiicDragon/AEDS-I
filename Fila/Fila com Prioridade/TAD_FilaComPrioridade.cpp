#include "TAD_FilaComPrioridade.hpp"

// Cria a fila vazia, obrigatorio o uso antes de usar a variavel.
void FilaPrioridade::criaFilaVazia(Fila* fila) {
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tamanho = 0;
}

// Retorna true caso a fila esteja vazia.
bool FilaPrioridade::verificaFilaVazia(Fila* fila) {
    if(fila->primeiro == NULL) {
        return true;   
    }
    return false;
}

// Insere o item no final da fila.
void FilaPrioridade::insereItemUltimo(Fila* fila, Item item) {
    Apontador aux = new Elemento;
    aux->item = item;
    aux->prox = NULL;

    if(verificaFilaVazia(fila)) {
        fila->primeiro = aux;
    } else {
        fila->ultimo->prox = aux;
    }

    fila->ultimo = aux;
    fila->tamanho++;
}

// Insere o item no começo da fila, usado na função insere com prioridade.
void FilaPrioridade::insereItemPrimeiro(Fila* fila, Item item) {

    Apontador aux = new Elemento;
    aux->item = item;
    aux->prox = NULL;

    if(verificaFilaVazia(fila)) {
        fila->primeiro = aux;
        fila->ultimo = fila->primeiro;
    } else {
        aux->prox = fila->primeiro;
        fila->primeiro = aux;
    }
    fila->tamanho++;
}

// Insere item apos outro item, usado na função insere com prioridade.
void FilaPrioridade::insereAposElemento(Apontador anterior, Apontador novo) {
    novo->prox = anterior->prox;
    anterior->prox = novo;
}

// Insere o item baseado em sua prioridade, prioridades menores são inseridas primeiro na fila.
void FilaPrioridade::insereItemPrioridade(Fila* fila, Item item) {
    if(verificaFilaVazia(fila)) {
        insereItemPrimeiro(fila, item);
        return;
    }

    if(item.prioridade < fila->primeiro->item.prioridade) {
        insereItemPrimeiro(fila, item);
        return;
    }

    Apontador anterior = fila->primeiro;
    Apontador atual = anterior->prox;

    Apontador novo = new Elemento;
    novo->item = item;
    novo->prox = NULL;

    
    while(atual != NULL) {
        if(novo->item.prioridade < atual->item.prioridade) {
            insereAposElemento(anterior, novo);
            return;
        }
        anterior = atual;
        atual = atual->prox;
        
    }
    insereAposElemento(fila->ultimo, novo);
    fila->ultimo = novo;
}

// Retira o primeiro item da fila e o retorna.
FilaPrioridade::Item FilaPrioridade::retiraItem(Fila* fila) {
    Item aux;
    aux.id = -1;

    if(verificaFilaVazia(fila)) {
        return aux;
    }

    aux = fila->primeiro->item;
    Apontador deletado = fila->primeiro;

    fila->primeiro = fila->primeiro->prox;
    fila->tamanho--;

    delete deletado;
    return aux;
}

// Retira todos os itens da fila.
void FilaPrioridade::esvaziaFila(Fila* fila) {
    Apontador aux = fila->primeiro;
    Apontador deletado;

    while(aux != NULL) {
        deletado = aux;
        aux = aux->prox;
        delete deletado;
    }

    fila->primeiro = NULL;
    fila->ultimo = fila->primeiro;
}

// Imprime o item recebido.
void FilaPrioridade::imprimeItem(Item item) {
    cout << "Id: " << item.id << endl;
    cout << "Prioridade: " << item.prioridade << endl;
    cout << "---------------";
    cout << endl;
}

// Imprime todos os itens da fila.
void FilaPrioridade::imprimeFila(Fila* fila) {
    Apontador aux = fila->primeiro;
    while(aux != NULL) {
        imprimeItem(aux->item);
        aux = aux->prox;
    }
}