#include "TAD_FilaComPrioridade.cpp"

#define MAX_TAM 5

using namespace FilaPrioridade;

struct Medico {
    string nome;
    string especialidade;
    string crm;

    float comecoDoAtendimento;
    float tempoDeAtendimento;
    Paciente pacienteAtendido;
    bool disponivel = true;
};

struct Upa {
    Medico medicos[MAX_TAM];
    int medicosDisponiveis = MAX_TAM;
    int totalDePacientesAtendidos;

    Fila filaDePacientes;

};
