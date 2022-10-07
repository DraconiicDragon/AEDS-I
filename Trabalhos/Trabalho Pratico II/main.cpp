#include <iostream>

#include "FuncoesMain.cpp"

using namespace std;

int main() {

    PilhaPedido mochila;
    criaPilhaVazia(&mochila);

    // Vetor para armazenar os nomes dos produtos, indices equiparam-se com a tabelaDePrecos
    string tabelaDeProdutos[QNT_PRODUTOS] = {"", "Suco", "Coxinha", "Sanduiche", "Bolo de Copo"};

    // Vetor para armazenar os preços dos produtos, indices equiparam-se com a tabelaDeProdutos
    float tabelaDePrecos[QNT_PRODUTOS] = {0, 3, 3.5, 4, 5.5};

    int idPedidos = 0; // Variável para o controle automático de IDs
    lerArquivo(&mochila, &idPedidos);
    idPedidos++;

    int opcao;

    do {
        imprimeMenu();
        cin >> opcao;
        system("cls");  

        switch(opcao) {
            case 1:
                incluiNovoPedido(&mochila, &idPedidos, tabelaDePrecos);
            break;

            case 2:
                listaPedidos(mochila, tabelaDeProdutos);
            break;

            case 3:
                imprimeCardapio();
            break;

            case 4:
                consultaPedido(mochila, tabelaDeProdutos);
            break;

            case 5:
                organizaPilha(&mochila);
            break;

            case 6:
                lancaEntrega(&mochila, tabelaDeProdutos);
            break;
        }

        system("pause");
        system("cls");
    } while(opcao != 7);

    salvarArquivo(&mochila);

    return 0;
}