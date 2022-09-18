#include <iostream>
#include <string.h>
#include <fstream>
#include "TAD_ListaEncadeada.hpp"

using namespace std;

// Lê o arquivo "funcionarios.bin" caso ele exista e inclui todos os funcionários contidos nele na lista.
// Atualiza o idFuncionario e idProjeto para o maior ID correspondente encontrado.
void lerArquivo(ListaFuncionarios* listaFuncionarios, int* idFuncionario, int* idProjeto) {
    FILE* file = fopen("funcionarios.bin", "r");
    Funcionario funcionario;
    if(file != NULL) {
        while(fread(&funcionario, sizeof(Funcionario), 1, file)) {
            if(funcionario.id > *idFuncionario) {
                *idFuncionario = funcionario.id;
            }
            for(int i = 0; i < funcionario.projetos.tamanho; i++) {
                if(funcionario.projetos.projeto[i].id > *idProjeto) {
                    *idProjeto = funcionario.projetos.projeto[i].id;
                }
            }
            InsereListaUltimo(listaFuncionarios, &funcionario);
        }
    }

    // ifstream arqEntrada("funcionarios.bin");
    // if(!arqEntrada.is_open()) {
    //     return;
    // } else {
    //     char indicador;
    //     arqEntrada.get(indicador);

    //     while(indicador == '$') {

    //         Funcionario funcionario;
    //         arqEntrada >> funcionario.id;
    //         arqEntrada.get();
    //         arqEntrada.getline(funcionario.nome, 50);
    //         arqEntrada.getline(funcionario.endereco.numero, 10);
    //         arqEntrada.getline(funcionario.endereco.rua, 50);
    //         arqEntrada.getline(funcionario.endereco.bairro, 50);
    //         arqEntrada.getline(funcionario.endereco.cidade, 50);
    //         arqEntrada.getline(funcionario.endereco.estado, 50);
    //         arqEntrada >> funcionario.dependentes;
    //         arqEntrada.get();

    //         if(funcionario.id > *idFuncionario) {
    //             *idFuncionario = funcionario.id;
    //         }

    //         ListaProjetos listaProjetos;
    //         criaListaVazia(&listaProjetos);

    //         arqEntrada.get(indicador);

    //         while(indicador == '?') {

    //             Projeto projeto;
    //             arqEntrada >> projeto.id;
    //             arqEntrada.get();
    //             arqEntrada.getline(projeto.nome, 50);
    //             arqEntrada >> projeto.horasSemanais;
    //             arqEntrada.get(indicador);
    //             insereItem(&listaProjetos, projeto);

    //             if(projeto.id > *idProjeto) {
    //                 *idProjeto = projeto.id;
    //             }

    //             arqEntrada.get(indicador);
    //         }

    //         funcionario.projetos = listaProjetos;
    //         InsereListaUltimo(listaFuncionarios, &funcionario);

    //     }
    // }
}

// Salva todos os funcionários presentes na lista no arquivo "funcionarios.bin".
void salvarArquivo(ListaFuncionarios* listaFuncionarios) {
    FILE* file = fopen("funcionarios.bin","w");
    Apontador aux = listaFuncionarios->primeiro->prox;
    while(aux != NULL) {
        fwrite(&aux->item, sizeof(Funcionario), 1, file);
        aux = aux->prox;
    }
    
    // ofstream arqSaida("funcionarios.bin");

    // Apontador aux;
    // aux = listaFuncionarios->primeiro->prox;

    // while(aux != NULL) {

    //     arqSaida << "$" << endl;
    //     arqSaida << aux->item.id << endl;
    //     arqSaida << aux->item.nome << endl;
    //     arqSaida << aux->item.endereco.numero << endl;
    //     arqSaida << aux->item.endereco.rua << endl;
    //     arqSaida << aux->item.endereco.bairro << endl;
    //     arqSaida << aux->item.endereco.cidade << endl;
    //     arqSaida << aux->item.endereco.estado << endl;
    //     arqSaida << aux->item.dependentes << endl;

    //     for(int i = 0; i < aux->item.projetos.tamanho; i++) {
    //         arqSaida << "?" << endl;
    //         arqSaida << aux->item.projetos.projeto[i].id << endl;
    //         arqSaida << aux->item.projetos.projeto[i].nome << endl;
    //         arqSaida << aux->item.projetos.projeto[i].horasSemanais << endl;
    //     }
    //     aux = aux->prox;
    // }
}

// Imprime o menu principal.
void imprimirMenu() {
    cout << "-------- Gestao De Funcionarios --------" << endl;
    cout << " 1 - Incluir Novo Funcionario" << endl;
    cout << " 2 - Incluir Projetos Em Funcionario" << endl;
    cout << " 3 - Excluir Projetos De Um Funcionario" << endl;
    cout << " 4 - Excluir Funcionarios Sem Projetos" << endl;
    cout << " 5 - Consulta Funcionario" << endl;
    cout << " 6 - Imprimir Contra Cheque" << endl;
    cout << " 7 - Imprimir Todos Funcionarios" << endl;
    cout << " 8 - Sair" << endl;
}

// Função chamada na hora de incluir novos projetos em um funcionário, 
// utilizada em incluirFuncionario() e incluirProjetosEmFuncionario().
void incluirProjetos(ListaProjetos *listaProjetos, int *idProjeto) {
    char opcao;
    do {
            Projeto projeto;
            do {
                projeto.id = *idProjeto;
                cin.ignore();
                cout << "Nome do projeto: ";
                cin.getline(projeto.nome, 50);
                cout << "Horas semanais: ";
                cin >> projeto.horasSemanais;

                // TEMP
                    // strcpy(projeto.nome, "NomeProjeto");
                    // projeto.horasSemanais = *idProjeto;
                // TEMP

                system("cls");
                do {
                    imprimeItem(projeto);
                    cout << "As informacoes desse projeto estao corretas?(s/n): ";
                    cin >> opcao;
                    system("cls");
                } while(opcao != 'n' && opcao != 's');

            } while(opcao == 'n');

            insereItem(listaProjetos, projeto);
            *idProjeto += 1;

            if(listaProjetos->tamanho < 5) {
                do {
                    cout << "Deseja incluir mais um projeto?(s/n): ";
                    cin >> opcao;
                    system("cls");
                } while(opcao != 'n' && opcao != 's');
            }

        } while(opcao == 's' && listaProjetos->tamanho < 5);
}

// Inclui novos funcionários na lista e apresenta a opção de incluir projetos.
void incluirFuncionario(ListaFuncionarios *listaFuncionarios, int *idFuncionario, int *idProjeto) {
    Funcionario funcionario;
    char opcao;

    do {
        funcionario.id = *idFuncionario;
        cin.ignore();
        cout << "Nome: ";
        cin.getline(funcionario.nome, 50);
        cout << "Rua: ";
        cin.getline(funcionario.endereco.rua, 50);
        cout << "Numero: ";
        cin.getline(funcionario.endereco.numero, 10);
        cout << "Bairro: ";
        cin.getline(funcionario.endereco.bairro, 50);
        cout << "Cidade: ";
        cin.getline(funcionario.endereco.cidade, 50);
        cout << "Estado: ";
        cin.getline(funcionario.endereco.estado, 50);
        cout << "Numero de dependentes: ";
        cin >> funcionario.dependentes;

        // TEMP
            // strcpy(funcionario.nome, "Nome");
            // strcpy(funcionario.endereco.rua, "Rua");
            // strcpy(funcionario.endereco.numero, "Num");
            // strcpy(funcionario.endereco.bairro, "Bairro");
            // strcpy(funcionario.endereco.cidade, "Cidade");
            // strcpy(funcionario.endereco.estado, "Estado");
            // funcionario.dependentes = 4;
        // TEMP
        system("cls");
        do {
            ImprimeItemRecebido(funcionario);
            cout << "As informacoes do funcionario estao corretas?(s/n): ";
            cin >> opcao;
            system("cls");
        } while(opcao != 'n' && opcao != 's');

    } while (opcao == 'n');

    ListaProjetos listaProjetos;
    criaListaVazia(&listaProjetos);

    do {
        cout << "Deseja cadastrar projetos para esse funcionario?(s/n): ";
        cin >> opcao;
        system("cls");
    } while(opcao != 'n' && opcao != 's');

    if(opcao == 's') {
        incluirProjetos(&listaProjetos, idProjeto);
    }

    funcionario.projetos = listaProjetos;
    InsereListaUltimo(listaFuncionarios, &funcionario);
    ImprimeItemRecebidoComProjetos(funcionario);
    *idFuncionario += 1;
}

// Inclui projetos em um funcionário já existente.
void incluirProjetosEmFuncionario(ListaFuncionarios *listaFuncionarios, int *idProjeto) {
    int id;
    char opcao;
    Apontador funcionario;
    do {
        cout << "Digite o ID do funcionario: ";
        cin >> id;
        system("cls");
        funcionario = PesquisaItem(listaFuncionarios, id);

        if(funcionario == NULL) {

            cout << "O ID informado nao corresponde a nenhum funcionario cadastrado." << endl;

        } else {

            do {
                ImprimeItemRecebidoComProjetos(funcionario->item);
                cout << "Deseja incluir novos projetos nesse funcionario?(s/n): ";
                cin >> opcao;
                system("cls");
            } while(opcao != 'n' && opcao != 's');

            if(opcao == 's') {
                if(funcionario->item.projetos.tamanho == 5) {
                    cout << "Esse funcionario ja possui 5 projetos cadastrados." << endl;
                } else {
                    incluirProjetos(&funcionario->item.projetos, idProjeto);
                }
            }
        }
    } while(opcao == 's');
}

// Exclui projetos de um funcinário já existente.
void excluirProjetos(ListaFuncionarios *listaFuncionarios) {
    int id;
    char opcao;

    cout << "Digite o ID do funcionario: ";
    cin >> id;
    system("cls");

    Apontador funcionario = PesquisaItem(listaFuncionarios, id);

    if(funcionario == NULL) {
        
        cout << "O ID informado nao corresponde a nenhum funcionario cadastrado." << endl;
        system("cls");

    } else {

        do {
                
            ImprimeItemRecebidoComProjetos(funcionario->item);

            cout << "Deseja apagar projetos desse funcionario?(s/n): ";
            cin >> opcao;

        } while(opcao != 'n' && opcao != 's');
        
    }
    
    if(funcionario->item.projetos.tamanho == 0) {

        cout << "Esse funcionario nao possui nenhum projeto cadastrado" << endl;

    } else {
         if(opcao == 's') {

            cout << "Digite o ID do projeto a ser apagado: ";
            cin >> id;
            int posicao = localizaItem(&funcionario->item.projetos, id);

            if(posicao == -1) {
                system("cls");
                cout << "O ID informado nao corresponde a nenhum projeto cadastrado" << endl;
            } else {

                do {

                    imprimeItem(funcionario->item.projetos.projeto[posicao]);
                    cout << "Deseja deletar esse projeto?(s/n): ";
                    cin >> opcao;
                    system("cls");

                } while(opcao != 'n' && opcao != 's');

                if(opcao == 's') {
                    removeItem(&funcionario->item.projetos, id);
                }
            }
        }
    }
    
}

// Exclui um ou todos os funcionários sem projetos cadastrados.
void excluirFuncionarios(ListaFuncionarios *listaFuncionarios) {
    
    cout << "-----Exclusao de Funcionarios-----" << endl;
    cout << "1 - Excluir todos os funcionarios" << endl;
    cout << "2 - Excluir um unico funcionario" << endl;
    cout << "3 - Voltar para o menu principal" << endl;
    
    char opcao;
    cout << "Escolha uma opcao: ";
    cin >> opcao;

    switch(opcao) {
        case '1':

            do {
                cout << "Deseja remover todos os funcionarios sem projetos cadastrados?(s/n): ";
                cin >> opcao;
                system("cls");
            } while(opcao != 'n' && opcao != 's');

            if(opcao == 's') {
                int i = RemoveFuncionariosSemProjetos(listaFuncionarios);
                cout << "Foram removidos " << i << " funcionario(s)." << endl;
            }  
        break;

        case '2':

            int id;
            cout << "Digite o ID do funcionario: ";
            cin >> id;
            system("cls");

            Apontador funcionario = PesquisaItem(listaFuncionarios ,id);
            
            if(funcionario == NULL) {

                cout << "O ID informado nao corresponde a nenhum funcionario cadastrado." << endl;

            } else {

                if(funcionario->item.projetos.tamanho != 0) {

                    cout << "Esse funcionario possui projetos cadastrados, por isso nao pode ser excluido!" << endl;

                } else {

                    ImprimeItemRecebido(funcionario->item);
                    RemoveItemPorId(listaFuncionarios, id);
                    cout << "Funcionario removido com sucesso" << endl;

                }
            }
        break;
    }
}

// Imprime as informações de um funcionários com base no ID informado.
void consultaFuncionario(ListaFuncionarios *listaFuncionarios) {
    int id;
    cout << "Digite o ID do funcionario: ";
    cin >> id;
    Apontador funcionario = PesquisaItem(listaFuncionarios ,id);
    system("cls");
    if(funcionario == NULL) {
        cout << "O ID informado nao corresponde a nenhum funcionario cadastrado." << endl;
    } else {
        ImprimeItemRecebidoComProjetos(funcionario->item);
    }
}

// Imprime o contra cheque de um ou todos funcionários cadastrados.
void imprimirContraCheque(ListaFuncionarios *listaFuncionarios) {
    cout << "------ Contra Cheque ------" << endl;
    cout << " 1 - Todos os funcionarios" << endl;
    cout << " 2 - Um unico funcionario" << endl;
    cout << "Escolha uma opcao: ";
    int opcao;
    cin >> opcao;
    system("cls");

    Apontador aux;
    switch(opcao) {
        case 1:

            aux = listaFuncionarios->primeiro->prox;
            while(aux != NULL) {

                ImprimeContraCheque(aux->item);
                cout << endl;
                if(aux != listaFuncionarios->ultimo) {
                    cout << "1 - Proximo / ";
                }
                cout << "2 - Menu" << endl;
                cout << "Escolha uma opcao: ";
                cin >> opcao;

                switch(opcao) {
                    case 1:
                    aux = aux->prox; 
                    break;
                    case 2:
                        return;
                    break;
                }
                system("cls");
            }     

        break;
        case 2:

            cout << "Digite o ID do funcionario: ";
            cin >> opcao;
            system("cls");

            aux = PesquisaItem(listaFuncionarios, opcao);
            if(aux == NULL) {
                cout << "O ID informado nao corresponde a nenhum funcionario cadastrado." << endl;
            } else {
                ImprimeContraCheque(aux->item);
            }
        break;
    }
}

// Imprime as informações de todos os funcionários cadastrados.
void imprimirTodosFuncionarios(ListaFuncionarios *listaFuncionarios) {
    Apontador aux = listaFuncionarios->primeiro->prox;
    int opcao;
    
    while(aux != NULL) {

        ImprimeItemRecebidoComProjetos(aux->item);
        cout << endl;
        if(aux != listaFuncionarios->ultimo) {
            cout << "1 - Proximo / ";
        }
        cout << "2 - Menu" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
               aux = aux->prox; 
            break;
            case 2:
                return;
            break;
        }
        system("cls");
    }
}