#include "TAD_FilaComPrioridade.hpp"

// Cria a fila vazia, obrigatorio o uso antes de usar a variavel.
void FilaPrioridade::criaFilaVazia(Fila* fila) {
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tamanho = 0;
}

// Retorna true caso a fila esteja vazia.
bool FilaPrioridade::filaVazia(Fila* fila) {
    if(fila->primeiro == NULL) {
        return true; 
    }
    return false;
}

// Insere o Paciente no final da fila.
void FilaPrioridade::inserePacienteUltimo(Fila* fila, Paciente Paciente) {
    Apontador aux = new Elemento;
    aux->paciente = Paciente;
    aux->prox = NULL;

    if(filaVazia(fila)) {
        fila->primeiro = aux;
    } else {
        fila->ultimo->prox = aux;
    }

    fila->ultimo = aux;
    fila->tamanho++;
}

// Insere o Paciente no começo da fila, usado na função insere com prioridade.
void FilaPrioridade::inserePacientePrimeiro(Fila* fila, Paciente Paciente) {

    Apontador aux = new Elemento;
    aux->paciente = Paciente;
    aux->prox = NULL;

    if(filaVazia(fila)) {
        fila->primeiro = aux;
        fila->ultimo = fila->primeiro;
    } else {
        aux->prox = fila->primeiro;
        fila->primeiro = aux;
    }
    fila->tamanho++;
}

// Insere Paciente apos outro Paciente, usado na função insere com prioridade.
void FilaPrioridade::insereAposElemento(Apontador anterior, Apontador novo) {
    novo->prox = anterior->prox;
    anterior->prox = novo;
}

// Insere o Paciente baseado em sua prioridade, prioridades menores são inseridas primeiro na fila.
void FilaPrioridade::inserePacientePrioridade(Fila* fila, Paciente Paciente) {
    // Se a fila estiver vazia insere o Paciente direto no primeiro.
    if(filaVazia(fila)) {
        inserePacientePrimeiro(fila, Paciente);
        return;
    }

    // Se a prioridade do novo Paciente for menor que a do primeiro, insere o Paciente no começo da fila.
    if(Paciente.prioridade < fila->primeiro->paciente.prioridade) {
        inserePacientePrimeiro(fila, Paciente);
        return;
    }

    Apontador anterior = fila->primeiro;
    Apontador atual = anterior->prox;
    Apontador novo = new Elemento;
    novo->paciente = Paciente;
    novo->prox = NULL;

    // Insere apos a maior prioridade encontrada, não funciona para o ultimo.
    while(atual != NULL) {
        if(novo->paciente.prioridade < atual->paciente.prioridade) {
            insereAposElemento(anterior, novo);
            return;
        }
        anterior = atual;
        atual = atual->prox; 
    }
    insereAposElemento(fila->ultimo, novo);
    fila->ultimo = novo;
}

// Retira o primeiro Paciente da fila e o retorna.
FilaPrioridade::Paciente FilaPrioridade::retiraPaciente(Fila* fila) {
    Paciente aux;
    aux.id = -1;

    if(filaVazia(fila)) {
        return aux;
    }

    aux = fila->primeiro->paciente;
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

// Imprime o Paciente recebido.
void FilaPrioridade::imprimePaciente(Paciente Paciente) {
    cout << "Id: " << Paciente.id << endl;
    cout << "Prioridade: " << Paciente.prioridade << endl;
    cout << "---------------";
    cout << endl;
}

// Imprime todos os itens da fila.
void FilaPrioridade::imprimeFila(Fila* fila) {
    Apontador aux = fila->primeiro;
    while(aux != NULL) {
        imprimePaciente(aux->paciente);
        aux = aux->prox;
    }
}