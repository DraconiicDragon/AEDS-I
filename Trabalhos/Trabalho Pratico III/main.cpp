#include <iostream>
#include "FuncoesMain.cpp"

using namespace std;

int main() {
    Upa hospital;
    criaFilaVazia(&hospital.filaDePacientes);
    cadastraMedicos(&hospital);

    int opcaoMenu;

    do {
        imprimeMenu();
        cin >> opcaoMenu;
        switch(opcaoMenu) {
            case 1:
                novoAtendimento(&hospital);
                break;
            case 2:
                imprimeFila(&hospital.filaDePacientes);
                break;
            case 3:
                imprimeListaMedicos(hospital.medicos);
                break;
        }
        system("cls");
        atualizaMedicos(&hospital);
        system("pause");
        system("cls");
    }while(opcaoMenu != 5);
    cout << "Foram atendidos " << hospital.totalDePacientesAtendidos << " hoje.";
    return 0;
}