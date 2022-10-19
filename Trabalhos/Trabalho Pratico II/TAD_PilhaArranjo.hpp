#ifndef PILHA_H
#define PILHA_H

#define MAX_TAM 10
#define MAX_ENTREGA 7

struct Pedido {
    int id;
    int produtos[MAX_TAM];
    int tamanhoProdutos;
    float valor_pedido;
    float distancia;
};

struct PilhaPedido {
    Pedido pedido[MAX_ENTREGA];
    int tamanho;
};

bool criaPilhaVazia(PilhaPedido* pilha);
bool verificaPilhaVazia(PilhaPedido* pilha);
bool verificaPilhaCheia(PilhaPedido* pilha);
bool empilha(PilhaPedido* pilha, Pedido item);
Pedido desempilha(PilhaPedido* pilha);
void imprimePilha(PilhaPedido pilha);
int getTamanho(PilhaPedido* pilha);

#endif