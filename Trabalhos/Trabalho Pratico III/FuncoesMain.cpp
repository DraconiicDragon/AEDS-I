#include "FuncoesMain.hpp"

// Perguntas da triagem
const string perguntasTriagem[] = {
    // Vermelho
    "Compromentimento da via aerea",
    "Respiracao ineficaz",
    "Choque",
    "Nao responde a estimulos",
    "Em convulsao",

    // Laranja
    "Dor severa",
    "Grande Hemorragia",
    "Alteracao do estado de conciencia",
    "Temperatura maior ou igual a 39°C",
    "Trauma craniano severo",

    // Amarelo
    "Dor moderada",
    "Pequena hemoragia incontrolavel",
    "Vomito persistente",
    "Temperatura entre 38°C e 39°C",
    "Idoso ou gravida",

    // Verde
    "Dor leve",
    "Nauseas",
    "Temperatura entre 37°C e 38°C"
};

void imprimeMenu() {
    cout << "-------------------------" << endl;
    cout << "| 1 - Novo Atendimento  |" << endl;
    cout << "| 2 - Imprime Fila      |" << endl;
    cout << "| 3 - Imprime Medicos   |" << endl;
    cout << "| 4 - Atualiza Sistema  |" << endl;
    cout << "| 5 - Sair              |" << endl;
    cout << "-------------------------" << endl;
}

// Determina a prioridade do paciente, com base na triagem
int determinaPrioridade(Triagem triagem) {
    int tamanhoTriagem = sizeof(triagem.respostas) / sizeof(triagem.respostas[0]);
    for(int i = 0; i < tamanhoTriagem; i++) {
        if(triagem.respostas[i] == true) {
            if(i < 5) return 0;
            if(i < 10) return 1;
            if(i < 15) return 2;
            if(i < 18) return 3;
        }
    }
    return 4;
}

// Preenche a triagem do paciente
void preenchimentoTriagem(Triagem* triagem) {
    int tamanhoPerguntas = sizeof(perguntasTriagem) / sizeof(perguntasTriagem[0]);
    int numSintomas = 0;
    char resposta;

    for(int i = 0; i < tamanhoPerguntas; i++) {
        do {
            cout << perguntasTriagem[i] << "?(s/n): ";
            cin >> resposta;
        } while(resposta != 's' && resposta != 'S' && resposta != 'n' && resposta != 'N');

        if(resposta == 's' || resposta == 'S') {
            triagem->respostas[i] = true;

            if(i == 5 || i == 10 || i == 15 || i == 18) numSintomas = 0;
            numSintomas++;

            if(numSintomas >= triagem->numSintomasNecessarios) {
                return;
            }
        } else {
            triagem->respostas[i] = false;
        }
    }
}

// Cadastra as informações basicas do paciente
void cadastroDePaciente(Paciente* paciente, int id) {
    paciente->id = id;

    cout << "Digite o nome do paciente: " << endl;
    cin >> paciente->nome;

    cout << "Digite a idade do paciente: " << endl;
    cin >> paciente->idade;

    cout << "Digite o sexo do paciente: " << endl;
    cin >> paciente->sexo;

    cout << "Digite o endereco do paciente: " << endl;
    cin >> paciente->endereco;
}

// Cadastra os medicos
void cadastraMedicos(Upa* hospital) {
    hospital->medicos[0].nome = "Medico 1";
    hospital->medicos[0].especialidade = "Clinico Geral";
    hospital->medicos[0].crm = "MG 0001";

    hospital->medicos[1].nome = "Medico 2";
    hospital->medicos[1].especialidade = "Cardiologista";
    hospital->medicos[1].crm = "SP 0001";

    hospital->medicos[2].nome = "Medico 3";
    hospital->medicos[2].especialidade = "Odontologista";
    hospital->medicos[2].crm = "AC 0001";

    hospital->medicos[3].nome = "Medico 4";
    hospital->medicos[3].especialidade = "Ortopedista";
    hospital->medicos[3].crm = "MG 0002";

    hospital->medicos[4].nome = "Medico 5";
    hospital->medicos[4].especialidade = "Clinico Geral";
    hospital->medicos[4].crm = "MG 0003";
}

// Sorteia um tempo de atendimento com base na prioridade do paciente
int tempoDeAtendimento(int prioridade) {
    srand(time(NULL));
    if(prioridade == 0) {
        return (rand() % 20) + 40;
    }
    if(prioridade == 1) {
        return (rand() % 10) + 15;
    }
    if(prioridade == 2) {
        return (rand() % 10) + 10;
    }
    if(prioridade == 3) {
        return (rand() % 6) + 4;
    }
    if(prioridade == 4) {
        return (rand() % 2) + 6;
    }
}

// Atualiza a disponibilidade dos medicos
void atualizaMedicos(Upa* hospital) {
    Paciente paciente;
    for(int i = 0; i < hospital->medicosDisponiveis; i++) {

        // Verifica se ha algum medico disponivel
        if(!hospital->medicos[i].disponivel) {
            // Verifica se algum atendimento ja terminou e libera o medico caso sim
            if(((clock() - hospital->medicos[i].comecoDoAtendimento) / CLOCKS_PER_SEC) / 60 >= hospital->medicos[i].tempoDeAtendimento) {
                hospital->medicos[i].disponivel = true;
                cout << "O Dr. " << hospital->medicos[i].nome << " terminou de atender o paciente " << hospital->medicos[i].pacienteAtendido.nome << "." << endl;
                hospital->totalDePacientesAtendidos++;
            }  
        }
        if(hospital->medicos[i].disponivel) {
            paciente = retiraPaciente(&hospital->filaDePacientes);

            // Verifica o retorno da funcao
            if(paciente.id != -1) {
                // Designa um medico ao paciente
                hospital->medicos[i].pacienteAtendido = paciente;
                hospital->medicos[i].comecoDoAtendimento = clock();
                hospital->medicos[i].disponivel = false;
                hospital->medicos[i].tempoDeAtendimento = tempoDeAtendimento(paciente.prioridade);
                cout << endl << "O Dr. " << hospital->medicos[i].nome << " comecou a atender o paciente " << paciente.nome << "." << endl;

            }
        }
    }
}

// Imprime a lista de medicos
void imprimeListaMedicos(Medico medicos[]) {
    system("cls");
    for(int i = 0; i < MAX_MEDICOS; i++) {
        cout << "Nome do medico: " << medicos[i].nome << endl;
        if(medicos[i].disponivel) {
            cout << "Medicos disponivel" << endl;
        } else {
            cout << "Atendendo: " << medicos[i].pacienteAtendido.nome << endl;
            cout << "Tempo restante de atendimento: " << medicos[i].tempoDeAtendimento - ((clock()  - medicos[i].comecoDoAtendimento)/CLOCKS_PER_SEC/60) << " minutos." << endl;
        }
        cout << "-----------------------------" << endl << endl;
    }
}

// Chama as funções necessarias na ordem correta
void novoAtendimento(Upa* hospital) {
    Paciente paciente;

    preenchimentoTriagem(&paciente.triagem);
    system("cls");

    cadastroDePaciente(&paciente, hospital->idPacientes);
    system("cls");

    paciente.prioridade = determinaPrioridade(paciente.triagem);

    hospital->idPacientes++;

    imprimePaciente(paciente);
    inserePacientePrioridade(&hospital->filaDePacientes, paciente);
};