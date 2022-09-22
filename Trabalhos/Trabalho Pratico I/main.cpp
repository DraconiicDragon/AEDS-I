#include <iostream>

#include "FuncoesMain.hpp"

using namespace std;

int main() {

    ListaFuncionarios listaFuncionarios;
    CriaListaVazia(&listaFuncionarios);

    int idFuncionario = 0; // Variável para o controle automático dos IDs.
    int idProjeto = 0;     // Variável para o controle automático dos IDs.
    lerArquivo(&listaFuncionarios, &idFuncionario, &idProjeto);

    idFuncionario++;
    idProjeto++;
   
    int opcao;
    do {
        imprimirMenu();
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
            case 7:
                imprimirTodosFuncionarios(&listaFuncionarios);
            break;
        }

        system("pause");
        system("cls");

    } while(opcao != 8);

    salvarArquivo(&listaFuncionarios);
    DesalocaLista(&listaFuncionarios);

    return 0;
}