#include "TAD_FilaComPrioridade.cpp"
#include <ctime>

#define MAX_MEDICOS 5

using namespace FilaPrioridade;

struct Medico {
    string nome;
    string especialidade;
    string crm;

    time_t comecoDoAtendimento;
    float tempoDeAtendimento;
    Paciente pacienteAtendido;
    bool disponivel = true;
};

struct Upa {
    Medico medicos[MAX_MEDICOS];
    int medicosDisponiveis = MAX_MEDICOS;
    int totalDePacientesAtendidos = 0;

    int idPacientes = 1;

    Fila filaDePacientes;
};
