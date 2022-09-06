#ifndef FUNCOESLISTAS_H
#define FUNCOESLISTAS_H

#include "TAD_ListaArranjo.cpp"

struct Projeto;
struct ListaProjetos;

void criaListaVazia(ListaProjetos *lista);            // Inicializa a variavel "tamanho" como 0
bool verificaListaVazia(ListaProjetos *lista);        // Verifica se a lista está vazia (tamanho == 0)
bool verificaListaCheia(ListaProjetos *lista);        // Verifica se a lista está cheia (tamanho == MAX_TAM)
bool insereItem(ListaProjetos *lista, Projeto item); // Insere um novo item na lista
int localizaItem(ListaProjetos *lista, int id);       // Procura um item usando o id e retorna sua posição
void removeItem(ListaProjetos *lista, int id);        // Remove um item usando o id
void imprimeLista(ListaProjetos lista);               // Imprime o id de todos os itens

#endif