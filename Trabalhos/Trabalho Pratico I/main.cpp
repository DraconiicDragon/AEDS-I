#include <iostream>
#include <fstream>

#include "FuncoesMain.hpp"

using namespace std;

int main() {

    ListaFuncionarios listaFuncionarios;
    if(!listaCriada) {
        CriaListaVazia(&listaFuncionarios);
    }

    int opcao;
    int idFuncionario = 0;
    int idProjeto = 0;
  
    ifstream arqEntrada("funcionarios.bin");

    if(arqEntrada.is_open()) {
        char indicador;
        arqEntrada.get(indicador);
        while(indicador == '$') {
            Funcionario funcionario;
            arqEntrada >> funcionario.id;
            arqEntrada.get();
            arqEntrada.getline(funcionario.nome, 50);
            arqEntrada.getline(funcionario.endereco.numero, 10);
            arqEntrada.getline(funcionario.endereco.rua, 50);
            arqEntrada.getline(funcionario.endereco.bairro, 50);
            arqEntrada.getline(funcionario.endereco.cidade, 50);
            arqEntrada.getline(funcionario.endereco.estado, 50);
            arqEntrada >> funcionario.dependentes;
            arqEntrada.get();

            if(funcionario.id > idFuncionario) {
                idFuncionario = funcionario.id;
            }

            ListaProjetos listaProjetos;
            criaListaVazia(&listaProjetos);

            arqEntrada.get(indicador);

            while(indicador == '?') {
                Projeto projeto;
                arqEntrada >> projeto.id;
                arqEntrada.get();
                arqEntrada.getline(projeto.nome, 50);
                arqEntrada >> projeto.horasSemanais;
                arqEntrada.get(indicador);
                insereItem(&listaProjetos, projeto);

                if(projeto.id > idProjeto) {
                    idProjeto = projeto.id;
                }
                arqEntrada.get(indicador);
            }
            funcionario.projetos = listaProjetos;
            InsereListaUltimo(&listaFuncionarios, &funcionario);
        }
    }

    idFuncionario++;
    idProjeto++;
   
    do {
        imprimirMenu();
        cout << "Digite sua escolha: ";
        cin >> opcao;
        system("cls");

        switch(opcao) {
            case 1:
                incluirFuncionario(&listaFuncionarios, &idFuncionario, &idProjeto);
            break;
            case 2:
                incluirProjetosEmFuncionario(&listaFuncionarios, &idProjeto);
            break;
            case 3:
                excluirProjetos(&listaFuncionarios);
            break;
            case 4:
                excluirFuncionarios(&listaFuncionarios);
            break;
            case 5:
                consultaFuncionario(&listaFuncionarios);
            break;
            case 6:
                imprimirContraCheque(&listaFuncionarios);
            break;
        }

        system("pause");
        system("cls");

    } while(opcao != 7);

    ofstream arqSaida("funcionarios.bin");
    Apontador aux;
    aux = listaFuncionarios.primeiro->prox;
    while(aux != NULL) {
        arqSaida << "$" << endl;
        arqSaida << aux->item.id << endl;
        arqSaida << aux->item.nome << endl;
        arqSaida << aux->item.endereco.numero << endl;
        arqSaida << aux->item.endereco.rua << endl;
        arqSaida << aux->item.endereco.bairro << endl;
        arqSaida << aux->item.endereco.cidade << endl;
        arqSaida << aux->item.endereco.estado << endl;
        arqSaida << aux->item.dependentes << endl;
        for(int i = 0; i < aux->item.projetos.tamanho; i++) {
            arqSaida << "?" << endl;
            arqSaida << aux->item.projetos.projeto[i].id << endl;
            arqSaida << aux->item.projetos.projeto[i].nome << endl;
            arqSaida << aux->item.projetos.projeto[i].horasSemanais << endl;
        }
        aux = aux->prox;
    }

    DesalocaLista(&listaFuncionarios);
    return 0;
}