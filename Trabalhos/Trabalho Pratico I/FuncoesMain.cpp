#include <iostream>
#include <string.h>
#include "TAD_ListaEncadeada.hpp"

using namespace std;

void imprimirMenu() {
    cout << "Menu" << endl;
    cout << "1 - Incluir Novo Funcionario" << endl;
    cout << "5 - Consulta Funcionario" << endl;
    cout << "7 - Sair" << endl;
}

void incluirFuncionario(ListaFuncionarios *listaFuncionarios, int *idFuncionario, int *idProjeto) {
    Funcionario funcionario;
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

    ListaProjetos listaProjetos;
    criaListaVazia(&listaProjetos);

    char opcao;
    cout << "Deseja cadastrar projetos para esse funcionario?(s/n): ";
    cin >> opcao;
    system("cls");

    if(opcao == 's') {
        do {
            Projeto projeto;
            projeto.id = *idProjeto;

            // cin.getline(projeto.nome, 50);
            // cin >> projeto.horasSemanais;

            // TEMP
                strcpy(projeto.nome, "NomeProjeto");
                projeto.horasSemanais = *idProjeto;
            // TEMP

            insereItem(&listaProjetos, projeto);
            *idProjeto += 1;

            if(listaProjetos.tamanho < 5) {
                cout << "Deseja incluir mais um projeto?(s/n): ";
                cin >> opcao;
                
            }
            system("cls");
        } while(opcao == 's' && listaProjetos.tamanho < 5);
    }

    funcionario.projetos = listaProjetos;
    InsereListaUltimo(listaFuncionarios, &funcionario);
    ImprimeItem(listaFuncionarios, *idFuncionario);
    *idFuncionario += 1;
}

void incluirProjetos() {

}

void excluirProjetos() {

}

void excluirFuncionarios() {

}

void consultaFuncionario(ListaFuncionarios *listaFuncionarios) {
    int id;
    cout << "Digite o ID do funcionario: ";
    cin >> id;
    ImprimeItem(listaFuncionarios, id);
}

void imprimirContraCheque() {

}
