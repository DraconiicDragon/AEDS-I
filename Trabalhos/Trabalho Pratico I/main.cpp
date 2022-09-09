#include <iostream>
#include "FuncoesMain.hpp"

using namespace std;

int main() {

    int opcao;
    int idFuncionario = 1;
    int idProjeto = 1;

    ListaFuncionarios listaFuncionarios;
    if(!listaCriada) {
        CriaListaVazia(&listaFuncionarios);
    }

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
                imprimirContraCheque();
            break;
        }

        system("pause");
        system("cls");

    } while(opcao != 7);

    DesalocaLista(&listaFuncionarios);
    return 0;
}