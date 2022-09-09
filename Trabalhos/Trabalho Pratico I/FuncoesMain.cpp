#include <iostream>
#include <string.h>
#include <fstream>
#include "TAD_ListaEncadeada.hpp"

using namespace std;

void imprimirMenu() {
    cout << "Menu" << endl;
    cout << "1 - Incluir Novo Funcionario" << endl;
    cout << "2 - Incluir Projetos Em Funcionario" << endl;
    cout << "3 - Excluir Projetos De Um Funcionario" << endl;
    cout << "4 - Excluir Funcionarios Sem Projetos" << endl;
    cout << "5 - Consulta Funcionario" << endl;
    cout << "7 - Sair" << endl;
}

void incluirProjetos(ListaProjetos *listaProjetos, int *idProjeto) {
    char opcao;
    do {
            Projeto projeto;
            do {
                projeto.id = *idProjeto;
                // cin.getline(projeto.nome, 50);
                // cin >> projeto.horasSemanais;

                // TEMP
                    strcpy(projeto.nome, "NomeProjeto");
                    projeto.horasSemanais = *idProjeto;
                // TEMP

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

void incluirFuncionario(ListaFuncionarios *listaFuncionarios, int *idFuncionario, int *idProjeto) {
    Funcionario funcionario;
    char opcao;

    do {
        funcionario.id = *idFuncionario;
        // cin.getline(funcionario.nome, 50);
        // cin.getline(funcionario.endereco.rua, 50);
        // cin.getline(funcionario.endereco.numero, 10);
        // cin.getline(funcionario.endereco.bairro, 50);
        // cin.getline(funcionario.endereco.cidade, 50);
        // cin.getline(funcionario.endereco.estado, 50);
        // cin >> funcionario.dependentes;

        // TEMP
            strcpy(funcionario.nome, "Nome");
            strcpy(funcionario.endereco.rua, "Rua");
            strcpy(funcionario.endereco.numero, "Num");
            strcpy(funcionario.endereco.bairro, "Bairro");
            strcpy(funcionario.endereco.cidade, "Cidade");
            strcpy(funcionario.endereco.estado, "Estado");
            funcionario.dependentes = 4;
        // TEMP

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
    ImprimeItem(listaFuncionarios, *idFuncionario);
    *idFuncionario += 1;
}

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
        do {
                
            cout << "Deseja digitar um novo ID?(s/n): ";
            cin >> opcao;
            system("cls");

        } while(opcao != 'n' && opcao != 's');
    } while(opcao == 's');

    cout << "Voltando ao menu principal" << endl;
}

void excluirProjetos(ListaFuncionarios *listaFuncionarios) {
    int id;
    char opcao;

    cout << "Digite o ID do funcionario: ";
    cin >> id;

    Apontador funcionario = PesquisaItem(listaFuncionarios, id);

    if(funcionario == NULL) {
        
        cout << "O ID informado nao corresponde a nenhum funcionario cadastrado." << endl;
        system("cls");

    } else {

        do {
                
            ImprimeItemRecebidoComProjetos(funcionario->item);

            cout << "Deseja apagar projetos desse funcionario?(s/n): ";
            cin >> opcao;
            system("cls");

        } while(opcao != 'n' && opcao != 's');
        
    }
    
    if(funcionario->item.projetos.tamanho == 0) {

        cout << "Esse funcionario nao possui nenhum projeto cadastrado" << endl;

    } else {
         if(opcao == 's') {

            cout << "Digite o ID do projeto a ser apagado: ";
            cin >> id;
            int posicao = localizaItem(&funcionario->item.projetos, id);

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

void excluirFuncionarios(ListaFuncionarios *listaFuncionarios) {
    char opcao;

    cout << "Deseja remover todos os funcionarios sem projetos cadastrados?(s/n): ";
    cin >> opcao;

    if(opcao == 's') {
        int i = RemoveFuncionariosSemProjetos(listaFuncionarios);
        cout << "Foram removidos " << i << " funcionarios." << endl;
    }
}

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

void imprimirContraCheque() {

}
