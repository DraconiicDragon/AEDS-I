#include <fstream>

#include "FuncoesMain.hpp"
#include "TAD_PilhaArranjo.cpp"

#define QNT_PRODUTOS 5

void lerArquivo(PilhaPedido* pilhaPedidos, int* idPedido) {
    FILE* file = fopen("lanchonete.bin", "r");
    Pedido pedido;
    if(file != NULL) {
        while(fread(&pedido, sizeof(Pedido), 1, file)) {
            if(pedido.id > *idPedido) {
                *idPedido = pedido.id;
            }
            empilha(pilhaPedidos, pedido);
        }
    }
}

void salvarArquivo(PilhaPedido* pilhaPedido) {
    FILE* file = fopen("lanchonete.bin","w");
    Pedido pedido;
    while(pilhaPedido->tamanho != 0) {
        pedido = desempilha(pilhaPedido);
        fwrite(&pedido, sizeof(Pedido), 1, file);
    }
}

void imprimeMenu() {
    cout << "----------------------------------" << endl;
    cout << "|              Menu              |" << endl;
    cout << "----------------------------------" << endl;
    cout << "| 1 - Incluir Novo Pedido        |" << endl;
    cout << "| 2 - Lista Pedidos              |" << endl;
    cout << "| 3 - Ver Cardapio               |" << endl;
    cout << "| 4 - Consultar Pedido           |" << endl;
    cout << "| 5 - Organizar Pilha de Entrega |" << endl;
    cout << "| 6 - Lancar Entrega             |" << endl;
    cout << "| 7 - Sair                       |" << endl;
    cout << "----------------------------------" << endl;
    cout << "Escolha uma opcao: ";
}

void imprimeCardapio() {
    cout << "--------------------" << endl;
    cout << "|     Cardapio     |" << endl;
    cout << "--------------------" << endl;
    cout << "| 1 - Suco         |" << endl;
    cout << "| 2 - Coxinha      |" << endl;
    cout << "| 3 - Sanduiche    |" << endl;
    cout << "| 4 - Bolo de Copo |" << endl;
    cout << "| 0 - Sair         |" << endl;
    cout << "--------------------" << endl;
}

// Preenche o vetor de produtos do pedido
void preencheProdutos(Pedido* pedido, float tabelaDePrecos[]) {
    pedido->tamanhoProdutos = 0;

    int opcaoCardapio;
    
    do {

        imprimeCardapio();
        cout << "Digite o codigo do produto: ";
        cin >> opcaoCardapio;
        system("cls");

        if(opcaoCardapio >= QNT_PRODUTOS || opcaoCardapio < 0) {

            cout << "Produto Inexistente!";

        } else if(opcaoCardapio != 0) {

            pedido->produtos[pedido->tamanhoProdutos] = opcaoCardapio;
            pedido->valor_pedido += tabelaDePrecos[opcaoCardapio];
            pedido->tamanhoProdutos++;

        } 
    } while (opcaoCardapio != 0 && pedido->tamanhoProdutos < MAX_TAM);
}

void incluiNovoPedido(PilhaPedido* pilhaPedidos, int* idPedido, float tabelaDePrecos[]) {
    Pedido pedido;
    pedido.id = *idPedido;
    
    pedido.valor_pedido = 0;
    preencheProdutos(&pedido, tabelaDePrecos);

    cout << "Digite a distancia da lanchonete: ";
    cin >> pedido.distancia;

    empilha(pilhaPedidos, pedido);
    *idPedido += 1;
}

// Imprime o pedido recebido junto com os nomes dos produtos
void imprimeItem(Pedido pedido, string tabelaDeProdutos[]) {
    cout << "Id do Pedido: " << pedido.id << endl;
    cout << "Valor Total: R$ " << pedido.valor_pedido << endl;
    cout << "Distancia: " << pedido.distancia << endl;
    cout << "Produtos: ";
    for(int i = 0; i < pedido.tamanhoProdutos; i++) {
        cout << tabelaDeProdutos[pedido.produtos[i]] << ", ";
    }
    cout << endl << "-------------------" << endl;
}

// Lista todos os pedidos da pilha
void listaPedidos(PilhaPedido pilhaPedido, string tabelaDeProdutos[]) {

    if(verificaPilhaVazia(&pilhaPedido)) {
        cout << "Pilha Vazia!" << endl;
        return;
    }

    Pedido pedido;
    while(pilhaPedido.tamanho != 0) {
        pedido = desempilha(&pilhaPedido);
        imprimeItem(pedido, tabelaDeProdutos);
    }
}

// Consulta um pedido especifico da pilha
void consultaPedido(PilhaPedido pilhaPedido, string tabelaDeProdutos[]) {
    int id;
    cout << "-----Busca de Pedido-----" << endl;
    cout << "Digite o ID do pedido: ";
    cin >> id;
    system("cls");

    Pedido pedido;
    while(pilhaPedido.tamanho != 0) {

        pedido = desempilha(&pilhaPedido);

        if(pedido.id == id) {
            imprimeItem(pedido, tabelaDeProdutos);
            return;
        }
    }
    cout << "Pedido Inexistente!" << endl;
}

// Organiza a pilha de forma crescente baseado na distância
void organizaPilha(PilhaPedido* pilhaPedido) {

    if(verificaPilhaVazia(pilhaPedido)) {
        cout << "Pilha Vazia!" << endl;
        return;
    }

    PilhaPedido aux1, aux2;
    criaPilhaVazia(&aux1);
    criaPilhaVazia(&aux2);

    Pedido pedido;

    int tamanhoPilha = pilhaPedido->tamanho;
    int maiorDistancia, idMaiorDistancia;

    // Desempilha pilhaPedido em aux1
    while(pilhaPedido->tamanho != 0) {
        empilha(&aux1, desempilha(pilhaPedido));
    }

    for(int i = 0; i < tamanhoPilha; i++) {
        maiorDistancia = -1;
        idMaiorDistancia = 0;

        // Desempilha aux1 em aux2 procurando a maior distância
        while(aux1.tamanho != 0) {
            pedido = desempilha(&aux1);
            empilha(&aux2, pedido);
            if(maiorDistancia < pedido.distancia) {
                maiorDistancia = pedido.distancia;
                idMaiorDistancia = pedido.id;
            }
        }

        // Desempilha aux2 em aux1, empilhando em pilhaPedido em vez de aux1, caso seja a maior distancia encontrada
        while(aux2.tamanho != 0) {
            pedido = desempilha(&aux2);
            if(pedido.id == idMaiorDistancia) {
                empilha(pilhaPedido, pedido);
            } else {
                empilha(&aux1, pedido);
            }
        }
    }
    cout << "Pilha Organizada com sucesso!" << endl;
}

// Desempilha o primeiro item da pilha
void lancaEntrega(PilhaPedido* pilhaPedido, string tabelaDeProdutos[]) {

    if(verificaPilhaVazia(pilhaPedido)) {
        cout << "Pilha Vazia!" << endl;
        return;
    }

    Pedido pedido;
    pedido = desempilha(pilhaPedido);
    cout << "Pedido Entregue!" << endl;
    imprimeItem(pedido, tabelaDeProdutos);
}