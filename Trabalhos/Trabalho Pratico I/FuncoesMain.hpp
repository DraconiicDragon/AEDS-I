#include "FuncoesMain.cpp"

// Arquivo

void lerArquivo(ListaFuncionarios* listaFuncionarios, int* idFuncionario, int* idProjeto);
void salvarArquivo(ListaFuncionarios* listaFuncionarios);

// Menu

void imprimirMenu();

// Inclusão

void incluirProjetos(ListaProjetos *listaProjetos, int *idProjeto);
void incluirFuncionario(ListaFuncionarios *listaFuncionarios, int *idFuncionario, int *idProjeto);
void incluirProjetosEmFuncionario(ListaFuncionarios *listaFuncionarios, int *idProjeto);

// Exclusão

void excluirProjetos(ListaFuncionarios *listaFuncionarios);
void excluirFuncionarios(ListaFuncionarios *listaFuncionarios);

// Impressão

void consultaFuncionario(ListaFuncionarios *listaFuncionarios);
void imprimirContraCheque(ListaFuncionarios *listaFuncionarios);
void imprimirTodosFuncionarios(ListaFuncionarios *listaFuncionarios);