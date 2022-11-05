#include <iostream>

using namespace std;

namespace FilaPrioridade {

struct Triagem {
    bool respostasVermelho[5];
    bool respostasLaranja[5];
    bool respostasAmarelo[5];
    bool respostasVerde[3];
};

struct Paciente {
    string nome;
    string endereco;
    int idade;
    char sexo;

    int id;
    int prioridade;
    Triagem triagem;
};

typedef struct Elemento* Apontador;

struct Elemento {
    Paciente paciente;
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


void inserePacienteUltimo(Fila* fila, Paciente Paciente); 
void inserePacientePrimeiro(Fila* fila, Paciente Paciente); 
void insereAposElemento(Apontador anterior, Apontador novo);
void inserePacientePrioridade(Fila* fila, Paciente Paciente); 

Paciente retiraPaciente(Fila* fila); 
void esvaziaFila(Fila* fila); 

void imprimePaciente(Paciente Paciente); 
void imprimeFila(Fila* fila); 

}

