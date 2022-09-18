#ifndef LISTA_H
#define LISTA_H

#include "TAD_ListaEncadeada.cpp"

typedef struct Funcionario;

typedef struct Elemento *Apontador;

typedef struct Elemento;
typedef struct ListaFuncionarios;

void CriaListaVazia(ListaFuncionarios *lista);
bool VerificaListaVazia(ListaFuncionarios *lista);
int TamanhoLista(ListaFuncionarios *lista);
void AtualizaUltimo(ListaFuncionarios *lista);

void InsereListaPrimeiro(ListaFuncionarios *lista, Funcionario *item);
void InsereListaAposElemento(ListaFuncionarios *lista, Funcionario *item, int id);
void InsereListaUltimo(ListaFuncionarios *lista, Funcionario *item);

void ImprimeLista(ListaFuncionarios lista);
Apontador PesquisaItem(ListaFuncionarios *lista, int id);
void ImprimeItemRecebido(Funcionario funcionario);
void ImprimeItemRecebidoComProjetos(Funcionario funcionario);
void ImprimeContraCheque(Funcionario funcionario);

void RemoveListaPrimeiro(ListaFuncionarios *lista);
void RemoveListaUltimo(ListaFuncionarios *lista);
void RemoveItemPorId(ListaFuncionarios *lista, int id);
int RemoveFuncionariosSemProjetos(ListaFuncionarios *lista);
void DesalocaLista(ListaFuncionarios *lista);

#endif